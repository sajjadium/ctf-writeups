int64_t _malloc_hook;
int64_t _free_hook;
int64_t saved_malloc_hook;
int64_t saved_free_hook;
int64_t alien_index;
int64_t samurai_index;
int64_t aliens[200];
char swords[1600];
int64_t samurais[200];

uint64_t new_alien()
{
    void **v0; // ST18_8
    int64_t v1; // rax
    uint64_t size; // [rsp+10h] [rbp-30h]
    char s; // [rsp+20h] [rbp-20h]
    uint64_t v5; // [rsp+38h] [rbp-8h]

    if ( (uint64_t)alien_index <= 199 )
    {
        if ( _malloc_hook == saved_malloc_hook )
        {
            puts("How long is my name?");
            fgets(&s, 24, stdin);
            size = strtoul(&s, 0LL, 0);
            if ( size > 7 )
            {
                v0 = (void **)malloc(16uLL);
                v0[1] = &qword_100;
                *v0 = malloc(size);
                puts("What is my name?");
                *((char *)*v0 + (signed int)read(0, *v0, size)) = 0;
                v1 = alien_index++;
                aliens[v1] = v0;
            }
            else
            {
                puts("Too short!");
            }
        }
        else
        {
            puts("WHOOOOOOOOOAAAAA");
        }
    }
    else
    {
        puts("Our mothership is too full!\n We require more overlords.");
    }
}

int64_t *kill_alien(int64_t a1)
{
    int64_t *result; // rax

    puts("EEEEEAAAAUGGHGGHGHGAAAAa");
    free(*(void **)aliens[a1]);
    free((void *)aliens[a1]);
    result = aliens;
    aliens[a1] = 0LL;
    return result;
}

uint64_t consume_alien()
{
    uint64_t v1; // [rsp+8h] [rbp-28h]
    char s; // [rsp+10h] [rbp-20h]
    uint64_t v3; // [rsp+28h] [rbp-8h]

    puts("Which alien is unsatisfactory, brood mother?");
    fgets(&s, 24, stdin);
    v1 = strtoul(&s, 0LL, 0);
    if ( v1 <= alien_index )
    {
        if ( _free_hook == saved_free_hook )
            kill_alien(v1);
        else
            puts("Whooooaaaaaaaa");
    }
    else
    {
        puts("That alien is too far away >(");
    }
}

uint64_t rename_alien()
{
    uint64_t v0; // rax
    int64_t v1; // ST00_8
    char s; // [rsp+10h] [rbp-20h]
    uint64_t v4; // [rsp+28h] [rbp-8h]

    puts("Brood mother, which one of my babies would you like to rename?");
    fgets(&s, 24, stdin);
    v0 = strtoul(&s, 0LL, 0);
    printf("Oh great what would you like to rename %s to?\n", *(int64_t *)aliens[v0], v0);
    *(char *)(*(int64_t *)aliens[v1] + read(0, *(void **)aliens[v1], 8uLL)) = 0;
}

uint64_t hatchery()
{
    uint64_t v0; // rax
    char s; // [rsp+10h] [rbp-20h]
    uint64_t v3; // [rsp+28h] [rbp-8h]

    do
    {
        while ( 1 )
        {
            while ( 1 )
            {
                while ( 1 )
                {
                    puts("Brood mother, what tasks do we have today.");
                    fgets(&s, 24, stdin);
                    v0 = strtoul(&s, 0LL, 0);
                    if ( v0 != 2 )
                        break;
                    consume_alien();
                }
                if ( v0 > 2 )
                    break;
                if ( v0 == 1 )
                    new_alien();
            }
            if ( v0 != 3 )
                break;
            rename_alien();
        }
    }
    while ( v0 != 4 );
}

int64_t *new_samurai()
{
    int64_t *v0; // rax
    int64_t *v1; // ST08_8
    int64_t v2; // rax
    int64_t v3; // rcx
    int64_t *result; // rax

    puts("hmph");
    v0 = malloc(16uLL);
    v1 = v0;
    v0[1] = 16LL;
    puts("What is my weapon's name?");
    fgets(&swords[8 * samurai_index], 8, stdin);
    *v1 = &swords[8 * samurai_index];
    v2 = samurai_index++;
    v3 = v2;
    result = samurais;
    samurais[v3] = v1;
    return result;
}

int64_t *kill_samurai(int64_t a1)
{
    int64_t *result; // rax

    puts("==||==============> AAAAA");
    free((void *)samurais[a1]);
    result = samurais;
    samurais[a1] = 0LL;
    return result;
}

uint64_t seppuku()
{
    uint64_t v1; // [rsp+8h] [rbp-28h]
    char s; // [rsp+10h] [rbp-20h]
    uint64_t v3; // [rsp+28h] [rbp-8h]

    puts("Which samurai was dishonorable O lord daimyo?");
    fgets(&s, 0x18, stdin);
    v1 = strtoul(&s, 0LL, 0);
    if ( v1 <= samurai_index )
        kill_samurai(v1);
    else
        puts("That is outside of our feudal kingdom.");
}

uint64_t dojo()
{
    uint64_t v0; // rax
    char s; // [rsp+10h] [rbp-20h]
    uint64_t v3; // [rsp+28h] [rbp-8h]

    while ( 1 )
    {
        while ( 1 )
        {
            puts("Daimyo, nani o shitaidesu ka?");
            fgets(&s, 0x18, stdin);
            v0 = strtoul(&s, 0LL, 0);
            if ( v0 != 2 )
                break;
            seppuku();
        }
        if ( v0 == 3 )
            break;
        if ( v0 == 1 )
            new_samurai();
    }
}

void lose()
{
    puts("Aliens have taken over the world.....");
    exit(0);
}

int64_t win()
{
    int64_t result; // rax
    uint64_t i; // [rsp+0h] [rbp-10h]
    uint64_t j; // [rsp+8h] [rbp-8h]

    puts(
        "Good work! The samurai have won!\n"
        "But wait... turns out the daimyo was an alien all along...\n"
        "Omae wa mou.....\n"
        "Shindeiru!");
    for ( i = 0LL; i < samurai_index; ++i )
    {
        if ( samurais[i] )
            kill_samurai(i);
    }
    puts("Ahaha Brood mother. Looks like all the ninjas killed themselves..\nwait are you a samurai\nstop eating us");
    for ( j = 0LL; ; ++j )
    {
        result = alien_index;
        if ( j >= alien_index )
            break;
        if ( aliens[j] )
            kill_alien(j);
    }
    return result;
}

void invasion()
{
    uint64_t i; // [rsp+0h] [rbp-10h]
    int64_t v1; // [rsp+8h] [rbp-8h]

    if ( !alien_index )
        lose();
    v1 = 0LL;
    for ( i = 0LL; i < alien_index; ++i )
    {
        if ( aliens[i] )
        {
            if ( !samurais[i] )
            {
                printf("No %d fighters? no problem\n", i, i, v1);
                lose();
            }
            v1 = 1LL;
            if ( *(int64_t *)(samurais[i] + 8LL) > *(int64_t *)(aliens[i] + 8LL) )
                win();
        }
    }
    lose();
}

int main()
{
    dojo();
    saved_malloc_hook = _malloc_hook;
    saved_free_hook = _free_hook;
    hatchery();
    invasion();
}
