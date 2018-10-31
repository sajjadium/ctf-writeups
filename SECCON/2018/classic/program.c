#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>

int64_t init()
{
    setbuf(stdout, 0LL);
    setbuf(stderr, 0LL);
    return 0LL;
}

int main()
{
    char buf[0x40];

    puts("Classic Pwnable Challenge");
    printf("Local Buffer >> ");
    gets(buf);
    puts("Have a nice pwn!!");
    return 0;
}
