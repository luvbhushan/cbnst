// cbnst
//Mathematical codes
#include <stdio.h>

// calculating u mentioned in the formula
float u_cal(float u, int n)
{
	float temp = u;
	for (int i = 1; i < n; i++)
		temp = temp * (u - i);
	return temp;
}

// calculating factorial of given number n
int fact(int n)
{
	int f = 1;
	for (int i = 2; i <= n; i++)
		f *= i;
	return f;
}

int main()
{
    int n;
    printf("Enter the number of values: ");
    scanf("%d", &n);

    int x[n];
    printf("Enter the values of x: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }

    // y[][] is used for difference table with y[][0] used for input
    float y[n][n];
    printf("Enter the values of y: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%f", &y[i][0]);
    }

    // Value to interpolate at
    float value;
    printf("Enter the value to evaluate at: ");
    scanf("%f", &value);

	// Calculating the forward difference table
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++)
			y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
	}

	// Displaying the forward difference table
	for (int i = 0; i < n; i++) {
        printf("%d \t", x[i]);
		for (int j = 0; j < n - i; j++)
            printf("%f \t", y[i][j]);
		printf("\n");
	}

	// initializing u and sum
	float sum = y[0][0];
	float u = (value - x[0]) / (x[1] - x[0]);			//(x - x0)/h
	for (int i = 1; i < n; i++) {
		sum = sum + (u_cal(u, i) * y[0][i]) / fact(i);
	}

    printf("Value at %f is: %f\n", value, sum);
	return 0;
}
