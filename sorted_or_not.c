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
            start=new_node;

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
    ptr=start;
    while(ptr->next!=NULL){

        printf("%d\t",ptr->val);
        ptr=ptr->next;

    }

    printf("%d",ptr->val);

}

int issorted(node *start){

    node *ptr,*preptr;
    preptr=start;

    int flag;

    while(preptr->next!=NULL){

        ptr=preptr->next;

        while(ptr!=NULL){

            if(preptr->val<=ptr->val)
            flag=1;

            else if(preptr->val>ptr->val)
            flag=0;

            ptr=ptr->next;

        }

        preptr=preptr->next;

    }

    if(flag==1)
    return 1;

    else if(flag==0)
    return 0;

}

int main(){

    start=create(start);
    printf("\nThe linked list is:\n");
    display(start);

    int sorted;
    sorted=issorted(start);
    printf("\nSorting Status= %d\n",sorted);

    return 0;
}