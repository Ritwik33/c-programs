#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node{

    int val;
    struct node *next;

}node;

node *start=NULL;

node *create(node *start){

    int num;
    printf("\nEnter value: ");
    scanf("%d",&num);

    node *ptr,*new_node;

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

        printf("\nEnter value: ");
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

node *reverse(node *start){

    node *prev=NULL,*curr,*next=NULL;
    curr=start;

    while(curr!=NULL){

        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;

    }

    start=prev;

    return start;

}

int main(){

    start=create(start);
    printf("\nOriginal list:\n");
    display(start);

    start=reverse(start);
    printf("\nReversed list:\n");
    display(start);

    return 0;

}