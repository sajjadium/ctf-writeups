int64_t (*MetadataClip_vtable[4])() =
{
    &create_MetadataClip,
    &edit_MetadataClip,
    &destroy_MetadataClip,
    &play_MetadataClip
};
int64_t subtitle_clip_index = -1LL;
int64_t metadata_clip_index = -1LL;
char byte_6043F0;
int64_t clips_table[16384];
int64_t clips_count;

int64_t return_zero()
{
    return 0LL;
}

uint64_t allocate_random_memories()
{
    unsigned __int8 v0; // al
    unsigned int buf; // [rsp+4h] [rbp-101Ch]
    int i; // [rsp+8h] [rbp-1018h]
    int fd; // [rsp+Ch] [rbp-1014h]
    void *v5[513]; // [rsp+10h] [rbp-1010h]
    uint64_t v6; // [rsp+1018h] [rbp-8h]

    fd = open("/dev/urandom", 0);
    if ( fd < 0 )
        exit(1);
    if ( read(fd, &buf, 4uLL) != 4 )
        exit(1);
    close(fd);
    srand(buf);
    for ( i = 0; i <= 255; ++i )
    {
        v0 = rand();
        v5[i] = (void *)operator new[](v0);
    }
    for ( i = 0; i <= 255; ++i )
    {
        if ( rand() % 3 == 0 )
        {
            if ( v5[i] )
                operator delete[](v5[i]);
        }
        v5[i] = 0LL;
    }
}

int64_t initialize()
{
    int64_t v0; // rax

    alarm(600u);
    allocate_random_memories();
    setvbuf(stdin, 0LL, 2, 0LL);
    setvbuf(stdout, 0LL, 2, 0LL);
    v0 = std::operator<<<std::char_traits<char >> (&std::cout, "Welcome to SVP ( SECCON Video Player ) !!!");
    return std::ostream::operator<<(v0, &std::endl<char, std::char_traits<char>>);
}

int64_t show_menu()
{
    int64_t v0; // rax
    int64_t v1; // rax
    int64_t v2; // rax
    int64_t v3; // rax

    v0 = std::operator<<<std::char_traits<char >> (&std::cout, "1. Add Clip");
    std::ostream::operator<<(v0, &std::endl<char, std::char_traits<char>>);
    v1 = std::operator<<<std::char_traits<char >> (&std::cout, "2. Edit Clip");
    std::ostream::operator<<(v1, &std::endl<char, std::char_traits<char>>);
    v2 = std::operator<<<std::char_traits<char >> (&std::cout, "3. Play Clip");
    std::ostream::operator<<(v2, &std::endl<char, std::char_traits<char>>);
    v3 = std::operator<<<std::char_traits<char >> (&std::cout, "4. Remove Clip");
    std::ostream::operator<<(v3, &std::endl<char, std::char_traits<char>>);
    return std::operator<<<std::char_traits<char >> (&std::cout, ">>> ");
}

int64_t show_clip_types()
{
    int64_t v0; // rax
    int64_t v1; // rax
    int64_t v2; // rax
    int64_t v3; // rax
    int64_t v4; // rax

    v0 = std::operator<<<std::char_traits<char >> (&std::cout, "Clip Adding");
    std::ostream::operator<<(v0, &std::endl<char, std::char_traits<char>>);
    v1 = std::operator<<<std::char_traits<char >> (&std::cout, "1. Video Clip");
    std::ostream::operator<<(v1, &std::endl<char, std::char_traits<char>>);
    v2 = std::operator<<<std::char_traits<char >> (&std::cout, "2. Audio Clip");
    std::ostream::operator<<(v2, &std::endl<char, std::char_traits<char>>);
    v3 = std::operator<<<std::char_traits<char >> (&std::cout, "3. Subtitle Clip");
    std::ostream::operator<<(v3, &std::endl<char, std::char_traits<char>>);
    v4 = std::operator<<<std::char_traits<char >> (&std::cout, "4. Metadata Clip");
    std::ostream::operator<<(v4, &std::endl<char, std::char_traits<char>>);
    return std::operator<<<std::char_traits<char >> (&std::cout, ">>> ");
}

