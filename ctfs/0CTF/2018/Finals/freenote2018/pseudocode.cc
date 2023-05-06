int notes_count;
int note_table[60];

int read_num()
{
    int64_t buf; // [rsp+10h] [rbp-10h]
    uint64_t v2; // [rsp+18h] [rbp-8h]

    buf = 0LL;
    read(0, &buf, 8uLL);
    return atoi((const char *)&buf);
}

int64_t show_banner()
{
    puts("Welcome to 0ctf 2018 finals\nhere you can");
    return 0LL;
}

int show_menu()
{
    puts("1. init a note");
    puts("2. edit a note");
    puts("3. free a note");
    puts("4. show a note");
    puts("5. exit");
    printf("Choice:");
    return read_num();
}

signed int64_t init_note()
{
    int64_t result; // rax
    unsigned int v1; // [rsp+Ch] [rbp-124h]
    unsigned int size; // [rsp+10h] [rbp-120h]
    int len; // [rsp+14h] [rbp-11Ch]
    void *new_note; // [rsp+18h] [rbp-118h]
    char buf; // [rsp+20h] [rbp-110h]
    uint64_t v6; // [rsp+128h] [rbp-8h]

    v1 = 0;
    if ( (unsigned int)notes_count <= 15 )
    {
        printf("Input the note length:");
        len = read_num();
        if ( len > 0 && len <= 256 )
        {
            printf("Input the note content:");
            size = read(0, &buf, 255uLL);
            if ( size > len )
                size = len;
            new_note = malloc(len + 8);
            if ( new_note && size )
                memcpy(new_note, &buf, size - 1);
            while ( note_table[4 * v1] )
                ++v1;
            *((int64_t *)&unk_202040 + 2 * (signed int)v1) = new_note;
            note_table[4 * v1] = len;
            ++notes_count;
            printf("Here is your label: %d\n", v1);
            puts("Done~!");
            result = 0LL;
        }
        else
        {
            puts("Not allow~!");
            result = 1LL;
        }
    }
    else
    {
        puts("Not allow~!");
        result = 1LL;
    }
    return result;
}

signed int64_t edit_note()
{
    int64_t result; // rax
    int v1; // [rsp+8h] [rbp-8h]

    printf("Input the note index:");
    v1 = read_num();
    if ( v1 >= 0 && v1 <= 16 )
    {
        if ( note_table[4 * v1] )
        {
            printf("Input the note content:");
            read(0, *((void **)&unk_202040 + 2 * v1), (unsigned int)note_table[4 * v1]);
            puts("Done~!");
            result = 0LL;
        }
        else
        {
            puts("Not allow~!");
            result = 1LL;
        }
    }
    else
    {
        puts("Not allow~!");
        result = 1LL;
    }
    return result;
}

signed int64_t free_note()
{
    int64_t result; // rax
    int v1; // [rsp+Ch] [rbp-4h]

    printf("Input the note index:");
    v1 = read_num();
    if ( v1 >= 0 && v1 <= 16 )
    {
        if ( note_table[4 * v1] )
        {
            free(*((void **)&unk_202040 + 2 * v1));
            puts("Done~!");
            result = 0LL;
        }
        else
        {
            puts("Not allow~!");
            result = 1LL;
        }
    }
    else
    {
        puts("Not allow~!");
        result = 1LL;
    }
    return result;
}

int view_note()
{
    return puts("Not allow~!");
}

void quit()
{
    puts("Bye~!");
    exit(0);
}

void main(int64_t a1, char **a2, char **a3)
{
    int64_t savedregs; // [rsp+30h] [rbp+0h]

    setvbuf(stdout, 0LL, 2, 0LL);
    setvbuf(stdin, 0LL, 2, 0LL);
    alarm(0x1Eu);
    show_banner();
    while ( 1 )
    {
        switch (show_menu())
        {
        case 1u:
            init_note();
            break;
        case 2u:
            edit_note();
            break;
        case 3u:
            free_note();
            break;
        case 4u:
            view_note();
            break;
        case 5u:
            quit();
            return;
        default:
            puts("Invalid input\n");
            break;
        }
    }
}
