int printNode(int64_t *a1)
{
    return printf("node.next: %p\nnode.buffer: %s\n", *a1, a1 + 1);
}

char *readline(char *a1, size_t a2)
{
    size_t n; // [rsp+10h] [rbp-10h]
    char *lineptr; // [rsp+18h] [rbp-8h]

    lineptr = 0LL;
    getline(&lineptr, &n, stdin);
    return strncpy(a1, lineptr, a2);
}

int goodbye()
{
    char s; // [rsp+Dh] [rbp-3h]

    puts("What are your initials?");
    fgets(&s, 32, stdin);
    return printf("Thanks %s\n", &s);
}

int nononode()
{
    char v1; // [rsp+0h] [rbp-40h]
    int64_t v2; // [rsp+8h] [rbp-38h]
    char *v3; // [rsp+20h] [rbp-20h]
    int64_t v4; // [rsp+28h] [rbp-18h]

    v3 = &v1;
    puts("(15 bytes) Text for node 1:  ");
    readline((char *)&v4, 15uLL);
    puts("(15 bytes) Text for node 2: ");
    readline((char *)&v2, 15uLL);
    puts("node1: ");
    printNode(&v3);
    return goodbye();
}

int main()
{
    setvbuf(stdin, 0LL, 2, 0LL);
    puts("Linked lists are great! \nThey let you chain pieces of data together.\n");
    nononode();
    return 0;
}
