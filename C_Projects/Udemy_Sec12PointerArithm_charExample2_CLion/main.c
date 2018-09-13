#include <stdio.h>
#include <string.h>

int main()
{

    int i;

    char multiple[] = "a string";
    char multiple2[] = "a cat";
    char multiple3[] = {'w', 'o', 'o', 'f', 'f'};
    char multiple4[] = {'m', 'e', 'o', 'w'};
    int intmulti[] = {1, 23, 4, 555};

    char * p = multiple;


    printf("multiple is '%s'\n", multiple);
    printf("multiple3 is '%s'\n", multiple3);
    printf("multiple4 is '%s'\n", multiple4);
    printf("size of multiple is %i bytes\n", sizeof(multiple));
    printf("size of multiple2 is %i bytes\n", sizeof(multiple2));
    printf("size of intmulti is %i bytes\n", sizeof(intmulti));
    printf("size of multiple3 is %i bytes\n", sizeof(multiple3));
    printf("strlen of multiple4 is %i\n", strlen(multiple4));
    printf("size of integer type num is %i bytes\n", sizeof(i));
    printf("size of array element space '%c' is %i bytes\n",multiple[1], sizeof(multiple[1]));
    printf("size calc of array is sizeof array %i bytes divided by sizeof array element %i bytes, and is %i\n",
           sizeof(multiple), sizeof(multiple[0]), (sizeof(multiple)/sizeof(multiple[0])));

    for(i=0; i<strlen(multiple); ++i)
        printf("multiple[%d] = %c       *(p+%d) = %c       &multiple[%d] = %p       p + %d = %p\n",
                         i, multiple[i],    i, *(p+i),            i, &multiple[i],      i,     p+i);

    return 0;
}
