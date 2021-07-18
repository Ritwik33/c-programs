#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node{

    int coeff;
    int pow;
    struct node *next;

}node;

node *create_ll(node *start){

    int coefficient;
    printf("\nEnter the coefficient: ");
    scanf("%d",&coefficient);

    int power;
    printf("\nEnter power of x: ");
    scanf("%d",&power);

    node *new_node,*ptr;

    while(power!=-1){

        if(start==NULL){

            new_node=(node *)malloc(sizeof(node));
            new_node->coeff=coefficient;
            new_node->pow=power;
            new_node->next=NULL;

            start=new_node;

        }

        else{

            new_node=(node *)malloc(sizeof(node));
            new_node->pow=power;
            new_node->coeff=coefficient;
            new_node->next=NULL;

            ptr=start;
            while(ptr->next!=NULL)
            ptr=ptr->next;

            ptr->next=new_node;

        }

        printf("\nEnter the coefficient: ");
        scanf("%d",&coefficient);

        printf("\nEnter power of x: ");
        scanf("%d",&power);

    }

    printf("\nFirst polynomial created\n");

    return start;

}

void display(node *start){

    node *ptr;
    ptr=start;
    while(ptr->next!=NULL){

        printf("%d x %d\t",ptr->coeff,ptr->pow);
        ptr=ptr->next;

    }

    printf("%d x %d",ptr->coeff,ptr->pow);

}

node *add_node(node *start,int c,int p){

    node *new_node,*ptr;

    if(start==NULL){

        new_node=(node *)malloc(sizeof(node));
        new_node->coeff=c;
        new_node->pow=p;
        new_node->next=NULL;

        start=new_node;

    }

    else{

        ptr=start;
        while(ptr->next!=NULL)
        ptr=ptr->next;

        new_node=(node *)malloc(sizeof(node));
        ptr->next=new_node;
        new_node->pow=p;
        new_node->coeff=c;
        new_node->next=NULL;

    }

    return start;

}

node *add(node *start1,node *start2,node *start3){

    node *ptr1,*ptr2;

    int sum_num;

    ptr1=start1,ptr2=start2;

    while(ptr1!=NULL&&ptr2!=NULL){

        if(ptr1->pow==ptr2->pow){

            sum_num=ptr1->coeff+ptr2->coeff;
            start3=add_node(start3,sum_num,ptr1->pow);
            ptr1=ptr1->next;
            ptr2=ptr2->next;

        }

        else if(ptr1->pow>ptr2->pow){

            start3=add_node(start3,ptr1->coeff,ptr1->pow);
            ptr1=ptr1->next;

        }

        else if(ptr1->pow<ptr2->pow){

            start3=add_node(start3,ptr2->coeff,ptr2->pow);
            ptr2=ptr2->next;

        }
    }

    if(ptr1==NULL){

        while(ptr2!=NULL){

            start3=add_node(start3,ptr2->coeff,ptr2->pow);
            ptr2=ptr2->next;

        }
    }

    if(ptr2==NULL){

        while(ptr1!=NULL){

            start3=add_node(start3,ptr1->coeff,ptr1->pow);
            ptr1=ptr1->next;

        }
    }

    return start3;

}

void main()

{

    node *start1=NULL,*start2=NULL,*start3=NULL;

    int option;

    do{

        printf("\n\n****MAIN MENU****\n\n");
        printf("\n1. insert first polynomial\n");
        printf("\n2. display first polynomial\n");
        printf("\n3. insert second polynomial\n");
        printf("\n4. display second polynomial\n");
        printf("\n5. add the polynomials\n");
        printf("\n6. display the result\n");
        printf("\n7. EXIT\n");

        printf("\nEnter an option: ");
        scanf("%d",&option);

        switch(option){

            case 1:
            start1=create_ll(start1);
            break;

            case 2:
            printf("\nThe first polynomial is:\n");
            display(start1);
            break;

            case 3:
            start2=create_ll(start2);
            break;

            case 4:
            printf("\nThe second polynomial is:\n");
            display(start2);
            break;

            case 5:
            start3=add(start1,start2,start3);
            break;

            case 6:
            printf("\nThe resultant polynomial is:\n");
            display(start3);
            break;

        }
    }while(option!=7);

    printf("\n\n****THANKYOU****\n\n");

    getch();

}