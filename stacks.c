#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5

int stack[MAX],top=-1;

void push(int val){

    if(top==MAX-1)
    printf("\nSTACK OVERFLOW\n");

    else{

        top++;
        stack[top]=val;

    }

}

int pop(){

    int val;

    if(top==-1){

        val=-999;
        printf("\nSTACK UNDERFLOW\n");

    }

    else{

        val=stack[top];
        top--;

    }

    return val;

}

int peek(){

    int val;

    if(top==-1){

        printf("\nSTACK IS EMPTY\n");
        val=-999;

    }

    else
    val=stack[top];

    return val;

}

void display(){

    int i;

    if(top==-1)
    printf("\nSTACK IS EMPTY\n");

    else{

        for(i=top;i>=0;i--)
        printf("%d\n",stack[i]);

    }

}

int main(){

    int option,val;

    do{

        printf("\n****MAIN MENU****\n");
        printf("\n1. push\n");
        printf("\n2. pop\n");
        printf("\n3. peek\n");
        printf("\n4. display\n");
        printf("\n5. EXIT\n");

        printf("\nEnter a choice from main menu: ");
        scanf("%d",&option);

        switch(option){

            case 1:
            printf("\nEnter a value to push: ");
            scanf("%d",&val);
            push(val);
            break;

            case 2:
            val=pop();
            if(val!=-999)
            printf("\nThe value popped from stack is %d",val);
            break;

            case 3:
            val=peek();
            if(val!=-999)
            printf("\nThe value peeked from stack is %d",val);
            break;

            case 4:
            display();
            break;

        }
    }while(option!=5);

    printf("\n****THANKYOU****\n");

    getch();

    return 0;
}