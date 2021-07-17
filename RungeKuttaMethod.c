#include<stdio.h>
#include<conio.h>
#include<math.h>

#define f(x,y) x*(y-x)

void main()
{
    float x0,y0,h;

    printf("\n\nEnter values of x0, y0 and h: ");
    scanf("%f %f %f",&x0,&y0,&h);

    float value;

    printf("\n\nEnter the value of x where you want to calculate the value of y: ");
    scanf("%f",&value);

    float k1,k2,k3,k4;

    int i=0;

    x0+=h;

    while(x0<=value)
    {
        k1=h*f(x0,y0);
        k2=h*f(x0+h/2,y0+k1/2);
        k3=h*f(x0+h/2,y0+k2/2);
        k4=h*f(x0+h,y0+k3);

        y0+=(k1+2*k2+2*k3+k4)/6;

        printf("\n\nITERATION %d\n\nx= %.3f y= %.3f",i+1,x0,y0);

        x0+=h;
        i++;
    }

    printf("\n\nThe value of y at x= %.3f is %.3f",value,y0);

    getch();
    
        
}