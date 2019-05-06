int64_t main(int64_t a1, char **a2, char **a3)
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
    int64_t v12; // rax
    int64_t v13; // rax
    int64_t v14; // rax
    int64_t v15; // rax
    int64_t v16; // rax
    int64_t v17; // rax
    int64_t v18; // rax
    int64_t v19; // rax
    int64_t v20; // rax
    int64_t v21; // rax
    int v23; // [rsp+4h] [rbp-BCh]
    int v24; // [rsp+8h] [rbp-B8h]
    int v25; // [rsp+Ch] [rbp-B4h]
    char buf; // [rsp+10h] [rbp-B0h]
    uint64_t v27; // [rsp+B8h] [rbp-8h]

    setvbuf(stdout, 0LL, 2, 0LL);
    setvbuf(stdin, 0LL, 2, 0LL);
    v23 = 0;
    v24 = 1;
    v25 = 0;
    while ( v24 )
    {
        v3 = std::operator<<<std::char_traits<char >> (&std::cout, "-------------------------");
        std::ostream::operator<<(v3, &std::endl<char, std::char_traits<char>>);
        v4 = std::operator<<<std::char_traits<char >> (&std::cout, "[*]SCV GOOD TO GO,SIR....");
        std::ostream::operator<<(v4, &std::endl<char, std::char_traits<char>>);
        v5 = std::operator<<<std::char_traits<char >> (&std::cout, "-------------------------");
        std::ostream::operator<<(v5, &std::endl<char, std::char_traits<char>>);
        v6 = std::operator<<<std::char_traits<char >> (&std::cout, "1.FEED SCV....");
        std::ostream::operator<<(v6, &std::endl<char, std::char_traits<char>>);
        v7 = std::operator<<<std::char_traits<char >> (&std::cout, "2.REVIEW THE FOOD....");
        std::ostream::operator<<(v7, &std::endl<char, std::char_traits<char>>);
        v8 = std::operator<<<std::char_traits<char >> (&std::cout, "3.MINE MINERALS....");
        std::ostream::operator<<(v8, &std::endl<char, std::char_traits<char>>);
        v9 = std::operator<<<std::char_traits<char >> (&std::cout, "-------------------------");
        std::ostream::operator<<(v9, &std::endl<char, std::char_traits<char>>);
        std::operator<<<std::char_traits<char >> (&std::cout, ">>");
        std::istream::operator>>(&std::cin, &v23);
        switch ( v23 )
        {
        case 2:
            v15 = std::operator<<<std::char_traits<char >> (&std::cout, "-------------------------");
            std::ostream::operator<<(v15, &std::endl<char, std::char_traits<char>>);
            v16 = std::operator<<<std::char_traits<char >> (&std::cout, "[*]REVIEW THE FOOD...........");
            std::ostream::operator<<(v16, &std::endl<char, std::char_traits<char>>);
            v17 = std::operator<<<std::char_traits<char >> (&std::cout, "-------------------------");
            std::ostream::operator<<(v17, &std::endl<char, std::char_traits<char>>);
            v18 = std::operator<<<std::char_traits<char >> (&std::cout, "[*]PLEASE TREAT HIM WELL.....");
            std::ostream::operator<<(v18, &std::endl<char, std::char_traits<char>>);
            v19 = std::operator<<<std::char_traits<char >> (&std::cout, "-------------------------");
            std::ostream::operator<<(v19, &std::endl<char, std::char_traits<char>>);
            puts(&buf);
            break;
        case 3:
            v24 = 0;
            v20 = std::operator<<<std::char_traits<char >> (&std::cout, "[*]BYE ~ TIME TO MINE MIENRALS...");
            std::ostream::operator<<(v20, &std::endl<char, std::char_traits<char>>);
            break;
        case 1:
            v10 = std::operator<<<std::char_traits<char >> (&std::cout, "-------------------------");
            std::ostream::operator<<(v10, &std::endl<char, std::char_traits<char>>);
            v11 = std::operator<<<std::char_traits<char >> (&std::cout, "[*]SCV IS ALWAYS HUNGRY.....");
            std::ostream::operator<<(v11, &std::endl<char, std::char_traits<char>>);
            v12 = std::operator<<<std::char_traits<char >> (&std::cout, "-------------------------");
            std::ostream::operator<<(v12, &std::endl<char, std::char_traits<char>>);
            v13 = std::operator<<<std::char_traits<char >> (&std::cout, "[*]GIVE HIM SOME FOOD.......");
            std::ostream::operator<<(v13, &std::endl<char, std::char_traits<char>>);
            v14 = std::operator<<<std::char_traits<char >> (&std::cout, "-------------------------");
            std::ostream::operator<<(v14, &std::endl<char, std::char_traits<char>>);
            std::operator<<<std::char_traits<char >> (&std::cout, ">>");
            v25 = read(0, &buf, 0xF8uLL);
            break;
        default:
            v21 = std::operator<<<std::char_traits<char >> (&std::cout, "[*]DO NOT HURT MY SCV....");
            std::ostream::operator<<(v21, &std::endl<char, std::char_traits<char>>);
            break;
        }
    }
    return 0LL;
}
