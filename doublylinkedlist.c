#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node{

    struct node *prev;
    int val;
    struct node *next;

}node;

node *create_dll(node *start){

    int num;
    printf("\nEnter value to insert(Enter -1 to end): ");
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

        printf("\nEnter value to insert: ");
        scanf("%d",&num);

    }

    printf("\nDLL created\n");

    return start;

}

void display(node *start){

    node *ptr;
    ptr=start;

    printf("\nThe dll is:\n");

    while(ptr->next!=NULL){

        printf("%d\t",ptr->val);
        ptr=ptr->next;

    }

    printf("%d",ptr->val);

}

node *insert_beg(node *start){

    int num;
    printf("\nEnter value to insert: ");
    scanf("%d",&num);

    node *new_node;

    new_node=(node *)malloc(sizeof(node));
    new_node->val=num;
    new_node->prev=NULL;
    new_node->next=start;

    start=new_node;

    printf("\ndll updated\n");

    return start;

}

node *insert_end(node *start){

    node *ptr;
    ptr=start;

    node *new_node;
    new_node=(node *)malloc(sizeof(node));

    int num;
    printf("\nEnter value to insert at end: ");
    scanf("%d",&num);

    new_node->val=num;
    new_node->next=NULL;

    while(ptr->next!=NULL)
    ptr=ptr->next;

    ptr->next=new_node;
    new_node->prev=ptr;

    printf("\nDLL updated\n");
    
    return start;

}

node *insert_after(node *start){

    int num;
    printf("\nEnter value of the node: ");
    scanf("%d",&num);

    int after;
    printf("\nEnter value after which it is to be inserted: ");
    scanf("%d",&after);

    node *new_node;
    new_node=(node *)malloc(sizeof(node));
    new_node->val=num;

    node *ptr;
    ptr=start;

    while(ptr->val!=after)
    ptr=ptr->next;

    new_node->next=ptr->next;
    ptr->next->prev=new_node;
    ptr->next=new_node;
    new_node->prev=ptr;

    printf("\nDLL updated\n");

    return start;

}

node *insert_before(node *start){

    int num;
    printf("\nEnter value to insert: ");
    scanf("%d",&num);

    int before;
    printf("\nEnter value before which it is to be inserted: ");
    scanf("%d",&before);

    node *new_node;
    new_node=(node *)malloc(sizeof(node));
    new_node->val=num;

    node *ptr;
    ptr=start;

    while(ptr->val!=before)
    ptr=ptr->next;

    ptr->prev->next=new_node;
    new_node->prev=ptr->prev;
    new_node->next=ptr;
    ptr->prev=new_node;

    printf("\nDLL updated\n");

    return start;

}

node *delt_start(node *start){

    node *ptr;
    ptr=start;

    start=start->next;

    start->prev=NULL;

    free(ptr);

    printf("\nDLL updated\n");

    return start;

}

node *delt_end(node *start){

    node *ptr;
    ptr=start;

    while(ptr->next!=NULL)
    ptr=ptr->next;

    ptr->prev->next=NULL;

    free(ptr);

    printf("\nDLL updated\n");

    return start;

}

node *delt_after(node *start){

    node *ptr;
    ptr=start;

    int num;
    printf("\nEnter value of the node after which the node is to be deleted: ");
    scanf("%d",&num);

    while(ptr->val!=num)
    ptr=ptr->next;

    ptr=ptr->next;

    ptr->prev->next=ptr->next;
    ptr->next->prev=ptr->prev;

    free(ptr);

    printf("\nDLL updated\n");

    return start;

}

node *delt_before(node *start){

    node *ptr;
    ptr=start;

    int num;
    printf("\nEnter node-value before which deletion is to be done: ");
    scanf("%d",&num);

    while(ptr->val!=num)
    ptr=ptr->next;

    ptr=ptr->prev;

    ptr->prev->next=ptr->next;
    ptr->next->prev=ptr->prev;

    free(ptr);

    printf("\nDLL updated\n");

    return start;

}

void main()

{

    node *start;
    start=NULL;

    int option;

    do{

    printf("\n\n****MAIN MENU****\n\n");
    printf("\n1. create dll\n");
    printf("\n2. display dll\n");
    printf("\n3. insert beginning\n");
    printf("\n4. insert end\n");
    printf("\n5. insert a node after a node\n");
    printf("\n6. insert a node before a node\n");
    printf("\n7. delete first node\n");
    printf("\n8. delete last node\n");
    printf("\n9. delete a node after a node\n");
    printf("\n10. delete a node before a node\n");
    printf("\n11. EXIT\n");

    printf("\nEnter an option from the main menu: ");
    scanf("%d",&option);

    switch(option){

        case 1:
        start=create_dll(start);
        break;

        case 2:
        display(start);
        break;

        case 3:
        start=insert_beg(start);
        break;

        case 4:
        start=insert_end(start);
        break;

        case 5:
        start=insert_after(start);
        break;

        case 6:
        start=insert_before(start);
        break;

        case 7:
        start=delt_start(start);
        break;

        case 8:
        start=delt_end(start);
        break;

        case 9:
        start=delt_after(start);
        break;

        case 10:
        start=delt_before(start);
        break;

    }

    }while(option!=11);

    printf("\n\n***Thankyou***\n\n");

    getch();
    
}

