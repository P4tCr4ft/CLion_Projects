#include <stdio.h>
#include <stddef.h>

int main()
{
    int count = 43;

    int * const pcount = &count; // defines a constant pointer
                                    // always points to same thing
                                    // address stored cannot be changed
    int item = 34;

//    pcount = &item; // No

    // Note: can still change value, unlike pointer to constant, where cannot change value

    *pcount = 345; // Yes






// Can also create a constant pointer that points to a value that is constant

    int item2 = 25;

    const int * const pitem = &item2; // constant pointer to a constant, so everything is fixed.
                                        // cannot change the address stored in pitem
                                        // cannot use pitem to modify what it points to


    // Note: can still change item2 through direct re-assignment and not using pointer

    item2 = 16; // yes

    // If want to lock item2 down, then declare as const as well, eg,

//    const int item2 = 12;

    return 0;
}
