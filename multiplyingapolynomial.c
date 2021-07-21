#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node{

    int coeff;
    int pow;
    struct node *next;

}node;

node *start=NULL;

node *create(node *start){

    int c,p;
    printf("\nEnter coefficient: ");
    scanf("%d",&c);
    printf("\nEnter power: ");
    scanf("%d",&p);

    node *ptr,*new_node;

    while(p!=-1){

        new_node=(node *)malloc(sizeof(node));
        new_node->coeff=c;
        new_node->pow=p;

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

        printf("\nEnter coefficient: ");
        scanf("%d",&c);

        printf("\nEnter power: ");
        scanf("%d",&p);

    }

    return start;

}

void display(node *start){

    node *ptr;
    ptr=start;

    while(ptr->next!=NULL){

        printf("%d x^ %d\t",ptr->coeff,ptr->pow);
        ptr=ptr->next;

    }

    printf("%d x^ %d",ptr->coeff,ptr->pow);

}

node *multiply(node *start){

    int num;
    printf("\n\nEnter the number to multiply the polynomial with: ");
    scanf("%d",&num);

    node *ptr;
    ptr=start;

    while(ptr->next!=NULL){

        ptr->coeff=num*ptr->coeff;
        ptr=ptr->next;

    }

    ptr->coeff=num*ptr->coeff;

    return start;

}

int main(){

    start=create(start);
    printf("\nThe polynomial is:\n");
    display(start);

    start=multiply(start);
    printf("\nThe polynomial is:\n");
    display(start);

    return 0;
}