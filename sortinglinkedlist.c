#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>

typedef struct node{

    int val;
    struct node *next;

}node;

node *create_list(node *start){

    node *new_node,*ptr;

    int num;

    printf("\nEnter the value to be inserted: ");
    scanf("%d",&num);

    while(num!=-1){

        new_node=(node *)malloc(sizeof(node));

        new_node->val=num;

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

        printf("\nEnter the value to be inserted: ");
        scanf("%d",&num);
    }

    return start;

}

void display(node *start){

    node *ptr;

    ptr=start;

    printf("\nThe linked list is:\n");

    while(ptr!=NULL){
        printf("%d\t",ptr->val);
        ptr=ptr->next;
    }

}

void swap(int *p,int *q){

    int temp=*p;
    *p=*q;
    *q=temp;
    
}

node *sort(node *start){

    node *ptr1,*ptr2;

    ptr1=start;

    while(ptr1->next!=NULL){

        ptr2=ptr1->next;

        while(ptr2!=NULL){

            if(ptr1->val>ptr2->val){

                swap(&ptr1->val,&ptr2->val);

            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }

    return start;

}

void main()
{

    node *start;
    start=NULL;

    start=create_list(start);

    display(start);

    start=sort(start);

    display(start);

    getch();

}