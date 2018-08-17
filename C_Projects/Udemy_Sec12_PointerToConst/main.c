#include <stdio.h>
#include <stddef.h>

int main()
{
    long value = 9999L;
    const long * pvalue = &value;

    // cannot change value of value by deref below

//    *pvalue = 8888L; //no

    // but I can change value itself.

    value = 8888L; //yes

// NOTE: the actual pointer is not constant, can still change the memory address of that,
// it's just saying, for pointer pvalue, as far as variable value is concerned, it's constant.

// but wait, get this, even though you could change the address of what pointer was pointing to,
// you now cannot change the new variable it is now pointing to. So what it is saying, is that
// what ever the pointer is pointing to is const, as far as the pointer is concerned. This must
// be because in the Dec the pointer is const.

    long number = 1111L;
    pvalue = &number; // yes
//    *pvalue = 3333L; // no, what pointer is pointing to is still const.






    const long value2 = 2222L;

// NOTE: the initialization below discards the const from the original dec of value2
// so deref pointer can change value of value2, but cannot directly re-assign value2

    long * pvalue2 = &value2;

    *pvalue2 = 3333L; // yes

//    value2 = 4444L; // no












    return 0;
}
