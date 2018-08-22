#include <stdio.h>
#include <stddef.h>

// Example function with array notation
int arraySum(int array[], const int n)
{
    int sum = 0;
    int * ptr;
    int * const arrayEnd = array + n;// constant pointer, so address cannot change. Points to last element address

//    for (ptr = array; ptr < arrayEnd; ++ptr)// ptr = array, same as ptr = &array[0], arrayEnd is last element address
                                            // ptr + 1 just goes to the next address

    for (; array < arrayEnd; ++array)// loop similar to pointer notation below but still works


//        sum += *ptr;// dereference pointer (indirection operator), pointing to each address in array (so value stored at each address), as it iterates
        sum += *array;

    return sum;
}

// Example function with pointer notation
int arraySum2(int * array, const int n)
{
    int sum = 0;
    int * const arrayEnd = array + n;

    for(; array < arrayEnd; ++array)
        sum += *array;

    return sum;
}

// Can also

int main() {

//    int arraySum(int array[], const int n); // Not sure why is prototyping arraySum function here, in the example?

    int values[10] = {3, 7, -9, 3, 6, -1, 7, 9, 1, -5};

    printf("The sum is %i\n", arraySum(values, 10));// to pass array to function, just specify array name
                                                    // to produce pointer to array, only need specify name of array,
                                                    // eg, ptr = array
    printf("The sum also is %i\n", arraySum2(values, 10));

    return 0;
}