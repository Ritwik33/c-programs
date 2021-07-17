#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()

{
    int n;

    printf("\nEnter number of Data-points: ");
    scanf("%d",&n);

    printf("\n\nEnter the Data-Points:\n\n");

    printf("\nEnter x- values:\n");

    int i;
    float x[n];

    for(i=0;i<n;i++)
    {
        printf("x[%d] = ",i);
        scanf("%f",&x[i]);
    }

    float y[n][n];

    printf("\nEnter y- values:\n");

    for(i=0;i<n;i++)
    {
        printf("y[%d] = ",i);
        scanf("%f",&y[i][0]);
    }

    int j;

    for(i=1;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j<n-i)
            {
                y[j][i] = (y[j+1][i-1]-y[j][i-1]);
            }

            else if(j>=n-i)
            {
                y[j][i] = 0.00;
            }
        }
    }

    printf("\n\nThe Newton's Forward Difference Table is:\n\n");

    for(i=0;i<n;i++)
    {
        printf("%.2f\t",x[i]);

        for(j=0;j<n-i;j++)
        {
            printf("%.2f\t",y[i][j]);
        }

        printf("\n");
    }

    printf("\n\nThe polynomial is:\n");

    printf("\n\nf(x) = %.2f ",y[0][0]);

    float temp=1,temp1,temporary;

    int k,fact=1;

    for(i=0;i<n-1;i++)
    {
        if(y[0][i+1]!=0)
        {

            printf(" + ");

            for(j=0;j<=i;j++)
            {

                if(x[j]>0)
                printf("(x - %.2f)",fabs(x[j]));

                else if(x[j]<0)
                printf("(x + %.2f)",fabs(x[j]));

                else
                printf("x");

            }

            temp1=x[i+1]-x[i];

            for(k=0;k<=i;k++)
            {
                temp*=temp1;
            }

            for(k=i+1;k>0;k--)
            {
                fact*=k;
            }

            temporary=temp*fact;

            y[0][i+1]=(y[0][i+1]/temporary);

            printf("*(%.2f)",y[0][i+1]);

            temp=1;
            fact=1;
        }
    }

    printf("\n\n");

    for(i=1;i<n;i++)
    {
        for(j=n-1;j>=0;j--)
        {
            if(j>=i)
            {
                y[j][i] = (y[j][i-1]-y[j-1][i-1]);
            }

            else if(j<i)
            {
                y[j][i] = 0.00;
            }
        }
    }

    printf("\n\nThe Newton's Backward Difference Table is:\n\n");

    for(i=0;i<n;i++)
    {
        printf("%.2f\t",x[i]);

        for(j=0;j<=i;j++)
        {
            printf("%.2f\t",y[i][j]);
        }

        printf("\n");
    }

    
    printf("\n\nThe polynomial is:\n");

    printf("\n\nf(x) = %.2f ",y[n-1][0]);


    for(i=0;i<n-1;i++)
    {
        if(y[n-1][i+1]!=0)
        {

            printf(" + ");

            for(j=n-1;j>=n-i-1;j--)
            {

                if(x[j]>0)
                printf("(x - %.2f)",fabs(x[j]));

                else if(x[j]<0)
                printf("(x + %.2f)",fabs(x[j]));

                else
                printf("x");

            }

            temp1=x[n-i-1]-x[n-i-2];

            for(k=0;k<=i;k++)
            {
                temp*=temp1;
            }

            for(k=i+1;k>0;k--)
            {
                fact*=k;
            }

            temporary=temp*fact;

            y[n-1][i+1]=(y[n-1][i+1]/temporary);

            printf("*(%.2f)",y[n-1][i+1]);

            temp=1;
            fact=1;
        }
    }

    getch();
    
}