// name/create info etc

#include <stdio.h>

// Create C program that converts number of minutes to days and years
// Program should ask user to enter number of minutes via terminal
// Program should display the output as minutes, and then it's equivalent years and days
// Use type double for all variables, except initial minutes amount as an int

int main()
{
    int minutes = 0;
    double hours = 0.0;
    double days = 0.0;
    double years = 0.0;

    printf("Enter integer amount of minutes:");

    scanf("%d", &minutes);

    hours = minutes / 60.0;

    printf("The integer amount of minutes entered is: %d\n", minutes);
    printf("%d minutes equates to %f hours", minutes, hours);

    return 0;
}
