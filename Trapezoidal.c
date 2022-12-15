# y=1/(1+x*x)

#include<stdio.h>
float func(float x)
{
  return 1+x*x;
}
float trapezoidal(float a , float b , int n)
{
float h=(b-a)/n;
float x[n+1],y[n+1];
for(int i=0;i<n+1;i++)
{
  x[i]=a+h*i;
  y[i]=1/func(x[i]);
}
float s= (y[0]+y[n])/2;
for(int i=1;i<n;i++)
  s+=y[i];
return s*h;
}
int main()
{
	float x0, xn;   // Range of definite integral
	int n;  // Number of grids. Higher value means more accuracy
        printf("Enter the range of definite integral: ");
        scanf("%f %f", &x0, &xn);

	printf("Enter the number of grids: ");
        scanf("%d", &n);

	printf("\nValue of integral is %6.4f\n", trapezoidal(x0, xn, n));
	return 0;
}
