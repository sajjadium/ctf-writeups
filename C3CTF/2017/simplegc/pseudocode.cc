void *user_list[96];
void *group_list[96];

char *read_string(int64_t a1, uint64_t a2)
{
    char *result; // rax
    uint64_t v3; // [rsp+18h] [rbp-8h]

    v3 = 0LL;
    do
    {
        if ( read(0, (void *)(a1 + v3), 1uLL) == -1 )
            exit(1);
        if ( *(char *)(a1 + v3) == 10 )
        {
            result = (char *)(a1 + v3);
            *(char *)(a1 + v3) = 0;
            return result;
        }
        ++v3;
    }
    while ( v3 < a2 );
    result = (char *)(v3 - 1 + a1);
    *result = 0;
    return result;
}

void *find_group(const char *group_name)
{
    unsigned __int16 i; // [rsp+1Eh] [rbp-2h]

    for ( i = 0; i <= 95u; ++i )
    {
        if ( group_list[i] && !strcmp(group_name, *(const char **)group_list[i]) && *((char *)group_list[i] + 8) )
        {
            ++*((char *)group_list[i] + 8);
            return group_list[i];
        }
    }
    return 0LL;
}

char *new_group(const void *group_name)
{
    void *new_group_name; // ST10_8
    char *group; // rax
    char *group_1; // ST18_8

    new_group_name = malloc(24uLL);
    group = malloc(16uLL);
    group_1 = group;
    group[8] = 1;
    *(int64_t *)group = new_group_name;
    memcpy(*(void **)group, group_name, 24uLL);
    return group_1;
}

void *add_group(int64_t group_name)
{
    unsigned __int16 i; // [rsp+1Eh] [rbp-12h]

    for ( i = 0; i <= 95u && group_list[i]; ++i )
        ;
    if ( i > 95u )
        exit(1);
    group_list[i] = new_group((const void *)group_name);
    return group_list[i];
}

uint64_t add_user()
{
    unsigned int user_name_len; // ST14_4
    int64_t *user; // rbx
    unsigned __int16 i; // [rsp+Eh] [rbp-162h]
    char age; // [rsp+10h] [rbp-160h]
    int64_t *group; // [rsp+18h] [rbp-158h]
    char age_buf; // [rsp+20h] [rbp-150h]
    char group_name; // [rsp+30h] [rbp-140h]
    char user_name; // [rsp+50h] [rbp-120h]
    uint64_t v9; // [rsp+158h] [rbp-18h]

    memset(&user_name, 0, 256uLL);
    memset(&age_buf, 0, 8uLL);
    memset(&group_name, 0, 24uLL);
    printf("Please enter the user's name: ", 0LL);
    read_string((int64_t)&user_name, 192uLL);
    printf("Please enter the user's group: ", 192LL);
    read_string((int64_t)&group_name, 24uLL);
    printf("Please enter your age: ", 24LL);
    read_string((int64_t)&age_buf, 4uLL);
    age = atoi(&age_buf);
    group = find_group(&group_name);
    if ( !group )
        group = add_group((int64_t)&group_name);
    for ( i = 0; i <= 95u && user_list[i]; ++i )
        ;
    if ( i > 95u )
    {
        puts("User database full");
        exit(1);
    }
    user_list[i] = malloc(24uLL);
    *((int64_t *)user_list[i] + 2) = *group;
    *(char *)user_list[i] = age;
    user_name_len = strlen(&user_name) + 1;
    user = user_list[i];
    user[1] = malloc(user_name_len);
    memcpy(*((void **)user_list[i] + 1), &user_name, user_name_len);
    puts("User created");
}

int print_user(unsigned __int8 *user)
{
    return printf("User:\n\tName: %s\n\tGroup: %s\n\tAge: %u\n", *((int64_t *)user + 1), *((int64_t *)user + 2), *user);
}

uint64_t display_user()
{
    unsigned int index; // [rsp+Ch] [rbp-14h]
    char buf; // [rsp+10h] [rbp-10h]
    uint64_t v3; // [rsp+18h] [rbp-8h]

    printf("Enter index: ");
    read_string((int64_t)&buf, 4uLL);
    index = atoi(&buf);
    if ( index <= 95 )
    {
        if ( user_list[index] )
            print_user((unsigned __int8 *)user_list[index]);
        else
            printf("No users at %u\n", index);
    }
    else
    {
        puts("invalid index");
    }
}

