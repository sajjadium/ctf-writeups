const char *heap[10];

int Init()
{
    setvbuf(stdin, 0LL, 2, 0LL);
    setvbuf(stdout, 0LL, 2, 0LL);
    return setvbuf(stderr, 0LL, 2, 0LL);
}

ssize_t myputs(const char *a1)
{
    size_t v1; // rax

    v1 = strlen(a1);
    return write(1, a1, v1);
}

ssize_t del(unsigned int a1)
{
    ssize_t result; // rax

    if ( a1 <= 9 )
    {
        free((void *)heap[a1]);
        result = myputs("Done!\n");
    }
    return result;
}

void alloc(unsigned int a1)
{
    if ( a1 <= 9 )
    {
        heap[a1] = (const char *)malloc(80uLL);
        myputs("Content:");
        read(0, (void *)heap[a1], 80uLL);
        myputs("Done!\n");
    }
}

const char *show(unsigned int a1)
{
    const char *result; // rax

    if ( a1 <= 9 )
    {
        result = heap[a1];
        if ( result )
        {
            myputs(heap[a1]);
            result = (const char *)myputs("Done!\n");
        }
    }
    return result;
}

ssize_t menu(int64_t a1, int64_t a2)
{
    myputs("1.alloc\n");
    myputs("2.show\n");
    myputs("3.free\n");
    myputs("4.exit\n");
    return myputs("Your choice:");
}

int main()
{
    char *v3; // rsi
    const char *v4; // rdi
    int v6; // [rsp+8h] [rbp-28h]
    unsigned int v7; // [rsp+Ch] [rbp-24h]
    char s; // [rsp+10h] [rbp-20h]
    uint64_t v9; // [rsp+28h] [rbp-8h]

    Init();
    v3 = 0LL;
    v4 = &s;
    memset(&s, 0, 16uLL);
    while ( 1 )
    {
        menu((int64_t)v4, (int64_t)v3);
        read(0, &s, 15uLL);
        v6 = atoi(&s);
        if ( v6 == 4 )
            break;
        myputs("Index:");
        v3 = &s;
        read(0, &s, 15uLL);
        v7 = atoi(&s);
        switch ( v6 )
        {
        case 2:
            v4 = (const char *)v7;
            show(v7);
            break;
        case 3:
            v4 = (const char *)v7;
            del(v7);
            break;
        case 1:
            v4 = (const char *)v7;
            alloc(v7);
            break;
        default:
            v4 = "Invalid option!\n";
            myputs("Invalid option!\n");
            break;
        }
    }
    return 0;
}