uint64_t add_clip()
{
    uint64_t *new_metadata_clip; // rsi
    int64_t *new_video_clip; // rsi
    int64_t v2; // rax
    int64_t *new_audio_clip; // rsi
    int64_t audio_clip_index; // rax
    int64_t *new_subtitle_clip; // rbx
    int64_t v6; // rax
    int64_t v7; // rax
    int64_t v8; // rax
    uint64_t v10; // [rsp+0h] [rbp-20h]
    uint64_t v11; // [rsp+8h] [rbp-18h]

    if ( (uint64_t)clips_count > 16383 )
        exit(1);
    show_clip_types();
    new_metadata_clip = &v10;
    std::istream::operator>>((int64_t)&std::cin, (int64_t)&v10);
    if ( v10 == 2 )
    {
        new_audio_clip = (int64_t *)operator new(72uLL);
        memset(new_audio_clip, 0, 72uLL);
        AudioClip_Constructor(new_audio_clip);
        clips_table[clips_count] = (int64_t)new_audio_clip;
        audio_clip_index = clips_count++;
        (**(void (* **)(int64_t))clips_table[audio_clip_index])(clips_table[audio_clip_index]);
    }
    else if ( v10 > 2 )
    {
        if ( v10 == 3 )
        {
            if ( subtitle_clip_index == -1 )
            {
                new_subtitle_clip = (int64_t *)operator new(24uLL);
                *new_subtitle_clip = 0LL;
                new_subtitle_clip[1] = 0LL;
                new_subtitle_clip[2] = 0LL;
                SubClip_Constructor(new_subtitle_clip);
                clips_table[clips_count] = (int64_t)new_subtitle_clip;
                v6 = clips_count++;
                subtitle_clip_index = v6;
            }
            (**(void (* **)(int64_t, uint64_t *))clips_table[subtitle_clip_index])(
                clips_table[subtitle_clip_index],
                &v10);
        }
        else
        {
            if ( v10 != 4 )
                goto LABEL_18;
            if ( metadata_clip_index == -1 )
            {
                new_metadata_clip = (uint64_t *)operator new(72uLL);
                memset(new_metadata_clip, 0, 72uLL);
                MetadataClip_Constructor(new_metadata_clip);
                clips_table[clips_count] = (int64_t)new_metadata_clip;
                v7 = clips_count++;
                metadata_clip_index = v7;
            }
            (**(void (* **)(int64_t, uint64_t *))clips_table[metadata_clip_index])(
                clips_table[metadata_clip_index],
                new_metadata_clip);
        }
    }
    else
    {
        if ( v10 != 1 )
        {
LABEL_18:
            v8 = std::operator<<<std::char_traits<char >> (&std::cout, "Wrong Type!!!");
            std::ostream::operator<<(v8, &std::endl<char, std::char_traits<char>>);
        }
        new_video_clip = (int64_t *)operator new(80uLL);
        memset(new_video_clip, 0, 80uLL);
        VideoClip_Constructor(new_video_clip);
        clips_table[clips_count] = (int64_t)new_video_clip;
        v2 = clips_count++;
        (**(void (* **)(int64_t))clips_table[v2])(clips_table[v2]);
    }
}

uint64_t edit_clip()
{
    int64_t index; // [rsp+0h] [rbp-10h]
    uint64_t v2; // [rsp+8h] [rbp-8h]

    std::operator<<<std::char_traits<char >> (&std::cout, "Enter index : ");
    std::istream::operator>>((int64_t)&std::cin, (int64_t)&index);
    if ( !clips_table[index] )
        exit(1);
    (*(void (* *)(int64_t, int64_t *))(*(int64_t *)clips_table[index] + 8LL))(clips_table[index], &index);
}

