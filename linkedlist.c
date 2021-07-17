#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>

typedef struct node{

    int val;
    struct node *next;

}node;

node *create_ll(node *start){

    node *new_node,*ptr;

    int num;

    printf("\nEnter the value to insert: ");
    scanf("%d",&num);

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
        printf("\nEnter the value to insert: ");
        scanf("%d",&num);
    }

    return start;

}

void *display(node *start){

    node *ptr;

    ptr=start;

    while(ptr!=NULL){
        printf("%d\t",ptr->val);
        ptr=ptr->next;
    }

}

node *insert_beg(node *start){

    node *new_node;

    int num;

    printf("\nEnter the value to add at the beginning: ");
    scanf("%d",&num);

    new_node=(node *)malloc(sizeof(node));

    new_node->val=num;

    new_node->next=start;

    start=new_node;

    return start;

}

node *insert_end(node *start){

    node *new_node;

    int num;

    printf("\nEnter the value to add at the end: ");
    scanf("%d",&num);

    new_node=(node *)malloc(sizeof(node));

    new_node->val=num;
    new_node->next=NULL;

    node *ptr;

    ptr=start;

    while(ptr->next!=NULL)
    ptr=ptr->next;

    ptr->next=new_node;

    return start;

}

node *insert_before(node *start){

    node *new_node,*ptr,*preptr;

    int num,before;

    printf("\nEnter the value to insert: ");
    scanf("%d",&num);

    printf("\nEnter the value before which the number has to be inserted: ");
    scanf("%d",&before);

    new_node=(node *)malloc(sizeof(node));

    new_node->val=num;

    ptr=start;

    while(ptr->val!=before){

        preptr=ptr;
        ptr=ptr->next;

    }

    preptr->next=new_node;
    new_node->next=ptr;

    return start;

}

node *insert_after(node *start){

    node *new_node,*ptr,*preptr;

    int num,after;

    printf("\nEnter the value to insert: ");
    scanf("%d",&num);

    printf("\nEnter the value after which the number is to be inserted: ");
    scanf("%d",&after);

    new_node=(node *)malloc(sizeof(node));

    new_node->val=num;

    ptr=start;

    preptr=ptr;

    while(preptr->val!=after){

        preptr=ptr;
        ptr=ptr->next;

    }

    preptr->next=new_node;
    new_node->next=ptr;

    return start;
}

node *delete_beg(node *start){

    node *ptr;

    ptr=start;

    start=start->next;

    free(ptr);

    return start;
    
}

node *delete_end(node *start){

    node *ptr,*preptr;

    ptr=start;

    preptr=ptr;

    while(ptr->next!=NULL){
        preptr=ptr;
        ptr=ptr->next;
    }

    preptr->next=NULL;

    free(ptr);

    return start;

}

node *delete_node(node *start){

    int num;

    printf("\nEnter the value of the node to be deleted: ");
    scanf("%d",&num);

    node *ptr,*preptr;

    ptr=start;

    preptr=ptr;

    while(ptr->val!=num){
        preptr=ptr;
        ptr=ptr->next;
    }

    preptr->next=ptr->next;

    free(ptr);

    return start;

}

node *delete_after(node *start){

    int num;

    printf("\nEnter the value after which the node has to be deleted: ");
    scanf("%d",&num);

    node *ptr,*preptr;

    ptr=start;

    preptr=ptr;

    while(preptr->val!=num){

        preptr=ptr;
        ptr=ptr->next;
    }

    preptr->next=ptr->next;

    free(ptr);

    return start;
    
}

node *delete_list(node *start){

    node *ptr;

    if(start!=NULL){
        ptr=start;

        while(ptr!=NULL){
            printf("\n%d is to be deleted next",ptr->val);
            start=delete_beg(ptr);
            ptr=start;
        }
    }

    return start;
}

void main()

{

    node *start;

    start=NULL;

    start = create_ll(start);

    printf("\nLinked List has been created!!\n\n");

    display(start);

    start=insert_beg(start);

    printf("\nModified linked list is:\n");

    display(start);

    start=insert_end(start);

    printf("\nModified linked list is:\n");

    display(start);

    start=insert_before(start);

    printf("\nModified list is:\n");

    display(start);

    start=insert_after(start);

    printf("\nModified list is:\n");

    display(start);

    start=delete_beg(start);

    printf("\n\nModified list after deletion of starting node is:\n");

    display(start);

    start=delete_end(start);

    printf("\n\nModified list after deletion of last node is:\n");

    display(start);

    start=delete_node(start);

    printf("\n\nModified list after deletion of said node is:\n");

    display(start);

    start=delete_after(start);

    printf("\n\nModified list is: \n");

    display(start);

    start=delete_list(start);

    printf("\nmodified list is:\n\n");

    getch();

}