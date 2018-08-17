#include <stdio.h>

int main()
{
    int i;
    char str[100];

    printf("Enter some text and a number: ");

    // first arg is a control string, containg required types
    // determines separation of input parameters using whitespace
    scanf("%s %d", str, &i);

    printf("\nYou entered: %s and %d", str, i);

    return 0;
}
