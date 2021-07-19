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
    printf("\nEnter value to insert in LL: ");
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

        printf("\nEnter value to insert in LL: ");
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

int occurences(node *start,int choice){

    node *ptr;
    ptr=start;

    int count=0;

    while(ptr->next!=NULL){

        if(ptr->val==choice){

            count++;

        }

        ptr=ptr->next;

    }

    if(ptr->val==choice)
    count++;

    return count;

}

void main()

{

    node *start=NULL;

    int choice;
    printf("\nEnter the value: ");
    scanf("%d",&choice);

    start=create_ll(start);

    display(start);

    int count;

    count=occurences(start,choice);

    printf("\nTotal number of occurences of %d is %d\n",choice,count);

    getch();
    
}