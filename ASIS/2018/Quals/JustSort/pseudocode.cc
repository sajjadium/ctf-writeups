int64_t record_table[10];

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
        " | |  | |         | |                        | |                                   \n"
        " | |__| | __ _ ___| |__ ______ ___  ___  _ __| |_   _ __ ___   ___ _ __ ___   ___  \n"
        " |  __  |/ _` / __| '_ \\______/ __|/ _ \\| '__| __| | '_ ` _ \\ / _ \\ '_ ` _ \\ / _ \\ \n"
        " | |  | | (_| \\__ \\ | | |     \\__ \\ (_) | |  | |_  | | | | | |  __/ | | | | | (_) |\n"
        " |_|  |_|\\__,_|___/_| |_|     |___/\\___/|_|   \\__| |_| |_| |_|\\___|_| |_| |_|\\___/ \n"
        "                                                                                  ");
    return putchar(10);
}

signed int64_t insert_record()
{
    int len; // eax
    int64_t result; // rax
    int64_t v2; // [rsp+0h] [rbp-50h]
    int64_t pos; // [rsp+0h] [rbp-50h]
    int64_t *entry; // [rsp+8h] [rbp-48h]
    uint64_t hash_id; // [rsp+10h] [rbp-40h]
    void *ptr; // [rsp+18h] [rbp-38h]
    char *record; // [rsp+20h] [rbp-30h]
    size_t size; // [rsp+28h] [rbp-28h]
    char *v9; // [rsp+38h] [rbp-18h]
    char buf; // [rsp+40h] [rbp-10h]
    uint64_t v11; // [rsp+48h] [rbp-8h]

    printf("how many charactors will you store? (0<=len<=100)\n> ", 0LL, 0LL, -1LL, 0LL, 0LL, 0LL);
    read(0, &buf, 4uLL);
    len = atoi(&buf);
    size = len;
    if ( len && (uint64_t)len <= 100 )
    {
        record = (char *)malloc(len);
        if ( !record )
        {
            puts("Can't allocate mamory");
            exit(0);
        }
        printf("Please input memo\n> ", &buf);
        read(0, record, size);
        v9 = strchr(record, 10);
        if ( v9 )
            *v9 = 0;
        ptr = malloc(24uLL);
        if ( !ptr )
        {
            puts("Can't allocate mamory");
            exit(0);
        }
        *((int64_t *)ptr + 1) = record;
        *((int64_t *)ptr + 2) = size;
        *(int64_t *)ptr = 0LL;
        hash_id = (uint64_t)(0xCCCCCCCCCCCCCCCDLL * (unsigned __int128)size >> 64) >> 3;
        if ( record_table[hash_id] )
        {
            entry = (int64_t *)record_table[hash_id];
            pos = 1LL;
            while ( *entry )
            {
                entry = (int64_t *)*entry;
                if ( (uint64_t)++pos > 5 )
                {
                    free(*((void **)ptr + 1));
                    free(ptr);
                    puts("already fulled");
                    return 0LL;
                }
            }
            *entry = ptr;
            printf("Inserted record at hash_id:%lu, pos:%lu\n", hash_id, pos, pos);
            result = 0LL;
        }
        else
        {
            record_table[hash_id] = (int64_t)ptr;
            printf("Inserted record at hash_id:%lu, pos:%lu\n", hash_id, v2);
            result = 0xFFFFFFFFLL;
        }
    }
    else
    {
        puts("Unacceptable number");
        result = 0LL;
    }
    return result;
}

int64_t print_record()
{
    int i; // [rsp+Ch] [rbp-14h]
    int64_t num; // [rsp+10h] [rbp-10h]
    int64_t *ptr; // [rsp+18h] [rbp-8h]

    for ( i = 0; i <= 9; ++i )
    {
        num = 0LL;
        printf("hash_id:%u\n", (unsigned int)i);
        ptr = (int64_t *)record_table[i];
        while ( ptr )
        {
            printf("    %lu: \"%s\"\n", num, ptr[1]);
            ptr = (int64_t *)*ptr;
            ++num;
        }
    }
    return 0LL;
}

signed int64_t edit_record()
{
    int64_t result; // rax
    char *record; // [rsp+8h] [rbp-78h]
    uint64_t pos; // [rsp+10h] [rbp-70h]
    int64_t ptr; // [rsp+18h] [rbp-68h]
    size_t size; // [rsp+20h] [rbp-60h]
    uint64_t hash_id; // [rsp+28h] [rbp-58h]
    char *v6; // [rsp+38h] [rbp-48h]
    char buf; // [rsp+40h] [rbp-40h]
    uint64_t v8; // [rsp+78h] [rbp-8h]

    printf("which hash number?\n> ");
    read(0, &buf, 4uLL);
    hash_id = atoi(&buf);
    if ( hash_id <= 9 )
    {
        printf("which position number?\n> ", &buf);
        read(0, &buf, 4uLL);
        pos = atoi(&buf);
        if ( pos <= 5 )
        {
            if ( record_table[hash_id] )
            {
                ptr = record_table[hash_id];
                while ( ptr && pos )
                {
                    ptr = *(int64_t *)ptr;
                    --pos;
                }
                if ( ptr )
                {
                    size = strlen(*(const char **)(ptr + 8));
                    if ( *(int64_t *)(ptr + 16) >= size )
                    {
                        record = *(char **)(ptr + 8);
                        if ( !record )
                        {
                            puts("any mistake?");
                            exit(0);
                        }
                    }
                    printf("You can write %lu characters, Please input memo\n> ", *(int64_t *)(ptr + 16));
                    read(0, record, *(int64_t *)(ptr + 16));
                    v6 = strchr(record, 10);
                    if ( v6 )
                        *v6 = 0;
                    printf("update_len %lu, current_record->value %lu\n", size, *(int64_t *)(ptr + 16));
                    result = 0xFFFFFFFFLL;
                }
                else
                {
                    puts("There is no record");
                    result = 1LL;
                }
            }
            else
            {
                puts("There is no record");
                result = 1LL;
            }
        }
        else
        {
            puts("Unacceptable number");
            result = 0LL;
        }
    }
    else
    {
        puts("Unacceptable number");
        result = 0LL;
    }
    return result;
}

