#include<stdio.h>

void main()

{
    int n;

    printf("Enter value of n: ");
    scanf("%d",&n);

    int data[n];

    int i;

    for(i=0;i<n;i++)
    scanf("%d",&data[i]);
    

    for(i=0;i<n;i++)
    printf("%d\t",data[i]);

    printf("\n");
    
    int j,temp;

    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<=n-1;j++)
        {
            if(data[i]<data[j])
            {
                temp=data[i];
                data[i]=data[j];
                data[j]=temp;
            }
        }
    }

    for(i=0;i<n;i++)
    printf("%d\t",data[i]);


}