int main()
{
    void *buf; // ST2C_4

    buf = mmap(0, 256u, 7, 34, -1, 0);
    read(0, buf, 256u);
    mprotect(buf, 256u, 5);
    close(stdin);
    close(stderr);
    close(stdout);
    ((void (*)(void))buf)();
    return 0;
}
