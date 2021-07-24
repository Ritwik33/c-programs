#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 10

char stack[MAX],source[MAX],target[MAX];
int top=-1;

void push(char c){

    if(top==MAX-1)
    printf("\nSTACK OVERFLOW\n");

    else
    stack[++top]=c;

}

char pop(){

    if(top==-1)
    printf("\nSTACK UNDERFLOW\n");

    else
    return stack[top--];

}

int getpriority(char c){

    if(c=='/'||c=='*'||c=='%')
    return 1;

    else if(c=='+'||c=='-')
    return 0;

}

void infixtopostfix(char source[],char target[]){

    int i=0,j=0;
    char temp;

    strcpy(target,"");

    while(source[i]!='\0'){

        if(source[i]=='('){

            push(source[i]);
            i++;

        }

        else if(source[i]==')'){

            while((top!=-1)&&(stack[top]!='(')){

                target[j]=pop();
                j++;

            }

            if(top==-1){

                printf("\nINVALID EXPRESSION\n");
                exit(1);

            }

            temp=pop();
            i++;

        }

        else if(isdigit(source[i])||isalpha(source[i])){

            target[j]=source[i];
            i++;
            j++;

        }

        else if(source[i]=='+'||source[i]=='-'||source[i]=='*'||source[i]=='/'||source[i]=='%'){

            while((top!=-1)&&(stack[top]!='(')&&(getpriority(stack[top])>getpriority(source[i]))){

                target[j]=pop();
                j++;

            }

            push(source[i]);
            i++;

        }

        else{

            printf("\nINCORRECT ELEMENT IN EXPRESSION\n");
            exit(1);

        }
    }

    while((top!=-1)&&(stack[top]!='(')){

        target[j]=pop();
        j++;

    }

    target[j]='\0';

}

int main(){

    printf("\nEnter a valid infix expression:\n");
    gets(source);

    strcpy(target,"");

    infixtopostfix(source,target);
    printf("\nThe corresponding postfix expression is:\n");
    puts(target);

    getch();

    return 0;
}