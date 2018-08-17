#include <stdio.h>

int main()
{
    // dont actually need to creat any variables, to test sizeof()
    int foo_int = 10;
    char foo_char = 'a';
    long _foo_long = 23.45454545;
    long foo_long = 0.0f;
    float foo_float = 45.45466433e+34;
    long long foo_l_long = 45.4545434;
    double foo_double = 4.333333;
    long double foo_l_double = 1.2222231;


    printf("Using sizeof() the byte size of int is %d\n", sizeof(foo_int));
    printf("Using sizeof() the byte size of char is %d\n", sizeof(foo_char));
    printf("Using sizeof() the byte size of long is %d\n", sizeof(foo_long));
    printf("Using sizeof() the byte size of float is %d\n", sizeof(foo_float));
    printf("Using sizeof() the byte size of long long is %d\n", sizeof(foo_l_long));
    printf("Using sizeof() the byte size of double is %d\n", sizeof(foo_double));
    printf("Using sizeof() the byte size of long double is %d\n", sizeof(foo_l_double));

    // can just use types in sizeof()

    printf("\n\n");

    printf("Variables of type char occupy %u bytes\n", sizeof(char));
    printf("Variables of type short occupy %u bytes\n", sizeof(short));
    printf("Variables of type int occupy %u bytes\n", sizeof(int));
    printf("Variables of type long occupy %u bytes\n", sizeof(long));
    printf("Variables of type long long occupy %u bytes\n", sizeof(long long));
    printf("Variables of type float occupy %u bytes\n", sizeof(float));
    printf("Variables of type double occupy %u bytes\n", sizeof(double));
    printf("Variables of type long double occupy %u bytes\n", sizeof(long double));

    return 0;
}
