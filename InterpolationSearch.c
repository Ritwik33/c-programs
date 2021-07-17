#include<stdio.h>
#include<conio.h>

void main()
{
    int size;

    printf("\nEnter size of array: ");
    scanf("%d",&size);

    int arr[size];

    printf("\nEnter elements in the sorted array:\n");

    int i;

    for(i=0;i<size;i++)
    scanf("%d",&arr[i]);

    for(i=0;i<size;i++)
    printf("%d\t",arr[i]);

    int key;

    printf("\nEnter key to search: ");
    scanf("%d",&key);

    int found=0;
    
    int lo=0,hi=size-1,pos,location;

    while(found==0){

        pos=lo+((key-arr[lo])*(hi-lo))/(arr[hi]-arr[lo]);

        if(arr[pos]==key){
            found=1;
            location=pos;
        }

        else if(arr[pos]>key){
            found=0;
            hi=pos-1;
        }

        else{
            found=0;
            lo=pos+1;
        }


    }

    if(found==1){
        printf("\nlocation= %d",location);
    }

    else if(found==0){
        printf("\nEntered element is not in array.\n");
    }
    
    getch();
    
}