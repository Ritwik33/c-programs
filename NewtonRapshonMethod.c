#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x) x*exp(x) - 1
#define g(x) x*exp(x) + x 

void main()
{
    float x0,x1,f0,g0;
    int num_steps,step;

    printf("\nEnter an initial guess:\n");
    scanf("%f",&x0);
    printf("\nEnter number of steps:\n");
    scanf("%d",&num_steps);

    printf("\nstep\t\tx(n-1)\t\tx(n)\t\tf(x(n-1))\t\tg(x(n-1))\n");

    for(step=1;step<=num_steps;step++)
    {
        f0=f(x0);
        g0=g(x0);

        x1=x0-(f0/g0);

        printf("\n%d\t\t%f\t%f\t%f\t\t%f\n",step,x0,x1,f0,g0);

        x0=x1;

    }

    printf("\nThe root is: %f ",x0);
    
}