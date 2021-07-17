#include<stdio.h>
#include<math.h>
#include<conio.h>

#define f(x) 1/(3+2*x)

void main()

{
    float a,b,h;

    printf("\nEnter value of a,b and h: ");
    scanf("%f %f %f",&a,&b,&h);

    int size=(a+b)/h;

    float x[size+1];

    int i;

    for(i=0;i<size+1;i++)
    {
        x[i]=a;

        a+=h;
    }

    float y[size+1];

    for(i=0;i<size+1;i++)
    {
        y[i]=f(x[i]);
    }

    printf("\n\nThe Data-Points are:\n\n");

    for(i=0;i<size+1;i++)
    {
        printf("%.3f\t%.3f\n",x[i],y[i]);
    }

    float integral=0;

    for(i=0;i<size+1;i++)
    {
        if(i==0||i==size)
        {
            integral+=y[i];
        }

        else
        {
            integral+=2*y[i];
        }
    }

    integral=(h/2)*integral;

    printf("\n\nThe integral using trapezoidal rule is: %.3f",integral);

    getch();


}
