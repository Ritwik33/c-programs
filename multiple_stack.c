#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10

int stack[MAX],topA=-1,topB=MAX;

void pushA(int val){

    if(topA==topB-1)
    printf("\nSTACK OVERFLOW\n");

    else{

        topA++;
        stack[topA]=val;

    }

}

void pushB(int val){

    if(topB==topA+1)
    printf("\nSTACK OVERFLOW\n");

    else{

        topB--;
        stack[topB]=val;

    }
    
}

int popA(){

    int val;
    if(topA==-1){

        printf("\nSTACK UNDERFLOW\n");
        val=-999;

    }

    else{

        val=stack[topA];
        topA--;

    }

    return val;

}

int popB(){

    int val;
    if(topB==MAX){

        printf("\nSTACK UNDERFLOW\n");
        val=-999;

    }

    else{

        val=stack[topB];
        topB++;

    }

    return val;
    
}

int peekA(){

    int val;

    if(topA==-1)
    printf("\nSTACK IS EMPTY\n");

    else{

        val=stack[topA];

    }

    return val;

}

int peekB(){

    int val;

    if(topB==MAX)
    printf("\nSTACK IS EMPTY\n");

    else{

        val=stack[topB];

    }

    return val;

}

void display_A(){

    int i;

    if(topA==-1)
    printf("\nSTACK IS EMPTY\n");

    else{

        for(i=topA;i>=0;i--)
        printf("%d\n",stack[i]);

    }

}

void display_B(){

    int i;

    if(topB==MAX)
    printf("\nSTACK IS EMPTY\n");

    else{

        for(i=topB;i<MAX;i++)
        printf("%d\n",stack[i]);

    }

}

int main(){

    int option,val;

    do{

        printf("\n****MAIN MENU***\n");
        printf("\n1. push in stack A\n");
        printf("\n2. push in stack B\n");
        printf("\n3. pop from stack A\n");
        printf("\n4. pop from stack B\n");
        printf("\n5. peek from stack A\n");
        printf("\n6. peek from stack B\n");
        printf("\n7. display stack A\n");
        printf("\n8. display stack B\n");
        printf("\n9. EXIT\n");

        printf("\nEnter an option from main menu: ");
        scanf("%d",&option);

        switch(option){

            case 1:
            printf("\nEnter value to push to A: ");
            scanf("%d",&val);
            pushA(val);
            break;

            case 2:
            printf("\nEnter value to push to stack B: ");
            scanf("%d",&val);
            pushB(val);
            break;

            case 3:
            val=popA();
            if(val!=-999)
            printf("\nThe value popped from stack A is: %d",val);
            break;

            case 4:
            val=popB();
            if(val!=-999)
            printf("\nThe value popped from stack B is: %d",val);
            break;

            case 5:
            val=peekA();
            if(val!=-999)
            printf("\nThe value peeked from stack A is: %d",val);
            break;

            case 6:
            val=peekB();
            if(val!=-999)
            printf("\nThe value peeked from stack B is: %d",val);
            break;
            
            case 7:
            display_A();
            break;

            case 8:
            display_B();
            break;

        }
    }while(option!=9);

    printf("\n****THANKYOU****\n");

    return 0;
}