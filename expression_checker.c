#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

char str[MAX],stack[MAX],top=-1;

void push(char c){

    if(top==MAX-1)
    printf("\nSTACK OVERFLOW\n");

    else
    stack[++top]=c;
    
}

char pop(){

    char c;

    if(top==-1)
    printf("\nSTACK UNDERFLOW\n");

    else
    return stack[top--];

}

int main(){

    printf("\nEnter an expression:\n");
    gets(str);

    int i,temp,flag=1;
    for(i=0;i<strlen(str);i++){

        if(str[i]=='('||str[i]=='{'||str[i]=='[')
        push(str[i]);

        if(str[i]==')'||str[i]=='}'||str[i]==']'){

            if(top==-1)
            flag=0;

            else{

                temp=pop();

                if(str[i]==')'&&(temp=='{'||temp=='['))
                flag=0;
                if(str[i]=='}'&&(temp=='('||temp=='['))
                flag=0;
                if(str[i]==']'&&(temp=='{'||temp=='('))
                flag=0;

            }
        }
    }

    if(top>=0)
    flag=0;

    if(flag==1)
    printf("\nVALID EXPRESSION\n");

    else
    printf("\nINVALID EXPRESSION\n");


    getch();

    return 0;
}