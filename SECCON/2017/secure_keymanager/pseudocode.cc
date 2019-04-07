char account[32];
void *key_list[8];
char key_map[];
char master[16];

int main()
{
    int v4; // [rsp+Ch] [rbp-4h]

    puts(
        " _____                            _   __          ___  ___                                  \n"
        "/  ___|                          | | / /          |  \\/  |                                  \n"
        "\\ `--.  ___  ___ _   _ _ __ ___  | |/ /  ___ _   _| .  . | __ _ _ __   __ _  __ _  ___ _ __ \n"
        " `--. \\/ _ \\/ __| | | | '__/ _ \\ |    \\ / _ \\ | | | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '__|\n"
        "/\\__/ /  __/ (__| |_| | | |  __/ | |\\  \\  __/ |_| | |  | | (_| | | | | (_| | (_| |  __/ |   \n"
        "\\____/ \\___|\\___|\\__,_|_|  \\___| \\_| \\_/\\___|\\__, \\_|  |_/\\__,_|_| |_|\\__,_|\\__, |\\___|_|   \n"
        "                                              __/ |                          __/ |          \n"
        "                                             |___/                          |___/           \n");
    printf("Set Your Account Name >> ", argv);
    read(0, account, 16uLL);
    printf("Set Your Master Pass >> ", account);
    read(0, master, 16uLL);
    while ( 1 )
    {
        v4 = menu();
        if ( !v4 )
            break;
        switch ( v4 )
        {
        case 1:
            add_key();
            break;
        case 2:
            show_key();
            break;
        case 3:
            edit_key();
            break;
        case 4:
            remove_key();
            break;
        case 9:
            change_master();
            break;
        default:
            puts("Invalid input...");
            break;
        }
        puts("done.");
    }
    return 0;
}

int64_t menu()
{
    unsigned int v0; // ST0C_4

    printf("\n1. add\n2. show\n3. edit\n4. remove\n9. change master pass\n0. exit\n>> ");
    v0 = getint();
    puts(&byte_401234);
    return v0;
}

signed int64_t change_master()
{
    int64_t result; // rax

    result = check_account();
    if ( (int)result )
    {
        printf("Set New Master Pass >> ");
        result = read(0, master, 16uLL);
    }
    return result;
}

signed int64_t check_account()
{
    int64_t result; // rax
    char buf; // [rsp+0h] [rbp-50h]
    uint64_t v2; // [rsp+48h] [rbp-8h]

    printf("Input Account Name >> ");
    read(0, &buf, 64uLL);
    if ( !strcmp(account, &buf) )
    {
        if ( master[0] )
        {
            printf("Input Master Pass >> ", &buf);
            read(0, &buf, 64uLL);
            if ( !strcmp(master, &buf) )
            {
                result = 1LL;
            }
            else
            {
                puts("Wrong Pass...");
                result = 0LL;
            }
        }
        else
        {
            result = 1LL;
        }
    }
    else
    {
        printf("Account '%s' does not exist...\n", &buf);
        result = 0LL;
    }
    return result;
}

int add_key()
{
    int result; // eax
    int64_t v1; // [rsp+0h] [rbp-10h]
    int v2; // [rsp+0h] [rbp-10h]
    int v3; // [rsp+4h] [rbp-Ch]
    char *new_key; // [rsp+8h] [rbp-8h]

    LODWORD(v1) = 0;
    while ( (signed int)v1 <= 7 && key_map[(signed int)v1] )
        LODWORD(v1) = v1 + 1;
    if ( (signed int)v1 > 7 )
        return puts("can't add key any more...");
    puts("ADD KEY");
    printf("Input key length...", v1);
    v3 = getint();
    new_key = (char *)malloc(v3 + 32LL);
    if ( !new_key )
        return puts("can not allocate...");
    printf("Input title...");
    getnline(new_key, 32);
    printf("Input key...", 32LL);
    getnline(new_key + 32, v3);
    key_list[v2] = new_key;
    result = v2;
    key_map[v2] = 1;
    return result;
}

int show_key()
{
    int result; // eax
    int i; // [rsp+Ch] [rbp-4h]

    result = puts("id : Title / Key");
    for ( i = 0; i <= 7; ++i )
    {
        result = (unsigned __int8)key_map[i];
        if ( (char)result )
            result = printf("%02d : ***SECRET*** / ***SECRET***\n", (unsigned int)i);
    }
    return result;
}

int edit_key()
{
    int result; // eax
    int v1; // eax
    int v2; // [rsp+Ch] [rbp-4h]

    puts("EDIT KEY");
    result = check_account();
    if ( result )
    {
        printf("Input id to edit...");
        v2 = getint();
        if ( v2 >= 0 && v2 <= 7 )
        {
            if ( key_map[v2] )
            {
                printf("Input new key...");
                v1 = malloc_usable_size(key_list[v2]);
                result = getnline((char *)key_list[v2] + 32, v1 - 32);
            }
            else
            {
                result = puts("not exits...");
            }
        }
        else
        {
            result = puts("out of length");
        }
    }
    return result;
}

int remove_key()
{
    int result; // eax
    int v1; // [rsp+Ch] [rbp-4h]

    puts("REMOVE KEY");
    result = check_account();
    if ( result )
    {
        printf("Input id to remove...");
        v1 = getint();
        if ( v1 >= 0 && v1 <= 7 )
        {
            if ( key_list[v1] )
            {
                free(key_list[v1]);
                result = v1;
                key_map[v1] = 0;
            }
            else
            {
                result = puts("not exits...");
            }
        }
        else
        {
            result = puts("out of length");
        }
    }
    return result;
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
    char nptr; // [rsp+0h] [rbp-50h]
    uint64_t v2; // [rsp+48h] [rbp-8h]

    memset(&nptr, 0, 64uLL);
    getnline(&nptr, 64);
    return atoi(&nptr);
}
