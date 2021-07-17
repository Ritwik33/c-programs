#include<stdio.h>
#include<conio.h>

void main()

{
    int n;
    
    printf("Enter the number of values in the array: ");
    scanf("%d",&n);

    int i,arr[n];

    for(i=0;i<n;i++)
    {
        printf("arr[%d]= ",i);
        scanf("%d",&arr[i]);
    }

    printf("The array is:\n");

    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }

    int del_num,pos;

    printf("\nEnter the value to be deleted: ");
    scanf("%d",&del_num);

    for(i=0;i<n;i++)
    {
        if(arr[i]==del_num)
        {
            pos=i;
        }
    }

    for(i=pos;i<n;i++)
    {
        arr[i]=arr[i+1];
    }

    n--;

    printf("\nThe array after deletion is:\n");

    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }


}