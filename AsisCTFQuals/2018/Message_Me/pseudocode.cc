time_t *msg_list[16];

int menu()
{
    puts("   Message System ");
    puts("---------------------");
    puts("0 : Add a message");
    puts("1 : Remove the message");
    puts("2 : Show the message");
    puts("3 : Change the timestamp");
    return puts("---------------------");
}

uint64_t add()
{
    int i; // [rsp+Ch] [rbp-24h]
    int64_t size; // [rsp+10h] [rbp-20h]
    time_t *message; // [rsp+18h] [rbp-18h]
    void *buf; // [rsp+20h] [rbp-10h]
    uint64_t v5; // [rsp+28h] [rbp-8h]

    printf("Give me the message size : ");
    __isoc99_scanf("%lld", &size);
    if ( size > 16 && size <= 4095 )
    {
        message = (time_t *)malloc(size + 8);
        *message = time(0LL);
        printf("Give me your meesage : ", &size);
        buf = message + 1;
        read(0, message + 1, size - 1);
        *((char *)buf + size - 1) = 0;
        for ( i = 0; i <= 15; ++i )
        {
            if ( !msg_list[i] )
            {
                msg_list[i] = message;
                puts("Done!!");
            }
        }
    }
}

uint64_t remove()
{
    int64_t index; // [rsp+0h] [rbp-10h]
    uint64_t v2; // [rsp+8h] [rbp-8h]

    printf("Give me index of the message : ");
    __isoc99_scanf("%lld", &index);
    if ( index >= 0 && index <= 15 && msg_list[index] )
    {
        free(msg_list[index]);
        puts("Done!!");
    }
}

uint64_t show()
{
    char *v0; // rax
    int64_t index; // [rsp+0h] [rbp-10h]
    uint64_t v3; // [rsp+8h] [rbp-8h]

    printf("Give me index of the message : ");
    __isoc99_scanf("%lld", &index);
    if ( index >= 0 && index <= 15 && msg_list[index] )
    {
        v0 = ctime(msg_list[index]);
        printf("Time : %sMessage : ", v0);
        puts((const char *)msg_list[index] + 8);
    }
}

uint64_t change_time_stamp()
{
    int64_t index; // [rsp+0h] [rbp-10h]
    uint64_t v2; // [rsp+8h] [rbp-8h]

    printf("Give me index of the message : ");
    __isoc99_scanf("%lld", &index);
    *msg_list[index] += rand() % 10;
    puts("Done!!");
}

int main()
{
    int64_t *v3; // rsi
    int64_t v4; // [rsp+0h] [rbp-10h]
    uint64_t v5; // [rsp+8h] [rbp-8h]

    setvbuf(stdout, 0LL, 2, 0LL);
    v3 = 0LL;
    setvbuf(stdin, 0LL, 2, 0LL);
    srand(1u);
    while ( 1 )
    {
        menu();
        printf("choice : ", v3);
        v3 = &v4;
        __isoc99_scanf("%lld", &v4);
        if ( v4 )
        {
            switch ( v4 )
            {
            case 1LL:
                remove();
                break;
            case 2LL:
                show();
                break;
            case 3LL:
                change_time_stamp();
                break;
            default:
                puts("Wrong Choice");
                break;
            }
        }
        else
        {
            add();
        }
    }
}
