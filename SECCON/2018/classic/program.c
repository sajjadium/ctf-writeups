#include <stdio.h>
#include <stdint.h>

int main()
{
  char v4[0x40];

  puts("Classic Pwnable Challenge");
  printf("Local Buffer >> ");
  gets((int64_t)v4);
  puts("Have a nice pwn!!");
  return 0;
}

