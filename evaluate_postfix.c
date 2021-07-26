#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 100

float stack[MAX];
int top=-1;
char postfix[MAX];

void push(float num){

    if(top==MAX-1)
    printf("\nSTACK OVERFLOW\n");

    else
    stack[++top]=num;

}

float pop(){

    if(top==-1)
    printf("\nSTACK UNDERFLOW\n");

    else
    return stack[top--];

}

float evaluatepostfix(){

    int i=0;
    float op1,op2,value;

    while(postfix[i]!='\0'){

        if(isdigit(postfix[i])){

            push((float)postfix[i]-'0');
            i++;

        }

        else if((postfix[i]=='*')||(postfix[i]=='/')||(postfix[i]=='%')||(postfix[i]=='+')||(postfix[i]=='-')){

            op1=pop();
            op2=pop();

            switch(postfix[i]){

                case '*':
                value=op2*op1;
                break;

                case '/':
                value=op2/op1;
                break;

                case '%':
                value=(int)op2&(int)op1;
                break;

                case '+':
                value=op2+op1;
                break;

                case '-':
                value=op2-op1;
                break;

            }

            push(value);
            i++;

        }
    }

    return pop();
    
}

int main(){

    printf("\nEnter a valid postfix expression:\n");
    gets(postfix);

    float value;
    value=evaluatepostfix();

    printf("\nThe value of the expression is: %.2f",value);

    getch();
    return 0;
}