#include <stdio.h>
#include <math.h>

void gcd(long long a, long long b, long long& x, long long& y, long long& ans)
{
	if(!b)
	{
		ans=a;
		x=1;
		y=0;
	}
	else
	{
		gcd(b, a%b, y, x, ans);
		y-=x*(a/b);
	}
}

int main()
{
	long long n, c1, c2, n1, n2, ans, x, y;
	while(scanf("%lld", &n) && n)
	{
		scanf("%lld%lld%lld%lld", &c1, &n1, &c2, &n2);
		
		gcd(n1, n2, x, y, ans);
		
		long long lower=ceil(-1.0*n*x/n2);
		long long upper=floor(1.0*n*y/n1);
		
		if(n%ans || lower>upper)
			puts("failed");
		else if(c1*n2>=c2*n1)
		{
			x=x*n/ans+n2/ans*lower;
			y=y*n/ans-n1/ans*lower;
			printf("%lld %lld\n", x, y);
		}
		else
		{
			x=x*n/ans+n2/ans*upper;
			y=y*n/ans-n1/ans*upper;
			printf("%lld %lld\n", x, y);
		}
	}
	
	return 0; 
}
