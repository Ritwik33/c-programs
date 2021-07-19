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

    printf("\nThe resultant linked list is:\n");

    while(ptr->next!=NULL){

        printf("%d\t",ptr->val);
        ptr=ptr->next;

    }

    printf("%d",ptr->val);
    
}

node *duplicate(node *start){

    node *pivot,*ptr,*preptr,*temp;
    pivot=start;

    while(pivot->next!=NULL){

        preptr=pivot;
        ptr=pivot->next;

        if(ptr->val==pivot->val){

            temp=ptr;
            ptr=ptr->next;
            free(temp);
            preptr->next=ptr;

        }

        else
        pivot=pivot->next;

    }

    return start;

}

void main()

{

    node *start=NULL;

    start=create_ll(start);

    display(start);

    start=duplicate(start);

    printf("\n");

    display(start);

    getch();

}