char name[64];

int main()
{
    int fd; // [rsp+18h] [rbp-8h]
    int sockfd; // [rsp+1Ch] [rbp-4h]

    sockfd = setup_socket(4141u);
    do
    {
        fd = accept_and_fork(sockfd);
        if ( fd > 0 )
            return handle_client(fd);
    }
    while ( fd >= 0 );
    return -1;
}

void invert_case(char *str)
{
    int len; // [rsp+18h] [rbp-8h]
    int i; // [rsp+1Ch] [rbp-4h]

    len = strlen(str);
    for ( i = 0; i < len; ++i )
    {
        if ( str[i] > 64 && str[i] <= 90 || str[i] > 96 && str[i] <= 122 )
            str[i] ^= ' ';
    }
}

int handle_client(int fd)
{
    char msg[1024]; // [rsp+10h] [rbp-430h]
    int rv_6; // [rsp+418h] [rbp-28h]
    int rv_5; // [rsp+41Ch] [rbp-24h]
    int rv_4; // [rsp+420h] [rbp-20h]
    int rv_3; // [rsp+424h] [rbp-1Ch]
    int rv_2; // [rsp+428h] [rbp-18h]
    int rv_1; // [rsp+42Ch] [rbp-14h]
    int rv_0; // [rsp+430h] [rbp-10h]
    int rv; // [rsp+434h] [rbp-Ch]
    char *prompt; // [rsp+438h] [rbp-8h]

    prompt = "Enter your name> ";
    rv = write_string(fd, "Enter your name> ");
    if ( rv < 0 )
        exit(rv);
    rv_0 = read_line_safe(fd, name, 64uLL);
    if ( rv_0 < 0 )
        exit(rv_0);
    prompt = "Enter message> ";
    rv_1 = write_string(fd, "Enter message> ");
    if ( rv_1 < 0 )
        exit(rv_1);
    rv_2 = read_line_safe(fd, msg, 0x400uLL);
    if ( rv_2 < 0 )
        exit(rv_2);
    invert_case(msg);
    prompt = "Greetings ";
    rv_3 = write_string(fd, "Greetings ");
    if ( rv_3 < 0 )
        exit(rv_3);
    rv_4 = write_string(fd, name);
    if ( rv_4 < 0 )
        exit(rv_4);
    prompt = "!\n  Your converted message is:\n";
    rv_5 = write_string(fd, "!\n  Your converted message is:\n");
    if ( rv_5 < 0 )
        exit(rv_5);
    rv_6 = write_string(fd, msg);
    if ( rv_6 < 0 )
        exit(rv_6);
    return 0;
}

int write_string(int fd, char *str)
{
    int max; // [rsp+14h] [rbp-Ch]
    int rv; // [rsp+18h] [rbp-8h]
    int total; // [rsp+1Ch] [rbp-4h]

    total = 0;
    max = strlen(str);
    do
    {
        rv = write(fd, &str[total], max - total);
        if ( rv <= 0 )
            return rv;
        total += rv;
    }
    while ( total < max );
    return total;
}

int read_line_safe(int fd, char *buf, size_t buf_size)
{
    uint64_t buf_sizea; // [rsp+8h] [rbp-28h]
    int rb; // [rsp+28h] [rbp-8h]
    int total; // [rsp+2Ch] [rbp-4h]

    buf_sizea = buf_size;
    memset(buf, 0, buf_size);
    total = 0;
    do
    {
        rb = read(fd, &buf[total], buf_sizea - 1);
        if ( rb <= 0 )
            break;
        total += rb;
        if ( buf[total - 1] == '\n' )
        {
            buf[total - 1] = 0;
            break;
        }
    }
    while ( buf_sizea > total );
    buf[total] = 0;
    return total;
}

int setup_socket(uint16_t port)
{
    int enable; // [rsp+1Ch] [rbp-24h]
    sockaddr_in sa; // [rsp+20h] [rbp-20h]
    int s; // [rsp+3Ch] [rbp-4h]

    s = socket(2, 1, 0);
    *(int64_t *)&sa.sin_family = 0LL;
    *(int64_t *)sa.sin_zero = 0LL;
    sa.sin_family = 2;
    sa.sin_port = htons(port);
    enable = 1;
    if ( setsockopt(s, 1, 2, &enable, 4u) < 0 )
    {
        perror("setsockopt(SO_REUSEADDR) failed");
        exit(-1);
    }
    if ( bind(s, (const struct sockaddr *)&sa, 0x10u) )
    {
        perror("bind");
        exit(-1);
    }
    listen(s, 10);
    return s;
}

int accept_and_fork(int sock)
{
    pid_t p; // [rsp+18h] [rbp-8h]
    int fd; // [rsp+1Ch] [rbp-4h]

    fd = accept(sock, 0LL, 0LL);
    p = fork();
    if ( !p )
        return fd;
    if ( p == -1 )
        return -1;
    return 0;
}
