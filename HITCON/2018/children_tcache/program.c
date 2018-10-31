#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

char *heap_table[12];
int64_t size_table[10];

void handler()
{
    puts("Timeout");
    _exit(1);
}

unsigned int initialize()
{
    setvbuf(stdin, 0LL, 2, 0LL);
    setvbuf(stdout, 0LL, 2, 0LL);
    setvbuf(stderr, 0LL, 2, 0LL);
    signal(14, handler);
    return alarm(60u);
}

int64_t read_number()
{
    char nptr[0x10]; // [rsp+10h] [rbp-20h]

    __read_chk(0LL, nptr, 16LL, 17LL);
    return atoll(nptr);
}

int64_t read_string(char *a1, uint64_t a2)
{
    int64_t result; // rax
    int v3; // [rsp+1Ch] [rbp-4h]

    v3 = __read_chk(0LL, a1, a2, a2);
    if ( v3 <= 0 )
    {
        puts("read error");
        _exit(1);
    }
    result = *(int8_t *)(v3 - 1 + a1);
    if ( (char)result == '\n' )
    {
        *(char *)(v3 - 1 + a1) = 0;
    }
    return 0;
}

int print_menu()
{
    puts("$$$$$$$$$$$$$$$$$$$$$$$$$$$");
    puts("$$$$$$$$$$$$$$$$$$$$$$$$$$$");
    puts("$   1. New heap           $");
    puts("$   2. Show heap          $");
    puts("$   3. Delete heap        $ ");
    puts("$   4. Exit               $ ");
    puts("$$$$$$$$$$$$$$$$$$$$$$$$$$$");
    return printf("Your choice: ");
}

uint64_t new_heap()
{
    signed int i; // [rsp+Ch] [rbp-2034h]
    char *dest; // [rsp+10h] [rbp-2030h]
    uint64_t size; // [rsp+18h] [rbp-2028h]
    char buffer[0x2010]; // [rsp+20h] [rbp-2020h]
    uint64_t v5; // [rsp+2038h] [rbp-8h]

    memset(buffer, 0, 0x2010);
    for ( i = 0; ; ++i )
    {
        if ( i > 9 )
        {
            puts(":(");
        }
        if ( !heap_table[i] )
            break;
    }
    printf("Size:");
    size = read_number();
    if ( size > 0x2000 )
        exit(-2);
    dest = (char *)malloc(size);
    if ( !dest )
        exit(-1);
    printf("Data:");
    read_string(buffer, size);
    strcpy(dest, buffer);
    heap_table[i] = dest;
    size_table[i] = size;
}

int show_heap()
{
    const char *chunk; // rax
    uint64_t index; // [rsp+8h] [rbp-8h]

    printf("Index:");
    index = read_number();
    if ( index > 9 )
        exit(-3);
    chunk = heap_table[index];
    if ( chunk )
        puts(heap_table[index]);
    return 0;
}

int delete_heap()
{
    uint64_t index; // [rsp+8h] [rbp-8h]

    printf("Index:");
    index = read_number();
    if ( index > 9 )
        exit(-3);
    if ( heap_table[index] )
    {
        memset((void *)heap_table[index], 0xDA, size_table[index]);
        free((void *)heap_table[index]);
        heap_table[index] = 0LL;
        size_table[index] = 0LL;
    }
    return puts(":)");
}

void main()
{
    uint64_t v3; // rax

    initialize();
    while ( 1 )
    {
        while ( 1 )
        {
            print_menu();
            v3 = read_number();
            if ( v3 != 2 )
                break;
            show_heap();
        }
        if ( v3 > 2 )
        {
            if ( v3 == 3 )
            {
                delete_heap();
            }
            else
            {
                if ( v3 == 4 )
                    _exit(0);
LABEL_13:
                puts("Invalid Choice");
            }
        }
        else
        {
            if ( v3 != 1 )
                goto LABEL_13;
            new_heap();
        }
    }
}
