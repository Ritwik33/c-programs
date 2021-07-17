#include<stdio.h>
#include<conio.h>
#include<math.h>


#define f1(x,y,z)  (6-2*z)/4
#define f2(x,y,z)  (-3-2*z)/5
#define f3(x,y,z)  (11-5*x-4*y)/10

int main()
{
 float x0=0, y0=0, z0=0, x1, y1, z1, e1, e2, e3, e;
 int count=1;
 printf("Enter tolerable error:\n");
 scanf("%f", &e);
 printf("\nCount\t\t\tx\t\t\ty\t\t\tz\n");
 do
 {
  x1 = f1(x0,y0,z0);
  y1 = f2(x1,y0,z0);
  z1 = f3(x1,y1,z0);
  printf("%d\t\t%f\t\t%f\t\t%f\n",count, x1,y1,z1);
  e1 = fabs(x0-x1);
  e2 = fabs(y0-y1);
  e3 = fabs(z0-z1);
  count++;
  x0 = x1;
  y0 = y1;
  z0 = z1;
 }while(e1>e && e2>e && e3>e);
 printf("\nSolution: x= %f, y= %f and z= %f\n",x1,y1,z1);
 getch();
 return 0;
}