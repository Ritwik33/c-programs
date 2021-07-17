#include<stdio.h>
#include<conio.h>

void main()

{
    int size;

    printf("Enter size: ");
    scanf("%d",&size);

    char arr[size][size];

    int i,j;

    for(i=0;i<size;i++)
    {
        for(j=i;j<size;j++)
        {
            arr[j][i]='*';
        }
    }

    for(i=0;i<size;i++)
    {

        for(j=0;j<=i;j++)
        {
            printf("%c\t",arr[i][j]);
        }

        printf("\n");

    }
}