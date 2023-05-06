char *s1 = "ASIS{N0T_R34LLY_4_FL4G}";
char *off_6020A0 = "TRANSMISSION_OVER";
void *buf = &aYeahThatSSomet;
void *off_6020B0 = &aWeReNotExpecti;

unsigned int setup_env()
{
    setvbuf(stdout, 0LL, 2, 0LL);
    setvbuf(stdin, 0LL, 1, 0LL);
    setvbuf(stderr, 0LL, 1, 0LL);
    return alarm(0xF0u);
}

int64_t setup_seccomp()
{
    int64_t v0; // ST08_8

    v0 = seccomp_init(0LL);
    seccomp_rule_add(v0, 2147418112LL, 231LL, 0LL);
    seccomp_rule_add(v0, 2147418112LL, 60LL, 0LL);
    seccomp_rule_add(v0, 2147418112LL, 0LL, 0LL);
    seccomp_rule_add(v0, 2147418112LL, 1LL, 0LL);
    seccomp_rule_add(v0, 2147418112LL, 3LL, 0LL);
    return seccomp_load(v0);
}

int64_t main(int64_t a1, char **a2, char **a3)
{
    __WAIT_STATUS stat_loc; // [rsp+Ch] [rbp-34h]
    int v5; // [rsp+14h] [rbp-2Ch]
    int pipedes[2]; // [rsp+18h] [rbp-28h]
    char buf; // [rsp+20h] [rbp-20h]

    LODWORD(stat_loc.__uptr) = 0;
    setup_env();
    pipe(pipedes);
    pipe((int *)&stat_loc.__iptr + 1);
    if ( fork() )
    {
        do
            read(SHIDWORD(stat_loc.__iptr), &buf, 0x80uLL);
        while ( strcmp(off_6020A0, &buf) );
        wait((__WAIT_STATUS)&stat_loc);
    }
    else
    {
        setup_seccomp();
        puts(
            "-> You're waiting for a train; a train that will take you far away. You know where you hope this train will take y"
            "ou, but you can't be sure.");
        printf("-> Let's do something: ", a2);
        read(0, &buf, 0x100uLL);
        if ( strcmp(s1, &buf) )
        {
            write(1, off_6020B0, 8uLL);
            write(v5, "TRANSMISSION_OVER", 10uLL);
            exit(0);
        }
        write(1, ::buf, 8uLL);
    }
    return 0LL;
}
