ssize_t read_data()
{
    char buf; // [esp+0h] [ebp-28h]

    return read(0, &buf, 0x40u);
}

int main()
{
    alarm(0xAu);
    read_data();
    return 0;
}
