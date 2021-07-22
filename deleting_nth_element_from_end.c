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

node *delt_from_end(node *start){

    node *ptr;
    ptr=start;
    int count=0;
    while(ptr->next!=NULL){

        count++;
        ptr=ptr->next;

    }

    count++;

    int pos;
    printf("\nEnter position from end: ");
    scanf("%d",&pos);

    ptr=start;
    node *preptr;
    preptr=ptr;
    int i=1;
    while(i<=count-pos){

        preptr=ptr;
        ptr=ptr->next;
        i++;

    }

    preptr->next=ptr->next;

    free(ptr);

    return start;
    
}

int main(){

    start=create(start);
    printf("\nThe Linked List:\n");
    display(start);

    start=delt_from_end(start);
    printf("\nModified Linked List is:\n");
    display(start);

    return 0;
}