#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char play_words[20][10]={"paper","boat","string","craft","rose","nose","embrace","chase","love","trust","hate","cheat","friends","lucky","blessed","misfortune","life","empty","gloom","hope"};
char *word(int no)
{
    char *ptr=&play_words[no];
    return ptr;
}

