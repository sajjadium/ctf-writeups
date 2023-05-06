int check_password(int client_sockfd)
{
    char *v1; // rbx
    char newliner; // [rsp+Fh] [rbp-79h]
    char pwbuffer[64]; // [rsp+10h] [rbp-78h]
    uint64_t v5; // [rsp+58h] [rbp-30h]

    dprintf(client_sockfd, "Please enter the correct password to get my secret ltc info\nPassword:");
    v1 = pwbuffer;
    for ( newliner = 0; read(client_sockfd, &newliner, 1uLL) && newliner != 10; *v1++ = newliner )
        ;
    return memcmp(pwbuffer, "INTERNET_FUNNY_MUNNY", 0x15uLL) == 0;
}

int main()
{
    int v3; // ebx
    int v4; // ebp
    int client_len; // [rsp+8h] [rbp-60h]
    int reuseon; // [rsp+Ch] [rbp-5Ch]
    sockaddr_in server_address; // [rsp+10h] [rbp-58h]
    sockaddr_in client_address; // [rsp+20h] [rbp-48h]
    uint64_t v9; // [rsp+38h] [rbp-30h]

    v3 = socket(2, 1, 0);
    *(int64_t *)&server_address.sin_family = 0x697A0002LL;
    reuseon = 1;
    if ( setsockopt(v3, 1, 2, &reuseon, 4u) >= 0 )
    {
        if ( bind(v3, (const struct sockaddr *)&server_address, 0x10u) )
        {
            puts("Unable to bind");
            exit(1);
        }
        if ( !listen(v3, 5) )
        {
            signal(17, 1);
            while ( 1 )
            {
                puts("server waiting");
                client_len = 16;
                v4 = accept(v3, (struct sockaddr *)&client_address, (socklen_t *)&client_len);
                puts("accepted client");
                if ( !fork() )
                    break;
                close(v4);
            }
            close(v3);
            if ( check_password(v4) )
                dprintf(v4, "You got the password right!\nMy litecoin address is %s", "LNpECGn9in6BGC8eaK87QawjzAXaWMht2b");
            else
                dprintf(v4, "You failed to get a correct password!\n");
            close(v4);
            exit(0);
        }
        puts("Unable to listen");
        exit(2);
    }
    puts("Unable to set reusable?");
    exit(1);
}
