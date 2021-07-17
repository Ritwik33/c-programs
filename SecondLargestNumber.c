#include<stdio.h>
#include<conio.h>

void main()

{
    int n;

    printf("Enter number of values in array: ");
    scanf("%d",&n);

    printf("\nEnter the values\n");

    int i,arr[n];

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int large=arr[0];

    for(i=0;i<n;i++)
    {
        if(arr[i]>large)
        {
            large=arr[i];
        }
    }

    printf("\nThe largest value is: %d\n",large);

    int second_large=arr[0];

    for(i=0;i<n;i++)
    {
        if(arr[i]!=large)
        {
            if(arr[i]>second_large)
            {
                second_large=arr[i];
            }
        }
    }

    printf("\nThe second largest value is: %d\n",second_large);

}