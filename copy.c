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
    printf("\nEnter value to insert: ");
    scanf("%d",&num);

    node *new_node,*ptr;

    while(num!=-1){

        new_node=(node *)malloc(sizeof(node));
        new_node->val=num;

        if(start==NULL){

            new_node->next=new_node;
            start=new_node;

        }

        else{

            ptr=start;
            while(ptr->next!=start)
            ptr=ptr->next;

            ptr->next=new_node;
            new_node->next=start;

        }

        printf("\nEnter value to insert: ");
        scanf("%d",&num);

    }

    return start;

}

void display(node *start){

    node *ptr;
    ptr=start;

    printf("\nThe resultant linked list is:\n");

    while(ptr->next!=start){

        printf("%d\t",ptr->val);
        ptr=ptr->next;

    }

    printf("%d",ptr->val);

}

node *copy(node *start,node *start1){

    node *ptr,*ptr1;
    ptr=start;

    node *new_node;

    while(ptr->next!=start){

        new_node=(node *)malloc(sizeof(node));
        new_node->val=ptr->val;

        if(start1==NULL){

            new_node->next=new_node;
            start1=new_node;

        }

        else{

            ptr1=start1;
            while(ptr1->next!=start1)
            ptr1=ptr1->next;

            ptr1->next=new_node;
            new_node->next=start1;

        }

        ptr=ptr->next;

    }

    ptr1=start1;
    while(ptr1->next!=start1)
    ptr1=ptr1->next;

    new_node=(node *)malloc(sizeof(node));
    new_node->val=ptr->val;

    ptr1->next=new_node;
    new_node->next=start1;
    
    return start1;

}

void main()
{

    node *start=NULL;

    start=create(start);

    display(start);

    node *start1=NULL;

    start1=copy(start,start1);

    printf("\n");

    display(start1);

    getch();

}