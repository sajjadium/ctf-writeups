int64_t get_number()
{
    char s; // [rsp+0h] [rbp-10h]
    uint64_t v2; // [rsp+8h] [rbp-8h]

    fgets(&s, 8, stdin);
    return atol(&s);
}

signed int64_t get_string(int fd, int64_t buffer, uint64_t size)
{
    uint64_t size_; // [rsp+8h] [rbp-28h]
    uint64_t v5; // [rsp+20h] [rbp-10h]
    ssize_t v6; // [rsp+28h] [rbp-8h]

    size_ = size;
    v5 = 0LL;
    while ( v5 < size_ )
    {
        v6 = read(fd, (void *)(v5 + buffer), size_ - v5);
        if ( v6 == -1 )
        {
            if ( *_errno_location() != 11 && *_errno_location() != 4 )
                return -1LL;
        }
        else
        {
            if ( !v6 )
                return v5;
            v5 += v6;
        }
    }
    return v5;
}

void *start_routine(void *a1)
{
    uint64_t size; // [rsp+8h] [rbp-1018h]
    char buffer; // [rsp+10h] [rbp-1010h]
    uint64_t v4; // [rsp+1018h] [rbp-8h]

    memset(&buffer, 0, 0x1000uLL);
    puts("Welcome to babystack 2018!");
    puts("How many bytes do you want to send?");
    size = get_number();
    if ( size <= 0x10000 )
    {
        get_string(0, (int64_t)&buffer, size);
        puts("It's time to say goodbye.");
    }
    else
    {
        puts("You are greedy!");
    }
    return 0LL;
}

signed int64_t main(int64_t a1, char **a2, char **a3)
{
    int64_t result; // rax
    pthread_t newthread; // [rsp+0h] [rbp-10h]
    uint64_t v5; // [rsp+8h] [rbp-8h]

    setbuf(stdin, 0LL);
    setbuf(stdout, 0LL);
    puts(" #   #    ####    #####  ######");
    puts("  # #    #    #     #    #");
    puts("### ###  #          #    #####");
    puts("  # #    #          #    #");
    puts(" #   #   #    #     #    #");
    puts("          ####      #    #");
    pthread_create(&newthread, 0LL, (void *(*)(void *))start_routine, 0LL);
    if ( pthread_join(newthread, 0LL) )
    {
        puts("exit failure");
        result = 1LL;
    }
    else
    {
        puts("Bye bye");
        result = 0LL;
    }
    return result;
}
