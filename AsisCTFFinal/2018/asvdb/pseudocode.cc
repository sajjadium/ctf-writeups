void *bug_list;

void setup_bug_list()
{
    setvbuf(stdin, 0LL, 2, 0LL);
    setvbuf(stdout, 0LL, 2, 0LL);
    alarm(0xB4u);
    bug_list = malloc(40uLL);
    bzero(bug_list, 0x28uLL);
}

int show_menu()
{
    puts("1. Create Bug");
    puts("2. Edit Bug (N/A)");
    puts("3. Delete Bug");
    puts("4. Show Bug");
    puts("5. Exit");
    return printf("> ");
}

int show_banner()
{
    return puts("WELCOME TO ASIS VULNERABILITY DATABASE");
}

int64_t read_string(int64_t a1, unsigned int a2)
{
    unsigned int i; // [rsp+1Ch] [rbp-4h]

    for ( i = 0; i < a2 && read(0, (void *)(i + a1), 1uLL) == 1; ++i )
    {
        if ( *(char *)(i + a1) == '\n' )
        {
            *(char *)(i + a1) = 0;
            return i;
        }
    }
    return i;
}

int64_t read_int()
{
    char s; // [rsp+10h] [rbp-20h]
    uint64_t v2; // [rsp+28h] [rbp-8h]

    bzero(&s, 0x10uLL);
    read_string((int64_t)&s, 0x10u);
    return strtoll(&s, 0LL, 10);
}

signed int64_t check_capacity()
{
    unsigned int i; // [rsp+0h] [rbp-4h]

    for ( i = 0; i <= 4; ++i )
    {
        if ( !*((int64_t *)bug_list + i) )
            return i;
    }
    return 4294967295LL;
}

int create_bug()
{
    void *title; // ST20_8
    void *desc; // ST28_8
    unsigned int idx; // [rsp+4h] [rbp-2Ch]
    unsigned int size; // [rsp+10h] [rbp-20h]
    int *new_bug; // [rsp+18h] [rbp-18h]

    idx = check_capacity();
    if ( idx == -1 )
        return puts("bug list is full, sorry.");
    puts("Creating Bug:");
    new_bug = malloc(32uLL);
    printf("Enter year: ");
    *(_WORD *)new_bug = read_int();
    printf("Enter id: ");
    new_bug[1] = read_int();
    printf("Enter title (Up to 64 chars): ");
    title = malloc(64uLL);
    bzero(title, 64uLL);
    read_string((int64_t)title, 63u);
    *((int64_t *)new_bug + 1) = title;
    printf("Enter description size: ", 63LL);
    size = read_int();
    if ( size && size <= 255 )
    {
        desc = malloc(size);
        bzero(desc, size);
        printf("Enter description: ", size);
        read_string((int64_t)desc, size - 1);
        *((int64_t *)new_bug + 2) = desc;
    }
    else
    {
        puts("Invalid description size.");
    }
    printf("Enter Severity: (0: LOW, 1: MEDIUM, 2: HIGH, 3: CRITICAL): ");
    new_bug[6] = read_int();
    *((int64_t *)bug_list + idx) = new_bug;
    return printf("New bug created at index=%u.\n", idx);
}

int edit_bug()
{
    return puts("Not implemented yet.");
}

int free_bug(unsigned int index)
{
    int64_t *v1; // rax

    if ( *((int64_t *)bug_list + index) )
    {
        free(*(void **)(*((int64_t *)bug_list + index) + 8LL));
        free(*(void **)(*((int64_t *)bug_list + index) + 16LL));
        free(*((void **)bug_list + index));
        v1 = (char *)bug_list + 8 * index;
        *v1 = 0LL;
    }
    else
    {
        LODWORD(v1) = puts("Wrong idx.");
    }
    return (signed int)v1;
}

int delete_bug()
{
    int result; // eax
    unsigned int index; // [rsp+Ch] [rbp-4h]

    printf("Enter bug index: ");
    index = read_int();
    if ( index <= 5 )
        result = free_bug(index);
    else
        result = puts("Wrong idx.");
    return result;
}

int show_bug()
{
    unsigned int v1; // eax
    unsigned int v2; // [rsp+Ch] [rbp-4h]

    printf("Enter bug index: ");
    v2 = read_int();
    if ( v2 > 5 )
        return puts("Wrong idx.");
    if ( !*((int64_t *)bug_list + v2) )
        return puts("Wrong idx.");
    puts("-------------------------");
    printf("idx: %u\n", v2);
    printf("ID: ASV-%u-%u\n", **((unsigned __int16 **)bug_list + v2), *(unsigned int *)(*((int64_t *)bug_list + v2) + 4LL));
    printf("Severity: ");
    v1 = *(int *)(*((int64_t *)bug_list + v2) + 24LL);
    if ( v1 == 1 )
    {
        puts("Medium");
    }
    else if ( v1 < 1 )
    {
        puts("Low");
    }
    else if ( v1 == 2 )
    {
        puts("High");
    }
    else if ( v1 == 3 )
    {
        puts("Critical");
    }
    else
    {
        puts("Unknown");
    }
    printf("title: %s\n", *(int64_t *)(*((int64_t *)bug_list + v2) + 8LL));
    if ( *(int64_t *)(*((int64_t *)bug_list + v2) + 16LL) )
        printf("Description: %s\n", *(int64_t *)(*((int64_t *)bug_list + v2) + 16LL));
    return puts("-------------------------");
}

int main_loop()
{
    while ( 1 )
    {
        show_menu();
        switch ( (unsigned int)read_int() )
        {
        case 1u:
            create_bug();
            break;
        case 2u:
            edit_bug();
            break;
        case 3u:
            delete_bug();
            break;
        case 4u:
            show_bug();
            break;
        case 5u:
            return puts("Thank you for choosing ASV DB");
        default:
            puts("Unknown menu.");
            break;
        }
    }
}

int64_t main(int64_t a1, char **a2, char **a3)
{
    setup_bug_list();
    show_banner();
    main_loop();
    return 0LL;
}
