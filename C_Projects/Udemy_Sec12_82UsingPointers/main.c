#include <stdio.h>
#include <stddef.h>

int main()
{
    long num1 = 0L; // explicit casting 0 as a long, so no implicit cast from int to long required
    long num2 = 0L;
    long * pnum = NULL;

    pnum = &num1;

    printf("num1 is %li and deref pnum is %li\n", num1, *pnum); // li is format specifier for long int

    printf("pnum is pointing to num1 so is num1's address %p\n", pnum); // this is address of variable, num1, that pnum is pointing to, so num1's address

    *pnum = 2L; // Value of variable pnum pointing to, num1, now set to 2L, so num1 is now 2

    ++num2;     // increment num2, so num2 is now 1

    num2 += *pnum; // add num1 to num2, num2 is now 3

    pnum = &num2; // pnum is now pointing to num2, so is num2's address

    printf("pnum is now pointing to num2 so is num2's address %p\n", pnum);

    ++*pnum;    // so now increment num2 indirectly by dereferencing pnum, which is pointing to num2, num2 is now 4

    printf("num2 to is now %li", num2); // num2 is now 4



    return 0;
}
