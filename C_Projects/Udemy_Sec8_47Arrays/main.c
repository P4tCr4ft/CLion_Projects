#include <stdio.h>

int main()
{
    int some_array [5]; // has 10 elements

    for(int i=0; i<5; i++)
    {
        some_array[i] = i;

    }


    for(int i=0; i<5; i++)
    {
        printf("Element %d in some_array is %d\n", i, some_array[i]);

    }









    // in this case the output is the same whether use i++ or ++i ...

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            printf("i is %d\n", i);
            printf("j is %d\n", j);
        }
        printf("\n");

    }


    return 0;
}
