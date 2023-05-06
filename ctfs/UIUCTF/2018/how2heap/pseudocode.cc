uint64_t line_up(int64_t a1, int64_t a2)
{
    int64_t *parent; // rax
    int64_t parent_age_1; // ST30_8
    int64_t parent_name_1; // ST38_8
    int64_t *first_child; // rax
    int64_t *parent_3; // rcx
    int64_t first_child_name; // rdx
    int64_t *first_child_1; // rcx
    int64_t *parent_1; // rax
    int64_t parent_1_age; // ST30_8
    int64_t parent_1_name; // ST38_8
    int64_t *second_child; // rax
    int64_t *parent_2; // rcx
    int64_t second_child_name; // rdx
    int64_t *second_child_2; // rcx
    int64_t parent_age; // [rsp+18h] [rbp-38h]
    int64_t first_child_age; // [rsp+20h] [rbp-30h]
    int64_t second_child_age; // [rsp+28h] [rbp-28h]
    uint64_t v20; // [rsp+48h] [rbp-8h]

    if ( 2 * a2 <= 15 )
    {
        parent_age = *(int64_t *)(16 * a2 + a1);
        first_child_age = *(int64_t *)(32 * a2 + a1);
        second_child_age = *(int64_t *)(32 * a2 + 16 + a1);
        if ( parent_age >= first_child_age || first_child_age <= second_child_age )
        {
            if ( parent_age < second_child_age )
            {
                parent_1 = (int64_t *)(16 * a2 + a1);
                parent_1_age = *parent_1;
                parent_1_name = parent_1[1];
                second_child = (int64_t *)(32 * a2 + 16 + a1);
                parent_2 = (int64_t *)(a1 + 16 * a2);
                second_child_name = second_child[1];
                *parent_2 = *second_child;
                parent_2[1] = second_child_name;
                second_child_2 = (int64_t *)(32 * a2 + 16 + a1);
                *second_child_2 = parent_1_age;
                second_child_2[1] = parent_1_name;
                line_up(a1, 2 * a2 + 1);
            }
        }
        else
        {
            parent = (int64_t *)(16 * a2 + a1);
            parent_age_1 = *parent;
            parent_name_1 = parent[1];
            first_child = (int64_t *)(32 * a2 + a1);
            parent_3 = (int64_t *)(a1 + 16 * a2);
            first_child_name = first_child[1];
            *parent_3 = *first_child;
            parent_3[1] = first_child_name;
            first_child_1 = (int64_t *)(32 * a2 + a1);
            *first_child_1 = parent_age_1;
            first_child_1[1] = parent_name_1;
            line_up(a1, 2 * a2);
        }
    }
}

uint64_t make_new_character(int64_t *a1)
{
    int64_t *parent; // rax
    int64_t parent_age; // ST30_8
    int64_t parent_name; // ST38_8
    int64_t *child; // rdx
    int64_t *parent2; // rcx
    int64_t child_age; // rax
    int64_t child_name; // rdx
    int64_t *child2; // rcx
    int64_t v10; // [rsp+18h] [rbp-38h]
    int64_t v11; // [rsp+20h] [rbp-30h]
    uint64_t v12; // [rsp+48h] [rbp-8h]

    if ( *a1 <= 14LL )
    {
        v10 = ++*a1;
        printf("What is your character's name? ");
        fflush(stdout);
        __isoc99_scanf("%7s", &a1[2 * v10 + 1]);
        while ( getchar() != 10 )
            ;
        puts(byte_123C);
        while ( 1 )
        {
            printf("What is your character's age? ");
            fflush(stdout);
            v11 = (signed int)__isoc99_scanf("%ld", &a1[2 * v10]);
            while ( getchar() != 10 )
                ;
            puts(byte_123C);
            if ( v11 == 1 )
                break;
            puts("Invalid age.");
        }
        while ( v10 > 1 && a1[2 * (v10 / 2)] < a1[2 * v10] )
        {
            parent = &a1[2 * (v10 / 2)];
            parent_age = *parent;
            parent_name = parent[1];
            child = &a1[2 * v10];
            parent2 = &a1[2 * (v10 / 2)];
            child_age = *child;
            child_name = child[1];
            *parent2 = child_age;
            parent2[1] = child_name;
            child2 = &a1[2 * v10];
            *child2 = parent_age;
            child2[1] = parent_name;
            v10 /= 2LL;
        }
        printf("Character %s created.\n", &a1[2 * v10 + 1]);
        puts("\x1B[3mNot again...\x1B[0m");
    }
    else
    {
        puts("Too many characters.\n");
        puts("\x1B[3mThat was close...\x1B[0m");
    }
}

