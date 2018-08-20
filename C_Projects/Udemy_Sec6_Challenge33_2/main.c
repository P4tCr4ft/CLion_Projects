#include <stdio.h>

int main()
{
    int minutes = 0;
    int int_year = 0;
    int int_days = 0;
    double hours = 0;
    double days = 0;
    double years = 0;
    double rem_days = 0;
    double rem_hours = 0;

    printf("Enter integer amount of minutes:");

    scanf("%d", &minutes);

    hours = minutes / 60.0;
    days = hours / 24.0;
    years = days / 365.0;

    int_year = years;
    rem_days = (years - int_year) * 365.0;

    int_days = rem_days;
    rem_hours = (rem_days - int_days) * 24.0;

//    rem_days = years % 1.0;
   // rem_hours = rem_days %

    printf("Amount of minutes entered is: %d\n", minutes);
    printf("%d minutes corresponds to %f hours\n", minutes, hours);
    printf("%d minutes corresponds to %f days\n", minutes, days);
    printf("%d minutes corresponds to %f years\n", minutes, years);
//    printf("int_years is %d\n", int_year);
//    printf("rem_days is %f\n", rem_days);
    printf("%d minutes cooresponds to %d years, %d days and %f hours\n", minutes, int_year, int_days, rem_hours);

    return 0;
}
