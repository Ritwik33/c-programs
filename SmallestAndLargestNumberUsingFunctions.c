#include<stdio.h>
#include<conio.h>

void read_array(int n,int arr[n])
{
    int i;

    for(i=0;i<n;i++)
    {
        printf("arr[%d] = ",i);
        scanf("%d",&arr[i]);
    }
}

int find_small(int n,int arr[n])
{
    int i,small=arr[0];
    
    for(i=1;i<n;i++)
    {
        if(arr[i]<small)
        {
            small=arr[i];
        }
    }

    return small;
}

int find_largest(int n,int arr[n])

{
    int i,large=arr[0];

    for(i=1;i<n;i++)
    {
        if(arr[i]>large)
        {
            large=arr[i];
        }
    }

    return large;
}

void main()

{
    int n;

    printf("\nEnter the size of the array: ");
    scanf("%d",&n);

    int arr[n];

    read_array(n,arr);

    int smallest,largest;

    smallest=find_small(n,arr);

    largest=find_largest(n,arr);

    printf("\nThe smallest number is %d and the largest number is %d",smallest,largest);

    getch();

    
}

