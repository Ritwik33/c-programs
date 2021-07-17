#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
{
    int order,step=1;

    printf("\nEnter the order of the matrix: ");
    scanf("%d",&order);

    int niter;

    printf("\nEnter maximum number of iterations: ");
    scanf("%d",&niter);

    int i,j;
    float A[order][order];

    printf("\nEnter the elements of the matrix row-wise\n");

    for(i=0;i<order;i++)
    {
        for(j=0;j<order;j++)
        {
            printf("A[%d][%d] = ",i+1,j+1);
            scanf("%f",&A[i][j]);
        }
    }

    printf("\nEnter the initial guess vector\n");

    printf("\n");

    float igv[order];

    for(i=0;i<order;i++)
    {
        printf("x[%d]= ",i+1);
        scanf("%f",&igv[i]);
    }

    printf("\n");

    float temp,igv_new[order];

    up:
    for(i=0;i<order;i++)
    {
        temp=0.0;

        for(j=0;j<order;j++)
        {
            temp+=A[i][j]*igv[j];
        }

        igv_new[i]=temp;
    }

    for(i=0;i<order;i++)
    {
        igv[i]=igv_new[i];
    }

    float lambda_new=fabs(igv[0]);

    for(i=1;i<order;i++)
    {
        if((fabs(igv[i]))>lambda_new)
        {
            lambda_new=igv[i];
        }
    }

    for(i=0;i<order;i++)
    {
        igv[i]=(igv[i]/lambda_new);
    }

    printf("\n");

    printf("STEP - %d\n",step);

    printf("The eigen value is: %.2f\n",lambda_new);

    printf("The corresponding Eigen Vector is:\n");

    for(i=0;i<order;i++)
    {
        printf("%.2f\n",igv[i]);
    }

    if(step<niter)
    {
        step++;
        goto up;
    }

    printf("\n");

    printf("The final Eigen value is: %.2f\n",lambda_new);

    printf("The corresponding Eigen vector is:\n");

    for(i=0;i<order;i++)
    {
        printf("%.2f\n",igv[i]);
    }

    getch();
}