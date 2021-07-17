#include<stdio.h>
#include<conio.h>
#include<math.h>

#define f(x,y) -2*x*y*y

void main()

{

    float x0,y0,h;

    printf("\n\nEnter values of x0, y0 and h: ");
    scanf("%f %f %f",&x0,&y0,&h);

    float point;

    printf("\n\nEnter value of x where you wish to find the value of y: ");
    scanf("%f",&point);

    float f0;

    int i=0;

    while(x0<=point)
    {
        f0=f(x0,y0);
        y0+=h*f0;
        x0+=h;
        printf("\n\nITERATION: %d \n\n x= %.3f  y= %.3f\n\n",i+1,x0,y0);
        i++;
    }

    printf("\n\nThe value of y at %.3f is %.3f\n\n",point,y0);

    getch();        
}