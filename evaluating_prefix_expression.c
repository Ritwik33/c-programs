#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 10

char str[MAX];
float stack[MAX];
int top=-1;

void push(float val){

    if(top==MAX-1)
    printf("\nSTACK OVERFLOW\n");

    else
    stack[++top]=val;

}

float pop(){

    if(top==-1)
    printf("\nSTACK UNDERFLOW\n");

    else
    return stack[top--];

}

float evaluateprefix(char str[]){

    int i=strlen(str)-1;

    float op1,op2,value;

    while(i>=0){

        if(isdigit(str[i]))
        push((float)(str[i]-'0'));

        else{

            op1=pop();
            op2=pop();

            switch(str[i]){

                case '+':
                value=op1+op2;
                break;

                case '-':
                value=op1-op2;
                break;

                case '*':
                value=op1*op2;
                break;

                case '/':
                value=op1/op2;
                break;

                case '%':
                value=(int)op1%(int)op2;
                break;

            }

            push(value);

        }

        i--;

    }

    return value;
    
}

int main(){

    printf("\nEnter a prefix expression:\n");
    gets(str);

    float val;
    val=evaluateprefix(str);
    printf("\nThe value of the prefix expression is: %.2f",val);

    getch();

    return 0;
}