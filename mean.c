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

int add(node *start){

    node *ptr;
    ptr=start;

    int sum=0;

    while(ptr->next!=NULL){

        sum+=ptr->val;
        ptr=ptr->next;

    }

    sum+=ptr->val;

    return sum;

}

float mean(int *sum,node *start){

    int count=0;

    node *ptr;
    ptr=start;

    while(ptr->next!=NULL){

        count++;
        ptr=ptr->next;

    }

    count++;

    float avg;
    avg=*sum/count;

    return avg;

}

void main()

{
    node *start=NULL;

    start=create(start);

    display(start);

    int sum;

    sum=add(start);

    float avg;

    avg=mean(&sum,start);

    printf("\naverage= %.2f",avg);

    getch();

}