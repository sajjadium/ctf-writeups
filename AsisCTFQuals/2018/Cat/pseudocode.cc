void *pet_table[10];
void *ptr;

unsigned int initialize()
{
    setvbuf(stdout, 0LL, 2, 0LL);
    setvbuf(stdin, 0LL, 1, 0LL);
    return alarm(0x20u);
}

int print_banner()
{
    putchar(10);
    puts(
        "$$$$$$$\\             $$\\           $$$$$$$\\                      $$\\             $$\\                         \n"
        "$$  __$$\\            $$ |          $$  __$$\\                     \\__|            $$ |                        \n"
        "$$ |  $$ | $$$$$$\\ $$$$$$\\         $$ |  $$ | $$$$$$\\   $$$$$$\\  $$\\  $$$$$$$\\ $$$$$$\\    $$$$$$\\   $$$$$$\\"
        "  \n"
        "$$$$$$$  |$$  __$$\\\\_$$  _|        $$$$$$$  |$$  __$$\\ $$  __$$\\ $$ |$$  _____|\\_$$  _|  $$  __$$\\ $$  __$$\\ "
        "\n"
        "$$  ____/ $$$$$$$$ | $$ |          $$  __$$< $$$$$$$$ |$$ /  $$ |$$ |\\$$$$$$\\    $$ |    $$$$$$$$ |$$ |  \\__|\n"
        "$$ |      $$   ____| $$ |$$\\       $$ |  $$ |$$   ____|$$ |  $$ |$$ | \\____$$\\   $$ |$$\\ $$   ____|$$ |      \n"
        "$$ |      \\$$$$$$$\\  \\$$$$  |      $$ |  $$ |\\$$$$$$$\\ \\$$$$$$$ |$$ |$$$$$$$  |  \\$$$$  |\\$$$$$$$\\ $$ |    "
        "  \n"
        "\\__|       \\_______|  \\____/       \\__|  \\__| \\_______| \\____$$ |\\__|\\_______/    \\____/  \\_______|\\__| "
        "     \n"
        "                                                       $$\\   $$ |                                            \n"
        "                                                       \\$$$$$$  |                                            \n"
        "                                                        \\______/                                             ");
    return putchar(10);
}

int print_menu()
{
    puts("------------------------------------------------");
    puts(" 1: create pet record");
    puts(" 2: edit pet record");
    puts(" 3: print record");
    puts(" 4: print all record");
    puts(" 5: delete record");
    puts(" 6: exit");
    return puts("------------------------------------------------");
}

int get_id()
{
    int result; // eax
    int v1; // [rsp+Ch] [rbp-24h]
    char buf; // [rsp+10h] [rbp-20h]
    uint64_t v3; // [rsp+28h] [rbp-8h]

    printf("which id?\n> ");
    read(0, &buf, 4uLL);
    v1 = atoi(&buf);
    if ( v1 >= 0 && v1 <= 9 )
        result = atoi(&buf);
    else
        result = -1;
    return result;
}

int64_t create_pet()
{
    void **v1; // rbx
    int64_t *v2; // rbx
    int64_t *v3; // rbx
    unsigned int v4; // [rsp+4h] [rbp-3Ch]
    int i; // [rsp+8h] [rbp-38h]
    char buf; // [rsp+10h] [rbp-30h]
    uint64_t v7; // [rsp+28h] [rbp-18h]

    v4 = -1;
    for ( i = 0; i <= 9; ++i )
    {
        if ( !pet_table[i] )
        {
            v4 = i;
            break;
        }
    }
    if ( v4 == -1 )
    {
        puts("records is full! (=+_+=)");
    }
    else
    {
        pet_table[v4] = malloc(0x18uLL);
        v1 = (void **)pet_table[v4];
        *v1 = malloc(0x17uLL);
        v2 = pet_table[v4];
        v2[1] = malloc(0x17uLL);
        printf("What's the pet's name?\n> ");
        *(char *)((signed int)read(0, *(void **)pet_table[v4], 0x16uLL) - 1LL + * (int64_t *)pet_table[v4]) = 0;
        printf("What's the pet's kind?\n> ");
        *(char *)((signed int)read(0, *((void **)pet_table[v4] + 1), 0x16uLL) - 1LL + * ((int64_t *)pet_table[v4] + 1)) = 0;
        printf("How old?\n> ");
        read(0, &buf, 4uLL);
        v3 = pet_table[v4];
        v3[2] = atoi(&buf);
        printf("create record id:%d\n", v4);
    }
    return 0LL;
}

