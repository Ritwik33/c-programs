#include<stdio.h>
#include<conio.h>

void main()

{
    int row1;

    printf("\n\nEnter number of rows of matrix-1: ");
    scanf("%d",&row1);

    int column1;

    printf("\n\nEnter number of columns of matrix-1: ");
    scanf("%d",&column1);

    int row2;

    printf("\n\nEnter number of rows of matrix-2: ");
    scanf("%d",&row2);

    int column2;

    printf("\n\nEnter number of columns of matrix-2: ");
    scanf("%d",&column2);

    if(column1==row2)
    {
        printf("\n\nEnter elements of matrix-1:\n");

        float mat1[row1][column1];

        int i,j;

        for(i=0;i<row1;i++)
        {
            for(j=0;j<column1;j++)
            {
                printf("mat1[%d][%d] = ",i+1,j+1);
                scanf("%f",&mat1[i][j]);
            }
        }

        printf("\n\nEnter elements of matrix-2:\n");

        float mat2[row2][column2];

        for(i=0;i<row2;i++)
        {
            for(j=0;j<column2;j++)
            {
                printf("mat2[%d][%d] = ",i+1,j+1);
                scanf("%f",&mat2[i][j]);
            }
        }

        float temp,mat3[row1][column2];

        int k;

        for(i=0;i<row1;i++)
        {
            for(j=0;j<column2;j++)
            {
                temp=0;

                for(k=0;k<column1;k++)
                {
                    temp+=mat1[i][k]*mat2[k][j];
                }

                mat3[i][j]=temp;
            }
        }

        printf("\n\nThe product of the matrices is:\n\n"); 

        for(i=0;i<row1;i++)
        {
            for(j=0;j<column2;j++)
            {
                printf("%.2f\t",mat3[i][j]);
            }

            printf("\n");
        }
        
    }

    else if(column1!=row2)
    {
        printf("\n\nCannot multiply");
    }

    getch();


    
}