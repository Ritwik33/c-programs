#include<stdio.h>
#include<conio.h>

void main()
{
    int size;

    printf("\nEnter the size of array: ");
    scanf("%d",&size);

    int arr[size];

    int i;

    printf("\nEnter the elements:\n");

    for(i=0;i<size;i++)
    scanf("%d",&arr[i]);

    int key;

    printf("\nEnter the element to search: ");
    scanf("%d",&key);

    int lowerbound=0,upperbound=size-1,found=0,midpoint,location;

    while(found==0){

        midpoint=lowerbound+(upperbound-lowerbound)/2;

        if(arr[midpoint]==key){
            found=1;
            location=midpoint;
        }

        else if(arr[midpoint]>key){
            found=0;
            upperbound=midpoint-1;
        }

        else{
            found=0;
            lowerbound=midpoint+1;
        }

    }

    if(found==1)
    printf("\nlocation= %d",location);

    else if(found==0)
    printf("\nEntered element is not in array.\n");

    getch();


}