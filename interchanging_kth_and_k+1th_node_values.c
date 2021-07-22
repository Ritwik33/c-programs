#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node{

    struct node *prev;
    int val;
    struct node *next;

}node;

node *start=NULL;

node *create(node *start){

    int num;
    printf("\nEnter value: ");
    scanf("%d",&num);

    node *new_node,*ptr;

    while(num!=-1){

        new_node=(node *)malloc(sizeof(node));
        new_node->val=num;

        if(start==NULL){

            new_node->prev=new_node;
            new_node->next=new_node;
            start=new_node;

        }

        else{

            ptr=start;
            while(ptr->next!=start)
            ptr=ptr->next;

            ptr->next=new_node;
            new_node->prev=ptr;
            new_node->next=start;
            start->prev=new_node;

        }

        printf("\nEnter value: ");
        scanf("%d",&num);

    }

    return start;

}

void display(node *start){

    node *ptr;
    ptr=start;

    while(ptr->next!=start){

        printf("%d\t",ptr->val);
        ptr=ptr->next;

    }

    printf("%d",ptr->val);

}

void swap(int *p,int *q){
    
    int temp=*p;
    *p=*q;
    *q=temp;
    
}

node *interchange(node *start){

    int pos;
    printf("\nEnter position: ");
    scanf("%d",&pos);

    int i=1;
    node *ptr;
    ptr=start;

    while(i<pos){

        ptr=ptr->next;
        i++;

    }

    swap(&ptr->val,&ptr->next->val);

    return start;

}

int main(){

    start=create(start);
    printf("\nThe Linked List is:\n");
    display(start);

    start=interchange(start);
    printf("\nThe updated linked list is:\n");
    display(start);

    return 0;
}