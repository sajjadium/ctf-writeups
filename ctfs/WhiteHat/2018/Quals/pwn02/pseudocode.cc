void *best_selling_book;
int64_t book_list;

int initialize(int64_t a1)
{
    setvbuf(stdout, 0LL, 2, 0LL);
    setvbuf(stderr, 0LL, 2, 0LL);
    alarm(0x1F4u);
    printf("%s", a1);
    return puts("Designed by Quang Nguyen(quangnh89), a member of PiggyBird.\nMy blog: https://develbranch.com");
}

int64_t get_number(int64_t a1)
{
    unsigned int v2; // [rsp+14h] [rbp-Ch]
    uint64_t v3; // [rsp+18h] [rbp-8h]

    if ( a1 )
        printf("%s:", a1);
    _fpurge(stdin);
    if ( scanf("%d%*c", &v2) <= 0 )
    {
        puts("invalid number");
        exit(0);
    }
    return v2;
}

int64_t show_menu()
{
    puts("=====================");
    puts("== Book Store ==");
    puts("1. Add");
    puts("2. Edit");
    puts("3. Remove");
    puts("4. List");
    puts("5. Exit");
    return get_number((int64_t)"Your choice");
}

char *print_best_selling_book(int64_t a1)
{
    char s; // [rsp+10h] [rbp-410h]
    uint64_t v3; // [rsp+418h] [rbp-8h]

    sprintf(&s, "\x1B[33m%s\x1B[0m", a1);
    return strdup(&s);
}

char *print_best_selling_book_0(int64_t a1)
{
    char s; // [rsp+10h] [rbp-410h]
    uint64_t v3; // [rsp+418h] [rbp-8h]

    sprintf(&s, "\x1B[32m%s\x1B[0m", a1);
    return strdup(&s);
}

int64_t set_best_selling_book(int64_t new_book)
{
    int64_t result; // rax

    if ( best_selling_book )
    {
        --*((char *)best_selling_book + 49);
        *(int64_t *)((char *)best_selling_book + 50) = print_best_selling_book_0;
        if ( !*((char *)best_selling_book + 49) )
        {
            free(*((void **)best_selling_book + 1));
            free(best_selling_book);
        }
    }
    best_selling_book = (void *)new_book;
    ++*(char *)(new_book + 49);
    result = new_book;
    *(int64_t *)(new_book + 50) = print_best_selling_book;
    return result;
}

char *get_string(int64_t a1, unsigned int a2)
{
    char *result; // rax
    char v3; // [rsp+1Bh] [rbp-5h]
    unsigned int i; // [rsp+1Ch] [rbp-4h]

    _fpurge(stdin);
    for ( i = 0; i < a2; ++i )
    {
        v3 = fgetc(stdin);
        if ( v3 == -1 )
            exit(0);
        if ( v3 == 10 )
            break;
        *(char *)(a1 + i) = v3;
    }
    result = (char *)(i + a1);
    *result = 0;
    return result;
}

uint64_t add_book()
{
    int64_t v0; // rsi
    char v2; // [rsp+8h] [rbp-248h]
    int64_t brief_size; // [rsp+Ch] [rbp-244h]
    int64_t i; // [rsp+10h] [rbp-240h]
    int64_t book; // [rsp+18h] [rbp-238h]
    int64_t *j; // [rsp+20h] [rbp-230h]
    int64_t *new_book; // [rsp+28h] [rbp-228h]
    char s; // [rsp+30h] [rbp-220h]
    char temp; // [rsp+40h] [rbp-210h]
    uint64_t v10; // [rsp+248h] [rbp-8h]

    new_book = malloc(58uLL);
    if ( new_book )
    {
        *((char *)new_book + 48) = -1;
        *((char *)new_book + 49) = 1;
        printf("Title:");
        get_string((int64_t)&temp, 511u);
        for ( i = book_list; i; i = *(int64_t *)i )
        {
            if ( !strncmp(&temp, (const char *)(i + 16), 32uLL) )
            {
                puts("Item is duplicated.");
                free(new_book);
            }
        }
        strncpy((char *)new_book + 16, &temp, 31uLL);
        brief_size = (unsigned int)get_number((int64_t)"Enter brief size");
        if ( (signed int)brief_size <= 0 || (signed int)brief_size > 1024 )
            exit(0);
        new_book[1] = malloc((signed int)brief_size + 1);
        printf("Enter brief:", &temp);
        get_string(new_book[1], brief_size);
        printf("Reference book title:", (unsigned int)brief_size);
        v0 = 511LL;
        get_string((int64_t)&temp, 511u);
        if ( temp )
        {
            book = book_list;
            v2 = 0;
            while ( book )
            {
                v0 = book + 16;
                if ( !strncmp(&temp, (const char *)(book + 16), 32uLL) )
                {
                    *((char *)new_book + 48) = v2;
                    ++*(char *)(book + 49);
                    break;
                }
                ++v2;
                book = *(int64_t *)book;
            }
        }
        *new_book = 0LL;
        if ( book_list )
        {
            for ( j = (int64_t *)book_list; *j; j = (int64_t *)*j )
                ;
            *j = new_book;
        }
        else
        {
            book_list = (int64_t)new_book;
        }
        *(int64_t *)((char *)new_book + 50) = print_best_selling_book_0;
        printf("Best Selling? (Y/N)", v0);
        fgets(&s, 5, stdin);
        if ( s == 'Y' || s == 'y' )
            set_best_selling_book((int64_t)new_book);
        puts("a book is added.");
    }
}

