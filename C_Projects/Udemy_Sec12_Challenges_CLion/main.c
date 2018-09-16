#include <stdio.h>

void pointer_basics();

void pointers_as_parameters(double * x);



int main() {

    pointer_basics();

    double num = 23.45;
    pointers_as_parameters(&num);
    printf("new value of num is: %f\n", num);






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

void pointers_as_parameters(double * x)
{
    double temp = *x;
    *x = temp * temp;
}