uint64_t play_clip()
{
    int64_t index; // [rsp+0h] [rbp-10h]
    uint64_t v2; // [rsp+8h] [rbp-8h]

    std::operator<<<std::char_traits<char >> (&std::cout, "Enter index : ");
    std::istream::operator>>((int64_t)&std::cin, (int64_t)&index);
    if ( !clips_table[index] )
        exit(1);
    (*(void (* *)(int64_t, int64_t *))(*(int64_t *)clips_table[index] + 24LL))(clips_table[index], &index);
}

uint64_t remove_clip()
{
    int64_t index; // [rsp+0h] [rbp-10h]
    uint64_t v2; // [rsp+8h] [rbp-8h]

    std::operator<<<std::char_traits<char >> (&std::cout, "Enter index : ");
    std::istream::operator>>((int64_t)&std::cin, (int64_t)&index);
    if ( !clips_table[index] )
        exit(1);
    (*(void (* *)(int64_t, int64_t *))(*(int64_t *)clips_table[index] + 16LL))(clips_table[index], &index);
    clips_table[index] = 0LL;
    if ( index == subtitle_clip_index )
    {
        subtitle_clip_index = -1LL;
    }
    else if ( index == metadata_clip_index )
    {
        metadata_clip_index = -1LL;
    }
}

int64_t main(int64_t a1, char **a2, char **a3)
{
    int64_t v3; // rax
    int64_t v4; // rax
    uint64_t v6; // [rsp+8h] [rbp-118h]
    char buf; // [rsp+10h] [rbp-110h]
    uint64_t v8; // [rsp+118h] [rbp-8h]

    initialize();
    v3 = std::operator<<<std::char_traits<char >> (&std::cout, "What is your movie name?");
    std::ostream::operator<<(v3, &std::endl<char, std::char_traits<char>>);
    read(0, &buf, 255uLL);
    while ( 1 )
    {
        while ( 1 )
        {
            while ( 1 )
            {
                while ( 1 )
                {
                    show_menu();
                    v6 = 0LL;
                    std::istream::operator>>((int64_t)&std::cin, (int64_t)&v6);
                    if ( v6 != 2 )
                        break;
                    edit_clip();
                }
                if ( v6 > 2 )
                    break;
                if ( v6 != 1 )
                    goto LABEL_13;
                add_clip();
            }
            if ( v6 != 3 )
                break;
            play_clip();
        }
        if ( v6 != 4 )
            break;
        remove_clip();
    }
LABEL_13:
    v4 = std::operator<<<std::char_traits<char >> (&std::cout, "See you next time!!");
    std::ostream::operator<<(v4, &std::endl<char, std::char_traits<char>>);
    return 0LL;
}

void create_Clip()
{
    ;
}

void edit_Clip()
{
    ;
}

void destroy_Clip()
{
    ;
}

void play_Clip()
{
    ;
}

bool create_VideoClip(void **a1)
{
    bool result; // al

    std::operator<<<std::char_traits<char >> (&std::cout, "Video Resolution : ");
    if ( read(0, a1 + 1, 8uLL) <= 0 )
        exit(1);
    std::operator<<<std::char_traits<char >> (&std::cout, "FPS : ");
    if ( read(0, a1 + 2, 4uLL) <= 0 )
        exit(1);
    std::operator<<<std::char_traits<char >> (&std::cout, "Number of Frames : ");
    if ( read(0, (char *)a1 + 20, 4uLL) <= 0 )
        exit(1);
    if ( *((int *)a1 + 5) > 1024u )
        *((int *)a1 + 5) = 1024;
    a1[3] = (void *)operator new[](*((unsigned int *)a1 + 5));
    if ( !a1[3] )
        exit(1);
    std::operator<<<std::char_traits<char >> (&std::cout, "Video Data : ");
    *((int *)a1 + 5) = read(0, a1[3], *((unsigned int *)a1 + 5));
    if ( !*((int *)a1 + 5) )
        exit(1);
    memset(a1 + 4, 0, 48uLL);
    std::operator<<<std::char_traits<char >> (&std::cout, "Add description : ");
    result = read(0, a1 + 4, 47uLL) <= 0;
    if ( result )
        exit(1);
    return result;
}