uint64_t edit_book()
{
    int64_t v0; // rsi
    int brief_size; // [rsp+4h] [rbp-23Ch]
    int64_t book; // [rsp+8h] [rbp-238h]
    char s; // [rsp+10h] [rbp-230h]
    char temp; // [rsp+20h] [rbp-220h]
    uint64_t v6; // [rsp+228h] [rbp-18h]

    printf("Old title:");
    get_string((int64_t)&temp, 0x1FFu);
    for ( book = book_list; ; book = *(int64_t *)book )
    {
        if ( !book )
        {
            puts("Book not found.");
        }
        if ( !strncmp(&temp, (const char *)(book + 16), 32uLL) )
            break;
    }
    printf("New title:", book + 16);
    v0 = 32LL;
    get_string(book + 16, 0x20u);
    brief_size = get_number((int64_t)"Enter brief size");
    if ( brief_size < 0 || brief_size > 1024 )
        exit(0);
    if ( brief_size > 0 )
    {
        if ( brief_size > strlen(*(const char **)(book + 8)) )
        {
            free(*(void **)(book + 8));
            *(int64_t *)(book + 8) = malloc(brief_size);
        }
        printf("Enter brief:", 32LL);
        v0 = (unsigned int)brief_size;
        get_string(*(int64_t *)(book + 8), brief_size);
    }
    printf("Best Selling? (Y/N)", v0);
    fgets(&s, 5, stdin);
    if ( s == 'Y' || s == 'y' )
        set_best_selling_book(book);
    puts("Entry is edited.");
}

void delete_book(void **a1)
{
    void **v1; // [rsp+10h] [rbp-10h]
    void **ptr; // [rsp+18h] [rbp-8h]

    v1 = 0LL;
    for ( ptr = (void **)book_list; ptr; ptr = (void **)*ptr )
    {
        if ( ptr == a1 )
        {
            if ( !-- * ((char *)ptr + 49) )
            {
                if ( v1 )
                    *v1 = *ptr;
                else
                    book_list = *(int64_t *)book_list;
                free(ptr[1]);
                free(ptr);
            }
            return;
        }
        v1 = ptr;
    }
}

uint64_t remove_book()
{
    int v1; // [rsp+4h] [rbp-22Ch]
    void **v2; // [rsp+8h] [rbp-228h]
    char *i; // [rsp+10h] [rbp-220h]
    void **v4; // [rsp+18h] [rbp-218h]
    char temp; // [rsp+20h] [rbp-210h]
    uint64_t v6; // [rsp+228h] [rbp-8h]

    v2 = 0LL;
    printf("Title:");
    get_string((int64_t)&temp, 0x1FFu);
    for ( i = (char *)book_list; ; i = *(char **)i )
    {
        if ( !i )
        {
            puts("Book not found.");
        }
        if ( !strncmp(&temp, i + 16, 32uLL) )
            break;
    }
    v4 = (void **)book_list;
    v1 = 0;
    while ( v4 )
    {
        if ( (unsigned __int8)i[48] == v1 )
        {
            v2 = v4;
            break;
        }
        ++v1;
        v4 = (void **)*v4;
    }
    delete_book((void **)i);
    delete_book(v2);
    puts("Entry is removed.");
}

int list_book()
{
    void *ptr; // ST10_8
    int result; // eax
    void *v2; // ST18_8
    int v3; // [rsp+4h] [rbp-1Ch]
    int64_t i; // [rsp+8h] [rbp-18h]

    v3 = 0;
    puts("|----+-------------------------------+-----------------------------------------|");
    printf("|%4s|%32s|%-40s\n", "ID", "Title", "Brief");
    puts("|----+-------------------------------+-----------------------------------------|");
    for ( i = book_list; i; i = *(int64_t *)i )
    {
        ptr = (void *)(*(int64_t (* *)(int64_t))(i + 50))(*(int64_t *)(i + 8));
        printf("|%04d|%32s|%s", (unsigned int)++v3, i + 16, ptr);
        puts(&byte_401977);
        free(ptr);
    }
    puts("|----+-------------------------------+-----------------------------------------|");
    result = (signed int)best_selling_book;
    if ( best_selling_book )
    {
        puts("|                The best selling book today                                   |");
        puts("|----+-------------------------------+-----------------------------------------|");
        v2 = (void *)(*(int64_t (* *)(int64_t))((char *)best_selling_book + 50))(*((int64_t *)best_selling_book + 1));
        printf("|%04d|%32s|%s", (unsigned int)(v3 + 1), (char *)best_selling_book + 16, v2);
        puts(&byte_401977);
        free(v2);
        result = puts("|----+-------------------------------+-----------------------------------------|");
    }
    return result;
}

signed int64_t main(int64_t a1, char **a2, char **a3)
{
    initialize((int64_t)banner_string);
    while ( 1 )
    {
        switch ( (unsigned int)show_menu() )
        {
        case 1u:
            add_book();
            break;
        case 2u:
            edit_book();
            break;
        case 3u:
            remove_book();
            break;
        case 4u:
            list_book();
            break;
        case 5u:
            return 42LL;
        default:
            continue;
        }
    }
}
