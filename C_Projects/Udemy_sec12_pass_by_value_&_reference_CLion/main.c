#include <stdio.h>
#include <string.h>

void swap(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void swap2(int * x, int * y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Unlike C++ cannot use address-of operator as a parameter type, in function definition)
//void testSwap(int & j, int & k)
//{
//    printf("testing ...");
//}

// So C++ has true 'pass by reference' where you can create ordinary variables that are not pointers
// and pass them to a function that has address-of parameters, effectively passing the address of the
// original variables to function. These parameters then act as alias
// for the original passed in variables, and hence changing the parameter/alias variable in the function actually
// changes the original variable, even though it's outside scope of function. So it kind of makes
// them global in a sense.

// C mimics this behaviour, but I don't think technically called pass by reference, although takes
// a bit more syntax - see swap2 function above, and call to it below, where arguments are address-of variables.


int main() {

    int a = 100;
    printf("Address of a is : %p\n", &a);
    int b = 200;
    printf("Address of b is : %p\n", &b);

    printf("Before swap, a is : %d\n", a);
    printf("Before swap, b is : %d\n", b);

    swap(a, b);

    printf("After swap, a is : %d\n", a);
    printf("After swap, b is : %d\n", b);

    swap2(&a, &b);

    printf("After swap2, a is : %d\n", a);
    printf("After swap2, b is : %d\n", b);

    return 0;
}