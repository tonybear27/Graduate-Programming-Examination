#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int a[10001];
int dp[10001][101];

//dp[i+1][(j+a[i])%k]=max(dp[i][j]) {0<=j<k}
/* Clear the data before each calculation; 
map the data to the value range of %k before calculation*/ 

int main()
{
	int times, n, k;
	cin>>times;
	while(times--)
	{
		cin>>n>>k;
		for(int i=0; i<n; i++)
			cin>>a[i];
		
//		map the data to the value range of %k 
		for(int i=0; i<n; i++)
			a[i]=abs(a[i])%k;
		
		memset(dp, 0, sizeof(dp));
		dp[0][0]=1;
		
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<k; j++)
			{
				if(dp[i][j])
				{
					dp[i+1][(j+k+a[i])%k]=1;
					dp[i+1][(j+k-a[i])%k]=1;
				}
			}
		}
		
		if(dp[n][0])
			puts("Divisible");
		else
			puts("Not divisible");
	}
	
	return 0;
}
