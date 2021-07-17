#include<stdio.h>
#include<conio.h>

void takelements(int size,int arr[size]){

    int i;

    printf("\nEnter elements:\n");

    for(i=0;i<size;i++)
    scanf("%d",&arr[i]);

}

void print(int size,int arr[size]){

    int i;

    for(i=0;i<size;i++)
    printf("%d\t",arr[i]);

}

void swap(int *p,int *q){

    int temp=*p;
    *p=*q;
    *q=temp;

}

int partition(int arr[],int lo,int hi){

    int pivot=arr[hi];

    int i=(lo-1);

    int j;

    for(j=lo;j<hi;j++){

        if(arr[j]<=pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }    
    }

    swap(&arr[i+1],&arr[hi]);

    return (i+1);

}

void quicksort(int arr[],int lo,int hi){

    if(lo<hi){

        int pi=partition(arr,lo,hi);

        quicksort(arr,lo,pi-1);

        quicksort(arr,pi+1,hi);

    }
}

void main()

{
    int size;

    printf("\nEnter size: ");
    scanf("%d",&size);

    int arr[size];

    takelements(size,arr);

    print(size,arr);

    printf("\n");

    quicksort(arr,0,size-1);

    printf("\nThe sorted array is:\n");

    print(size,arr);

    getch();

}