int num_of_marimo;
int64_t marimo_list[15];
int total_money;

void main(int64_t a1, char **a2, char **a3)
{
    int64_t v3; // [rsp+0h] [rbp-30h]
    int64_t v4; // [rsp+8h] [rbp-28h]
    int64_t v5; // [rsp+10h] [rbp-20h]
    int v6; // [rsp+18h] [rbp-18h]
    __int16 v7; // [rsp+1Ch] [rbp-14h]
    uint64_t v8; // [rsp+28h] [rbp-8h]

    v3 = 0LL;
    v4 = 0LL;
    v5 = 0LL;
    v6 = 0;
    v7 = 0;
    show_banner();
    while ( 1 )
    {
        do
        {
            show_menu();
            fflush(stdout);
            __isoc99_scanf(" %30[^\n]s", &v3);
        }
        while ( (unsigned int)make_free_marimo((const char *)&v3) );
        switch ( (char)v3 )
        {
        case 'A':
            about();
            break;
        case 'B':
            buy_marimo();
            break;
        case 'Q':
            puts("bye");
            exit(0);
            return;
        case 'S':
            sell_marimo();
            break;
        case 'V':
            view_my_bowls();
            break;
        default:
            puts("wrong input");
            break;
        }
    }
}

int about()
{
    puts("=============================");
    puts("=========   About   =========");
    puts("=============================");
    puts(&byte_4014F4);
    puts("Do you know marimo?");
    puts("It is an incredibly cute moss <3");
    puts("Sell Marimo for Buy more Marimo! XD");
    return puts("more info --> [https://en.wikipedia.org/wiki/Marimo]");
}

signed int64_t make_free_marimo(const char *a1)
{
    void *new_marimo; // ST18_8

    if ( strcmp(a1, "show me the marimo") )
        return 0LL;
    new_marimo = malloc(24uLL);
    make_marimo((int64_t)new_marimo, 1u, 5u);
    marimo_list[num_of_marimo++] = (int64_t)new_marimo;
    return 1LL;
}

uint64_t view_my_bowls()
{
    int i; // [rsp+Ch] [rbp-24h]
    char v2; // [rsp+10h] [rbp-20h]
    uint64_t v3; // [rsp+28h] [rbp-8h]

    if ( num_of_marimo )
    {
        puts("\n\n== Marimo's bowl List ==");
        for ( i = 0; i < num_of_marimo; ++i )
            printf("[ bowl %0d ]", (unsigned int)i);
        puts(&byte_4014F4);
        puts("Select number or [B]ack");
        printf(">> ");
        fflush(stdout);
        __isoc99_scanf("%19s", &v2);
        if ( v2 != 'B' )
        {
            if ( v2 - 48 < 0 || v2 - 48 >= num_of_marimo )
                puts("[X] Invalid");
            else
                show_modify_marimo((unsigned int *)marimo_list[v2 - 48]);
        }
    }
    else
    {
        puts("** Empty **");
    }
}

uint64_t show_modify_marimo(unsigned int *marimo)
{
    unsigned int v1; // ST18_4
    unsigned int v3; // [rsp+1Ch] [rbp-24h]
    char v4; // [rsp+20h] [rbp-20h]
    uint64_t v5; // [rsp+38h] [rbp-8h]

    puts(&byte_4014F4);
    printf("birth : %d\n", *marimo);
    v1 = time(0LL);
    printf("current time : %d\n", v1);
    v3 = v1 + marimo[1] - *marimo;
    printf("size : %d\n", v3);
    printf("price : %d\n", 5 * v3);
    printf("name : %s\n", *((int64_t *)marimo + 1));
    printf("profile : %s\n", *((int64_t *)marimo + 2));
    puts(&byte_4014F4);
    puts("[M]odify / [B]ack ?");
    printf(">> ");
    fflush(stdout);
    __isoc99_scanf("%19s", &v4);
    if ( v4 == 'M' )
    {
        puts("Give me new profile");
        printf(">> ", &v4);
        fflush(stdout);
        get_string(*((int64_t *)marimo + 2), 32 * v3);
        show_modify_marimo(marimo);
    }
}

signed int64_t buy_marimo()
{
    int size; // [rsp+0h] [rbp-30h]
    int price; // [rsp+4h] [rbp-2Ch]
    void *new_marimo; // [rsp+8h] [rbp-28h]
    char v4; // [rsp+10h] [rbp-20h]
    uint64_t v5; // [rsp+28h] [rbp-8h]

    puts("== Marimo Market! ==");
    puts("[?] What size do you want for Marimo? (cm)");
    printf(">> ");
    fflush(stdout);
    __isoc99_scanf("%d", &size);
    if ( size <= 0 || size > 150 )
    {
        puts("[X] Invalid Size ;(");
        return 0LL;
    }
    price = 5 * size;
    printf("\nIt's %d dollars.\nGive me money :P\n", (unsigned int)(5 * size));
    puts("[P]ay / [R]un away ?");
    printf(">> ");
    fflush(stdout);
    __isoc99_scanf("%19s", &v4);
    if ( v4 == 'P' )
    {
        if ( num_of_marimo == 15 )
            puts("[X] Your bowl is full! :o");
        if ( total_money >= price )
        {
            new_marimo = malloc(24uLL);
            make_marimo((int64_t)new_marimo, size, price);
            marimo_list[num_of_marimo++] = (int64_t)new_marimo;
            return 1LL;
        }
        puts("[X] Not enough money! :o");
    }
    return 0LL;
}

