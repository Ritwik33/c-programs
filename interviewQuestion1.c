#include<stdio.h>
#include<conio.h>

void main()
{
    int size;

    printf("Enter size: ");
    scanf("%d",&size);

    int arr[size];

    int i;

    for(i=0;i<size;i++)
    {
        printf("arr[%d]= ",i);
        scanf("%d",&arr[i]);
    }

    for(i=0;i<size;i++)
    printf("%d\t",arr[i]);

    int *t,*c;

    c=&arr[size];

    t=&arr[size-1];

    int temp;

    while(t>=&arr[0])
    {
        if(*t!=0)
        {
            c--;
            temp=*t;
            *t=*c;
            *c=temp;
        }
        t--;
    }

    printf("\n");

    for(i=0;i<size;i++)
    printf("%d\t",arr[i]);

    getch();


}