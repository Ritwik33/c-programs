#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node{

    int val;
    struct node *next;

}node;

node *start=NULL;

node *create(node *start){

    int num;
    printf("\nEnter value: ");
    scanf("%d",&num);

    node *new_node,*ptr;

    while(num!=-1){

        new_node=(node *)malloc(sizeof(node));
        new_node->val=num;

        if(start==NULL){

            new_node->next=NULL;
            start=(node *)malloc(sizeof(node));
            start->next=new_node;

        }

        else{

            ptr=start;
            while(ptr->next!=NULL)
            ptr=ptr->next;

            ptr->next=new_node;
            new_node->next=NULL;

        }

        printf("\nEnter value: ");
        scanf("%d",&num);

    }

    return start;

}

void display(node *start){

    node *ptr;
    ptr=start->next;

    while(ptr!=NULL){

        printf("%d\t",ptr->val);
        ptr=ptr->next;

    }
    
}

node *delt_negatives(node *start){

    node *ptr,*preptr,*temp;
    ptr=start->next;

    while(ptr->next!=NULL){

        if(start->next->val<0){

            temp=start->next;
            start->next=start->next->next;

            free(temp);

            ptr=start->next;
            preptr=ptr;

            ptr=ptr->next;

        }

        else if(ptr->val<0){

            preptr->next=ptr->next;
            temp=ptr;
            ptr=ptr->next;
            free(temp);

        }

        else{

            preptr=ptr;
            ptr=ptr->next;

        }

    }

    if(ptr->val<0){

        preptr->next=NULL;
        free(ptr);

    }

    return start;

}

int main(){

    start=create(start);
    printf("\nThe linked list is:\n");
    display(start);
    
    start=delt_negatives(start);
    printf("\nThe Linked List after deletion of all negative values is:\n");
    display(start);

    getch();

    return 0;
}