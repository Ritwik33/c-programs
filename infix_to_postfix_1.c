#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

char infix[MAX],postfix[MAX],stack[MAX];
int top=-1;

void push(char c){

    if(top==MAX-1)
    printf("\nSTACK OVERFLOW\n");

    else
    stack[++top]=c;

}

int priority(char op){

    if((op=='*')||(op=='/')||(op=='%'))
    return 1;

    else if((op=='+')||(op=='-'))
    return 0;

}

char pop(){

    if(top==-1)
    printf("\nSTACK UNDERFLOW\n");

    else
    return stack[top--];

}

void infixtopostfix(){

    int i=0;
    while(infix[i]!='\0')
    i++;

    infix[i]=')';
    i++;

    infix[i]='\0';

    i=0;

    int j=0;

    push('(');

    while(infix[i]!='\0'){

        if(infix[i]=='('){

            push(infix[i]);
            i++;

        }

        else if(isalpha(infix[i])){

            postfix[j]=infix[i];
            i++;
            j++;

        }

        else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='%'){

            while((top!=-1)&&(stack[top]!='(')&&(priority(stack[top])>(priority(infix[i])))){

                postfix[j]=pop();
                j++;

            }

            push(infix[i]);
            i++;

        }

        else if(infix[i]==')'){

            while((stack[top]!='(')&&(top!=-1)){

                postfix[j]=pop();
                j++;

            }

            if(top==-1){

                printf("\nINCORRECT EXPRESSION\n");
                exit(1);

            }

            pop();
            i++;

        }

        else{

            printf("\nINCORRECT ELEMENT IN EXPRESSION\n");
            exit(1);

        }
    }

    while((top!=-1)&&(stack[top]!='(')){

        postfix[j]=pop();
        j++;

    }

    postfix[j]='\0';

}

int main(){

    printf("\nEnter a valid infix expression:\n");
    gets(infix);

    infixtopostfix();

    printf("\nThe corresponding postfix expression is:\n");
    puts(postfix);

    getch();
    return 0;
}