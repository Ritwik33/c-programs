#include<stdio.h>
#include<conio.h>

void main()

{
    char str[100];

    printf("\nenter the string: ");
    gets(str);

    char *pstr;

    pstr=str;

    int lower=0,upper=0;

    while(*pstr!='\0'){

        if(*pstr>='A'&&*pstr<='Z')
        upper++;

        else if(*pstr>='a'&&*pstr<='z')
        lower++;

        pstr++;

    }

    printf("\nlower cases: %d\nupper cases: %d\n",lower,upper);

    getch();

}