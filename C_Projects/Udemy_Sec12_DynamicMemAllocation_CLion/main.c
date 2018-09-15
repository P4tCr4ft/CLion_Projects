#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Can only employ Dynamic Memory Allocation on pointers

// whenever you define a variable in C the compiler allocates correct amount of memory based on type.

// What if you want to create a pointer, but not assign it address-of operator of some existing variable?
// You can dynamically allocate memory to the pointer. You can do this while program is running, you can
// allocate memory as you need it.

// Re static. I think this means it is fixed at runtime. Or put another way, after program has compiled, something that
// is static, is already fixed. It's kind of opposite to dynamic, which is where can allocate as required while program
// is running.

// If you program wants to read data from a file into an array in memory, there are 3 choices regarding
// setting up that array in terms of size/memory;
//      1. define size of array (max no. of elements),
//      2. Use variable-length array (Vector? only avail in C11 I'm pretty sure)
//      3. Best choice - allocate array dynamically using one of C's memory allocation functions

// So Dynamic Mem Alloc has some great advantages. Having to allocate memory at compile time is restrictive
// and cumbersome - if you need more mem (if array is too small, could crash program) and you have
// fix code and re-compile. Plus if you make array too large, you have wasted memory - allocated and not used.
// So Dynamic is much better. As can only do with pointers, is one of the main incentives to
// use pointers in your code. You can allocate memory at runtime, which is just large enough to store
// data, and thus not wasting memory, which is very efficient. Is why C is very good for embedded real-time
// systems.

// Heap Vs Stack
// DMA stores everything on the heap. This memory persists longer, can be managed, re-sized etc, and I believe
// also needs to be cleaned up, deleted etc.
// The stack is more limited, and is where local variables, function args etc, get stored. That is, it forms
// the call stack. Everything related to functions are executed on the stack, the local variables etc.
// When you exit the function, and it goes out of scope, everything gets deleted.
// On the heap, you control when it's created and deleted, so things persist longer. You control this,
// so must monitor when things no longer needed, you need to free up the memory so it can be re-used.
// This is especially crucial on embedded systems where may not have as much mem resources.

// 3 implementations of DMA
// malloc, calloc and realloc

int main() {

    char * str;// declared but not initialised, has no mem address associated with it.
                // remember is best idea to set to NULL, so when check for NULL, if it's
                // not NULL it's because you have set it, not because you have just not
                // initialised it, like above, so not being NULL, if you go ahead and
                // use it, it will hose your program.

    str = (char *)malloc(15*sizeof(char));// malloc returns a void pointer, so needs casting to char pointer

    printf("sizeof malloc char pointer is %d and address is %p\n", sizeof(str), str);// This is just the size of pointer
                                                                                        // ie size required to store an address
                                                                                        // it's not talking about the data

    strcpy(str, "stephen john triplett");

    printf("str is %s, sizeof malloc char pointer str is %d and address is %p\n", str, sizeof(str[0]), str);
    printf("str is %s, sizeof malloc char pointer str is %d and address is %p\n", str, strlen(str), str);
    printf("dereference str pointer is %c\n", *str);

//    str = (char *)realloc(str, 25* sizeof(char));



//    for(int i=0; i<sizeof(str)/sizeof(str[0]); ++i)
//        printf("string element is %s", str[i]);

    for(int i=0; i<strlen(str); ++i)
    {
        printf("string element is %c\n", str[i]);
        printf("string element is %p\n", (void *)str+i);
        printf("string element is %c\n", *(str + i));
    }


    return 0;
}