uint64_t delete_old_character(int64_t *a1)
{
    int64_t age; // ST10_8
    int64_t *lastnode; // rax
    int64_t *oldnode; // rcx
    int64_t lastnode_name; // rdx
    int64_t name; // [rsp+18h] [rbp-18h]
    uint64_t v7; // [rsp+28h] [rbp-8h]

    if ( a1[2] > 0LL )
    {
        age = a1[2];
        name = a1[3];
        lastnode = &a1[2 * *a1];
        oldnode = a1 + 2;
        lastnode_name = lastnode[1];
        *oldnode = *lastnode;
        oldnode[1] = lastnode_name;
        memset(&a1[2 * *a1 + 1], 0, 8uLL);
        --*a1;
        if ( a1[2] > 0LL )
            line_up((int64_t)a1, 1LL);
        printf("%s, the oldest character, has been deleted.\n", &name);
        puts("\x1B[3mGoodbye, cruel world...\x1B[0m");
        puts("\x1B[3mAt least I have extra character slots now.\x1B[0m");
    }
    else
    {
        puts("Nothing happened...");
    }
}

int64_t main(int64_t a1, char **a2, char **a3)
{
    int64_t v3; // rsi
    int i; // [rsp+Ch] [rbp-114h]
    int j; // [rsp+Ch] [rbp-114h]
    int64_t s[33]; // [rsp+10h] [rbp-110h]
    uint64_t v8; // [rsp+118h] [rbp-8h]

    setvbuf(stdout, 0LL, 2, 0LL);
    setvbuf(stdin, 0LL, 2, 0LL);
    v3 = 0LL;
    memset(s, 0, 0x100uLL);
    puts("Help! I've made too many GW2 alts! Can you help me?");
    sleep(1u);
    puts(byte_123C);
    while ( 1 )
    {
        puts("===========================================");
        puts("     GW2 Character Management Interface    ");
        puts("===========================================");
        puts("0. Line up your characters nicely");
        puts("1. Do a head count");
        puts("2. Make a new character");
        puts("3. Delete old characters");
        puts("9. Quit GW2 forever");
        printf("Choice: ", v3);
        fflush(stdout);
        if ( (unsigned __int8)getchar() != 10 )
        {
            while ( getchar() != 10 )
                ;
        }
        puts(byte_123C);
        switch ( (unsigned int)off_14A8 )
        {
        case '0':
            for ( i = 15; i > 0; --i )
            {
                v3 = i;
                line_up((int64_t)s, i);
            }
            puts("\x1B[3mYou feel a vague sense of satisfaction.\x1B[0m");
            break;
        case '1':
            for ( j = 1; j <= 15 && s[2 * j] > 0; ++j )
                ;
            s[0] = j - 1;
            puts("\x1B[3mToo many.\x1B[0m");
            break;
        case '2':
            make_new_character(s);
            break;
        case '3':
            delete_old_character(s);
            break;
        case '9':
            puts("\x1B[3m:(\x1B[0m");
            fflush(stdout);
            return 0LL;
        default:
            break;
        }
        puts(byte_123C);
    }
}
