#include <stdio.h>
#include <cmath>

int main()
{
	double a;
	while(scanf("%lf", &a)!=EOF)
	{
		double x, y, z;
		z=a*a-a*a*M_PI/4;
		z-=a*a*M_PI/4-a*a*M_PI/6-(a*a*M_PI/6-a*a*sqrt(3.0)/4);
		y=a*a-a*a*M_PI/4-2*z;
		x=a*a-4*y-4*z;
		printf("%.3lf %.3lf %.3lf\n", x, 4*y, 4*z);
	}
	
	return 0;
}
