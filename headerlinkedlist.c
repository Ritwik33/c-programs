#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node{

    int val;
    struct node *next;

}node;

node *create_hll(node *start){

    int num;
    printf("\nEnter value to insert: ");
    scanf("%d",&num);

    node *new_node,*ptr;

    while(num!=-1){

        new_node=(node *)malloc(sizeof(node));
        new_node->val=num;
        new_node->next=NULL;

        if(start==NULL){

            start=(node *)malloc(sizeof(node));
            start->next=new_node;

        }

        else{

            ptr=start;
            while(ptr->next!=NULL)
            ptr=ptr->next;

            ptr->next=new_node;

        }

        printf("\nEnter value to insert: ");
        scanf("%d",&num);

    }

    return start;

}

void display(node *start){

    node *ptr;
    ptr=start->next;

    while(ptr->next!=NULL){

        printf("%d\t",ptr->val);
        ptr=ptr->next;
    }

    printf("%d",ptr->val);

}

void main()

{

    node *start=NULL;

    int option;

    do{

        printf("\n\n****MAIN MENU****\n\n");
        printf("\n1. create header linked list\n");
        printf("\n2. display header linked list\n");
        printf("\n3. EXIT\n");

        printf("\nEnter an option: ");
        scanf("%d",&option);

        switch(option){

            case 1:
            start=create_hll(start);
            break;

            case 2:
            display(start);
            break;
        }
    }while(option!=3);

    printf("\n\n****THANKYOU****\n\n");

    getch();

}