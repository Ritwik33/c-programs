#include<stdio.h>
#include<conio.h>
int main()
{
    int num,i;
    long long int result=1;
    printf("\n Enter a number: ");
    scanf("%d",&num);

    for(i=2;i<=num;i++)
    {
        result*=i;
    }

    printf("The factorial of %d is %lli", num,result);
    getch();

}