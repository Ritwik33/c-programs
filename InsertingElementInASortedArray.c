#include<stdio.h>
#include<conio.h>

void main()

{
    int n;

    printf("Enter number of elements in the array: ");
    scanf("%d",&n);

    int i,arr[n];

    for(i=0;i<n;i++)
    {
        printf("arr[%d] = ",i);
        scanf("%d",&arr[i]);
    }

    printf("The array before insertion is:\n");

    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }

    int num;

    printf("\nEnter the number to be inserted: ");
    scanf("%d",&num);

    int j;

    for(i=0;i<n;i++)
    {
        if(arr[i]>num)
        {
            for(j=n-1;j>=i;j--)
            {
                arr[j+1]=arr[j];
            }

            arr[i]=num;
            break;
        }
    }

    n++;

    printf("\nThe array after insertion of the element is:\n");

    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}