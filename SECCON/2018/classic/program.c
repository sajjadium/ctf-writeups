#include <stdio.h>

int main()
{
  char v4[0x40];

  puts("Classic Pwnable Challenge");
  printf("Local Buffer >> ");
  gets(v4);
  puts("Have a nice pwn!!");
  return 0;
}