bool edit_VideoClip(void **a1)
{
    bool result; // al
    void *v2; // [rsp+18h] [rbp-8h]

    std::operator<<<std::char_traits<char >> (&std::cout, "Video Resolution : ");
    if ( read(0, a1 + 1, 8uLL) <= 0 )
        exit(1);
    std::operator<<<std::char_traits<char >> (&std::cout, "FPS : ");
    if ( read(0, a1 + 2, 4uLL) <= 0 )
        exit(1);
    std::operator<<<std::char_traits<char >> (&std::cout, "Number of Frames : ");
    if ( read(0, (char *)a1 + 20, 4uLL) <= 0 )
        exit(1);
    if ( *((int *)a1 + 5) > 1024u )
        *((int *)a1 + 5) = 1024;
    v2 = (void *)operator new[](*((unsigned int *)a1 + 5));
    if ( !v2 )
        exit(1);
    a1[3] = v2;
    if ( a1[3] )
        operator delete[](a1[3]);
    std::operator<<<std::char_traits<char >> (&std::cout, "Video Data : ");
    *((int *)a1 + 5) = read(0, a1[3], *((unsigned int *)a1 + 5));
    if ( !*((int *)a1 + 5) )
        exit(1);
    memset(a1 + 4, 0, 48uLL);
    std::operator<<<std::char_traits<char >> (&std::cout, "Edit description : ");
    result = read(0, a1 + 4, 47uLL) <= 0;
    if ( result )
        exit(1);
    return result;
}

int64_t play_VideoClip(int64_t a1)
{
    int64_t v1; // rax
    unsigned int i; // [rsp+1Ch] [rbp-4h]

    v1 = std::operator<<<std::char_traits<char >> (&std::cout, "Playing video...");
    std::ostream::operator<<(v1, &std::endl<char, std::char_traits<char>>);
    for ( i = 0; * (int *)(a1 + 20) >= i; ++i )
        std::operator<<<std::char_traits<char >> (
            &std::cout,
            (unsigned int)(char)(*(char *)(*(int64_t *)(a1 + 24) + i) ^ 0xCC));
    return std::ostream::operator<<(&std::cout, &std::endl<char, std::char_traits<char>>);
}

int64_t destroy_VideClip(int64_t a1)
{
    int64_t result; // rax

    if ( *(int64_t *)(a1 + 24) )
        operator delete[](*(void **)(a1 + 24));
    result = a1;
    *(int64_t *)(a1 + 24) = 0LL;
    return result;
}

bool create_AudioClip(void **audio_clip)
{
    bool result; // al

    std::operator<<<std::char_traits<char >> (&std::cout, "Audio Bitrate : ");
    if ( read(0, audio_clip + 1, 2uLL) <= 0 )
        exit(1);
    std::operator<<<std::char_traits<char >> (&std::cout, "Audio Length (seconds) : ");
    if ( read(0, (char *)audio_clip + 12, 4uLL) <= 0 )
        exit(1);
    if ( *((int *)audio_clip + 3) > 256u )
        *((int *)audio_clip + 3) = 256;
    audio_clip[2] = (void *)operator new[](*((unsigned int *)audio_clip + 3));
    if ( !audio_clip[2] )
        exit(1);
    std::operator<<<std::char_traits<char >> (&std::cout, "Audio Data : ");
    *((int *)audio_clip + 3) = read(0, audio_clip[2], *((unsigned int *)audio_clip + 3));
    if ( !*((int *)audio_clip + 3) )
        exit(1);
    memset(audio_clip + 3, 0, 48uLL);
    std::operator<<<std::char_traits<char >> (&std::cout, "Add description : ");
    result = read(0, audio_clip + 3, 47uLL) <= 0;
    if ( result )
        exit(1);
    return result;
}

