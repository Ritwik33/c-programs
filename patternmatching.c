#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()

{
    char main[100];

    printf("\nEnter main string: ");
    gets(main);

    char str[100];

    printf("\nEnter the string: ");
    gets(str);

    int i=0,j,location,found=0;

    for(j=0;j<strlen(main);j++){

        if(str[0]==main[j]){

            location=j;
            
            while(main[j]!='\0'){

                if(str[i]==main[j]){
                    found=1;
                    i++;
                    j++;
                }
            }
            break;
        }
    }

    if(found==1){

        printf("\nlocation= %d",location);
    }

    else if(found==0){

        printf("\nNot found");
    }

    getch();
    
}