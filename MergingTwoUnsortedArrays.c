#include<stdio.h>
#include<conio.h>

void main()

{

    int n1;

    printf("\nEnter number of elements in array1: ");
    scanf("%d",&n1);

    int arr1[n1];

    printf("\nEnter elements of array 1:\n");

    int i;

    for(i=0;i<n1;i++)
    {
        printf("arr1[%d] = ",i+1);
        scanf("%d",&arr1[i]);
    }

    printf("\nThe first array is:\n");

    for(i=0;i<n1;i++)
    {
        printf("%d\t",arr1[i]);
    }
    
    int n2;

    printf("\n\nEnter number of elements in array2: ");
    scanf("%d",&n2); 

    int arr2[n2];

    printf("\nEnter the elements of array2:\n");

    for(i=0;i<n2;i++)
    {
        printf("arr2[%d] = ",i+1);
        scanf("%d",&arr2[i]);
    }

    printf("\nThe second array is:\n");

    for(i=0;i<n2;i++)
    {
        printf("%d\t",arr2[i]);
    }

    int n3=n1+n2;

    int arr3[n3];

    for(i=0;i<n3;i++)
    {
        if(i<n1)
        {
            arr3[i]=arr1[i];
        }

        else if(i>=n1)
        {
            arr3[i]=arr2[i-n1];
        }
    }

    printf("\n\nThe merged array is:\n");

    for(i=0;i<n3;i++)
    {
        printf("%d\t",arr3[i]);
    }

    getch();

}