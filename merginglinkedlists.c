#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node{

    int val;
    struct node *next;

}node;

node *create(node *start){

    int num;
    printf("\nEnter the value to insert: ");
    scanf("%d",&num);

    node *new_node,*ptr;

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

        printf("\nEnter the value to insert: ");
        scanf("%d",&num);

    }

    return start;

}

void display(node *start){

    node *ptr;
    ptr=start;

    printf("\nThe linked list is:\n");

    while(ptr->next!=NULL){

        printf("%d\t",ptr->val);
        ptr=ptr->next;

    }

    printf("%d",ptr->val);

}

node *merge(node *start1,node *start2){

    node *ptr;
    ptr=start1;

    while(ptr->next!=NULL)
    ptr=ptr->next;

    ptr->next=start2;

    return start1;

}

void swap(int *p,int *q){

    int temp=*p;
    *p=*q;
    *q=temp;

}

node *sort(node *start){

    node *ptr,*preptr;
    preptr=start;

    while(preptr->next!=NULL){

        ptr=preptr->next;

        while(ptr!=NULL){

            if(preptr->val>ptr->val)
            swap(&preptr->val,&ptr->val);

            ptr=ptr->next;

        }

        preptr=preptr->next;

    }

    return start;

}

void main()

{

    node *start1=NULL,*start2=NULL;

    printf("\nEnter the first sorted linked list:\n");

    start1=create(start1);

    printf("\n\n");

    printf("\nEnter the second sorted linked list:\n");

    start2=create(start2);

    display(start1);

    printf("\n");

    display(start2);

    start1=merge(start1,start2);

    printf("\n");

    printf("\nAfter merging:\n");

    display(start1);

    start1=sort(start1);

    printf("\n");

    printf("\nAfter sorting:\n");

    display(start1);

    getch();

}