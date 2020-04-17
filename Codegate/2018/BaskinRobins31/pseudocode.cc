_BOOL8 check_decision(char a1)
{
    return a1 > 0 && a1 <= 3;
}

signed int64_t your_turn(int *a1)
{
    int64_t result; // rax
    char s; // [rsp+10h] [rbp-B0h]
    size_t n; // [rsp+B0h] [rbp-10h]
    int v4; // [rsp+BCh] [rbp-4h]

    v4 = 0;
    memset(&s, 0, 0x96uLL);
    puts("How many numbers do you want to take ? (1-3)");
    n = read(0, &s, 0x190uLL);
    write(1, &s, n);
    putchar(10);
    v4 = strtoul(&s, 0LL, 10);
    if ( (unsigned int)check_decision(v4) )
    {
        *a1 -= v4;
        result = 1LL;
    }
    else
    {
        puts("Don't break the rules...:( ");
        result = 0LL;
    }
    return result;
}

int my_turn(int *a1)
{
    int v1; // edx
    unsigned int v3; // [rsp+1Ch] [rbp-4h]

    if ( *a1 == 4 )
    {
        v3 = 4;
        *a1 = 0;
        puts("HUMMMMMMMMMMM");
        sleep(1u);
        puts("I got this!");
        sleep(1u);
        puts("HA! HA!");
        sleep(1u);
    }
    else
    {
        if ( *a1 & 3 )
        {
            v3 = *a1 % 4;
            v1 = *a1 - v3;
        }
        else
        {
            v3 = 1;
            v1 = *a1 - 1;
        }
        *a1 = v1;
    }
    return printf("I've taken %i number(s)\n", v3);
}

int main()
{
    unsigned int v3; // eax
    unsigned int v5; // [rsp+8h] [rbp-8h]
    _BOOL4 v6; // [rsp+Ch] [rbp-4h]

    setvbuf(stdout, 0LL, 2, 0LL);
    setvbuf(stdin, 0LL, 2, 0LL);
    v3 = time(0LL);
    srand(v3);
    v5 = 31;
    v6 = 0;
    puts("### This game is similar to the BaskinRobins31 game. ###");
    puts("### The one that take the last match win ###");
    printf("There are %u number(s)\n", 31LL);
    while ( (signed int)v5 > 0 )
    {
        if ( v6 )
        {
            my_turn((int *)&v5);
            v6 = 0;
        }
        else
        {
            v6 = (uint64_t)your_turn(&v5) != 0;
        }
        printf("remaining number(s) : %i \n", v5);
    }
    if ( v6 )
    {
        puts("Wow! You win!");
        puts("Hint is : ROP");
    }
    else
    {
        puts("You lose!");
    }
    return 0;
}

