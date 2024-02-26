#include<stdio.h>

int main()
{
    int age, marks;
    printf("Enter your age : ");
    scanf("%d", &age);
    printf("Enter your marks : ");
    scanf("%d", &marks);
    switch (age)
    {
    case 15:
        printf("The age is 15\n");
        switch (marks)
        {
        case 56:
            printf("The marks is 56");
            break;
        
        default:
            printf("The marks is not 56");
        }
        break;
    case 18:
        printf("The age is 18");
        break;
    case 45:
        printf("The age is 45");
        break;
    
    default:
    printf("The age is not in eligibility criteria as entered age is %d", age);
        break;
    }
    return 0;
}
