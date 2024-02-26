#include <stdio.h>

int main()
{
    int gift;
    printf("WELCOME TO AWARD SECTION\nWE WILL AWARD YOU ACCORDING TO YOUR RESULTS :\n\n");

    printf("PRESS 1 IF YOU HAVE PASSED MATHS EXAM ONLY \n");
    printf("PRESS 2 IF YOU HAVE PASSED SCIENCE EXAM ONLY \n");
    printf("PRESS 3 IF YOU HAVE PASSED BOTH \n\n");
    
    printf("Enter : ");

    scanf("%d", &gift);

    if (gift==3)
    {
        printf("\nCONGRATULATIONS !! YOU ARE AWARDED WITH $45M FOR PASSING BOTH MATH AND SCIENCE EXAMINATIONS");
    }
    else if (gift==2)
    {
        printf("\nCONGRATULATIONS !! YOU ARE AWARDED WITH $15M FOR PASSING SCIENCE EXAMINATION");
    }
    else if (gift==1)
    {
        printf("\nCONGRATULATIONS !! YOU ARE AWARDED WITH $15M FOR PASSING MATH EXAMINATION");
    }
    else
    {
        printf("\nSORRY :( IT SEEMS YOU ENTERED WRONG NUMBER\nTRY AGAIN :(");
    }
    return 0;
}
