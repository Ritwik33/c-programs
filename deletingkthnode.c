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

node *deltkth(node *start){

    int num;
    printf("\nEnter the node number: ");
    scanf("%d",&num);

    node *ptr,*preptr;
    ptr=start,preptr=ptr;
    int count=1;
    while(count<num){

        preptr=ptr;
        ptr=ptr->next;
        count++;

    }

    preptr->next=ptr->next;
    free(ptr);

    return start;
    
}

int main(){

    start=create(start);
    printf("\nThe linked list is:\n");
    display(start);

    start=deltkth(start);
    printf("\nThe linked list is:\n");
    display(start);

    return 0;
}