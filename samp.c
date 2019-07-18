//This is a single line comment

/* *** This is a 
Multiline comment
***** */

#include <stdio.h>

int main()
{
    int a = 10, b = 4;

    // relational operators
    // greater than example
    if (a > b)
        printf("a is greater than b\n");
    else
        printf("a is less than or equal to b\n");

    // greater than equal to
    if (a >= b)
        printf("a is greater than or equal to b\n");
    else
        printf("a is lesser than b\n");

    // less than example
    if (a < b)
        printf("a is less than b\n");
    else
        printf("a is greater than or equal to b\n");

    // lesser than equal to
    if (a <= b)
        printf("a is lesser than or equal to b\n");
    else
        printf("a is greater than b\n");

    // equal to
    if (a == b)
        printf("a is equal to b\n");
    else
        printf("a and b are not equal\n");

    // not equal to
    if (a != b)
        printf("a is not equal to b\n");
    else
        printf("a is equal b\n");

    a += 4;
    b -= 10;
    b *= 100;
    a /= b;

    /*  int a = 10, b = 4, res; 
  
    //printing a and b 
    printf("a is %d and b is %d\n", a, b); 
  
    res = a+b; //addition 
    printf("a+b is %d\n", res); 
  
    res = a-b; //subtraction 
    printf("a-b is %d\n", res); 
  
    res = a*b; //multiplication 
    printf("a*b is %d\n", res); 
  
    res = a/b; //division 
    printf("a/b is %d\n", res); 

   */
    return 0;
}