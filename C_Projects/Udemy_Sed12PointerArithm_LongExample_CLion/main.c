#include <stdio.h>

int main()
{
    long multiple[] = {15L, 25L, 35L, 45L};
    long * p = multiple;
    int i;

// Notice when incrementing the pointer using iterator i, it knows the correct
// size of memory, ie it knows to increment it 4 bytes for array of type long int,
// and increment it 1 byte for array of type char, etc
// so even though adding 1 to iterator, compiler knows to go to the next memory address

    for(i=0; i<(sizeof(multiple)/ sizeof(multiple[0])); ++i)
        printf("Address p+%d (&multiple[%d]) is: %li                  *(p+%d) is: %li\n",
                          i,            i, (long)(p+i),        i,     *(p+i));


// Can see if have pointer format specifier %p below prints out memory address
// and if type cast to long int, see above, it converts it to decimal representation if address,
// and the numbers are all 4 apart

//        printf("Address p + %d (&multiple[%d]) is: %p or    %p                  *(p + %d) is: %li\n",
//                           i,            i,   (p + i),    &multiple[i],        i,     *(p + i));


    printf("Type long occupies %d bytes", (sizeof(long)));



    return 0;
}