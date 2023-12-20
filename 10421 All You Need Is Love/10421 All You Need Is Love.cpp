#include <stdio.h>
#include <string.h>
#include <stdlib.h>
long long btd(char *s)
{
	long long pow=1, i=0;
	long long ans=0;
	while(i<strlen(s))
	{
		ans+=pow*(s[strlen(s)-i-1]-'0');
		pow*=2;
		i++;
	}
	
	return ans;
}

long long gcd(long long a, long long b)
{
	long long r;
	while(b)
	{
		r=a%b;
		a=b;
		b=r;
	}
	
	return a;
}

int main()
{
	int times;
	int pair=1;
	scanf("%d", &times);
	while(times--)
	{
		char s[2][1000];
		scanf(" ");
		scanf("%s%s", s[0], s[1]);
		
		long long num[2];
		num[0]=btd(s[0]);
		num[1]=btd(s[1]);
		
		int ans=gcd(num[0], num[1]);
		
		if(ans>1)
			printf("Pair #%d: All you need is love!\n", pair);
		else
			printf("Pair #%d: Love is not all you need!\n", pair);
		
		pair++;
	}
	
	return 0;
}
