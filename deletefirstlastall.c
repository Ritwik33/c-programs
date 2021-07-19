#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node{

    struct node *prev;
    int val;
    struct node *next;

}node;

node *create(node *start){

    int num;
    printf("\nEnter value: ");
    scanf("%d",&num);

    node *new_node,*ptr;

    while(num!=-1){

        new_node=(node *)malloc(sizeof(node));
        new_node->val=num;

        if(start==NULL){

            new_node->prev=NULL;
            new_node->next=NULL;
            start=new_node;

        }

        else{

            ptr=start;
            while(ptr->next!=NULL)
            ptr=ptr->next;

            ptr->next=new_node;
            new_node->prev=ptr;
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

    printf("\nThe linked list is:\n");

    while(ptr->next!=NULL){

        printf("%d\t",ptr->val);
        ptr=ptr->next;

    }

    printf("%d",ptr->val);

}

node *delete_first(node *start){

    int num;
    printf("\nEnter a number: ");
    scanf("%d",&num);
    
}

void main(){

    node *start=NULL;

    int option;

    do{

        printf("\n\n****MAIN MENU****\n\n");
        printf("\n1. create linked list\n");
        printf("\n2. display linked list\n");
        printf("\n3. delete first occurence\n");
        printf("\n4. delete last occurence\n");
        printf("\n5. delete every occurence\n");
        printf("\n6. EXIT\n");

        printf("\nEnter an option: ");
        scanf("%d",&option);

        switch(option){

            case 1:
            start=create(start);
            break;

            case 2:
            display(start);
            break;

            case 3:
            start=delete_first(start);
            break;
        }
    }while(option!=6);

    printf("\n\n****THANKYOU****\n\n");

    getch();

}