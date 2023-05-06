FILE *stream;

char *change_id(const char *a1)
{
    size_t v1; // rax
    char v3; // [rsp+10h] [rbp-B0h]
    char v4[8]; // [rsp+70h] [rbp-50h]
    int64_t v5; // [rsp+78h] [rbp-48h]
    int64_t v6; // [rsp+80h] [rbp-40h]
    int64_t v7; // [rsp+88h] [rbp-38h]
    char v8; // [rsp+90h] [rbp-30h]
    char v9[28]; // [rsp+A0h] [rbp-20h]
    int i; // [rsp+BCh] [rbp-4h]

    *(int64_t *)v4 = 0LL;
    v5 = 0LL;
    v6 = 0LL;
    v7 = 0LL;
    v8 = 0;
    MD5_Init(&v3);
    v1 = strlen(a1);
    MD5_Update(&v3, a1, v1);
    MD5_Final(v9, &v3);
    for ( i = 0; i <= 15; ++i )
        sprintf(&v4[2 * i], "%02X", (unsigned __int8)v9[i]);
    return strdup(v4);
}

int print_banner()
{
    puts(
        "\n"
        " #   #    ####   #####  ######\n"
        "  # #    #    #    #    #\n"
        "### ###  #         #    #####\n"
        "  # #    #         #    #\n"
        " #   #   #    #    #    #\n"
        "          ####     #    #\n"
        "\n");
    setvbuf(stdout, 0LL, 2, 0LL);
    setvbuf(stdin, 0LL, 2, 0LL);
    return chdir("/tmp");
}

int print_menu()
{
    puts("=====MENU======");
    puts("1. Edit note");
    puts("2. Show note");
    puts("3. Save note");
    puts("4. Change ID");
    return puts("5. Exit");
}

char *load_note()
{
    char s; // [rsp+0h] [rbp-100h]

    if ( !stream )
        return 0LL;
    fseek(stream, 0LL, 0);
    _isoc99_fscanf(stream, "%256s", &s);
    return strdup(&s);
}

int save_note(const char *a1)
{
    int result; // eax

    if ( a1 )
    {
        fseek(stream, 0LL, 0);
        result = fputs(a1, stream);
    }
    return result;
}

char *edit_note()
{
    char s; // [rsp+0h] [rbp-100h]

    _isoc99_scanf("%256s", &s);
    return strdup(&s);
}

FILE *load_id()
{
    FILE *result; // rax
    const char *filename; // [rsp+8h] [rbp-8h]

    printf("Input your ID:");
    _isoc99_scanf("%256s", &unk_602040);
    filename = change_id((const char *)&unk_602040);
    stream = fopen(filename, "r+");
    result = stream;
    if ( !stream )
    {
        result = fopen(filename, "w+");
        stream = result;
    }
    return result;
}

void main(int64_t a1, char **a2, char **a3)
{
    char *v3; // rax
    int64_t *v4; // [rsp-8h] [rbp-28h]
    int v5; // [rsp+Ch] [rbp-14h]
    const char *v6; // [rsp+10h] [rbp-10h]
    char *v7; // [rsp+18h] [rbp-8h]
    int64_t savedregs; // [rsp+20h] [rbp+0h]

    v4 = &savedregs;
    print_banner();
    v6 = "%d";
    load_id();
    v7 = load_note();
    print_menu();
    while ( 1 )
    {
        printf("> ", a2);
        a2 = (char **)&v5;
        if ( (signed int)_isoc99_scanf(v6, &v5) <= 0 )
            break;
        switch ( v5 )
        {
        case 1:
            printf("Note:", &v5);
            v7 = edit_note();
            break;
        case 2:
            a2 = (char **)v7;
            printf("Note:%s\n", v7);
            break;
        case 3:
            save_note(v7);
            puts("Saved!");
            break;
        case 4:
            fclose(stream);
            v3 = change_id((const char *)&unk_602040);
            unlink(v3);
            load_id();
            puts("Done!");
            break;
        case 5:
            if ( stream )
                fclose(stream);
            exit(0);
            return;
        default:
            puts("Invalid choice");
            break;
        }
    }
    exit(0);
}
