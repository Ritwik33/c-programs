#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 3

int st[MAX],top=-1;

void push(int st[],int *val){

    if(top==MAX-1)
    printf("\nSTACK OVERFLOW\n");

    else{

        top++;
        st[top]=*val;

    }

}

int pop(int st[]){

    int val;

    if(top==-1){

        printf("\nSTACK UNDERFLOW\n");
        return -1;

    }

    else{

        val=st[top];
        top--;
        return val;

    }

}

int peek(int st[]){

    if(top==-1){

        printf("\nSTACK IS EMPTY\n");
        return -1;

    }

    else
    return st[top];

}

void display(int st[]){

    int i;

    if(top==-1)
    printf("\nSTACK IS EMPTY\n");

    else{

        for(i=top;i>=0;i--)
        printf("%d\n",st[i]);
        printf("\n");

    }

}

int main(){

    int option,val;

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
            printf("\nEnter a number to push to stack: ");
            scanf("%d",&val);
            push(st,&val);
            break;

            case 2:
            val=pop(st);
            if(val!=-1)
            printf("\nThe value deleted from stack is: %d\n",val);
            break;

            case 3:
            val=peek(st);
            if(val!=-1)
            printf("\nThe value stored at top of the stack is: %d\n",val);
            break;

            case 4:
            display(st);
            break;

        }
    }while(option!=5);

    printf("\n****THANKYOU****\n");

    getch();

    return 0;
}