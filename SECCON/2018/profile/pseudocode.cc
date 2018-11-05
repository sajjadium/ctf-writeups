int64_t Profile::update_msg(Profile *this)
{
    int64_t v1; // rax
    int64_t result; // rax
    void *ptr; // [rsp+10h] [rbp-10h]
    size_t v4; // [rsp+18h] [rbp-8h]

    ptr = (void *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::c_str(this);
    v4 = malloc_usable_size(ptr);
    if ( v4 == 0 )
    {
        v1 = std::operator<<<std::char_traits<char >> (&std::cout, "Unable to update message.");
        result = std::ostream::operator<<(v1, &std::endl<char, std::char_traits<char>>);
    }
    else
    {
        std::operator<<<std::char_traits<char >> (&std::cout, "Input new message >> ");
        result = getn((char *)ptr, v4);
    }
    return result;
}

int64_t Profile::show(Profile *this)
{
    int64_t v1; // rax
    int64_t v2; // rax
    unsigned int v3; // ebx
    int64_t v4; // rax
    int64_t v5; // rax
    int64_t v6; // rax
    int64_t v7; // rax

    v1 = std::operator<<<std::char_traits<char >> (&std::cout, "Name : ");
    v2 = std::operator<<<char, std::char_traits<char>, std::allocator<char >> (v1, (int64_t)this + 32);
    std::ostream::operator<<(v2, &std::endl<char, std::char_traits<char>>);
    v3 = *((int *)this + 16);
    v4 = std::operator<<<std::char_traits<char >> (&std::cout, "Age  : ");
    v5 = std::ostream::operator<<(v4, v3);
    std::ostream::operator<<(v5, &std::endl<char, std::char_traits<char>>);
    v6 = std::operator<<<std::char_traits<char >> (&std::cout, "Msg  : ");
    v7 = std::operator<<<char, std::char_traits<char>, std::allocator<char >> (v6, (int64_t)this);
    return std::ostream::operator<<(v7, &std::endl<char, std::char_traits<char>>);
}

int main()
{
    int64_t v3; // rax
    int64_t v4; // rax
    int64_t v5; // rax
    int64_t v6; // rax
    int64_t v7; // rax
    int64_t v8; // rax
    int64_t v9; // rax
    int64_t v10; // rax
    int64_t v11; // rax
    int age_or_option; // [rsp+Ch] [rbp-C4h]
    char v14; // [rsp+10h] [rbp-C0h]
    char name; // [rsp+30h] [rbp-A0h]
    char message; // [rsp+50h] [rbp-80h]
    char profile; // [rsp+70h] [rbp-60h]
    uint64_t v18; // [rsp+B8h] [rbp-18h]

    Profile::Profile((Profile *)&profile, (int64_t)argv);
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::basic_string(
                (int64_t)&v14,
                (int64_t)argv);
    v3 = std::operator<<<std::char_traits<char >> (&std::cout, "Please introduce yourself!");
    std::ostream::operator<<(v3, &std::endl<char, std::char_traits<char>>);
    std::operator<<<std::char_traits<char >> (&std::cout, "Name >> ");
    std::operator>><char, std::char_traits<char>, std::allocator<char>>(&std::cin, &v14);
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::basic_string(&name, &v14);
    Profile::set_name((int64_t)&profile, (int64_t)&name);
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string(&name);
    std::operator<<<std::char_traits<char >> (&std::cout, "Age >> ");
    std::istream::operator>>(&std::cin, &age_or_option);
    Profile::set_age((Profile *)&profile, age_or_option);
    std::operator<<<std::char_traits<char >> (&std::cout, "Message >> ");
    std::operator>><char, std::char_traits<char>, std::allocator<char>>(&std::cin, &v14);
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::basic_string(&message, &v14);
    Profile::set_msg((int64_t)&profile, (int64_t)&message);
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string(&message);
    do
    {
        v4 = std::ostream::operator<<(&std::cout, &std::endl<char, std::char_traits<char>>);
        v5 = std::operator<<<std::char_traits<char >> (v4, "1 : update message");
        v6 = std::ostream::operator<<(v5, &std::endl<char, std::char_traits<char>>);
        v7 = std::operator<<<std::char_traits<char >> (v6, "2 : show profile");
        v8 = std::ostream::operator<<(v7, &std::endl<char, std::char_traits<char>>);
        v9 = std::operator<<<std::char_traits<char >> (v8, "0 : exit");
        v10 = std::ostream::operator<<(v9, &std::endl<char, std::char_traits<char>>);
        std::operator<<<std::char_traits<char >> (v10, ">> ");
        std::istream::operator>>(&std::cin, &age_or_option);
        getchar();
        if ( age_or_option == 1 )
        {
            Profile::update_msg((Profile *)&profile);
        }
        else if ( age_or_option == 2 )
        {
            Profile::show((Profile *)&profile);
        }
        else
        {
            v11 = std::operator<<<std::char_traits<char >> (&std::cout, "Wrong input...");
            std::ostream::operator<<(v11, &std::endl<char, std::char_traits<char>>);
        }
    }
    while ( age_or_option );
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string(&v14);
    Profile::~Profile((Profile *)&profile);
    return 0;
}

int64_t getn(char *a1, unsigned int a2)
{
    char buf; // [rsp+13h] [rbp-Dh]
    unsigned int i; // [rsp+14h] [rbp-Ch]
    uint64_t v5; // [rsp+18h] [rbp-8h]

    for ( i = 0; i < a2; ++i )
    {
        read(0, &buf, 1uLL);
        if ( buf == '\n' )
            break;
        a1[i] = buf;
    }
    return i;
}

int64_t Profile::Profile(Profile *this, int64_t a2)
{
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::basic_string((int64_t)this, a2);
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::basic_string((int64_t)this + 32, a2);
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::operator=(
                (char *)this + 32,
                &unk_401734);
    *((int *)this + 16) = 0;
    return std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::operator=(this, &unk_401734);
}

int64_t Profile::set_name(int64_t a1, int64_t a2)
{
    return std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::operator=(a1 + 32, a2);
}

Profile *Profile::set_age(Profile *this, int a2)
{
    Profile *result; // rax

    result = this;
    *((int *)this + 16) = a2;
    return result;
}

int64_t Profile::set_msg(int64_t a1, int64_t a2)
{
    return std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::operator=(a1, a2);
}

int64_t Profile::~Profile(Profile *this)
{
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((char *)this + 32);
    return std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string(this);
}