uint64_t display_group()
{
    unsigned int i; // [rsp+Ch] [rbp-34h]
    char group_name; // [rsp+10h] [rbp-30h]
    uint64_t v3; // [rsp+38h] [rbp-8h]

    printf("Enter group name: ");
    read_string((int64_t)&group_name, 24uLL);
    for ( i = 0; i <= 95; ++i )
    {
        if ( user_list[i] && !strcmp(&group_name, *((const char **)user_list[i] + 2)) )
            print_user((unsigned __int8 *)user_list[i]);
    }
}

void remove_one_user_from_group(const char *group_name)
{
    unsigned __int16 i; // [rsp+1Eh] [rbp-2h]

    for ( i = 0; i <= 95u; ++i )
    {
        if ( group_list[i] && !strcmp(group_name, *(const char **)group_list[i]) )
        {
            if ( *((char *)group_list[i] + 8) )
                --*((char *)group_list[i] + 8);
        }
    }
}

uint64_t delete_user()
{
    unsigned int index; // [rsp+Ch] [rbp-14h]
    char buf; // [rsp+10h] [rbp-10h]
    uint64_t v3; // [rsp+18h] [rbp-8h]

    printf("Enter index: ");
    read_string((int64_t)&buf, 4uLL);
    index = atoi(&buf);
    if ( index <= 95 )
    {
        if ( user_list[index] )
        {
            remove_one_user_from_group(*((const char **)user_list[index] + 2));
            free(user_list[index]);
            user_list[index] = 0LL;
        }
    }
    else
    {
        puts("invalid index");
    }
}

void delete_empty_groups(void *a1)
{
    unsigned int i; // [rsp+18h] [rbp-8h]

    sleep(1u);
    while ( 1 )
    {
        for ( i = 0; i <= 95; ++i )
        {
            if ( group_list[i] )
            {
                if ( !*((char *)group_list[i] + 8) )
                {
                    free(*(void **)group_list[i]);
                    free(group_list[i]);
                    group_list[i] = 0LL;
                }
            }
        }
        sleep(0);
    }
}

uint64_t edit_group()
{
    int index; // [rsp+Ch] [rbp-54h]
    int64_t *group; // [rsp+10h] [rbp-50h]
    char buf; // [rsp+20h] [rbp-40h]
    char group_name; // [rsp+30h] [rbp-30h]
    uint64_t v5; // [rsp+58h] [rbp-8h]

    printf("Enter index: ");
    read_string((int64_t)&buf, 4uLL);
    index = atoi(&buf);
    if ( user_list[index] )
    {
        printf(
            "Would you like to propagate the change, this will update the group of all the users sharing this group(y/n): ",
            4LL);
        read_string((int64_t)&buf, 2uLL);
        printf("Enter new group name: ", 2LL);
        if ( buf == 'y' )
        {
            read_string(*((int64_t *)user_list[index] + 2), 24uLL);
        }
        else
        {
            read_string((int64_t)&group_name, 24uLL);
            group = find_group(&group_name);
            if ( group )
                *((int64_t *)user_list[index] + 2) = *group;
            else
                *((int64_t *)user_list[index] + 2) = *(int64_t *)add_group((int64_t)&group_name);
        }
    }
}

void main(int64_t a1, char **a2, char **a3)
{
    int *v3; // rsi
    int v4; // [rsp+Ch] [rbp-14h]
    pthread_t newthread; // [rsp+10h] [rbp-10h]
    uint64_t v6; // [rsp+18h] [rbp-8h]

    setvbuf(stdin, 0LL, 2, 0LL);
    setvbuf(stdout, 0LL, 2, 0LL);
    alarm(160u);
    v3 = 0LL;
    pthread_create(&newthread, 0LL, (void *(*)(void *))delete_empty_groups, 0LL);
    while ( 1 )
    {
        puts("0: Add a user");
        puts("1: Display a group");
        puts("2: Display a user");
        puts("3: Edit a group");
        puts("4: Delete a user");
        puts("5: Exit");
        printf("Action: ", v3);
        v3 = &v4;
        if ( (unsigned int)__isoc99_scanf("%d", &v4) == -1 )
            break;
        if ( !v4 )
            add_user();
        if ( v4 == 1 )
            display_group();
        if ( v4 == 2 )
            display_user();
        if ( v4 == 3 )
            edit_group();
        if ( v4 == 4 )
            delete_user();
        if ( v4 == 5 )
        {
            puts("Bye");
            exit(0);
        }
    }
    exit(1);
}
