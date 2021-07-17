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
                y[j][i] = ((y[j+1][i-1]-y[j][i-1])/(x[j+1]-x[j]));
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
        printf("%f\t",x[i]);

        for(j=0;j<n-i;j++)
        {
            printf("%f\t",y[i][j]);
        }

        printf("\n");
    }

    printf("\n\nThe polynomial is:\n");

    printf("\n\nf(x) = %f ",y[0][0]);

    for(i=0;i<n-1;i++)
    {
        if(y[0][i+1]!=0)
        {

            printf(" + ");

            for(j=0;j<=i;j++)
            {

                if(x[j]>0)
                printf("(x - %f)",fabs(x[j]));

                else if(x[j]<0)
                printf("(x + %f)",fabs(x[j]));

                else
                printf("x");

            }

            printf("*(%f)",y[0][i+1]);
        }
    }

    int choice;

    printf("\n\nDo you want to interpolate at a point?\n(1=yes,0=no) ");
    scanf("%d",&choice);

    if(choice==1)
    {
        float xp;

        printf("Enter interpolation point: ");
        scanf("%f",&xp);

        float temp,p=1;

        temp=y[0][0];

        for(i=1;i<n;i++)
        {

            for(j=0;j<i;j++)
            {
                if(x[j]>0)
                {
                    p=p*(xp-fabs(x[j]));
                }

                else if(x[j]==0)
                {
                    p=p*xp;
                }

                else if(x[j]<0)
                {
                    p=p*(xp+fabs(x[j]));
                }   
            }

            p=p*y[0][i];

            temp=temp+p;

            p=1;
        }

        float yp=temp;

        printf("\n\nThe interpolated value at %f is %f",xp,yp);


    }

    else if(choice==0)
    {
        printf("OK");
    }

    getch();
    
}