bool edit_AudioClip(void **a1)
{
    bool result; // al
    void *v2; // [rsp+18h] [rbp-8h]

    std::operator<<<std::char_traits<char >> (&std::cout, "Audio Bitrate : ");
    if ( read(0, a1 + 1, 2uLL) <= 0 )
        exit(1);
    std::operator<<<std::char_traits<char >> (&std::cout, "Audio Length (seconds) : ");
    if ( read(0, (char *)a1 + 12, 4uLL) <= 0 )
        exit(1);
    if ( *((int *)a1 + 3) > 256u )
        *((int *)a1 + 3) = 256;
    v2 = (void *)operator new[](*((unsigned int *)a1 + 3));
    if ( !v2 )
        exit(1);
    if ( a1[2] )
        operator delete[](a1[2]);
    a1[2] = v2;
    std::operator<<<std::char_traits<char >> (&std::cout, "Audio Data : ");
    *((int *)a1 + 3) = read(0, a1[2], *((unsigned int *)a1 + 3));
    if ( !*((int *)a1 + 3) )
        exit(1);
    memset(a1 + 3, 0, 48uLL);
    std::operator<<<std::char_traits<char >> (&std::cout, "Edit description : ");
    result = read(0, a1 + 3, 47uLL) <= 0;
    if ( result )
        exit(1);
    return result;
}

int64_t play_AudioClip(int64_t a1)
{
    unsigned int i; // [rsp+1Ch] [rbp-4h]

    for ( i = 0; * (int *)(a1 + 12) >= i; ++i )
        std::ostream::operator<<(&std::cout, (unsigned __int8)(*(char *)(*(int64_t *)(a1 + 16) + i) ^ 0x55));
    return std::ostream::operator<<(&std::cout, &std::endl<char, std::char_traits<char>>);
}

int64_t destroy_AudioClip(int64_t a1)
{
    int64_t result; // rax

    if ( *(int64_t *)(a1 + 16) )
        operator delete[](*(void **)(a1 + 16));
    result = a1;
    *(int64_t *)(a1 + 16) = 0LL;
    return result;
}

uint64_t create_SubClip(int64_t a1)
{
    unsigned int buf; // [rsp+1Ch] [rbp-14h]
    void *dest; // [rsp+20h] [rbp-10h]
    uint64_t v4; // [rsp+28h] [rbp-8h]

    if ( *(int64_t *)(a1 + 16) )
    {
        buf = 0;
        dest = 0LL;
        std::operator<<<std::char_traits<char >> (&std::cout, "Subtitle Length : ");
        if ( read(0, &buf, 4uLL) <= 0 )
            exit(1);
        if ( *(int *)(a1 + 12) + buf > 1024 )
            buf = 1024 - *(int *)(a1 + 12);
        dest = (void *)operator new[](*(int *)(a1 + 12) + buf);
        if ( !dest )
            exit(1);
        std::operator<<<std::char_traits<char >> (&std::cout, "Add Subtitle : ");
        memcpy(dest, *(const void **)(a1 + 16), *(unsigned int *)(a1 + 12));
        if ( read(0, (char *)dest + * (unsigned int *)(a1 + 12), buf) <= 0 )
            exit(1);
        if ( *(int64_t *)(a1 + 16) )
            operator delete[](*(void **)(a1 + 16));
        *(int64_t *)(a1 + 16) = dest;
    }
    else
    {
        std::operator<<<std::char_traits<char >> (&std::cout, "Subtitle Language : ");
        if ( read(0, (void *)(a1 + 8), 4uLL) <= 0 )
            exit(1);
        std::operator<<<std::char_traits<char >> (&std::cout, "Subtitle Length : ");
        if ( read(0, (void *)(a1 + 12), 4uLL) <= 0 )
            exit(1);
        if ( *(int *)(a1 + 12) > 1024u )
            *(int *)(a1 + 12) = 1024;
        *(int64_t *)(a1 + 16) = operator new[](*(unsigned int *)(a1 + 12));
        if ( !*(int64_t *)(a1 + 16) )
            exit(1);
        std::operator<<<std::char_traits<char >> (&std::cout, "Add Subtitle : ");
        if ( read(0, *(void **)(a1 + 16), *(unsigned int *)(a1 + 12)) <= 0 )
            exit(1);
    }
}

