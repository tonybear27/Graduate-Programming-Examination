#include <stdio.h>

int main()
{
	long long S, D;
	
	while(scanf("%lld%lld", &S, &D)!=EOF)
	{
		long long num=S;
		
		while(num<D)
		{
			S++;
			num+=S;
		}
		
		printf("%lld\n", S);
	}
	
	return 0;
} 
