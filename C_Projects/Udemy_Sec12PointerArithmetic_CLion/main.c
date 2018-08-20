#include <stdio.h>
#include <stddef.h>

int arraySum(int array[], const int n)
{
    int sum = 0;
    int * ptr;
    int * const arrayEnd = array + n;// constant pointer, so address cannot change

    for (ptr = array; ptr < arrayEnd; ++ptr)// ptr = array, same as ptr = &array[0], arrayEnd is last element address
                                            // ptr + 1 just goes to the next address



        sum += *ptr;// dereference pointer, pointing to each address in array, as it iterates

    return sum;
}

int main() {

//    int arraySum(int array[], const int n); // Not sure why is prototyping arraySum function here, in the example?

    int values[10] = {3, 7, -9, 3, 6, -1, 7, 9, 1, -5};

    printf("The sum is %i\n", arraySum(values, 10));


    return 0;
}