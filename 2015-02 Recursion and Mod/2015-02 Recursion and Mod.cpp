#include <stdio.h>
long long f(long long n)
{
	if(n==1)
		return 1;
	else
		return (3*f(n-1)+4)%(long long)(1E+9+9);
}

int main()
{
	long long n;
	while(scanf("%lld", &n))
		printf("%lld\n", f(n));
	return 0;	
}
