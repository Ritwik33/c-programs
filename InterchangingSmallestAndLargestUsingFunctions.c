#include<stdio.h>
#include<conio.h>

void read_array(int n,int arr[n])
{
    int i;

    for(i=0;i<n;i++)
    {
        printf("arr[%d] = ",i+1);
        scanf("%d",&arr[i]);
    }

}

int find_small_pos(int n,int arr[n])
{
    int i,pos=0,small=arr[0];

    for(i=1;i<n;i++)
    {
        if(arr[i]<small)
        {
            small=arr[i];
            pos=i;
        }
    }

    return pos;
}

int find_large_pos(int n,int arr[n])
{
    int i,pos=0,large=arr[0];

    for(i=1;i<n;i++)
    {
        if(arr[i]>large)
        {
            large=arr[i];
            pos=i;
        }
    }

    return pos;
}

void interchange(int n,int arr[n])
{
    int small_pos,large_pos;

    small_pos=find_small_pos(n,arr);
    large_pos=find_large_pos(n,arr);

    int temp;

    temp=arr[small_pos];
    arr[small_pos]=arr[large_pos];
    arr[large_pos]=temp;

}

void display_array(int n,int arr[n])
{
    int i;

    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }

}

void main()

{
    
    int n;  

    printf("\nEnter the size of the array: ");
    scanf("%d",&n);

    int arr[n];

    read_array(n,arr);

    printf("\nThe original array is:\n");
    display_array(n,arr);

    printf("\n");

    interchange(n,arr);

    printf("\nThe modified array is:\n");
    display_array(n,arr);
    
    getch();

}