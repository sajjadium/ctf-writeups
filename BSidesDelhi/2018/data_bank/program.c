#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>

int count = 5;
unsigned int size[8];
char *table[7];

int64_t get_inp(void *a1, int a2)
{
    int v3;

    v3 = read(0, a1, a2);
    if ( v3 == -1 )
        exit(0);
    if ( *((char *)a1 + v3 - 1) == 0xA )
        *((char *)a1 + v3 - 1) = 0;
    return (unsigned int)(v3 - 1);
}

int get_int()
{
    char nptr[0x30];

    get_inp(&nptr, 0x20);
    return atoi(nptr);
}

int printmenu()
{
    puts("1) Add data\n2) Edit data\n3) Remove data\n4) View data\n5) Exit");
    printf(">> ");
    return get_int();
}

int add()
{
    int result;
    int index;

    puts("Enter the index:");
    result = get_int();
    index = result;
    while ( index >= 0 && index <= 6 )
    {
        if ( table[index] )
            return puts("The idx is occupied\n");
        puts("Enter the size:");
        size[index] = get_int();
        if ( (size[index] & 0x80000000) == 0 && (signed int)size[index] <= 1024 )
        {
            table[index] = malloc((signed int)size[index]);
            if ( !table[index] )
                return puts("malloc_error");
            puts("Enter data:");
            return get_inp((void *)table[index], size[index]);
        }
        result = puts("Invalid size");
    }
    return result;
}

int edit()
{
    int index;
    int idx;

    puts("Enter the index:");
    index = get_int();
    idx = index;
    if ( index >= 0 && index <= 6 )
    {
        if ( table[index] )
        {
            puts("Please update the data:");
            if ( (unsigned int)get_inp((void *)table[idx], size[idx]) )
                index = puts("update successful\n");
            else
                index = puts("update unsuccessful");
        }
        else
        {
            index = puts("The index is empty\n");
        }
    }
    return index;
}

int delete()
{
    int result;
    int v1;
    int index;

    puts("Enter the index:");
    result = get_int();
    index = result;
    while ( index >= 0 && index <= 6 )
    {
        if ( !table[index] )
            return puts("The index is empty");
        v1 = count--;
        if ( v1 )
        {
            free((void *)table[index]);
            return puts("done");
        }
        result = puts("Sorry no more removal\n");
    }
    return result;
}

int view()
{
    int result;

    puts("Enter the index:");
    result = get_int();
    if ( result >= 0 && result <= 6 )
    {
        if ( table[result] )
            result = printf("Your data :%s\n\n", table[result]);
        else
            result = puts("The index is empty");
    }
    return result;
}

int main()
{
    alarm(0x3Cu);
    setvbuf(stdout, 0LL, 2, 0LL);
    setvbuf(stdin, 0LL, 2, 0LL);
    setvbuf(stderr, 0LL, 2, 0LL);
    puts("----------DATA BANK----------");
    while ( 1 )
    {
        switch (printmenu())
        {
        case 1u:
            add();
            break;
        case 2u:
            edit();
            break;
        case 3u:
            delete();
            break;
        case 4u:
            view();
            break;
        case 5u:
            exit(0);
        default:
            puts("Invalid");
            break;
        }
    }
}

