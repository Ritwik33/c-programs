#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node{

    int val;
    struct node *next;

}node;

node *create(node *start){

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

void sortedornot(node *start){

    node *pivot,*ptr;
    pivot=start;
    
    int flag;

    while(pivot->next!=NULL){

        ptr=pivot->next;

        while(ptr->next!=NULL){

            if(pivot->val>ptr->val){

                flag=1;
                break;

            }
            ptr=ptr->next;
        }
        pivot=pivot->next;

        if(flag==1)
        break;

    }

    if(flag==1)
    printf("\nunsorted in ascending order\n");

    else
    printf("\nsorted in ascending order\n");

}

void main()

{
    node *start=NULL;

    start=create(start);

    display(start);

    sortedornot(start);

    getch();

}