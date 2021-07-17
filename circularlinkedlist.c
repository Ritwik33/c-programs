#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>

typedef struct node{

    int val;
    struct node *next;

}node;

node *create_cll(node *start){

    int num;

    printf("\nEnter the data\n(Enter -1 to end)\n ");
    scanf("%d",&num);

    node *new_node,*ptr;

    while(num!=-1){

        new_node=(node *)malloc(sizeof(node));
        new_node->val=num;

        if(start==NULL){

            new_node->next=new_node;
            start=new_node;

        }

        else{

            ptr=start;

            while(ptr->next!=start)
            ptr=ptr->next;

            ptr->next=new_node;
            new_node->next=start;

        }

        printf("\nEnter the data: ");
        scanf("%d",&num);

    }

    printf("\nCLL created\n");
    
    return start;
    
}

void *display(node *start){

    node *ptr;
    ptr=start;

    printf("\nThe CLL is:\n");

    while(ptr->next!=start){

        printf("%d\t",ptr->val);
        ptr=ptr->next;

    }

    printf("%d",ptr->val);
    
}

node *insert_beg(node *start){

    int num;

    printf("\nEnter the node value: ");
    scanf("%d",&num);

    node *new_node;
    new_node=(node *)malloc(sizeof(node));
    new_node->val=num;

    node *ptr;
    ptr=start;

    new_node->next=start;

    while(ptr->next!=start)
    ptr=ptr->next;

    ptr->next=new_node;
    start=new_node;

    printf("\nCLL updated.\n");

    return start;

}

node *insert_end(node *start){

    node *ptr;
    ptr=start;

    int num;

    printf("\nEnter the node value: ");
    scanf("%d",&num);

    node *new_node;
    new_node=(node *)malloc(sizeof(node));
    new_node->val=num;
    new_node->next=start;

    while(ptr->next!=start)
    ptr=ptr->next;

    ptr->next=new_node;

    printf("\nCLL updated\n");

    return start;

}

node *delt_beg(node *start){

    node *ptr;
    ptr=start;

    while(ptr->next!=start)
    ptr=ptr->next;

    node *temp;
    temp=start;

    ptr->next=temp->next;

    start=temp->next;

    free(temp);

    printf("\nCLL updated\n");

    return start;
    
}

node *delt_end(node *start){

    node *ptr,*preptr;

    ptr=start;
    preptr=ptr;

    while(ptr->next!=start){

        preptr=ptr;
        ptr=ptr->next;

    }

    preptr->next=ptr->next;
    free(ptr);

    printf("\nCLL updated\n");

    return start;

}

node *delt_after(node *start){

    int num;

    printf("\nEnter the number after which deletion is to be done: ");
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

    printf("\nCLL updated\n");

    return start;
    
}

node *delt_list(node *start){

    node *ptr,*preptr;
    ptr=start,preptr=ptr;
    
    while(ptr->next!=start){

        preptr=ptr;
        free(preptr);
        ptr=ptr->next;

    }

    free(ptr);

    start=NULL;

    printf("\nEntire list deleted\n");

    return start;

}

void main()

{

    node *start=NULL;

    int option;

    do{

        printf("\n\n****MAIN MENU****\n\n");
        printf("\n1. Create linked list:\n");
        printf("\n2. display linked list\n");
        printf("\n3. add a node at the beginning\n");
        printf("\n4. add a node at the end\n");
        printf("\n5. delete a node from the beginning\n");
        printf("\n6. delete a node from the end\n");
        printf("\n7. delete a node after a given node\n");
        printf("\n8. delete the entire list\n");
        printf("\n9. EXIT\n");
        printf("\n\nEnter a choice: ");

        scanf("%d",&option);

        switch(option){

            case 1:
            start=create_cll(start);
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
            start=delt_beg(start);
            break;

            case 6:
            start=delt_end(start);
            break;

            case 7:
            start=delt_after(start);
            break;

            case 8:
            start=delt_list(start);
            break;
        
        }


    }while(option!=9);

    if(option==9)
    printf("\nThank-you\nHave a nice day\n");

    getch();

}