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
    printf("\nEnter value: ");
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

            ptr=start->prev;

            ptr->next=new_node;
            new_node->prev=ptr;
            new_node->next=start;
            start->prev=new_node;

        }

        printf("\nEnter value: ");
        scanf("%d",&num);

    }

    printf("\nLinked list created\n");

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

node *insert_beg(node *start){

    int num;
    printf("\nEnter the value to insert at beginning: ");
    scanf("%d",&num);

    node *new_node;
    new_node=(node *)malloc(sizeof(node));
    new_node->val=num;

    new_node->next=start;
    new_node->prev=start->prev;
    start->prev->next=new_node;
    start->prev=new_node;

    start=new_node;

    printf("\nLinked list updated\n");

    return start;

}

node *insert_end(node *start){

    int num;
    printf("\nEnter a value to insert at beginning: ");
    scanf("%d",&num);

    node *new_node;
    new_node=(node *)malloc(sizeof(node));
    new_node->val=num;

    node *ptr;
    ptr=start->prev;

    new_node->prev=ptr;
    new_node->next=start;
    start->prev=new_node;
    ptr->next=new_node;

    printf("\nLinked list updated\n");

    return start;

}

node *delete_beg(node *start){

    node *ptr;
    ptr=start;

    start->prev->next=start->next;
    start->next->prev=start->prev;
    start=start->next;

    free(ptr);

    printf("\nLinked list updated\n");

    return start;

}

node *delete_end(node *start){

    node *ptr;
    ptr=start->prev;

    ptr->prev->next=start;
    start->prev=ptr->prev;

    free(ptr);

    printf("\nLinked list updated\n");

    return start;

}

node *delete_node(node *start){

    int num;
    printf("\nEnter the value of the node to be deleted: ");
    scanf("%d",&num);

    node *ptr;
    ptr=start;

    while(ptr->val!=num)
    ptr=ptr->next;

    ptr->prev->next=ptr->next;
    ptr->next->prev=ptr->prev;

    free(ptr);

    printf("\nLinked list updated\n");

    return start;

}

node *delete_list(node *start){

    node *ptr;
    ptr=start;

    while(ptr->next!=start)
    ptr=delete_end(ptr);

    free(ptr);

    start=NULL;

    return start;

}

void main()

{

    node *start=NULL;

    int option;

    do{

        printf("\n\n****MAIN MENU****\n\n");
        printf("\n1. create_ll\n");
        printf("\n2. display ll\n");
        printf("\n3. insert beginning\n");
        printf("\n4. insert end\n");
        printf("\n5. delete beginning\n");
        printf("\n6. delete end\n");
        printf("\n7. delete node\n");
        printf("\n8. delete list\n");
        printf("\n9. EXIT\n");

        printf("\nEnter an option: ");
        scanf("%d",&option);

        switch(option){

            case 1:
            start=create_ll(start);
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
            start=delete_beg(start);
            break;

            case 6:
            start=delete_end(start);
            break;

            case 7:
            start=delete_node(start);
            break;

            case 8:
            start=delete_list(start);
            break;

        }      

    }while(option!=9);

    printf("\n\n****THANKYOU****\n\n");

    getch();

}