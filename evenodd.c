#include<stdio.h>
#include<conio.h>
int evenodd(int);
int main()

{
    int num,flag;
    printf("\n Enter a number: ");
    scanf("%d",&num);
    flag= evenodd(num);

    if(flag==1)
    printf("%d is EVEN",num);

    else 
    printf("%d is ODD",num);

    getch();

    return 0;

}

int evenodd(int a)
{
    if(a%2==0)
    return 1;

    else
    return 0;

}