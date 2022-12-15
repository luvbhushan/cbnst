// y=1/(1+x*x)

#include<stdio.h>
float func(float x)
{
  return 1+x*x;
}
float Simpsons(float a , float b , int n)
{
float h=(b-a)/n;
float x[n+1],y[n+1];
for(int i=0;i<n+1;i++)
{
  x[i]=a+h*i;
  y[i]=1/func(x[i]);
}
float s= (y[0]+y[n]);
for(int i=1;i<n;i++)
{ 
  if(i%2==0) s=s+2*y[i];
  else s=s+4*y[i];
}
return s*h/3;
}
int main()
{
	float x0, xn;   // Range of definite integral
	int n;  // Number of grids. Higher value means more accuracy
        printf("Enter the range of definite integral: ");
        scanf("%f %f", &x0, &xn);

	printf("Enter the number of grids: ");
        scanf("%d", &n);

	printf("\nValue of integral is %6.4f\n", Simpsons(x0, xn, n));
	return 0;
}
