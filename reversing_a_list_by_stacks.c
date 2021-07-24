#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10

int arr[MAX],stack[MAX],top=-1;

void push(int val){

    if(top==MAX-1)
    printf("\nSTACK OVERFLOW\n");

    else
    stack[++top]=val;

}

int pop(){

    int val;

    if(top==-1){

        val=-999;
        printf("\nSTACK UNDERFLOW\n");

    }

    else
    val=stack[top--];

    return val;

}

int main(){

    int size;
    printf("\nEnter size of array: ");
    scanf("%d",&size);

    printf("\nEnter elements of array:\n");

    int i;
    for(i=0;i<size;i++)
    scanf("%d",&arr[i]);

    printf("\nThe array is:\n");
    for(i=0;i<size;i++)
    printf("%d\t",arr[i]);

    for(i=0;i<size;i++)
    push(arr[i]);

    int val;

    for(i=0;i<size;i++){

        val=pop();
        if(val!=-999)
        arr[i]=val;

    }

    printf("\nThe reversed list is:\n");

    for(i=0;i<size;i++)
    printf("%d\t",arr[i]);

    return 0;
}