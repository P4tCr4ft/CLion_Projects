#include <stdio.h>
#include <stdlib.h>

void pointer_basics();

void pointers_Pass_by_Ref_square(double * const x);



int main() {

    pointer_basics();

    double num = 23.45;
    pointers_Pass_by_Ref_square(&num);
    printf("new value of num is: %f\n", num);

    // Instead of passing address of existing variable num above,
    // can dynamically create some memory and pass that pointer pNum instead, below

    double * pNum = (double *)malloc(sizeof(double));// malloc returns void pointer (void *) so cast to double
    *pNum = 63.78;
    pointers_Pass_by_Ref_square(pNum);
    printf("New value of pNum is: %f\n", *pNum);



    return 0;
}

void pointer_basics()
{
    int num = 10;
    int * pNum = NULL;
    pNum = &num;

    printf("Address of the pointer (it's own address) is: %p\n", &pNum);// %p expects void* so implicit cast (void*) here
    printf("Value of the pointer pNum (address of num %p) is: %p\n",&num, pNum);
    printf("Value of what pointer is pointing to (num) is: %d\n", *pNum);// indirection operator or dereference
}

void pointers_Pass_by_Ref_square(double * const x)// const pointer so can't change address that's stored in it
                                            // but can change what it's pointing to
{
    *x = (*x) * (*x);
}