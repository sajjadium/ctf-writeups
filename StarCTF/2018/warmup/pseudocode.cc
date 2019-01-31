int64_t mem;

int print_banner()
{
    puts(s);
    puts(" #   #    ####    #####  ######");
    puts("  # #    #    #     #    #");
    puts("### ###  #          #    #####");
    puts("  # #    #          #    #");
    puts(" #   #   #    #     #    #");
    puts("          ####      #    #");
    puts(s);
    return puts("Let's warmup now!");
}

ssize_t print_string(int a1, const char *a2)
{
    size_t v2; // rax

    v2 = strlen(a2);
    return write(a1, a2, v2);
}

int64_t main(int64_t a1, char **a2, char **a3)
{
    int64_t result; // rax
    char s; // [rsp+0h] [rbp-20h]
    int64_t *v5; // [rsp+8h] [rbp-18h]
    int v6; // [rsp+14h] [rbp-Ch]
    int64_t v7; // [rsp+18h] [rbp-8h]

    setbuf(stdin, 0LL);
    setbuf(stdout, 0LL);
    print_banner();
    mem = (int64_t)malloc(8uLL);
    v7 = mem;
    memset(&s, 0, 8uLL);
    puts("What are you looking for?");
    _isoc99_scanf("%zu", &v5);
    printf("%#zx\n", *v5);
    puts("What's your name?");
    _isoc99_scanf("%s", &s);
    if ( v7 == mem )
    {
        puts("Bye bye.");
        result = 0LL;
    }
    else
    {
        v6 = open("/dev/tty", 2);
        if ( v6 != -1 )
        {
            print_string(v6, "[INFO] A hacker is coming!\n");
            print_string(v6, "[INFO] Exiting...\n");
            exit(1);
        }
        puts("Something is broken!");
        result = 0LL;
    }
    return result;
}
