#include <stdio.h>

int main()
{
    long multiple[] = {15L, 25L, 35L, 45L};
    long * p = multiple;
    int i;

    for(i=0; i<(sizeof(multiple)/ sizeof(multiple[0])); ++i)
//        printf("Address p + %d (&multiple[%d]) is: %llu                  *(p + %d) is: %d\n",
//                          i,            i, (long long unsigned)(p + i),        i,     *(p + i));
//
        printf("Address p + %d (&multiple[%d]) is: %p or    %p                  *(p + %d) is: %d\n",
                           i,            i,   (p + i),    &multiple[i],        i,     *(p + i));


    printf("Type long occupies %d bytes", (sizeof(long)));



    return 0;
}