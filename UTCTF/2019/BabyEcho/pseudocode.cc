int main()
{
  char s; // [esp+1Ah] [ebp-3Eh]
  unsigned int v4; // [esp+4Ch] [ebp-Ch]

  v4 = __readgsdword(0x14u);
  setbuf(stdin, 0);
  setbuf(stdout, 0);
  puts("Give me a string to echo back.");
  fgets(&s, 0x32, stdin);
  printf(&s);
  exit(0);
}
