#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node{

    struct node *prev;
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

        printf("\nEnter value to insert: ");
        scanf("%d",&num);

    }

    return start;

}

void display(node *start){

    node *ptr;
    ptr=start;

    printf("\nThe linked list is:\n");

    while(ptr->next!=start){

        printf("%d\t",ptr->val);
        ptr=ptr->next;

    }

    printf("%d",ptr->val);

}

node *delete(node *start){

    int count=0;

    node *ptr;
    ptr=start;

    while(ptr->next!=start){

        count++;
        ptr=ptr->next;

    }

    count++;

    node *first,*middle,*last;
    first=start,last=start->prev;

    count=count/2;

    middle=start;

    int number=1;

    while(number!=count){

        middle=middle->next;
        number++;

    }

    node *temp;
    temp=start;
    start=start->next;

    last->next=start;
    start->prev=last;

    free(temp);

    last->prev->next=start;
    start->prev=last->prev;

    free(last);

    middle->prev->next=middle->next;
    middle->next->prev=middle->prev;

    free(middle);

    return start;
    
}

void main()
{
    node *start=NULL;

    start=create_ll(start);

    display(start);

    start=delete(start);

    display(start);

}