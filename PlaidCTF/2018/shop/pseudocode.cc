int64_t checkedout_items[32];
int64_t shop_name;
int items_count;
int64_t item_list;
FILE *stream;

char *ReadString(char *a1, int a2)
{
    int v2; // eax
    char *result; // rax
    int v4; // [rsp+1Ch] [rbp-4h]

    if ( !fgets(a1, a2, stdin) )
    {
        puts("Couldn't read input.");
        exit(1);
    }
    v2 = strlen(a1);
    v4 = v2;
    result = (char *)(unsigned __int8)a1[v2 - 1];
    if ( (char)result == '\n' )
    {
        result = &a1[v4 - 1];
        *result = 0;
    }
    return result;
}

uint64_t InsertRandomWord(int64_t a1)
{
    int i; // [rsp+1Ch] [rbp-14h]
    char ptr[8]; // [rsp+20h] [rbp-10h]
    uint64_t v4; // [rsp+28h] [rbp-8h]

    if ( fread(ptr, 1uLL, 2uLL, stream) <= 1 )
    {
        puts("Couldn't read random bytes.");
        exit(1);
    }
    for ( i = 0; i <= 1; ++i )
    {
        *(char *)(a1 + 2 * i + 8) = byte_602090[ptr[i] & 0xF];
        *(char *)(a1 + 2 * i + 1 + 8) = byte_602090[(unsigned __int8)ptr[i] >> 4];
    }
}

uint64_t AddItem()
{
    char *new_item; // [rsp+8h] [rbp-28h]
    char v2; // [rsp+10h] [rbp-20h]
    uint64_t v3; // [rsp+28h] [rbp-8h]

    if ( items_count <= 32 )
    {
        new_item = (char *)malloc(304uLL);
        if ( !new_item )
        {
            puts("Couldn't allocate item.");
            exit(1);
        }
        ReadString(new_item + 12, 32);
        ReadString(new_item + 44, 256);
        ReadString(&v2, 10);
        if ( (signed int)__isoc99_sscanf(&v2, "%f", new_item + 300) <= 0 )
        {
            puts("Couldn't parse price.");
            exit(1);
        }
        InsertRandomWord((int64_t)new_item);
        *(int64_t *)new_item = item_list;
        item_list = (int64_t)new_item;
        ++items_count;
    }
    else
    {
        printf("Too many items.");
    }
}

uint64_t CheckoutItems()
{
    int v0; // eax
    int v2; // [rsp+Ch] [rbp-10024h]
    float v3; // [rsp+10h] [rbp-10020h]
    int i; // [rsp+14h] [rbp-1001Ch]
    int64_t *item; // [rsp+18h] [rbp-10018h]
    char haystack; // [rsp+20h] [rbp-10010h]
    uint64_t v7; // [rsp+10028h] [rbp-8h]

    ReadString(&haystack, 65540);
    item = (int64_t *)item_list;
    v2 = 0;
    while ( item )
    {
        if ( (unsigned int)memmem(&haystack, 65540uLL, item + 1, 4uLL) )
        {
            v0 = v2++;
            checkedout_items[v0] = (int64_t)item;
        }
        item = (int64_t *)*item;
    }
    v3 = 0.0;
    printf("%s Checkout in process...\n", shop_name);
    for ( i = 0; i < v2; ++i )
    {
        printf("\tBuying %s for $%.2f\n", checkedout_items[i] + 12, *(float *)(checkedout_items[i] + 300));
        v3 = *(float *)(checkedout_items[i] + 300) + v3;
    }
    printf("TOTAL: $%.2f\n", v3);
}

int64_t PrintItems()
{
    int64_t result; // rax
    int64_t item; // [rsp+8h] [rbp-8h]

    result = item_list;
    for ( item = item_list; item; item = *(int64_t *)item )
    {
        printf("%s: $%.2f - %s\n", item + 12, item + 44, *(float *)(item + 300));
        result = *(int64_t *)item;
    }
    return result;
}

char *GetShopName()
{
    if ( !shop_name )
        shop_name = (int64_t)malloc(304uLL);
    printf("Enter your shop name:");
    return ReadString((char *)shop_name, 304);
}

void main(int64_t a1, char **a2, char **a3)
{
    const char *v3; // rsi
    char **v4; // [rsp+0h] [rbp-20h]
    char v5; // [rsp+10h] [rbp-10h]
    uint64_t v6; // [rsp+18h] [rbp-8h]

    v4 = a2;
    setbuf(stdout, 0LL);
    v3 = "r";
    stream = fopen("/dev/urandom", "r");
    if ( !stream )
    {
        puts("Couldn't open urandom.");
        exit(1);
    }
    GetShopName();
    while ( 1 )
    {
        while ( 1 )
        {
            printf("> ", v3, v4);
            v3 = (const char *)3;
            ReadString(&v5, 3);
            if ( v5 != 'c' )
                break;
            CheckoutItems();
        }
        if ( v5 > 'c' )
        {
            if ( v5 == 'l' )
            {
                PrintItems();
            }
            else if ( v5 == 'n' )
            {
                GetShopName();
            }
            else
            {
LABEL_16:
                puts("Command not recognized.");
            }
        }
        else
        {
            if ( v5 != 'a' )
                goto LABEL_16;
            AddItem();
        }
    }
}

