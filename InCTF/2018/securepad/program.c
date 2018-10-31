#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

int64_t sizes;
char password[32];
int64_t table;

int64_t get_size(int index)
{
  unsigned int v2; // [rsp+Ch] [rbp-8h]
  int i; // [rsp+10h] [rbp-4h]

  for ( i = 0; i <= 9; ++i )
  {
    v2 = i;
    if ( i == index )
      return *(unsigned int *)(4LL * i + sizes);
  }
  return v2;
}

int64_t get_inp(void *a1, int a2)
{
  int v3; // [rsp+1Ch] [rbp-4h]

  v3 = read(0, a1, a2);
  if ( v3 == -1 )
    exit(0);
  if ( *((char *)a1 + v3 - 1) == '\n' )
    *((char *)a1 + v3 - 1) = 0;
  return (unsigned int)(v3 - 1);
}

int get_int()
{
  char nptr; // [rsp+0h] [rbp-30h]
  uint64_t v2; // [rsp+28h] [rbp-8h]

  get_inp(&nptr, 32);
  return atoi(&nptr);
}

int64_t add_data()
{
  unsigned int i; // [rsp+10h] [rbp-10h]
  int size; // [rsp+14h] [rbp-Ch]
  void *new_data; // [rsp+18h] [rbp-8h]

  puts("Enter size");
  size = get_int();
  if ( size <= 0x70 )
  {
    new_data = malloc(size);
    if ( new_data )
    {
      for ( i = 0; i <= 9 && *(int64_t *)(8LL * i + table); ++i )
        ;
      if ( i != 10 )
      {
        printf("Enter data: ");
        get_inp(new_data, size);
        *(int64_t *)(table + 8LL * i) = new_data;
        *(int *)(sizes + 4LL * i) = size;
      }
    }
  }
  return 0LL;
}

int64_t edit_data()
{
  unsigned int v1; // [rsp+8h] [rbp-18h]
  int i; // [rsp+Ch] [rbp-14h]
  unsigned int index; // [rsp+10h] [rbp-10h]
  int size; // [rsp+14h] [rbp-Ch]
  void *data; // [rsp+18h] [rbp-8h]

  puts("Enter index");
  index = get_int();
  if ( index > 9 )
  {
    v1 = 0;
  }
  else
  {
    for ( i = 0; i <= 9; ++i )
    {
      if ( i == index )
        data = *(void **)(8LL * i + table);
    }
    size = get_size(index);
    if ( !data || !size || (v1 = get_inp(data, size)) != 0 )
      v1 = 0;
  }
  return v1;
}

int64_t remove_data()
{
  void *data; // [rsp+10h] [rbp-20h]
  uint64_t i; // [rsp+18h] [rbp-18h]
  int64_t index; // [rsp+20h] [rbp-10h]

  puts("Enter index");
  index = get_int();
  for ( i = 0LL; i <= 9; ++i )
  {
    if ( i == index )
    {
      data = *(void **)(8 * i + table);
      break;
    }
  }
  if ( data )
  {
    free(data);
    *(int64_t *)(8 * i + table) = 0LL;
  }
  return 0LL;
}

int64_t view_data()
{
  unsigned int v1; // [rsp+Ch] [rbp-14h]
  int i; // [rsp+10h] [rbp-10h]
  unsigned int index; // [rsp+14h] [rbp-Ch]
  char *data; // [rsp+18h] [rbp-8h]

  v1 = -1;
  puts("Enter index");
  index = get_int();
  if ( index <= 9 )
  {
    for ( i = 0; i <= 9; ++i )
    {
      if ( i == index )
        data = *(char **)(8LL * i + table);
    }
    if ( data )
      v1 = puts(data);
    else
      v1 = 0;
  }
  return v1;
}

int menu()
{
  puts("0) Exit\n1) Add\n2) Edit\n3) Remove\n4) View");
  printf(">>> ");
  return get_int();
}

int64_t authenticate()
{
  size_t n; // ST08_8
  unsigned int v2; // [rsp+4h] [rbp-41Ch]
  char pass; // [rsp+10h] [rbp-410h]
  uint64_t v4; // [rsp+418h] [rbp-8h]

  puts("Enter password");
  get_inp(&pass, 0x400);
  n = strlen(password);
  if ( !strncmp(&pass, password, n) )
    v2 = system("sh");
  else
    v2 = 0;
  return v2;
}

int init_password()
{
  int fd; // ST0C_4
  char *mem; // rax

  fd = open("/dev/urandom", 0);
  read(fd, password, 0x20uLL);
  mem = (char *)mmap(0LL, 0x1000uLL, 3, 34, -1, 0LL);
  table = (int64_t)mem;
  sizes = (int64_t)(mem + 0x100);
  return close(fd);
}

int main()
{
  alarm(0x3Cu);
  setvbuf(stdout, 0LL, 2, 0LL);
  init_password();
  while ( 1 )
  {
    switch ( menu() )
    {
      case 0u:
        exit(0);
        return;
      case 1u:
        authenticate();
        add_data();
        break;
      case 2u:
        authenticate();
        edit_data();
        break;
      case 3u:
        authenticate();
        remove_data();
        break;
      case 4u:
        authenticate();
        view_data();
        break;
      default:
        puts("Invalid");
        break;
    }
  }
}

