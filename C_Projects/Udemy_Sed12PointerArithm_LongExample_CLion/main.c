#include <stdio.h>

int main()
{
    long multiple[] = {15L, 25L, 35L, 45L};
    long * p = multiple;
    int i;

    for(i=0; i<(sizeof(multiple)/ sizeof(multiple[0])); ++i)
        printf("Address p + %d (&multiple[%d]) is: %li                  *(p + %d) is: %li\n",
                          i,            i, (long)(p + i),        i,     *(p + i));

//        printf("Address p + %d (&multiple[%d]) is: %p or    %p                  *(p + %d) is: %li\n",
//                           i,            i,   (p + i),    &multiple[i],        i,     *(p + i));


    printf("Type long occupies %d bytes", (sizeof(long)));



    return 0;
}