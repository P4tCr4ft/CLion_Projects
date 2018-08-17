// name info etc

#include <stdio.h>

int main()
{
    // int is signed by default

    int a = 60;
    int b = 13;
    int c = 25;
    unsigned int d;
    unsigned int e;

    int result = 0;
    int result2 = 0;


    // apparently the below compiles even though unsigned not supposed to be neg
    // some bizzaro explanation stackoverflow. I think ultimately what happens is that
    // d is not what you think it is, as you told compiler d was unsigned ,but then
    // assigned it to neg number. So printf somehow works out what you mean if you put
    // %d, but if you put %u you do not get -50, you get some other massive +ve number,
    // most certainly not -50.

    // so the lesson is not to assign it a neg number, if you declare it as unsigned.

    d = -50;

    e = a - c;

    //

    printf("variable d is %d\n", d );
    printf("variable e is %u\n", e);

    // bitwise AND of 60 (0011 1100) and 13(0000 1101)
    result = a & b;
    // result is 0000 1100

    printf("result is %d\n", result);

    result2 = a | b;
    // 0011 1101

    printf("result2 is %d\n", result2);



    return 0;

}
