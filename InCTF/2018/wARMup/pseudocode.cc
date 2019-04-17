int main(void)
{
    char auStack108 [100];

    alarm(0x1e);
    setvbuf(stdout, (char *)0x0, 2, 0);
    puts("Welcome to bi0s CTF!");
    read(0, auStack108, 0x78);
    return 0;
}
