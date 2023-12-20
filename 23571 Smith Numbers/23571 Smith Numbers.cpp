#include <stdio.h>
#include <math.h>

//count the sum of digits
int count(int n)
{
	int sum=0;
	while(n)
	{
		sum+=n%10;
		n/=10;		
	}
	return sum;
}

int C(int n)
{
	int ans=n;
	int digits1=count(n), digits2=0, flag=1;
	//Prime factorization
	for(int i=2; i<=(int)sqrt(n); i++)
	{
		if(n%i==0)
		{
			int times=0;
			while(n%i==0)
			{
				times++;
				n/=i;
			}
			digits2+=times*count(i);
			flag=0;
		}
	}
	
	if(n!=1)
		digits2+=count(n);
	if(digits1==digits2 && !flag)
	{
		printf("%d\n", ans);
		return 1;
	}
	
	return 0;
}

int main()
{
	int times, n;
	scanf("%d", &times);
	while(times--)
	{
		scanf("%d", &n);
		for(int i=n+1; ; i++)
			if(C(i))
				break;
	}
	
	return 0;
}
