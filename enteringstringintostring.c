#include<stdio.h>
#include<conio.h>
#include<string.h>

void insert(char main[],char str[],int *pos){

    main[strlen(main)+strlen(str)]='\0';

    int i,j=0;

    for(i=strlen(main)-1;i>=*pos;i--){

        main[i+strlen(str)]=main[i];

    }

    for(i=*pos;i<*pos+strlen(str);i++){

        main[i]=str[j];
        j++;

    }

}

void main()

{
    
    char main[100];

    printf("\nEnter main text: ");
    gets(main);

    char str[100];

    printf("\nEnter string: ");
    gets(str);

    int pos;

    printf("\nEnter position: ");
    scanf("%d",&pos);

    insert(main,str,&pos);

    puts(main);

    getch();

}