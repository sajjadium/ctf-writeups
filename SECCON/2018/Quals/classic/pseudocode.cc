int64_t init()
{
    setbuf(stdout, 0LL);
    setbuf(stderr, 0LL);
    return 0LL;
}

int main()
{
    char buf; // [rsp+0h] [rbp-40h]

    puts("Classic Pwnable Challenge");
    printf("Local Buffer >> ", argv);
    gets((int64_t)&buf);
    puts("Have a nice pwn!!");
    return 0;
}

