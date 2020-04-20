note *table[10];

int get_inp(char *buffer, int size)
{
    int retval; // [rsp+1Ch] [rbp-4h]

    retval = read(0, buffer, size);
    if ( retval == -1 )
        exit(0);
    if ( buffer[retval - 1] == 10 )
        buffer[retval - 1] = 0;
    return retval - 1;
}

int get_int()
{
    char buffer[32]; // [rsp+0h] [rbp-30h]
    uint64_t v2; // [rsp+28h] [rbp-8h]

    get_inp(buffer, 32);
    return atoi(buffer);
}

int64_t get_ll()
{
    char buffer[32]; // [rsp+0h] [rbp-30h]
    uint64_t v2; // [rsp+28h] [rbp-8h]

    get_inp(buffer, 32);
    return atoll(buffer);
}

int insert(char *name, int64_t size, char *desc, int idx)
{
    table[idx]->size = size;
    table[idx]->desc = desc;
    strcpy(table[idx]->name, name);
    return 0;
}

int add_note()
{
    char *v0; // rdx
    size_t size; // ST10_8
    char *ptr; // ST18_8
    int i; // [rsp+Ch] [rbp-174h]
    char name[80]; // [rsp+20h] [rbp-160h]
    char desc[256]; // [rsp+70h] [rbp-110h]
    uint64_t v7; // [rsp+178h] [rbp-8h]

    memset(desc, 0, sizeof(desc));
    v0 = name;
    memset(name, 0, sizeof(name));
    for ( i = 0; i <= 9; ++i )
    {
        v0 = (char *)i;
        if ( !table[i] )
            break;
    }
    if ( i == 10 )
        return 0;
    printf("ID : %d\n", (unsigned int)i, v0);
    printf("Enter name: ");
    fgets(name, 81, stdin);
    printf("Enter desc: ", 81LL);
    fgets(desc, 257, stdin);
    size = strlen(desc);
    ptr = strdup(desc);
    table[i] = (note *)malloc(0x60uLL);
    insert(name, size, ptr, i);
    return i;
}

int edit_note()
{
    int64_t v0; // rsi
    int idx; // [rsp+Ch] [rbp-174h]
    char *ptr; // [rsp+10h] [rbp-170h]
    int64_t size; // [rsp+18h] [rbp-168h]
    char name[80]; // [rsp+20h] [rbp-160h]
    char desc[256]; // [rsp+70h] [rbp-110h]
    uint64_t v7; // [rsp+178h] [rbp-8h]

    memset(desc, 0, sizeof(desc));
    memset(name, 0, sizeof(name));
    printf("Enter index: ", v0, name);
    idx = get_int();
    if ( idx < 0 || idx > 9 || !table[idx] )
        return 0;
    printf("Enter name: ");
    fgets(name, 81, stdin);
    printf("Enter size: ", 81LL);
    size = get_ll();
    printf("Enter desc: ");
    if ( size > 256 )
    {
        ptr = (char *)malloc(size);
        fgets(ptr, size + 1, stdin);
    }
    else
    {
        fgets(desc, 257, stdin);
        ptr = strdup(desc);
    }
    insert(name, size, ptr, idx);
    return 0;
}

int remove_note()
{
    int idx; // [rsp+Ch] [rbp-4h]

    printf("Enter idx: ");
    idx = get_int();
    if ( idx < 0 || idx > 9 || !table[idx] )
        return 0;
    free(table[idx]->desc);
    table[idx]->desc = 0LL;
    free(table[idx]);
    table[idx] = 0LL;
    return 0;
}

int view_note()
{
    int idx; // [rsp+Ch] [rbp-4h]

    printf("Enter idx: ");
    idx = get_int();
    if ( idx < 0 || idx > 9 || !table[idx] )
        return 0;
    printf("Note ID : %d\nName : %s\n", (unsigned int)idx, table[idx]);
    printf("Size : %lld\nDescription : %s\n", table[idx]->size, table[idx]->desc);
    return 0;
}

int printmenu()
{
    puts("1) Add note\n2) Edit note\n3) Remove note\n4) View note\n5) Exit");
    printf(">> ");
    return get_int();
}

int main()
{
    alarm(0x1Eu);
    setvbuf(stdout, 0LL, 2, 0LL);
    puts("---------------------------");
    while ( 1 )
    {
        switch (printmenu())
        {
        case 1u:
            add_note();
            break;
        case 2u:
            edit_note();
            break;
        case 3u:
            remove_note();
            break;
        case 4u:
            view_note();
            break;
        case 5u:
            exit(0);
            return;
        default:
            puts("Invalid");
            break;
        }
    }
}
