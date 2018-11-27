char strings_modification_count[32];
int strings_sizes[32];

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
        *(char *)(a1 + i) = buf;
        if ( buf == 10 )
            break;
    }
    *(char *)(a2 - 1 + a1) = 0;
}

int64_t read_number()
{
    int64_t result; // rax
    int v1; // [rsp+Ch] [rbp-24h]
    char s; // [rsp+10h] [rbp-20h]
    uint64_t v3; // [rsp+28h] [rbp-8h]

    memset(&s, 0, 0x10uLL);
    read_string((int64_t)&s, 0x10u);
    v1 = atoi(&s);
    if ( v1 >= 0 )
        result = (unsigned int)v1;
    else
        result = 0LL;
    return result;
}

int *add_string()
{
    unsigned int len; // eax
    int *result; // rax
    int64_t i; // [rsp+8h] [rbp-18h]
    unsigned int size; // [rsp+10h] [rbp-10h]
    void *string_ptr; // [rsp+18h] [rbp-8h]

    if ( strings_count > 32u )
        show_error((int64_t)"too many string");
    printf("please input string length: ");
    len = read_number();
    size = len;
    if ( !len || len > 256uLL )
        show_error((int64_t)"invalid size");
    string_ptr = calloc(len, 1uLL);
    if ( !string_ptr )
        show_error((int64_t)"memory error");
    printf("please input the string content: ", 1LL);
    read_string((int64_t)string_ptr, size);
    for ( i = 0LL; i <= 31 && *(int64_t *)(8 * i + strings_list); ++i )
        ;
    if ( i > 31 )
        show_error((int64_t)"too many string");
    *(int64_t *)(strings_list + 8 * i) = string_ptr;
    printf("your string: %s\n", string_ptr);
    ++strings_count;
    result = strings_sizes;
    strings_sizes[i] = size;
    return result;
}

int show_string()
{
    return puts("don't even think about it");
}

unsigned int edit_string()
{
    unsigned int result; // eax
    unsigned int index; // [rsp+Ch] [rbp-14h]
    unsigned int size; // [rsp+10h] [rbp-10h]
    unsigned int byte_index; // [rsp+14h] [rbp-Ch]
    int64_t ptr; // [rsp+18h] [rbp-8h]

    printf("please input the index: ");
    index = read_number();
    if ( index > 31 )
        show_error((int64_t)"not a validate index");
    ptr = *(int64_t *)(8LL * index + strings_list);
    if ( !ptr )
        show_error((int64_t)"not a validate index");
    size = strings_sizes[index];
    if ( strings_modification_count[index] > 4u )
        return puts("nope!");
    printf("input the byte index: ");
    byte_index = read_number();
    if ( byte_index > size )
        return puts("nope!");
    ++*(char *)(byte_index + ptr);
    result = index;
    ++strings_modification_count[index];
    return result;
}

void delete_string()
{
    unsigned int index; // [rsp+4h] [rbp-Ch]
    void *string_ptr; // [rsp+8h] [rbp-8h]

    printf("please input the index: ");
    index = read_number();
    if ( index > 31 )
        show_error((int64_t)"not a validate index");
    string_ptr = *(void **)(8LL * index + strings_list);
    if ( !string_ptr )
        show_error((int64_t)"not a validate index");
    free(string_ptr);
}

int show_menu()
{
    puts("1. New string");
    puts("2. Show string");
    puts("3. Edit string");
    puts("4. Delete string");
    puts("5. Exit");
    return printf("choice: ");
}

uint64_t initialize()
{
    unsigned __int16 buf; // [rsp+2h] [rbp-1Eh]
    int fd; // [rsp+4h] [rbp-1Ch]
    void *addr; // [rsp+8h] [rbp-18h]
    void *v4; // [rsp+10h] [rbp-10h]
    uint64_t v5; // [rsp+18h] [rbp-8h]

    strings_count = 0;
    memset(strings_sizes, 0, 128uLL);
    memset(strings_modification_count, 0, 32uLL);
    setvbuf(stdin, 0LL, 2, 0LL);
    setvbuf(stdout, 0LL, 2, 0LL);
    setvbuf(stderr, 0LL, 2, 0LL);
    fd = open("/dev/urandom", 0);
    if ( fd < 0 )
        show_error((int64_t)"open device error");
    buf = 0;
    if ( read(fd, &buf, 2uLL) < 0 )
        show_error((int64_t)"read() error");
    v4 = calloc(buf, 1uLL);
    if ( !v4 )
        show_error((int64_t)"memory error");
    addr = 0LL;
    read(fd, &addr, 6uLL);
    addr = (void *)((uint64_t)addr & 0xFFFFFFFFF000LL);
    strings_list = mmap(addr, 0x1000uLL, 3, 34, -1, 0LL);
    if ( !strings_list )
        show_error((int64_t)"memory error");
    close(fd);
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
            show_menu();
            v4 = read_number();
            if ( v4 != 1 )
                break;
            add_string();
        }
        if ( v4 == 2 )
        {
            show_string();
        }
        else if ( v4 == 3 )
        {
            edit_string();
        }
        else if ( v4 == 4 )
        {
            delete_string();
        }
        else
        {
            if ( v4 == 5 )
                exit(0);
            puts("wrong choice");
        }
    }
}
