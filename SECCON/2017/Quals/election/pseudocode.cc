int lv = 1;
int64_t list;
int inv_votes;

int main()
{
    int v4; // [rsp+Ch] [rbp-4h]

    puts("*** Election ***");
    add_list("Tatsumi");
    add_list("Shinonome");
    add_list("Ojima");
    while ( 1 )
    {
        v4 = menu();
        if ( !v4 )
            break;
        switch ( v4 )
        {
        case 2:
            vote();
            break;
        case 3:
            result();
            break;
        case 1:
            stand();
            break;
        default:
            puts("Invalid input...");
            break;
        }
        puts("done.");
    }
    printf("Thank you!!", argv);
    return 0;
}

int64_t menu()
{
    unsigned int v0; // ST0C_4

    printf("\n1. stand\n2. vote\n3. result\n0. eat chocolate\n>> ");
    v0 = getint();
    putchar(10);
    return v0;
}

uint64_t stand()
{
    char v1; // [rsp+0h] [rbp-30h]
    uint64_t v2; // [rsp+28h] [rbp-8h]

    if ( (unsigned int)lv <= 1 )
    {
        printf("Enter the name.\n>> ");
        getnline(&v1, 32);
        add_list(&v1);
    }
    else
    {
        puts("The candidacy has already closed.");
    }
}

uint64_t vote()
{
    const char *v0; // rsi
    const char **i; // [rsp+8h] [rbp-48h]
    char s1; // [rsp+10h] [rbp-40h]
    int64_t v4; // [rsp+30h] [rbp-20h]
    char v5; // [rsp+38h] [rbp-18h]
    uint64_t v6; // [rsp+48h] [rbp-8h]

    v5 = 1;
    if ( (unsigned int)lv <= 2 )
    {
        lv = 2;
        printf("Show candidates? (Y/n) ");
        getnline(&s1, 32);
        v0 = "n";
        if ( strcasecmp(&s1, "n") )
        {
            puts("Candidates:");
            for ( i = (const char **)list; i; i = (const char **)i[1] )
            {
                v0 = *i;
                printf("* %s\n", *i);
            }
        }
        printf("Enter the name of the candidate.\n>> ", v0);
        getnline(&s1, 32);
        if ( !strcasecmp(&s1, "oshima") )
        {
            v4 = find_list("ojima");
            if ( v4 )
            {
                printf("I'm not 'Oshima', but 'Ojima'!\nWould you modify the name and re-vote?\n>> ", "oshima");
                getnline(&s1, 48);
                if ( !strcasecmp(&s1, "yes") )
                    *(int *)(v4 + 16) += v5;
            }
        }
        else
        {
            v4 = find_list(&s1);
            if ( v4 )
            {
                *(int *)(v4 + 16) += v5;
            }
            else
            {
                printf("'%s' is invalid vote :(\n", &s1);
                ++inv_votes;
            }
        }
    }
    else
    {
        puts("The voting has already closed.");
    }
}

int result()
{
    int64_t i; // [rsp+8h] [rbp-8h]

    lv = 3;
    for ( i = list; i; i = *(int64_t *)(i + 8) )
        printf("%11s : %d\n", *(int64_t *)i, *(unsigned int *)(i + 16));
    return printf("%11s : %d\n", "INVALID", (unsigned int)inv_votes);
}

int *add_list(const char *a1)
{
    int *v1; // ST18_8
    int *result; // rax

    v1 = malloc(24uLL);
    *(int64_t *)v1 = strdup(a1);
    v1[4] = rand() % 100;
    *((int64_t *)v1 + 1) = list;
    result = v1;
    list = (int64_t)v1;
    return result;
}

int64_t find_list(const char *a1)
{
    int64_t i; // [rsp+18h] [rbp-8h]

    for ( i = list; i; i = *(int64_t *)(i + 8) )
    {
        if ( !strcasecmp(a1, *(const char **)i) )
            return i;
    }
    return 0LL;
}

int64_t getnline(void *a1, int a2)
{
    unsigned int v3; // [rsp+14h] [rbp-Ch]
    char *v4; // [rsp+18h] [rbp-8h]

    if ( a2 <= 0 )
        return 0LL;
    v3 = read(0, a1, a2 - 1);
    if ( !v3 )
        return 0LL;
    *((char *)a1 + (signed int)v3) = 0;
    v4 = strchr((const char *)a1, 10);
    if ( v4 )
        *v4 = 0;
    return v3;
}

int getint()
{
    char nptr[8]; // [rsp+0h] [rbp-30h]
    int64_t v2; // [rsp+8h] [rbp-28h]
    int64_t v3; // [rsp+10h] [rbp-20h]
    int64_t v4; // [rsp+18h] [rbp-18h]
    uint64_t v5; // [rsp+28h] [rbp-8h]

    *(int64_t *)nptr = 0LL;
    v2 = 0LL;
    v3 = 0LL;
    v4 = 0LL;
    getnline(nptr, 32);
    return atoi(nptr);
}
