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

    node *ptr,*new_node;

    while(num!=-1){

        new_node=(node *)malloc(sizeof(node));
        new_node->val=num;

        if(start==NULL){

            start=(node *)malloc(sizeof(node));
            start->prev=new_node;
            start->next=new_node;

            new_node->prev=start;
            new_node->next=start;

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
    ptr=start->next;

    while(ptr->next!=start){

        printf("%d\t",ptr->val);
        ptr=ptr->next;

    }

    printf("%d",ptr->val);

}

node *delt_beg(node *start){

    node *ptr;
    ptr=start->next;

    start->next=ptr->next;
    ptr->next->prev=ptr->prev;

    free(ptr);

    return start;

}

node *delt_end(node *start){

    node *ptr;
    ptr=start->prev;

    ptr->prev->next=ptr->next;
    ptr->next->prev=ptr->prev;

    free(ptr);

    return start;

}

node *delt_node(node *start){

    int num;
    printf("\nEnter value to be deleted: ");
    scanf("%d",&num);

    node *ptr;
    ptr=start;

    while(ptr->val!=num)
    ptr=ptr->next;

    ptr->next->prev=ptr->prev;
    ptr->prev->next=ptr->next;

    free(ptr);

    return start;
    
}

int main(){

    start=create(start);
    printf("\nThe linked list is:\n");
    display(start);

    start=delt_beg(start);
    printf("\nThe linked list is:\n");
    display(start);

    start=delt_end(start);
    printf("\nThe linked list is:\n");
    display(start);

    start=delt_node(start);
    printf("\nThe linked list is:\n");
    display(start);

    return 0;
}