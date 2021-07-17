#include<stdio.h>
#include<conio.h>

void elements(int *size,int arr[*size]){

    int i;

    for(i=0;i<*size;i++)
    scanf("%d",&arr[i]);

}

void print(int *size,int arr[*size]){

    int i;

    for(i=0;i<*size;i++)
    printf("%d\t",arr[i]);
}

void swap(int *p,int *q){
    int temp=*p;
    *p=*q;
    *q=temp;
}

void bubblesort(int *size,int arr[*size]){

    int i,j;

    for(i=0;i<*size-1;i++)
    {
        for(j=0;j<*size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            swap(&arr[j],&arr[j+1]);
        }
    }
    
}

void selectionsort(int *size,int arr[*size]){

    int i,j,min;

    for(i=0;i<*size-1;i++){

        min=i;

        for(j=i+1;j<*size;j++){

            if(arr[j]<arr[min]){

                min=j;

            }
        }

        swap(&arr[min],&arr[i]);

    }

}

void insertionsort(int *size,int arr[*size]){

    int i,j,key;

    for(i=1;i<*size;i++){

        key=arr[i];

        j=i-1;

        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void shellsort(int *size,int arr[*size]){

    int i,interval,temp,j;

    for(interval=*size/2;interval>0;interval/=2){

        for(i=interval;i<*size;i++){
            temp=arr[i];

            for(j=i;j>=interval&&arr[j-interval]>temp;j-=interval){
                arr[j]=arr[j-interval];
            }
            arr[j]=temp;
        }
    }
}

int partition(int size,int arr[size],int low,int high){
    int pivot=arr[high];

    int i=low-1;

    for(int j=low;j<=high-1;j++){
        if(arr[j]<=pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);

    return (i+1);
}

void quicksort(int size,int arr[size],int low,int high){

    if(low<high){
        int pi=partition(size,arr,low,high);

        quicksort(size,arr,low,pi-1);

        quicksort(size,arr,pi+1,high);

    }
}

void main()
{
    int size;

    printf("\nEnter size of array: ");
    scanf("%d",&size);

    int arr[size];

    printf("\nEnter elements:\n");

    elements(&size,arr);

    print(&size,arr);

    bubblesort(&size,arr);

    printf("\n");

    print(&size,arr);

    selectionsort(&size,arr);

    printf("\n");

    print(&size,arr);

    insertionsort(&size,arr);

    printf("\n");

    print(&size,arr);

    shellsort(&size,arr);

    printf("\n");

    print(&size,arr);

    int low=0,high=size-1;

    quicksort(size,arr,low,high);

    printf("\n");

    print(&size,arr);

    getch();

}