int64_t search_record()
{
    int len; // eax
    int64_t result; // rax
    int64_t pos; // [rsp+0h] [rbp-80h]
    int64_t entry; // [rsp+8h] [rbp-78h]
    char *record; // [rsp+10h] [rbp-70h]
    size_t size; // [rsp+18h] [rbp-68h]
    uint64_t hash_id; // [rsp+20h] [rbp-60h]
    char *v7; // [rsp+28h] [rbp-58h]
    char buf; // [rsp+30h] [rbp-50h]
    uint64_t v9; // [rsp+78h] [rbp-8h]

    printf("How many charactors does search word have? (0<=len<=100)\n> ", 0LL, 0LL, 0LL, 0LL, -1LL);
    read(0, &buf, 4uLL);
    len = atoi(&buf);
    size = len;
    if ( len && (uint64_t)len <= 100 )
    {
        record = (char *)malloc(len);
        if ( !record )
        {
            puts("Can't allocate mamory");
            exit(0);
        }
        printf("which value do you looking for?\n> ", &buf);
        read(0, record, 100uLL);
        v7 = strchr(record, 10);
        if ( v7 )
            *v7 = 0;
        pos = 0LL;
        hash_id = (uint64_t)(0xCCCCCCCCCCCCCCCDLL * (unsigned __int128)size >> 64) >> 3;
        entry = record_table[hash_id];
        while ( strcmp(record, *(const char **)(entry + 8)) )
        {
            entry = *(int64_t *)entry;
            if ( !entry )
                goto LABEL_14;
            ++pos;
        }
        printf("Find word at hash_id:%lu, pos:%lu\n", hash_id, pos, pos);
LABEL_14:
        free(record);
        result = 0LL;
    }
    else
    {
        puts("Unacceptable number");
        result = 0LL;
    }
    return result;
}

signed int64_t delete_record()
{
    int64_t result; // rax
    void **ptr_1; // ST08_8
    uint64_t pos; // [rsp+0h] [rbp-60h]
    void *ptr; // [rsp+8h] [rbp-58h]
    int64_t *prev_ptr; // [rsp+10h] [rbp-50h]
    uint64_t hash_id; // [rsp+18h] [rbp-48h]
    char buf; // [rsp+20h] [rbp-40h]
    uint64_t v7; // [rsp+58h] [rbp-8h]

    prev_ptr = 0LL;
    printf("which hash number?\n> ", 0LL, 0LL);
    read(0, &buf, 4uLL);
    hash_id = atoi(&buf);
    if ( hash_id <= 9 )
    {
        printf("which position number?\n> ", &buf);
        read(0, &buf, 4uLL);
        pos = atoi(&buf);
        if ( pos <= 5 )
        {
            if ( record_table[hash_id] )
            {
                if ( pos )
                {
                    ptr = (void *)record_table[hash_id];
                    while ( ptr && pos )
                    {
                        prev_ptr = ptr;
                        ptr = *(void **)ptr;
                        if ( !ptr )
                        {
                            puts("There is no record");
                            return 1LL;
                        }
                        --pos;
                    }
                    *prev_ptr = *(int64_t *)ptr;
                    free(*((void **)ptr + 1));
                    free(ptr);
                    printf("delete record at hash_id:%lu, pos:%lu\n", hash_id, pos, pos);
                    result = 0LL;
                }
                else
                {
                    ptr_1 = (void **)record_table[hash_id];
                    record_table[hash_id] = (int64_t) * ptr_1;
                    free(ptr_1[1]);
                    free(ptr_1);
                    printf("delete record at hash_id:%lu, pos:%lu\n", hash_id, 0LL, 0LL);
                    result = 0LL;
                }
            }
            else
            {
                puts("There is no record");
                result = 1LL;
            }
        }
        else
        {
            puts("Unacceptable number");
            result = 0LL;
        }
    }
    else
    {
        puts("Unacceptable number");
        result = 0LL;
    }
    return result;
}

int64_t main(int64_t a1, char **a2, char **a3)
{
    int v4; // [rsp+8h] [rbp-18h]
    char buf; // [rsp+10h] [rbp-10h]
    uint64_t v6; // [rsp+18h] [rbp-8h]

    initialize();
    print_banner();
    v4 = 1;
    while ( v4 )
    {
        printf(
            "------------------------------------------------\n"
            " 1: insert record\n"
            " 2: edit record\n"
            " 3: print record\n"
            " 4: search record\n"
            " 5: delete record\n"
            " 6: exit\n"
            "------------------------------------------------\n"
            "which command?\n"
            "> ");
        read(0, &buf, 4uLL);
        switch ( atoi(&buf) )
        {
        case 1:
            insert_record();
            break;
        case 2:
            edit_record();
            break;
        case 3:
            print_record();
            break;
        case 4:
            search_record();
            break;
        case 5:
            delete_record();
            break;
        case 6:
            v4 = 0;
            break;
        default:
            puts("Invalid command!");
            break;
        }
    }
    return 0LL;
}
