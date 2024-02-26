#include<stdio.h>

int main()
{
    int a;
    printf("WELCOME TO OUR QUIZ SECTION : \nSO YOUR FIRST QUESTION IS :\n\nIN WHICH DIRECTION SUN RISES ?\n  ");
    printf("1. NORTH\t\t2. EAST\n  3. SOUTH\t\t4. WEST\n\n");
    printf("YOUR ANSWER IS : ");
    scanf("%d", &a);
    switch (a)
    {
    case 1:
        printf("SORRY YOUR ANSWER IS WRONG");
        break;
    case 2:
        printf("CONGRATULATIONS !! EAST IS THE RIGHT ANSWER");
        break;
    case 3:
        printf("SORRY YOUR ANSWER IS WRONG");
        break;
    case 4:
        printf("SORRY YOUR ANSWER IS WRONG");
        break;
    
    default:
        printf("PLEASE ENTER A VALID OPTION");
    }
    return 0;
}
