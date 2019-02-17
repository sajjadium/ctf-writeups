char *setup_mem()
{
    int fd; // [rsp+4h] [rbp-3Ch]
    char *addr; // [rsp+8h] [rbp-38h]
    int64_t v3; // [rsp+10h] [rbp-30h]
    uint64_t buf; // [rsp+20h] [rbp-20h]
    uint64_t v5; // [rsp+28h] [rbp-18h]
    uint64_t v6; // [rsp+38h] [rbp-8h]

    setvbuf(stdin, 0LL, 2, 0LL);
    alarm(0x3Cu);
    puts("===== Baby Heap in 2017 =====");
    fd = open("/dev/urandom", 0);
    if ( fd < 0 || read(fd, &buf, 0x10uLL) != 16 )
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
    puts("2. Fill");
    puts("3. Free");
    puts("4. Dump");
    puts("5. Exit");
    return printf("Command: ");
}

void allocate_data(int64_t mem)
{
    int i; // [rsp+10h] [rbp-10h]
    int size; // [rsp+14h] [rbp-Ch]
    void *data; // [rsp+18h] [rbp-8h]

    for ( i = 0; i <= 15; ++i )
    {
        if ( !*(int *)(24LL * i + mem) )
        {
            printf("Size: ");
            size = read_int();
            if ( size > 0 )
            {
                if ( size > 0x1000 )
                    size = 0x1000;
                data = calloc(size, 1uLL);
                if ( !data )
                    exit(-1);
                *(int *)(24LL * i + mem) = 1;
                *(int64_t *)(mem + 24LL * i + 8) = size;
                *(int64_t *)(mem + 24LL * i + 16) = data;
                printf("Allocate Index %d\n", (unsigned int)i);
            }
            return;
        }
    }
}

int64_t fill_data(int64_t mem)
{
    int64_t var; // rax
    int index; // [rsp+18h] [rbp-8h]
    int size; // [rsp+1Ch] [rbp-4h]

    printf("Index: ");
    var = read_int();
    index = var;
    if ( (signed int)var >= 0 && (signed int)var <= 15 )
    {
        var = *(unsigned int *)(24LL * (signed int)var + mem);
        if ( (int)var == 1 )
        {
            printf("Size: ");
            var = read_int();
            size = var;
            if ( (signed int)var > 0 )
            {
                printf("Content: ");
                var = read_bytes(*(int64_t *)(24LL * index + mem + 16), size);
            }
        }
    }
    return var;
}

int64_t free_data(int64_t mem)
{
    int64_t idx; // rax
    int index; // [rsp+1Ch] [rbp-4h]

    printf("Index: ");
    idx = read_int();
    index = idx;
    if ( (signed int)idx >= 0 && (signed int)idx <= 15 )
    {
        idx = *(unsigned int *)(24LL * (signed int)idx + mem);
        if ( (int)idx == 1 )
        {
            *(int *)(24LL * index + mem) = 0;
            *(int64_t *)(24LL * index + mem + 8) = 0LL;
            free(*(void **)(24LL * index + mem + 16));
            idx = 24LL * index + mem;
            *(int64_t *)(idx + 16) = 0LL;
        }
    }
    return idx;
}

signed int dump_data(int64_t mem)
{
    int index; // eax
    int _index; // [rsp+1Ch] [rbp-4h]

    printf("Index: ");
    index = read_int();
    _index = index;
    if ( index >= 0 && index <= 15 )
    {
        index = *(int *)(24LL * index + mem);
        if ( index == 1 )
        {
            puts("Content: ");
            write_bytes(*(int64_t *)(24LL * _index + mem + 16), *(int64_t *)(24LL * _index + mem + 8));
            index = puts(byte_14F1);
        }
    }
    return index;
}

int64_t main(int64_t a1, char **a2, char **a3)
{
    char *mem; // [rsp+8h] [rbp-8h]

    mem = setup_mem();
    while ( 1 )
    {
        print_menu();
        read_int();
        switch ( (uint64_t)off_14F4 )
        {
        case 1uLL:
            allocate_data((int64_t)mem);
            break;
        case 2uLL:
            fill_data((int64_t)mem);
            break;
        case 3uLL:
            free_data((int64_t)mem);
            break;
        case 4uLL:
            dump_data((int64_t)mem);
            break;
        case 5uLL:
            return 0LL;
        default:
            continue;
        }
    }
}

uint64_t read_bytes(int64_t a1, uint64_t a2)
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

uint64_t read_line(int64_t buffer, int64_t size)
{
    int64_t v3; // rax
    char buf; // [rsp+17h] [rbp-19h]
    uint64_t v5; // [rsp+18h] [rbp-18h]
    ssize_t v6; // [rsp+20h] [rbp-10h]
    uint64_t v7; // [rsp+28h] [rbp-8h]

    if ( !size )
        return 0LL;
    v5 = 0LL;
    while ( size - 1 > v5 )
    {
        v6 = read(0, &buf, 1uLL);
        if ( v6 > 0 )
        {
            if ( buf == '\n' )
                break;
            v3 = v5++;
            *(char *)(v3 + buffer) = buf;
        }
        else if ( *_errno_location() != '\v' && *_errno_location() != '\x04' )
        {
            break;
        }
    }
    *(char *)(buffer + v5) = 0;
    return v5;
}

uint64_t write_bytes(int64_t a1, uint64_t a2)
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

int64_t read_int()
{
    char nptr; // [rsp+0h] [rbp-10h]
    uint64_t v2; // [rsp+8h] [rbp-8h]

    read_line((int64_t)&nptr, 8LL);
    return atol(&nptr);
}
