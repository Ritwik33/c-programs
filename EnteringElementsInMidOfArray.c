#include<stdio.h>
#include<conio.h>

void main()

{
    int n;

    printf("Enter number of values of array: ");
    scanf("%d",&n);

    int i,arr[n];

    for(i=0;i<n;i++)
    {
        printf("arr[%d] = ",i);
        scanf("%d",&arr[i]);
    }

    printf("The array before insertion of the element is:\n");

    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }

    int val;

    printf("\nEnter the value to be inserted: ");
    scanf("%d",&val);

    int pos;

    printf("Enter the position where the number is to be inserted: ");
    scanf("%d",&pos);

    for(i=n-1;i>=pos;i--)
    {
        arr[i+1]=arr[i];
    }

    n+=1;

    arr[pos]=val;

    printf("\nThe array after insertion of one element is:\n");

    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }


}