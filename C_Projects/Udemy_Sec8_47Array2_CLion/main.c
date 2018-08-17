#include <stdio.h>

int main()
{
    int grades[10]; // array storing 10 elements
    long sum = 0.0;
    float average = 0.0f;

    printf("Enter 10 grades:\n");

    for(int i=0; i<5; ++i)
    {
        printf("%d>", i + 1);
        scanf("%d", &grades[i]);
        sum += grades[i];
        average = (float)(sum / (i + 1));
    }

    printf("\nThe average grade is: %.2f", average);

    return 0;
}
