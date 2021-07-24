#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

float st[MAX];
char str[MAX];
int top=-1;

void push(float val){

    if(top==MAX-1)
    printf("\nSTACK OVERFLOW\n");

    else
    st[++top]=val;

}

float pop(){

    if(top==-1)
    printf("\nSTACK UNDERFLOW\n");
    
    else
    return st[top--];

}

float evaluatepostfix(char str[]){

    int i=0;
    float op1,op2,value;

    while(str[i]!='\0'){

        if(isdigit(str[i]))
        push((float)(str[i]-'0'));

        else{

            op1=pop();
            op2=pop();

            switch(str[i]){

                case '+':
                value=op2+op1;
                break;

                case '-':
                value=op2-op1;
                break;

                case '*':
                value=op2*op1;
                break;

                case '/':
                value=op2/op1;
                break;

                case '%':
                value=(int)op2%(int)op1;
                break;

            }

            push(value);

        }

        i++;

    }

    return pop();

}

int main(){

    printf("\nEnter any postfix expression: ");
    gets(str);

    float val;

    val=evaluatepostfix(str);
    printf("\nThe value of postfix expression is %.2f",val);

    getch();

    return 0;
}

