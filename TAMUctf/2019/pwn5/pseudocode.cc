int run_cmd(char a1)
{
    char v2; // [esp+6h] [ebp-12h]

    snprintf(&v2, 7, "ls %s", a1);
    printf("Result of %s:\n", (unsigned int)&v2);
    return system(&v2);
}

int laas()
{
    int result; // eax
    char s; // [esp+Bh] [ebp-Dh]

    puts("ls as a service (laas)(Copyright pending)");
    puts("Version 2: Less secret strings and more portable!");
    puts("Enter the arguments you would like to pass to ls:");
    gets(&s);
    if ( strchr(&s, 47) )
        result = puts("No slashes allowed");
    else
        result = run_cmd((unsigned int)&s);
    return result;
}

int main()
{
    setvbuf(stdout, 2, 0, 0);
    while ( 1 )
        laas();
}
