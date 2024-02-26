#include <stdio.h>
#define PI 3.14
/*
This is a multiline comment

okh!
*/
int main()
{
    int a = 75;
    const float b = 50.76;
    //PI = 4.56 //cannot do this since PI is a constant
    printf(" beep \a tab character \t\t my backslash \\n %f", PI);

    // b =2.45; //cannot do this since b is constant
    // printf("The value of a is %d and the value of b is %f\n", a, b);
    // printf("%18.4f than", b);

    return 0;
}
