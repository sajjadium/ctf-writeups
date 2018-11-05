char *initialize()
{
    int fd; // [rsp+4h] [rbp-3Ch]
    char *addr; // [rsp+8h] [rbp-38h]
    int64_t v3; // [rsp+10h] [rbp-30h]
    uint64_t buf; // [rsp+20h] [rbp-20h]
    uint64_t v5; // [rsp+28h] [rbp-18h]
    uint64_t v6; // [rsp+38h] [rbp-8h]

    setvbuf(stdin, 0LL, 2, 0LL);
    alarm(0x3Cu);
    puts(
        "    __ __ _____________   __   __    ___    ____\n"
        "   / //_// ____/ ____/ | / /  / /   /   |  / __ )\n"
        "  / ,<  / __/ / __/ /  |/ /  / /   / /| | / __  |\n"
        " / /| |/ /___/ /___/ /|  /  / /___/ ___ |/ /_/ /\n"
        "/_/ |_/_____/_____/_/ |_/  /_____/_/  |_/_____/\n");
    puts("===== Baby Heap in 2018 =====");
    fd = open("/dev/urandom", 0);
    if ( fd < 0 || read(fd, &buf, 16uLL) != 16 )
        exit(-1);
    close(fd);
    addr = (char *)((buf
                     - 0x555555543000LL * ((uint64_t)(0xC000000294000009LL * (unsigned __int128)buf >> 64) >> 46)
                     + 0x10000) & 0xFFFFFFFFFFFFF000LL);
    v3 = (v5 - 3712 * (0x8D3DCB08D3DCB0DLL * (unsigned __int128)(v5 >> 7) >> 64)) & 0xFFFFFFFFFFFFFFF0LL;
    if ( mmap(addr, 0x1000uLL, 3, 34, -1, 0LL) != addr )
        exit(-1);
    return &addr[v3];
}

int print_menu()
{
    puts("1. Allocate");
    puts("2. Update");
    puts("3. Delete");
    puts("4. View");
    puts("5. Exit");
    return printf("Command: ");
}

void allocate(int64_t a1)
{
    int i; // [rsp+10h] [rbp-10h]
    int size; // [rsp+14h] [rbp-Ch]
    void *v3; // [rsp+18h] [rbp-8h]

    for ( i = 0; i <= 15; ++i )
    {
        if ( !*(int *)(24LL * i + a1) )
        {
            printf("Size: ");
            size = read_number();
            if ( size > 0 )
            {
                if ( size > 88 )
                    size = 88;
                v3 = calloc(size, 1uLL);
                if ( !v3 )
                    exit(-1);
                *(int *)(24LL * i + a1) = 1;
                *(int64_t *)(a1 + 24LL * i + 8) = size;
                *(int64_t *)(a1 + 24LL * i + 16) = v3;
                printf("Chunk %d Allocated\n", (unsigned int)i);
            }
            return;
        }
    }
}

int update(int64_t table)
{
    uint64_t old_size; // rax
    int index; // [rsp+18h] [rbp-8h]
    int new_size; // [rsp+1Ch] [rbp-4h]

    printf("Index: ");
    index = read_number();
    if ( index >= 0 && index <= 15 && *(int *)(24LL * index + table) == 1 )
    {
        printf("Size: ");
        LODWORD(old_size) = read_number();
        new_size = old_size;
        if ( (signed int)old_size > 0 )
        {
            old_size = *(int64_t *)(24LL * index + table + 8) + 1LL;
            if ( new_size <= old_size )
            {
                printf("Content: ");
                read_string2(*(int64_t *)(24LL * index + table + 16), new_size);
                LODWORD(old_size) = printf("Chunk %d Updated\n", (unsigned int)index);
            }
        }
    }
    else
    {
        LODWORD(old_size) = puts("Invalid Index");
    }
    return old_size;
}

int delete_(int64_t table)
{
    int index; // [rsp+1Ch] [rbp-4h]

    printf("Index: ");
    index = read_number();
    if ( index < 0 || index > 15 || *(int *)(24LL * index + table) != 1 )
        return puts("Invalid Index");
    *(int *)(24LL * index + table) = 0;
    *(int64_t *)(24LL * index + table + 8) = 0LL;
    free(*(void **)(24LL * index + table + 16));
    *(int64_t *)(24LL * index + table + 16) = 0LL;
    return printf("Chunk %d Deleted\n", (unsigned int)index);
}

int view(int64_t a1)
{
    int index; // [rsp+1Ch] [rbp-4h]

    printf("Index: ");
    index = read_number();
    if ( index < 0 || index > 15 || *(int *)(24LL * index + a1) != 1 )
        return puts("Invalid Index");
    printf("Chunk[%d]: ", (unsigned int)index);
    write_string(*(int64_t *)(24LL * index + a1 + 16), *(int64_t *)(24LL * index + a1 + 8));
    return 0;
}

int64_t main(int64_t a1, char **a2, char **a3)
{
    char *table; // [rsp+8h] [rbp-8h]

    table = initialize();
    while ( 1 )
    {
        print_menu();
        switch (read_number())
        {
        case 1uLL:
            allocate((int64_t)table);
            break;
        case 2uLL:
            update((int64_t)table);
            break;
        case 3uLL:
            delete_((int64_t)table);
            break;
        case 4uLL:
            view((int64_t)table);
            break;
        case 5uLL:
            return 0LL;
        default:
            continue;
        }
    }
}

uint64_t read_string2(int64_t a1, uint64_t a2)
{
    uint64_t v3; // [rsp+10h] [rbp-10h]
    ssize_t v4; // [rsp+18h] [rbp-8h]

    if ( !a2 )
        return 0LL;
    v3 = 0LL;
    while ( v3 < a2 )
    {
        v4 = read(0, (void *)(v3 + a1), a2 - v3);
        if ( v4 > 0 )
        {
            v3 += v4;
        }
        else if ( *_errno_location() != 11 && *_errno_location() != 4 )
        {
            return v3;
        }
    }
    return v3;
}

uint64_t read_string(int64_t a1, int64_t a2)
{
    int64_t v3; // rax
    char buf; // [rsp+17h] [rbp-19h]
    uint64_t v5; // [rsp+18h] [rbp-18h]
    ssize_t v6; // [rsp+20h] [rbp-10h]
    uint64_t v7; // [rsp+28h] [rbp-8h]

    if ( !a2 )
        return 0LL;
    v5 = 0LL;
    while ( a2 - 1 > v5 )
    {
        v6 = read(0, &buf, 1uLL);
        if ( v6 > 0 )
        {
            if ( buf == 10 )
                break;
            v3 = v5++;
            *(char *)(v3 + a1) = buf;
        }
        else if ( *_errno_location() != 11 && *_errno_location() != 4 )
        {
            break;
        }
    }
    *(char *)(a1 + v5) = 0;
    return v5;
}

uint64_t write_string(int64_t a1, uint64_t a2)
{
    uint64_t v3; // [rsp+10h] [rbp-10h]
    ssize_t v4; // [rsp+18h] [rbp-8h]

    v3 = 0LL;
    while ( v3 < a2 )
    {
        v4 = write(1, (const void *)(v3 + a1), a2 - v3);
        if ( v4 > 0 )
        {
            v3 += v4;
        }
        else if ( *_errno_location() != 11 && *_errno_location() != 4 )
        {
            return v3;
        }
    }
    return v3;
}

int64_t read_number()
{
    char nptr; // [rsp+0h] [rbp-10h]
    uint64_t v2; // [rsp+8h] [rbp-8h]

    read_string((int64_t)&nptr, 8LL);
    return atol(&nptr);
}