char *make_marimo(int64_t new_marimo, unsigned int size, unsigned int price)
{
    uint64_t v3; // ST00_8
    int v4; // ST04_4

    v3 = __PAIR__(size, price);
    *(int *)new_marimo = time(0LL);
    *(int *)(new_marimo + 4) = size;
    *(int64_t *)(new_marimo + 8) = malloc(16uLL);
    puts("What's your new marimo's name? (0x10)");
    printf(">> ", v3);
    fflush(stdout);
    __isoc99_scanf("%16s", *(int64_t *)(new_marimo + 8));
    *(int64_t *)(new_marimo + 16) = malloc(32 * v4);
    printf("write %s's profile. (0x%X)\n", *(int64_t *)(new_marimo + 8), (unsigned int)(32 * v4));
    fflush(stdout);
    printf(">> ");
    fflush(stdout);
    return get_string(*(int64_t *)(new_marimo + 16), 32 * v4);
}

char *get_string(int64_t a1, int a2)
{
    char *result; // rax
    char v3; // [rsp+1Bh] [rbp-5h]
    int i; // [rsp+1Ch] [rbp-4h]

    while ( _IO_getc(stdin) != 10 )
        ;
    for ( i = 0; i < a2; ++i )
    {
        v3 = _IO_getc(stdin);
        if ( v3 == 10 )
            break;
        *(char *)(a1 + i) = v3;
    }
    result = (char *)(i + a1);
    *result = 0;
    return result;
}

uint64_t sell_marimo()
{
    int index; // [rsp+4h] [rbp-2Ch]
    int i; // [rsp+8h] [rbp-28h]
    unsigned int price; // [rsp+Ch] [rbp-24h]
    char v4; // [rsp+10h] [rbp-20h]
    uint64_t v5; // [rsp+28h] [rbp-8h]

    puts("== Marimo Market! ==");
    puts("[?] Which marimo do you want to sell? (number)");
    printf(">> ");
    fflush(stdout);
    __isoc99_scanf("%d", &index);
    if ( marimo_list[index] )
    {
        price = 0;
        price = 5 * ((uint64_t)time(0LL) - * (int *)marimo_list[index] + * (int *)(marimo_list[index] + 4));
        printf("It's %d dollars.\n[S]ell / [R]un away ?", price);
        fflush(stdout);
        __isoc99_scanf("%19s", &v4);
        if ( v4 == 'S' )
        {
            for ( i = index + 1; i < num_of_marimo; ++i )
                marimo_list[i - 1] = marimo_list[i];
            --num_of_marimo;
            total_money += price;
            puts("[*] good bye marimo T-T");
        }
    }
    else
    {
        puts("[X] 404 marimo");
    }
}

