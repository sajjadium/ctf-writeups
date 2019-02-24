int corps;
char major[28];
char first_name[];
char last_name[];

int change_major()
{
    char dest; // [esp+Ch] [ebp-1Ch]

    getchar();
    gets(&dest);
    strncpy(&dest, major, 0x14u);
    return printf("You changed your major to: %s\n", major);
}

int first_day_normal()
{
    int result; // eax

    puts("You wake up as your alarm clock goes off feeling well rested and ready for the day");
    puts("You decdide to get breakfast at Sbisa and enjoy some nice eggs and potatos");
    puts("You finish up your mediocre breakfast and head on out");
    puts("Finally your first day of class begins at Texas A&M. What do you decide to do next?(Input option number)");
    puts("1. Go to class.\n2. Change your major.\n3. Skip class and sleep\n4. Study");
    result = (char)getchar();
    if ( result == 50 )
    {
        printf(
            "You decide that you are already tired of studying %s and go to the advisors office to change your major\n",
            major);
        printf("What do you change your major to?: ");
        result = change_major();
    }
    else if ( result > 50 )
    {
        if ( result == 51 )
        {
            result = puts(
                         "You decide that you are better at learning stuff on your own and will use the time gained not going to "
                         "class to take a nap");
        }
        else if ( result == 52 )
        {
            puts("You decide to get ahead in your classes and go to the library to study.");
            result = printf(
                         "You get a cup of coffee and settle in to study. After a while some of the material in %s starts making sense to you\n",
                         major);
        }
    }
    else if ( result == 49 )
    {
        puts("You go to class and decide to sit somewhere in the middle row");
        printf(
            "As the lecturer drones on about a topic that you don't quite understand in the field of %s you notice the cadet si"
            "tting up front nodding off\n",
            major);
        result = putchar(10);
    }
    return result;
}

int first_day_corps()
{
    int result; // eax

    printf(
        "You wake with a start as your sophomore yells \"Wake up fish %s! Why aren't you with your buddies in the fallout hole?\"\n",
        &last_name);
    puts("As your sophomore slams your door close you quickly get dressed in pt gear and go to the fallout hole.");
    puts("You spend your morning excersizing and eating chow.");
    puts("Finally your first day of class begins at Texas A&M. What do you decide to do next?(Input option number)");
    puts("1. Go to class.\n2. Change your major.\n3. Skip class and sleep\n4. Study");
    getchar();
    result = (char)getchar();
    if ( result == 50 )
    {
        printf(
            "You decide that you are already tired of studying %s and go to the advisors office to change your major\n",
            major);
        printf("What do you change your major to?: ");
        result = change_major();
    }
    else if ( result > 50 )
    {
        if ( result == 51 )
        {
            result = puts(
                         "You succumb to the sweet calling of your rack and decide that sleeping is more important than class at the moment.");
        }
        else if ( result == 52 )
        {
            puts(
                "You realize that the corps dorms are probably not the best place to be studying and decide to go to the library");
            result = printf(
                         "Unfortunately the queitness of the library works against you and as you are studying %s related topics "
                         "you start to doze off and fall asleep\n");
        }
    }
    else if ( result == 49 )
    {
        puts("You go to class and sit front and center as the Corps academic advisors told you to do.");
        printf(
            "As the lecturer drones on about a topic that you don't quite understand in the field of %s you feel yourself begin"
            "ning to drift off.\n",
            major);
        result = puts("You wake with a start and find that you are alone in the lecture hall.");
    }
    return result;
}

int print_beginning()
{
    int result; // eax
    char v1; // [esp+Fh] [ebp-9h]

    puts("Welcome to the TAMU Text Adventure!");
    puts("You are about to begin your journey at Texas A&M as a student");
    puts("But first tell me a little bit about yourself");
    printf("What is your first name?: ");
    fgets(&first_name, 100, stdin);
    strtok(&first_name, "\n");
    printf("What is your last name?: ");
    fgets(&last_name, 100, stdin);
    strtok(&last_name, "\n");
    printf("What is your major?: ");
    fgets(major, 20, stdin);
    strtok(major, "\n");
    printf("Are you joining the Corps of Cadets?(y/n): ");
    v1 = getchar();
    corps = v1 == 121 || v1 == 89;
    printf("\nWelcome, %s %s, to Texas A&M!\n", &first_name, &last_name);
    if ( corps )
        result = first_day_corps();
    else
        result = first_day_normal();
    return result;
}

int main()
{
    print_beginning();
    return 0;
}
