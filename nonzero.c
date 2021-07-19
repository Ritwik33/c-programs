#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node{

    int val;
    struct node *next;

}node;

node *create_ll(node *start){

    int num;
    printf("\nEnter value to insert: ");
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

        printf("\nEnter value to insert: ");
        scanf("%d",&num);

    }

    return start;

}

void display(node *start){

    node *ptr;
    ptr=start;

    while(ptr->next!=NULL){

        printf("%d\t",ptr->val);
        ptr=ptr->next;

    }

    printf("%d",ptr->val);

}

int nonzero(node *start){

    node *ptr;
    ptr=start;

    int count=0;

    while(ptr->next!=NULL){

        if(ptr->val!=0)
        count++;

        ptr=ptr->next;

    }

    if(ptr->val!=0)
    count++;

    return count;

}

void main()

{
    node *start=NULL;

    start=create_ll(start);

    display(start);
    
    int count;
    count=nonzero(start);
    printf("\nThe number of nonzeros are: %d",count);

    getch();

}