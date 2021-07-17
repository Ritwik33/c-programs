#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()

{

    char main[100];

    printf("\nEnter main text: ");
    gets(main);

    int pos,len;

    printf("\nEnter position and length\n");
    scanf("%d %d",&pos,&len);

    int i;

    for(i=pos;i<strlen(main);i++){

        main[i]=main[i+len];

    }

    main[len+pos+1]='\0';

    puts(main);

    getch();

}