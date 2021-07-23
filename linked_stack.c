#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct stack{

    int val;
    struct stack *next;

}stack;

stack *top=NULL;

stack *push(stack *top,int num){

    stack *new;
    new=(stack *)malloc(sizeof(stack));
    new->val=num;

    if(top==NULL){

        new->next=NULL;
        top=new;

    }

    else{

        new->next=top;
        top=new;

    }

    return top;

}

stack *pop(stack *top){

    stack *ptr;
    ptr=top;

    if(top==NULL)
    printf("\nSTACK UNDERFLOW\n");

    else{

        printf("\nThe value being deleted from stack is %d\n",top->val);
        top=top->next;

        free(ptr);

    }

    return top;

}

stack *peek(stack *top){

    if(top==NULL)
    printf("\nSTACK IS EMPTY\n");

    else{

        printf("\nValue at top of stack is %d\n",top->val);

    }

    return top;

}

void display(stack *top){

    stack *ptr;
    ptr=top;

    if(top==NULL)
    printf("\nSTACK IS EMPTY\n");

    else{

        while(ptr->next!=NULL){

            printf("%d\n",ptr->val);
            ptr=ptr->next;

        }

        printf("%d\n",ptr->val);

    }

}

int main(){

    int option,num;

    do{

        printf("\n****MAIN MENU****\n");
        printf("\n1. PUSH\n");
        printf("\n2. POP\n");
        printf("\n3. PEEK\n");
        printf("\n4. DISPLAY\n");
        printf("\n5. EXIT\n");

        printf("\nEnter an option from main menu: ");
        scanf("%d",&option);

        switch(option){

            case 1:
            printf("\nEnter the value to be pushed to stack: ");
            scanf("%d",&num);
            top=push(top,num);
            break;

            case 2:
            top=pop(top);
            break;

            case 3:
            top=peek(top);
            break;

            case 4:
            display(top);
            break;

        }

    }while(option!=5);

    printf("\n****THANKYOU****\n");

    getch();

    return 0;
}