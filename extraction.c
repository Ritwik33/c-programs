#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node{

    int val;
    struct node *next;

}node;

void main()

{
    int num;
    printf("\nEnter a number: ");
    scanf("%d",&num);

    int temp;
    int arr[10];

    int i=0,count=0;

    while(num!=0){

        temp=num%10;
        arr[i]=temp;
        num-=temp;
        num/=10;
        i++;
        count++;

    }

    node *ptr,*new_node,*start=NULL;

    i=count-1;

    while(i>=0){

        new_node=(node *)malloc(sizeof(node));
        new_node->val=arr[i];

        if(start==NULL){

            new_node->next=NULL;
            start=new_node;

        }

        else{

            ptr=start;
            while(ptr->next!=NULL)
            ptr=ptr->next;

            ptr->next=new_node;
            new_node->next=NULL;
            
        }

        i--;

    }

    printf("\n");

    ptr=start;

    while(ptr->next!=NULL){

        printf("%d\t",ptr->val);
        ptr=ptr->next;

    }

    printf("%d",ptr->val);

    getch();

}