#include<stdio.h>
#include<conio.h>

void init(int size,int arr[size])
{
    int i;

    for(i=0;i<size;i++)
    arr[i]=-1;
    
}

void insert(int size,int arr[size],int value)
{
    int key=value%size;

    if(arr[key]==-1)
    {
        arr[key]=value;
        printf("%d inserted at arr[%d]\n",value,key);
    }

    else
    {
        printf("collision:arr[%d] has element %d already!!\n",key,arr[key]);
        printf("unable to insert %d\n",value);
    }
}

void del(int size,int arr[size],int value)
{
    int key=value%size;

    if(arr[key]==value)
    arr[key]=-1;

    else
    printf("%d not present in the hash table\n",value);
}

void search(int size,int arr[size],int value)
{
    int key=value%size;

    if(arr[key]==value)
    printf("\nSearch found.\n");

    else
    printf("\nSearch not found.\n");
}

void print(int size,int arr[size])
{
    int i;

    for(i=0;i<size;i++)
    printf("arr[%d]= %d\n",i,arr[i]);

}



void main()
{
    int size;

    printf("\nEnter size of array: ");
    scanf("%d",&size);

    printf("\n");

    int arr[size];

    init(size,arr);

    insert(size,arr,10);

    insert(size,arr,4);

    insert(size,arr,2);

    insert(size,arr,3);

    printf("\nHash Table:\n");

    print(size,arr);

    printf("\n");

    printf("Deleting value 10...\n");

    del(size,arr,10);

    printf("Deleting value 5...\n");

    del(size,arr,5);

    printf("Hash Table after deletion:\n");

    print(size,arr);

    printf("\n");

    printf("\nSearching value 4...\n");

    search(size,arr,4);

    printf("\nSearching value 10...\n");

    search(size,arr,10);

    getch();

}