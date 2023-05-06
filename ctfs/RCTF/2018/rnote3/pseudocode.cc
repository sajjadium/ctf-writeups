int64_t notes_list[33];

void show_error(int64_t a1)
{
    fprintf(stderr, "[x]%s\n", a1);
    exit(-1);
}

uint64_t read_string(int64_t a1, unsigned int a2)
{
    char buf; // [rsp+13h] [rbp-Dh]
    unsigned int i; // [rsp+14h] [rbp-Ch]
    uint64_t v5; // [rsp+18h] [rbp-8h]

    for ( i = 0; i < a2; ++i )
    {
        buf = 0;
        if ( read(0, &buf, 1uLL) < 0 )
            show_error((int64_t)"read() error");
        if ( buf == 10 )
            *(char *)(i + a1) = 0;
        else
            *(char *)(a1 + i) = buf;
        if ( buf == 10 )
            break;
    }
    *(char *)(a2 - 1 + a1) = 0;
}

int read_int()
{
    char nptr; // [rsp+0h] [rbp-20h]
    uint64_t v2; // [rsp+18h] [rbp-8h]

    read_string((int64_t)&nptr, 0x10u);
    return atoi(&nptr);
}

uint64_t add_note(int64_t a1, int64_t a2)
{
    int i; // [rsp+0h] [rbp-20h]
    int v4; // [rsp+4h] [rbp-1Ch]
    char *dest; // [rsp+8h] [rbp-18h]
    char src; // [rsp+10h] [rbp-10h]
    uint64_t v7; // [rsp+18h] [rbp-8h]

    if ( notes_count > 32 )
        show_error((int64_t)"too many note");
    dest = (char *)malloc(24uLL);
    if ( !dest )
        show_error((int64_t)"memory error");
    printf("please input title: ", a2);
    read_string((int64_t)&src, 8u);
    strncpy(dest, &src, 8uLL);
    printf("please input content size: ", &src);
    v4 = read_int();
    if ( v4 <= 0 || v4 > 256 )
        show_error((int64_t)"invalid size");
    *((int64_t *)dest + 2) = malloc(v4);
    if ( !*((int64_t *)dest + 2) )
        show_error((int64_t)"memory error");
    printf("please input content: ");
    read_string(*((int64_t *)dest + 2), v4);
    *((int64_t *)dest + 1) = v4;
    for ( i = 0; i <= 31 && notes_list[i]; ++i )
        ;
    notes_list[i] = dest;
    ++notes_count;
}

uint64_t view_note()
{
    int i; // [rsp+4h] [rbp-1Ch]
    int64_t v2; // [rsp+8h] [rbp-18h]
    char s1; // [rsp+10h] [rbp-10h]
    uint64_t v4; // [rsp+18h] [rbp-8h]

    v2 = 0LL;
    printf("please input note title: ");
    read_string((int64_t)&s1, 8u);
    for ( i = 0; i <= 31; ++i )
    {
        if ( notes_list[i] && !strncmp(&s1, (const char *)notes_list[i], 8uLL) )
        {
            v2 = notes_list[i];
            break;
        }
    }
    if ( v2 )
        printf("note title: %s\nnote content: %s\n", v2, *(int64_t *)(v2 + 16));
    else
        puts("not a valid title");
}

uint64_t delete_note()
{
    int i; // [rsp+4h] [rbp-1Ch]
    void **ptr; // [rsp+8h] [rbp-18h]
    char s1; // [rsp+10h] [rbp-10h]
    uint64_t v4; // [rsp+18h] [rbp-8h]

    printf("please input note title: ");
    read_string((int64_t)&s1, 8u);
    for ( i = 0; i <= 31; ++i )
    {
        if ( notes_list[i] && !strncmp(&s1, (const char *)notes_list[i], 8uLL) )
        {
            ptr = (void **)notes_list[i];
            break;
        }
    }
    if ( ptr )
    {
        free(ptr[2]);
        free(ptr);
        notes_list[i] = 0LL;
    }
    else
    {
        puts("not a valid title");
    }
}

uint64_t edit_note()
{
    int i; // [rsp+4h] [rbp-1Ch]
    int64_t v2; // [rsp+8h] [rbp-18h]
    char s1; // [rsp+10h] [rbp-10h]
    uint64_t v4; // [rsp+18h] [rbp-8h]

    v2 = 0LL;
    printf("please input note title: ");
    read_string((int64_t)&s1, 32u);
    for ( i = 0; i <= 31; ++i )
    {
        if ( notes_list[i] && !strncmp(&s1, (const char *)notes_list[i], 8uLL) )
        {
            v2 = notes_list[i];
            break;
        }
    }
    if ( v2 )
    {
        printf("please input new content: ");
        read_string(*(int64_t *)(v2 + 16), *(int64_t *)(v2 + 8));
    }
    else
    {
        puts("not a valid title");
    }
}

int show_menu()
{
    puts("welcome to the new RNote service");
    puts("1. Add new note");
    puts("2. View a note");
    puts("3. Edit a note");
    puts("4. Delete a note");
    return puts("5. Exit");
}

int initialize()
{
    memset(notes_list, 0, 256uLL);
    notes_count = 0;
    setvbuf(stdin, 0LL, 2, 0LL);
    setvbuf(stdout, 0LL, 2, 0LL);
    return setvbuf(stderr, 0LL, 2, 0LL);
}

void main(int64_t a1, char **a2, char **a3)
{
    unsigned int v3; // eax
    char v4; // [rsp+1Fh] [rbp-1h]

    initialize();
    if ( (signed int)a1 > 1 )
    {
        v3 = atoi(a2[1]);
        a1 = v3;
        alarm(v3);
    }
    show_menu();
    while ( 1 )
    {
        while ( 1 )
        {
            v4 = read_int();
            if ( v4 != 1 )
                break;
            add_note(a1, (int64_t)a2);
        }
        if ( v4 == 2 )
        {
            view_note();
        }
        else if ( v4 == 3 )
        {
            edit_note();
        }
        else if ( v4 == 4 )
        {
            delete_note();
        }
        else
        {
            if ( v4 == 5 )
                exit(0);
            a1 = (int64_t)"invalid choice!";
            puts("invalid choice!");
        }
    }
}
