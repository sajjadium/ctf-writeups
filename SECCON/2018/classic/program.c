#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

int64_t init()
{
  setbuf(stdout, 0LL);
  setbuf(stderr, 0LL);
  return 0LL;
}

int main()
{
  char buf[0x40]; // [rsp+0h] [rbp-40h]

  puts("Classic Pwnable Challenge");
  printf("Local Buffer >> ");
  gets(buf);
  puts("Have a nice pwn!!");
  return 0;
}
