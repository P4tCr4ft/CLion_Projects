#include <stdio.h>

void copyString(char to[], char from[])
{
    int i;

    for(i=0; from[i]!='\0'; ++i)
        to[i] = from[i];

    to[i] = '\0';
}

int main() {



    return 0;
}