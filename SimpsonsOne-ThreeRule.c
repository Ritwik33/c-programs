#include<stdio.h>
#include<conio.h>
#include<math.h>

#define f(x) 1/(3+2*x)

void main()

{
    float a,b,h;

    printf("\n\nEnter values of a,b and h: ");
    scanf("%f %f %f",&a,&b,&h);

    int size = (a+b)/h;

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
        integral+=y[i];

        else if(i%2==1)
        integral+=4*y[i];

        else if(i%2==0)
        integral+=2*y[i];
    }

    integral=(h/3)*integral;

    printf("\n\nThe value of the integral according to Simpson's 1/3-Rule is: %.3f",integral);

    getch();

}