#include<stdio.h>
#include<conio.h>

void main()
{
    int size;

    printf("Enter size: ");
    scanf("%d",&size);

    int arr[size];

    printf("\nEnter elements:\n");

    int i;

    for(i=0;i<size;i++)
    scanf("%d",&arr[i]);

    for(i=0;i<size;i++)
    printf("%d\t",arr[i]);

    i=size-1;
    int j,temp;
    
    while(i>=0)
    {
        j=0;
        while(j<i)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            j++;
        }
        i--;
    }

    printf("\n");

    for(i=0;i<size;i++)
    printf("%d\t",arr[i]);

    getch();
    
}