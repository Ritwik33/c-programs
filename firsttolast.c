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
    printf("\nEnter -1 to end\n");
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

node *firsttolast(node *start){

    int temp=start->val;

    node *ptr;
    ptr=start;
    start=start->next;

    free(ptr);

    ptr=start;

    while(ptr->next!=NULL)
    ptr=ptr->next;

    node *new_node;
    new_node=(node *)malloc(sizeof(node));

    ptr->next=new_node;
    new_node->next=NULL;
    new_node->val=temp;

    return start;

}

int main(){

    start=create(start);
    printf("\nThe original linked list is:\n");
    display(start);

    start=firsttolast(start);
    printf("\nThe updated list is:\n");
    display(start);

    return 0;

}