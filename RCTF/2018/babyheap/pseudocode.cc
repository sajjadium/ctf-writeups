void fail(int64_t a1)
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
            fail((int64_t)"read() error");
        *(char *)(a1 + i) = buf;
        if ( buf == 10 )
            break;
    }
    *(char *)(i + a1) = 0;
}

int read_int()
{
    char s; // [rsp+0h] [rbp-30h]
    uint64_t v2; // [rsp+28h] [rbp-8h]

    memset(&s, 0, 0x20uLL);
    read(0, &s, 0x20uLL);
    return atoi(&s);
}

void *alloc()
{
    void *result; // rax
    uint64_t i; // [rsp+8h] [rbp-18h]
    int64_t chunk_size; // [rsp+10h] [rbp-10h]
    void *chunk_ptr; // [rsp+18h] [rbp-8h]

    if ( num_of_chunks > 32u )
        fail((int64_t)"too many chunk");
    printf("please input chunk size: ");
    chunk_size = read_int();
    if ( chunk_size <= 0 || chunk_size > 256 )
        fail((int64_t)"invalid size");
    chunk_ptr = calloc(chunk_size, 1uLL);
    if ( !chunk_ptr )
        fail((int64_t)"memory error");
    printf("input chunk content: ", 1LL);
    read_string((int64_t)chunk_ptr, chunk_size);
    for ( i = 0LL; i <= 31 && *(int64_t *)(8 * i + chunk_list); ++i )
        ;
    if ( i == 32 )
        fail((int64_t)"too many chunk");
    *(int64_t *)(chunk_list + 8 * i) = chunk_ptr;
    result = &num_of_chunks;
    ++num_of_chunks;
    return result;
}

int show()
{
    int result; // eax
    int chunk_index; // [rsp+4h] [rbp-Ch]
    int64_t chunk_ptr; // [rsp+8h] [rbp-8h]

    printf("please input chunk index: ");
    chunk_index = read_int();
    if ( chunk_index < 0 || chunk_index > 31 )
        fail((int64_t)"invalid index");
    chunk_ptr = *(int64_t *)(8LL * chunk_index + chunk_list);
    if ( chunk_ptr )
        result = printf("content: %s\n", chunk_ptr);
    else
        result = puts("no such a chunk");
    return result;
}

int64_t *delete()
{
    int64_t v0; // rdx
    int64_t *result; // rax
    int chunk_index; // [rsp+4h] [rbp-Ch]
    void *chunk_ptr; // [rsp+8h] [rbp-8h]

    printf("please input chunk index: ");
    chunk_index = read_int();
    if ( chunk_index < 0 || chunk_index > 31 )
        fail((int64_t)"invalid index");
    v0 = 8LL * chunk_index;
    result = *(int64_t **)(v0 + chunk_list);
    chunk_ptr = *(void **)(v0 + chunk_list);
    if ( chunk_ptr )
    {
        --num_of_chunks;
        free(chunk_ptr);
        result = (int64_t *)(8LL * chunk_index + chunk_list);
        *result = 0LL;
    }
    return result;
}

uint64_t initialize()
{
    unsigned __int16 buf; // [rsp+2h] [rbp-1Eh]
    int fd; // [rsp+4h] [rbp-1Ch]
    void *addr; // [rsp+8h] [rbp-18h]
    void *v4; // [rsp+10h] [rbp-10h]
    uint64_t v5; // [rsp+18h] [rbp-8h]

    num_of_chunks = 0;
    setvbuf(stdin, 0LL, 2, 0LL);
    setvbuf(stdout, 0LL, 2, 0LL);
    setvbuf(stderr, 0LL, 2, 0LL);
    fd = open("/dev/urandom", 0);
    if ( fd < 0 )
        fail((int64_t)"open device error");
    buf = 0;
    if ( read(fd, &buf, 2uLL) < 0 )
        fail((int64_t)"read() error");
    v4 = calloc(buf, 1uLL);
    if ( !v4 )
        fail((int64_t)"memory error");
    addr = 0LL;
    read(fd, &addr, 6uLL);
    addr = (void *)((uint64_t)addr & 0xFFFFFFFFFFF000LL);
    chunk_list = mmap(addr, 0x1000uLL, 3, 34, -1, 0LL);
    if ( !chunk_list )
        fail((int64_t)"memory error");
    close(fd);
}

int menu()
{
    puts("1. Alloc");
    puts("2. Show");
    puts("3. Delete");
    puts("4. Exit");
    return printf("choice: ");
}

void main(const char *a1, char **a2, char **a3)
{
    int v3; // eax
    int v4; // [rsp+1Ch] [rbp-4h]

    initialize();
    if ( (signed int)a1 > 1 )
    {
        v3 = atoi(a2[1]);
        alarm(v3);
    }
    while ( 1 )
    {
        while ( 1 )
        {
            menu();
            v4 = read_int();
            if ( v4 != 1 )
                break;
            alloc();
        }
        if ( v4 == 2 )
        {
            show();
        }
        else if ( v4 == 3 )
        {
            delete();
        }
        else
        {
            if ( v4 == 4 )
                exit(0);
            puts("wrong choice");
        }
    }
}
