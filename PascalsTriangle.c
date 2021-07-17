#include<stdio.h>
#include<conio.h>

void filling_first_column(int size,int arr[size][size])
{
    int i;

    for(i=0;i<size;i++)
    {
        arr[i][0]=1;
    }
}

void pascals_triangle(int size,int arr[size][size])
{
    int i,j,temp;

    for(i=1;i<size;i++)
    {
        temp=0;

        for(j=i;j<size;j++)
        {
            arr[j][i]=arr[j-1][i-1]+temp;
            temp=arr[j][i];
        }
    }
}

void display(int size,int arr[size][size])
{
    int i,j;

    printf("\n\nThe Pascal's Triangle is:\n\n");

    for(i=0;i<size;i++)
    {
        for(j=0;j<=i;j++)
        {
            printf("%d\t",arr[i][j]);
        }

        printf("\n");
    }

}

void main()

{
    int size;

    up:

    printf("\nEnter the size of the array: ");
    scanf("%d",&size);

    int arr[size][size];

    filling_first_column(size,arr);

    pascals_triangle(size,arr);

    display(size,arr);

    int choice;

    printf("\n\nWant to try another size?\n(1=Yes,0=No) ");
    scanf("%d",&choice);

    if(choice==1)
    goto up;

    else if(choice==0)
    printf("\n\nOK Thankyou");

    getch();
}