int show_banner()
{
    unsigned int v0; // eax
    int result; // eax

    v0 = time(0LL);
    srand(v0);
    result = rand() % 3;
    switch ( result )
    {
    case 1:
        return puts(
                   " ___       __   _______   ___       ________  ________  _____ ______   _______           _________  _____"
                   "___                   \n"
                   "|\\  \\     |\\  \\|\\  ___ \\ |\\  \\     |\\   ____\\|\\   __  \\|\\   _ \\  _   \\|\\  ___ \\         "
                   "|\\___   ___\\\\   __  \\                  \n"
                   "\\ \\  \\    \\ \\  \\ \\   __/|\\ \\  \\    \\ \\  \\___|\\ \\  \\|\\  \\ \\  \\\\\\__\\ \\  \\ \\   __/"
                   "|        \\|___ \\  \\_\\ \\  \\|\\  \\                 \n"
                   " \\ \\  \\  __\\ \\  \\ \\  \\_|/_\\ \\  \\    \\ \\  \\    \\ \\  \\\\\\  \\ \\  \\\\|__| \\  \\ \\  \\_"
                   "|/__           \\ \\  \\ \\ \\  \\\\\\  \\                \n"
                   "  \\ \\  \\|\\__\\_\\  \\ \\  \\_|\\ \\ \\  \\____\\ \\  \\____\\ \\  \\\\\\  \\ \\  \\    \\ \\  \\ \\  "
                   "\\_|\\ \\           \\ \\  \\ \\ \\  \\\\\\  \\               \n"
                   "   \\ \\____________\\ \\_______\\ \\_______\\ \\_______\\ \\_______\\ \\__\\    \\ \\__\\ \\_______\\   "
                   "        \\ \\__\\ \\ \\_______\\              \n"
                   "    \\|____________|\\|_______|\\|_______|\\|_______|\\|_______|\\|__|     \\|__|\\|_______|            \\"
                   "|__|  \\|_______|              \n"
                   "                                                                                                         "
                   "                      \n"
                   "                                                                                                         "
                   "                      \n"
                   "                                                                                                         "
                   "                      \n"
                   " _____ ______   ________  ________  ___  _____ ______   ________          ___  ___  ________  ___  ___  _"
                   "_______  _______      \n"
                   "|\\   _ \\  _   \\|\\   __  \\|\\   __  \\|\\  \\|\\   _ \\  _   \\|\\   __  \\        |\\  \\|\\  \\|\\ "
                   "  __  \\|\\  \\|\\  \\|\\   ____\\|\\  ___ \\     \n"
                   "\\ \\  \\\\\\__\\ \\  \\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\ \\  \\\\\\__\\ \\  \\ \\  \\|\\  \\       \\ "
                   "\\  \\\\\\  \\ \\  \\|\\  \\ \\  \\\\\\  \\ \\  \\___|\\ \\   __/|    \n"
                   " \\ \\  \\\\|__| \\  \\ \\   __  \\ \\   _  _\\ \\  \\ \\  \\\\|__| \\  \\ \\  \\\\\\  \\       \\ \\   _"
                   "_  \\ \\  \\\\\\  \\ \\  \\\\\\  \\ \\_____  \\ \\  \\_|/__  \n"
                   "  \\ \\  \\    \\ \\  \\ \\  \\ \\  \\ \\  \\\\  \\\\ \\  \\ \\  \\    \\ \\  \\ \\  \\\\\\  \\       \\ "
                   "\\  \\ \\  \\ \\  \\\\\\  \\ \\  \\\\\\  \\|____|\\  \\ \\  \\_|\\ \\ \n"
                   "   \\ \\__\\    \\ \\__\\ \\__\\ \\__\\ \\__\\\\ _\\\\ \\__\\ \\__\\    \\ \\__\\ \\_______\\       \\ \\"
                   "__\\ \\__\\ \\_______\\ \\_______\\____\\_\\  \\ \\_______\\\n"
                   "    \\|__|     \\|__|\\|__|\\|__|\\|__|\\|__|\\|__|\\|__|     \\|__|\\|_______|        \\|__|\\|__|\\|___"
                   "____|\\|_______|\\_________\\|_______|\n"
                   "                                                                                                         "
                   " \\|_________|         \n"
                   "                                                                                                         "
                   "                      \n"
                   "                                                                                                         "
                   "                      \n");
    case 2:
        return puts(&byte_4028A0);
    case 0:
        puts(
            "____    __    ____  _______  __        ______   ______   .___  ___.  _______    .___________.  ______                      ");
        puts(
            "\\   \\  /  \\  /   / |   ____||  |      /      | /  __  \\  |   \\/   | |   ____|   |           | /  __  \\    "
            "                 ");
        puts(
            " \\   \\/    \\/   /  |  |__   |  |     |  ,----'|  |  |  | |  \\  /  | |  |__      `---|  |----`|  |  |  |                    ");
        puts(
            "  \\            /   |   __|  |  |     |  |     |  |  |  | |  |\\/|  | |   __|         |  |     |  |  |  |                    ");
        puts(
            "   \\    /\\    /    |  |____ |  `----.|  `----.|  `--'  | |  |  |  | |  |____        |  |     |  `--'  |                    ");
        puts(
            "    \\__/  \\__/     |_______||_______| \\______| \\______/  |__|  |__| |_______|       |__|      \\______/     "
            "                ");
        puts(
            "                                                                                                                           ");
        puts(
            ".___  ___.      ___      .______       __  .___  ___.   ______       __    __    ______    __    __       _______. _______ ");
        puts(
            "|   \\/   |     /   \\     |   _  \\     |  | |   \\/   |  /  __  \\     |  |  |  |  /  __  \\  |  |  |  |     /"
            "       ||   ____|");
        puts(
            "|  \\  /  |    /  ^  \\    |  |_)  |    |  | |  \\  /  | |  |  |  |    |  |__|  | |  |  |  | |  |  |  |    |   (----`|  |__   ");
        puts(
            "|  |\\/|  |   /  /_\\  \\   |      /     |  | |  |\\/|  | |  |  |  |    |   __   | |  |  |  | |  |  |  |     \\ "
            "  \\    |   __|  ");
        puts(
            "|  |  |  |  /  _____  \\  |  |\\  \\----.|  | |  |  |  | |  `--'  |    |  |  |  | |  `--'  | |  `--'  | .----)   |   |  |____ ");
        result = puts(
                     "|__|  |__| /__/     \\__\\ | _| `._____||__| |__|  |__|  \\______/     |__|  |__|  \\______/   \\______"
                     "/  |_______/    |_______|\n");
        break;
    }
    return result;
}

int show_menu()
{
    puts("\n[V]iew my bowls");
    puts("[B]uy marimo");
    puts("[S]ell marimo");
    puts("[A]bout");
    puts("[Q]uit");
    printf(">> ");
    return fflush(stdout);
}
