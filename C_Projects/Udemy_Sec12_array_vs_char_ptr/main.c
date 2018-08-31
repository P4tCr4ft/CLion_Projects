#include <stdio.h>

// Using char arrays as function parameters (arguments are what are passed when function called)

void copyString(char to[], char from[])
{
    int i;

    // \0 is null character

    for(i=0; from[i]!='\0'; ++i)
        to[i] = from[i];

    to[i] = '\0';
}

// Note: Cannot overload copyString function like can in C++, have to call it something else
// Using char pointers as function parameters

void copy2String(char * to, char * from)
{
    for(; *from!='\0'; ++from, ++to)
        *to = *from;

    *to = '\0';
}

// Can simplify even further using char pointers and a while loop instead

void copy3String(char * to, char * from)
{
    while(*from)// the null character is equal to 0, and 0 is boolean false, so jumps out
        *to++ = *from++;// this does *to = *from and increments after executing the statement
                        // can also use *to-- decrement operator, to step backwards one

    *to = '\0';
}

int main() {

    char string1[] = "A string to be copied.";
    char string2[50];

//    copyString(string2, string1);
//    copy2String(string2, string1);
    copy3String(string2, string1);

    printf("%s\n", string2);

    return 0;
}