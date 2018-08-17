#include <stdio.h>
#include <stddef.h>

int main()
{
    int number = 15;

    int count = 10, x; // initialise count but not x. Note x has a memory address, but nothing stored there.
                        // if try to dereference x, I think it just pulls some random number from stack?

    int * pnum = NULL; // Always a good idea to initialize pointers with a NULL, as ensures it points to nothing.

    int * p_somenum; // declare pointer but not initialized to anything, to see what happens in test

/*

Ok, here's what I've been able to find re NULL pointers, and why it's a good idea to initialize created
pointers to NULL.

Dereferencing a NULL pointer is still a bad thing, as far as I can see, even though some online comments
claim that the address 0x0, which is what NULL sets pointer to, can still store things??? But in my case
using Windows 7 on PRN, it crashed the program.

But from what I can gather, initializing pointers to NULL is a good idea, because it is a widely accepted
practice, and accordingly also widely accepted practice to check for NULL pointer prior to doing something
with pointer, and if NULL, return some nice error that is handled nicely.

If not set to NULL, can be much harder to determine what's going on. That is, if you commonly set pointer to
NULL, then if pointer is not NULL, you can be fairly confident it has a legitimate address, as you have purposefully
set the pointer to an address at some stage. It is basically saying start pointers off with NULL, and then the first
time you use the pointer you give it a legitimate address.

Basically if you just declare a pointer and don't initialise it to NULL, it is potentially a lot more random and dangerous??
In this case below (on Windows 7 PRN) if I print the declared-but-not-initialised-to-anything-(including NULL) pointer,
it prints some random number, which I'm pretty sure is not an address, is not a hex number(in appearance),
but I have no idea what it actually is.

I guess the issue for me is that I thought initializing it to NULL would make it nice and safe. But the annoying/confusing
thing is that even initialised to NULL, dereferencing it can still crash program.

But I understand the point that if your common practice is to initialise them to NULL, and the NULL check says it's
not NULL, then you can have good confidence it has been given a legitimate address properly,
and is not just some random, weird, what-the-heck-is-it number.



@@@@@ Wait..... hang on.... This could be it! If you commonly initialize it to NULL, and check to see if it's NULL,
and it's not NULL, that means you have legitimately given it an address, and therefor it is safe to dereference. @@@@@

 */

//    if(!pnum)
    if(!p_somenum)
    {
//        printf("pointer pnum is NULL\n");
        printf("pointer p_somenum is NULL\n");
        printf("You should now give some nice error stating the pointer is NULL\n");
        printf("You should not try to deref this NULL pointer, as that is still bad\n");
        // So now is safe to dereference, eg in this way, *pnum = 5, I think ...
        //NO!!! Below is also very bad, as crashed program!!
        // which makes sense, as trying to store 5 in an address that doesn't exist,
        // as pnum is NULL, so has no address in it, so cannot store any value in a non-existant address.

//        *pnum = 5; // ^^^^Using deref of a NULL pointer in an assignment like this is very bad also^^^^

    }else{
        printf("pointer p_somenum is not set to NULL, but it exists,\n");
        printf("(therefore !p_somenum is fasle),\n");
        printf("and has been declared without any initialization whatsoever, \n");
        printf("and it is ... ? ... is %p, and if you try to deref this pointer, it is very bad\n", p_somenum);
                                                            // p_some is almost certainly NOT a memory address
                                                            // is some random number, THIS IS VERY BAD!!
                                                            // and if you deref in this way *p_somenum = 5;
                                                            // then very bad memory violation, as doesn't know
                                                            // memory address, and may overwrite, crash, etc.
    }

    pnum = &number;

//    int * pnum = &x;

    int result = 0;

    printf("pnum is %p\n", pnum); // %p is format specifier for pointers, to display memory address stored as value in pointer.
                                    // Note: is memory address of what it's pointing to, ie mem address of number,
                                    // not the actual memory address of the pointer itself.

    printf("numbers memory address is %p\n", &number); // this is exactly the same as pnum
    printf("pnum's own memory address is %p\n", (void*)&pnum); // this is actual memory address of the pointer itself.
                                                                // this worked without using cast to (void*) as well, gave same result

    printf("size of pointer is %d\n", (int)sizeof(pnum)); // pointers are 4 bytes on this OS (PRN), so hexadecimal addresses only 8 digits
                                                        // again, tutorial states above needs to cast to (int) before sizeof(pnum)
                                                        // but in this case mine works fine without it.

//    result = *pnum + 5;
    result = *pnum ; // dereference pnum to get the value that is stored at the address the pointer points to

    printf("result is %i\n", result);

    *pnum += 25; // this increments the value of the number variable by 25
                    // the use of dereference operator *pnum is identical to using the variable number in an expression

    printf("number is now %d\n", number);


    return 0;
}
