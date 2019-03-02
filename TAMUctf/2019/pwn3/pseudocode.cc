char *echo()
{
    char s; // [esp+Eh] [ebp-12Ah]

    printf("Take this, you might need it on your journey %p!\n", &s);
    return gets(&s);
}

int main()
{
    setvbuf(stdout, (char *)&dword_0 + 2, 0, 0);
    echo();
    return 0;
}
