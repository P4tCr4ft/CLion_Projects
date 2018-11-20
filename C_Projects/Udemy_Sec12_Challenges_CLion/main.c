#include <stdio.h>
#include <stdlib.h>

void pointer_basics();

// CLion calls this prototype below the declaration, and doesn't need the const here
void pointers_Pass_by_Ref_square(double *x);

int pointers_calc_string_length(const char * pChar);



int main() {

    pointer_basics();

    double num = 23.45;
    pointers_Pass_by_Ref_square(&num);
    printf("new value of num is: %f\n", num);

    // Instead of passing address of existing variable num above,
    // can dynamically create some memory and pass that pointer pNum instead, below

    double * pNum = (double *)malloc(sizeof(double));// malloc returns void pointer (void *) so cast to double
    *pNum = 63.78;// have to assign a value to address stored in pointer, so can deref in the function
    pointers_Pass_by_Ref_square(pNum);
    printf("New value of pNum is: %f\n", *pNum);


    // In C the best practice way to create a string is to declare a char array with a string literal,
    // and not specifying a size. This way the compiler automatically allocates the correct size and
    // compiler also automatically puts the null terminator character \0 on the end in the array.
    // this (null char) is important for looping thru char etc, using while loop
    char someString[] = "A nice string";
    int length = pointers_calc_string_length(someString);
    printf("The length of someString is: %d\n", length);

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

// CLion calls this below the definition and this is where the const takes effect
void pointers_Pass_by_Ref_square(double * const x)// const pointer so can't change address that's stored in it
                                            // but can change what it's pointing to
{
    *x = (*x) * (*x);
}

int pointers_calc_string_length(const char * pChar)
{

    const char * startPtr = pChar;

    int length = 0;

//    long start = (long)(pChar);

    while(*pChar)
    {
        printf("deref pchar is: %c\n", *pChar);
        ++pChar;
    }

//    length = (int)((long)(pChar) - start);
    length = (int)(pChar - startPtr);

    return length;






}