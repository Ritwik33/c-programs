#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node{

    float val;
    struct node *next;

}node;

node *start=NULL;

node *create(node *start){

    float num;
    printf("\nEnter value: ");
    scanf("%f",&num);

    node *ptr,*new_node;

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
        scanf("%f",&num);

    }

    return start;

}

void display(node *start){

    node *ptr;
    ptr=start;

    while(ptr->next!=NULL){

        printf("%.2f\t",ptr->val);
        ptr=ptr->next;

    }

    printf("%.2f",ptr->val);

}

void sumnmean(node *start){

    node *ptr;
    ptr=start;

    float sum=0;
    while(ptr->next!=NULL){

        sum+=ptr->val;
        ptr=ptr->next;

    }

    sum+=ptr->val;

    printf("\nSum = %.2f",sum);

    int count=0;
    ptr=start;
    while(ptr->next!=NULL){

        count++;
        ptr=ptr->next;

    }

    count++;

    float mean=sum/count;

    printf("\nMean = %.2f",mean);

}

int main(){

    start=create(start);
    printf("\nlist is:\n");
    display(start);

    sumnmean(start);

    return 0;

}