int64_t edit_pet()
{
    int64_t result; // rax
    void **v1; // rbx
    int64_t *v2; // rbx
    int64_t v3; // rsi
    int v4; // ST0C_4
    int v5; // eax
    int64_t *v6; // rbx
    void *ptr; // ST10_8
    void *v8; // ST18_8
    unsigned int v9; // [rsp+8h] [rbp-48h]
    char buf; // [rsp+20h] [rbp-30h]
    uint64_t v11; // [rsp+38h] [rbp-18h]

    v9 = get_id();
    if ( v9 == -1 )
    {
        puts("Invalid id! (=+_+=)");
        result = 0LL;
    }
    else if ( pet_table[v9] )
    {
        if ( !::ptr )
        {
            ::ptr = malloc(0x18uLL);
            v1 = (void **)::ptr;
            *v1 = malloc(0x17uLL);
            v2 = ::ptr;
            v2[1] = malloc(0x17uLL);
        }
        printf("What's the pet's name?\n> ");
        v3 = *(int64_t *)::ptr;
        v4 = read(0, *(void **)::ptr, 0x16uLL);
        *(char *)(v4 - 1LL + * (int64_t *)::ptr) = 0;
        printf("What's the pet's kind?\n> ", v3);
        v5 = read(0, *((void **)::ptr + 1), 0x16uLL);
        *(char *)(v5 - 1LL + * ((int64_t *)::ptr + 1)) = 0;
        printf("How old?\n> ");
        read(0, &buf, 4uLL);
        v6 = ::ptr;
        v6[2] = atoi(&buf);
        printf("Would you modify? (y)/n> ", &buf);
        read(0, &buf, 4uLL);
        if ( buf == 110 )
        {
            ptr = *(void **)::ptr;
            v8 = (void *) * ((int64_t *)::ptr + 1);
            free(::ptr);
            free(ptr);
            free(v8);
        }
        else
        {
            free(*(void **)pet_table[v9]);
            free(*((void **)pet_table[v9] + 1));
            free(pet_table[v9]);
            pet_table[v9] = ::ptr;
            ::ptr = 0LL;
            printf("edit id %d\n", v9);
        }
        result = 0LL;
    }
    else
    {
        puts("Invalid id! (=+_+=)");
        result = 0LL;
    }
    return result;
}

int64_t print_pet()
{
    int64_t result; // rax
    unsigned int v1; // [rsp+Ch] [rbp-4h]

    v1 = get_id();
    if ( v1 == -1 )
    {
        puts("Invalid id! (=+_+=)");
        result = 0LL;
    }
    else
    {
        if ( pet_table[v1] )
        {
            printf(
                "name: %s\nkind: %s\nold: %lu\n",
                *(int64_t *)pet_table[v1],
                *((int64_t *)pet_table[v1] + 1),
                *((int64_t *)pet_table[v1] + 2));
            printf("print id %d\n", v1);
        }
        else
        {
            puts("Invalid id! (=+_+=)");
        }
        result = 0LL;
    }
    return result;
}

int64_t print_all_pets()
{
    int i; // [rsp+Ch] [rbp-4h]

    for ( i = 0; i <= 9; ++i )
    {
        if ( pet_table[i] )
        {
            puts("---");
            printf(
                "id: %d\nname: %s\nkind: %s\nold: %lu\n",
                (unsigned int)i,
                *(int64_t *)pet_table[i],
                *((int64_t *)pet_table[i] + 1),
                *((int64_t *)pet_table[i] + 2));
        }
    }
    puts("print all: ");
    return 0LL;
}

int64_t delete_pet()
{
    int64_t result; // rax
    unsigned int v1; // [rsp+Ch] [rbp-4h]

    v1 = get_id();
    if ( v1 == -1 )
    {
        puts("Invalid id! (=+_+=)");
        result = 0LL;
    }
    else
    {
        if ( pet_table[v1] )
        {
            free(*(void **)pet_table[v1]);
            free(*((void **)pet_table[v1] + 1));
            free(pet_table[v1]);
            pet_table[v1] = 0LL;
            printf("delete id %d\n", v1);
        }
        else
        {
            puts("Invalid id! (=+_+=)");
        }
        result = 0LL;
    }
    return result;
}

int64_t main(int64_t a1, char **a2, char **a3)
{
    int v4; // [rsp+8h] [rbp-28h]
    char buf; // [rsp+10h] [rbp-20h]
    uint64_t v6; // [rsp+28h] [rbp-8h]

    initialize();
    print_banner();
    v4 = 1;
    while ( v4 )
    {
        print_menu();
        printf("which command?\n> ");
        read(0, &buf, 4uLL);
        switch ( atoi(&buf) )
        {
        case 1:
            create_pet();
            break;
        case 2:
            edit_pet();
            break;
        case 3:
            print_pet();
            break;
        case 4:
            print_all_pets();
            break;
        case 5:
            delete_pet();
            break;
        case 6:
            v4 = 0;
            break;
        default:
            puts("Invalid command! (=+_+=)");
            break;
        }
    }
    return 0LL;
}
