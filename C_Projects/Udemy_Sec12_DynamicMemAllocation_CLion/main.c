#include <stdio.h>

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
//      3. allocate array dynamically using one of C's memory allocation routines

int main() {



    return 0;
}