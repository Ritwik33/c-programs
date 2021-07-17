#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()

{
    int var,i,j,k;
    float c,root,mat[20][20],A[20],B[20];

    printf("\nEnter the number of variables:\n");
    scanf("%d",&var);

    printf("\nEnter the elements of Augmented matrix:\n");
    
    for(i=0;i<var;i++)
    {
        for(j=0;j<=var;j++)
        {
            printf("AugMat%d%d: ",i+1,j+1);
            scanf("%f",&mat[i][j]);
        }
    }

    printf("\n");

    for(i=0;i<var;i++)
    {
        for(j=0;j<var;j++)
        {
            
            if(i!=j)
            {
                c=mat[j][i]/mat[i][i];
                for(k=0;k<=var;k++)
                {
                    mat[j][k]=mat[j][k]-c*mat[i][k];
                }
            }
        }
    }

    printf("\nReduced matrix is:\n");
    for(i=0;i<var;i++)
    {
        for(j=0;j<=var;j++)
        {
            printf("%0.2f\t",mat[i][j]);
        }
        printf("\n");
    }

    
    for(i=0;i<var;i++)
    {
        for(j=0;j<var;j++)
        {
            if(i==j)
            {
                A[i]=mat[i][j];
            }
        }
    }

    printf("\n\n");

    printf("\nMatrix of diagonal elements of the reduced matrix is:\n");
    for(i=0;i<var;i++)
    {
        printf("%0.2f\t",A[i]);
    }


    for(i=0;i<var;i++)
    {
        for(j=var;j<var+1;j++)
        {
            B[i]=mat[i][j];
        }      
    }

    printf("\n\n");

    printf("\nReduced coefficient matrix is:\n");
    for(i=0;i<var;i++)
    {
        printf("%0.2f\n",B[i]);
    }

    printf("\n");

    for(i=0;i<var;i++)
    {
        root=B[i]/A[i];
        printf("Root%d is: %0.2f",i+1,root);
        printf("\t");

    }

    printf("\n");
}