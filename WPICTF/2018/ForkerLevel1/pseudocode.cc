int check_password(int a1)
{
    int v1; // eax
    char buf; // [rsp+1Fh] [rbp-51h]
    char s1[76]; // [rsp+20h] [rbp-50h]
    int v5; // [rsp+6Ch] [rbp-4h]

    dprintf(a1, "Please enter the correct password to get my secret ltc info\nPassword:");
    buf = 0;
    v5 = 0;
    while ( read(a1, &buf, 1uLL) && buf != 10 )
    {
        v1 = v5++;
        s1[v1] = buf;
    }
    return strncmp(s1, "INTERNET_FUNNY_MUNNY", 64uLL) == 0;
}

int main()
{
    int optval; // [rsp+Ch] [rbp-34h]
    struct sockaddr v4; // [rsp+10h] [rbp-30h]
    struct sockaddr addr; // [rsp+20h] [rbp-20h]
    socklen_t addr_len; // [rsp+30h] [rbp-10h]
    int v7; // [rsp+34h] [rbp-Ch]
    socklen_t len; // [rsp+38h] [rbp-8h]
    int fd; // [rsp+3Ch] [rbp-4h]

    fd = socket(2, 1, 0);
    addr.sa_family = 2;
    *(int *)&addr.sa_data[2] = htonl(0);
    *(_WORD *)addr.sa_data = htons(31337u);
    len = 16;
    optval = 1;
    if ( setsockopt(fd, 1, 2, &optval, 4u) < 0 )
    {
        puts("Unable to set reusable?");
        exit(1);
    }
    if ( bind(fd, &addr, len) )
    {
        puts("Unable to bind");
        exit(1);
    }
    if ( listen(fd, 5) )
    {
        puts("Unable to listen");
        exit(2);
    }
    signal(17, 1);
    while ( 1 )
    {
        puts("server waiting");
        addr_len = 16;
        v7 = accept(fd, &v4, &addr_len);
        puts("accepted client");
        if ( !fork() )
            break;
        close(v7);
    }
    close(fd);
    if ( (unsigned int)check_password(v7) )
        dprintf(v7, "You got the password right!\nMy litecoin address is %s", "LNpECGn9in6BGC8eaK87QawjzAXaWMht2b");
    else
        dprintf(v7, "You failed to get a correct password!\n");
    close(v7);
    exit(0);
}
