#include<stdio.h>
#include<conio.h>

void main()

{
    int n;

    printf("\nEnter the number of given data points: ");
    scanf("%d",&n);

    int i;

    float x[n],y[n];

    for(i=0;i<n;i++)
    {
        printf("x[%d] = ",i);
        scanf("%f",&x[i]);

        printf("y[%d] = ",i);
        scanf("%f",&y[i]);

        printf("\n");
    }

    float xp;

    printf("\nEnter interpolation point: ");
    scanf("%f",&xp);

    int j;

    float p=1,yp=0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i!=j)
            {
                p=p*((xp-x[j])/(x[i]-x[j]));
            }
        }

        yp += p*y[i];
    }

    printf("\nThe interpolated value at %.2f is %.2f\n",xp,yp);

    getch();
    
}