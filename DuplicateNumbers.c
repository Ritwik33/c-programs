#include<stdio.h>
#include<conio.h>

void main()

{
    int n;

    printf("\nEnter number of values in the array: ");
    scanf("%d",&n);

    int i,num[n];

    printf("\nEnter the values:\n");

    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }

    int j,flag=0,dup_num[n];

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(num[i]==num[j])
            {
                flag=1;
                printf("\nDuplicate numbers found at locations %d and %d\n",i,j);
            }
            
        }
    }

    if(flag==0)
    {
        printf("\nNo duplicates found.\n");
    }



}