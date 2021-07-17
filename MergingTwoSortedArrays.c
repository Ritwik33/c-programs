#include<stdio.h>
#include<conio.h>

void main()

{
    int n1;

    printf("\nEnter number of elements in array-1: ");
    scanf("%d",&n1);

    int i,arr1[n1];

    printf("\nEnter the elements of array-1:\n");

    for(i=0;i<n1;i++)
    {
        printf("arr1[%d] = ",i+1);
        scanf("%d",&arr1[i]);
    }

    printf("\nThe first sorted array is:\n");

    for(i=0;i<n1;i++)
    {
        printf("%d\t",arr1[i]);
    }

    int n2;

    printf("\n\nEnter number of elements in array-2: ");
    scanf("%d",&n2);

    int arr2[n2];

    printf("\nEnter the elements of array-2:\n");

    for(i=0;i<n2;i++)
    {
        printf("arr2[%d] = ",i+1);
        scanf("%d",&arr2[i]);
    }

    printf("\nThe second sorted array is:\n");

    for(i=0;i<n2;i++)
    {
        printf("%d\t",arr2[i]);
    }

    int n3=n1+n2;

    int index=0,index_first=0,index_second=0,arr3[n3];

    while(index_first<n1 && index_second<n2)
    {

        if(arr1[index_first]<arr2[index_second])
        {
            arr3[index]=arr1[index_first];
            index_first++;
        }

        else
        {
            arr3[index]=arr2[index_second];
            index_second++;
        }

        index++;
    }

    if(index_first==n1)
    {
       while(index_second<n2)
       {
           arr3[index]=arr2[index_second];
           index_second++;
           index++;
       }
    }

    else if(index_second==n2)
    {
        while(index_first<n1)
        {
            arr3[index]=arr1[index_first];
            index_first++;
            index++;
        }
    }

    printf("\n\nThe merged sorted array is:\n");

    for(i=0;i<n3;i++)
    {
        printf("%d\t",arr3[i]);
    }

    getch();

}