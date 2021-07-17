#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()

{
    int order;

    printf("\n\nEnter the order of the matrix: ");
    scanf("%d",&order);

    float A[order][order];

    printf("\n\nEnter the elements of the matrix row-wise:\n\n");

    int i,j;

    for(i=0;i<order;i++)
    {
        for(j=0;j<order;j++)
        {
            printf("A[%d][%d]= ",i+1,j+1);
            scanf("%f",&A[i][j]);
        }
    }

    printf("\n\nThe matrix is: \n\n");

    for(i=0;i<order;i++)
    {
        for(j=0;j<order;j++)
        {
            printf("%.2f\t",A[i][j]);
        }
        printf("\n");
    }

    float augmat[order][2*order];

    for(i=0;i<order;i++)
    {
        for(j=0;j<2*order;j++)
        {
            if(j<=2)
            {
                augmat[i][j]=A[i][j];
            }

            else if(j>2)
            {
                if(j-i==order)
                {
                    augmat[i][j]=1;
                }
                else
                {
                    augmat[i][j]=0;
                }
            }
        }
    }

    printf("\n\nThe augmented matrix is:\n");

    for(i=0;i<order;i++)
    {
        for(j=0;j<2*order;j++)
        {
            printf("%.2f\t",augmat[i][j]);
        }
        printf("\n");
    }

    float ratio;

    int k;

    for(i=0;i<order;i++)
    {
        for(j=0;j<2*order;j++)
        {
            if(i!=j)
            {
                ratio=augmat[j][i]/augmat[i][i];
                for(k=0;k<2*order;k++)
                {
                    augmat[j][k]=augmat[j][k]-ratio*augmat[i][k];
                }
            }
        }
    }

    float c;

    for(i=0;i<order;i++)
    {
        for(j=0;j<2*order;j++)
        {
            if(i==j)
            {
                c=augmat[i][j];
            }
            augmat[i][j]=augmat[i][j]/c;
        }
    }

    printf("\n\nThe reduced matrix is: \n\n");

    for(i=0;i<order;i++)
    {
        for(j=0;j<2*order;j++)
        {
            printf("%.2f\t",augmat[i][j]);
        }

        printf("\n");
    }

    float inv[order][order];

    for(i=0;i<order;i++)
    {
        for(j=order;j<2*order;j++)
        {
            inv[i][j-order]=augmat[i][j];
        }

    }

    printf("\n\nThe inverse of the matrix is: \n\n");

    for(i=0;i<order;i++)
    {
        for(j=0;j<order;j++)
        {
            printf("%.2f\t",inv[i][j]);
        }
        printf("\n");
    }

    getch();
    
}