bool edit_SubClip(int64_t a1)
{
    bool result; // al

    std::operator<<<std::char_traits<char >> (&std::cout, "New Language : ");
    if ( read(0, (void *)(a1 + 8), 4uLL) <= 4 )
        exit(1);
    std::operator<<<std::char_traits<char >> (&std::cout, "Edit data : ");
    result = read(0, *(void **)(a1 + 16), *(unsigned int *)(a1 + 12)) <= 0;
    if ( result )
        exit(1);
    return result;
}

int64_t play_SubClip()
{
    int64_t v0; // rax

    v0 = std::operator<<<std::char_traits<char >> (&std::cout, "Not Playable");
    return std::ostream::operator<<(v0, &std::endl<char, std::char_traits<char>>);
}

int64_t destroy_SubClip(int64_t a1)
{
    int64_t result; // rax

    if ( *(int64_t *)(a1 + 16) )
        operator delete[](*(void **)(a1 + 16));
    result = a1;
    *(int64_t *)(a1 + 16) = 0LL;
    return result;
}

bool create_MetadataClip(int64_t a1)
{
    bool result; // al

    std::operator<<<std::char_traits<char >> (&std::cout, "Date of Creation : ");
    memset((void *)(a1 + 8), 0, 32uLL);
    if ( read(0, (void *)(a1 + 8), 31uLL) <= 0 )
        exit(1);
    std::operator<<<std::char_traits<char >> (&std::cout, "Owner of video : ");
    memset((void *)(a1 + 40), 0, 32uLL);
    result = read(0, (void *)(a1 + 40), 31uLL) <= 0;
    if ( result )
        exit(1);
    return result;
}

bool edit_MetadataClip(int64_t a1)
{
    bool result; // al

    std::operator<<<std::char_traits<char >> (&std::cout, "Date of Creation : ");
    memset((void *)(a1 + 8), 0, 32uLL);
    if ( read(0, (void *)(a1 + 8), 31uLL) <= 0 )
        exit(1);
    std::operator<<<std::char_traits<char >> (&std::cout, "Owner of video : ");
    memset((void *)(a1 + 40), 0, 32uLL);
    result = read(0, (void *)(a1 + 40), 31uLL) <= 0;
    if ( result )
        exit(1);
    return result;
}

int64_t play_MetadataClip()
{
    int64_t v0; // rax

    v0 = std::operator<<<std::char_traits<char >> (&std::cout, "Not Playable");
    return std::ostream::operator<<(v0, &std::endl<char, std::char_traits<char>>);
}

void destroy_MetadataClip()
{
    ;
}

int64_t *Clip_Constructor(int64_t *clip)
{
    int64_t *result; // rax

    result = clip;
    *clip = Clip_vtable;
    return result;
}

int64_t *VideoClip_Constructor(int64_t *a1)
{
    int64_t *result; // rax

    Clip_Constructor(a1);
    result = a1;
    *a1 = VideoClip_vtable;
    return result;
}

int64_t *AudioClip_Constructor(int64_t *this)
{
    int64_t *result; // rax

    Clip_Constructor(this);
    result = this;
    *this = AudioClip_vtable;
    return result;
}

int64_t *SubClip_Constructor(int64_t *this)
{
    int64_t *result; // rax

    Clip_Constructor(this);
    *this = SubClip_vtable;
    result = this;
    this[2] = 0LL;
    return result;
}

int64_t *MetadataClip_Constructor(int64_t *a1)
{
    int64_t *result; // rax

    Clip_Constructor(a1);
    result = a1;
    *a1 = MetadataClip_vtable;
    return result;
}
