#include<stdio.h>
#include<conio.h>

void main()

{
    int n;

    printf("\nEnter number of values in array: ");
    scanf("%d",&n);

    printf("\nEnter the Elements:\n");
    
    int i,arr[n];

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int min=arr[0],pos=0;

    for(i=1;i<n;i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
            pos=i;
        }
    }

    printf("\nThe minimum value is %d and its position in the array is %d",min,pos);

}