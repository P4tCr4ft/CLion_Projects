#include <stdio.h>

int main()
{
    enum Company{GOOGLE, FACEBOOK, XEROX, YAHOO=10, EBAY, MICROSOFT};

    enum Company google = GOOGLE;
    enum Company xerox = XEROX;
    enum Company ebay = EBAY;

    printf("Company 1 Xerox is %d,\nCompany 2 Google is %d,\nCompany 3 Ebay is %d\n", xerox, google, ebay);

    int num = 10;

    int foo = 20;

    printf("size of num is %d\n", sizeof(num));

    // below ++foo the print statement returns 21
    // below foo++ the print statement returns 20
    printf("increment operator test on foo, foo is %d\n", ++foo);

    printf("foo is %d\n", foo);

    return 0;
}
