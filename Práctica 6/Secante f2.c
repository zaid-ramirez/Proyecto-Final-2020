/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <math.h>

float f(float x)
{
   float y;
    y= (8*sin(x)*exp(-x))-1;
   return y;
}

float secante(float x0,float x1, int iter)
{
   int i=1;
   float xi, ximasuno,ximenosuno,erp;
   float fprima;
   printf("i \t Xi \t\t Xi-1 \t\t Xi+1 \t\t ~=f'(x) \t\t Err\n");
   xi=x1;
   ximenosuno=x0;
   do
   {
      ximasuno= xi - (f(xi)*(ximenosuno-xi))/(f(ximenosuno)-f(xi));
      erp= fabs((ximasuno-xi)/ximasuno)*100;
      fprima= (f(ximenosuno)-f(xi))/(ximenosuno-xi);
      printf("%i \t %.8f \t %.8f \t %.8f \t%.8f\t%.8f\n",i,xi,ximenosuno,ximasuno,fprima,erp);
      ximenosuno=xi;
      xi=ximasuno;
      i++;
   }while(i<=iter);
   return ximasuno;
}

int main ()
{
	float x0=0.3, x1=0.5,raiz;
    int iter=5;

    raiz=secante(x0,x1,iter);


	return 0;
}
