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

void swap(int *p,int *q){

    int temp=*p;
    *p=*q;
    *q=temp;

}

node *interchange(node *start){

    node *ptr;
    ptr=start;

    int count=0;

    while(ptr->next!=NULL){

        count++;
        ptr=ptr->next;

    }

    count++;

    count/=2;

    node *first,*last;
    first=start,last=start;

    while(last->next!=NULL)
    last=last->next;

    int i=1;

    while(i<=count){

        swap(&first->val,&last->val);
        i++;
        first=first->next;
        last=last->prev;

    }

    return start;

}

int main(){

    start=create(start);
    printf("\nThe original linked list is:\n");
    display(start);

    start=interchange(start);
    printf("\nThe reversed linked list is:\n");
    display(start);

    return 0;
}