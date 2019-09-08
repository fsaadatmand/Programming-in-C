/* calculating the square root of a Number */

#include <stdio.h>

/* Function to calculate the absolute value of a number */

double absoluteValue(double x)
{
	if (x < 0)
		x = -x;

	return (x);
}

/* function to calculate gcd value between two numbers */

int gcd(int u, int v)
{
	int temp;

	while (v != 0) {
		temp = u % v;
		u = v;
		v = temp;
	}

	return u;
}

/* function to calculate a ratio between two numbers */

double ratio(double u, double v) 
{
	double ratio;

	ratio = (u / gcd(u, v)) / (v / gcd(u, v));

	return ratio;
}

/* Function to compute the square root of a number */

double squareRoot(double x, const double epsilon)
{
	double guess = 1.0;
	double ration;

	while (absoluteValue(ratio (x, guess * guess)) >= epsilon) {
		printf("%f\n", guess);
		guess = (x / guess + guess) / 2.0;
	}

	return guess;
}

int main(void) 
{
	double absoluteValue(double x);
	int gcd(int u, int v);
	double ratio(double u, double v); 
	double squareRoot(double x, const double epsilon);

	printf("squareRoot (2.0) = %f\n", squareRoot (2.0, 1.0));
//	printf("squareRoot (144.0) = %f\n", squareRoot (144.0, 1.0));
//	printf("squareRoot (17.5) = %f\n", squareRoot (17.5, 1.0));

	return 0;
}
