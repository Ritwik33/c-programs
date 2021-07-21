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

int min(node *start){

    int min;
    min=start->val;

    node *ptr;
    ptr=start->next;

    while(ptr->next!=NULL){

        if(ptr->val<min)
        min=ptr->val;

        ptr=ptr->next;

    }

    if(ptr->val<min)
    min=ptr->val;
    
    return min;

}

int max(node *start){

    int max;
    max=start->val;

    node *ptr;

    ptr=start->next;
    
    while(ptr->next!=NULL){

        if(ptr->val>max)
        max=ptr->val;

        ptr=ptr->next;

    }

    if(ptr->val>max)
    max=ptr->val;

    return max;
    
}

void main(){

    node *start=NULL;

    start=create(start);

    display(start);

    int mn,mx;

    mn=min(start);

    mx=max(start);

    printf("\nmin= %d and max= %d",mn,mx);

    getch();

}