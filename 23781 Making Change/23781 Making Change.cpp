//DP Greedy 
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	const int coins[]={5, 10, 20, 50, 100, 200};
	int have[6];
	int dp[601]={};
	int change[201]={}; //Ways of making change
	for(int i=5; i<201; i++)//Start from smallest
	{
		int back=i;
		for(int k=5; k>=0 && back; k--)
		{
			change[i]+=back/coins[k];
			back%=coins[k];
		}
	}
	
	while(1)
	{
		int sum=0;
		for(int i=0; i<6; i++)
		{
			scanf("%d", &have[i]);
			sum+=have[i]*coins[i];
		}
		if(sum==0)
			break;
		
		int a, b, price;
		scanf("%d.%d", &a, &b);
		price=100*a+b;
	
		for(int i=1; i<=600; i++)
			dp[i]=0xffff;
		
		for(int i=0; i<6; i++)
			for(int k=have[i]; k;k--)
				for(int p=min(600, sum); p>=coins[i]; p--)
				{
					int t=p-coins[i];
					if(dp[t]<0xffff)
						dp[p]=min(dp[t]+1, dp[p]);
				}
				
		int mi=0xffff;
		for(int p=min(600, sum); p>=price; --p)
		{
			if(dp[p]<0xffff)
			{
				if(p>price)
					dp[p]+=change[p-price];
					
				if(dp[p]<mi)
					mi=dp[p];
			}
		}
		
		printf("%3d\n", mi);
	}
	
	return 0;
}
