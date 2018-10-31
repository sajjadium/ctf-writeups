#include <stdio.h>
#include <stdint.h>

int main()
{
    char buf[0x40];
    puts("Classic Pwnable Challenge");
    printf("Local Buffer >> ");
    gets(buf);
    puts("Have a nice pwn!!");
    return 0;
}
