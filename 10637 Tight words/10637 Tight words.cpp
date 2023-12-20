//DP
#include <stdio.h>
#include <math.h>
double dp[101][10];

int main()
{
	int k, n;
	while(scanf("%d%d", &k, &n)!=EOF)
	{
		//Initial Conditions
		for(int i=0; i<=k; i++)
			dp[1][i]=1./(1.+k);
		
		//dp[i][j] = sum(dp[i-1][t]/(k+1))
		for(int i=2; i<=n; i++)
			for(int j=0; j<=k; j++) //Elememts by elements
			{
				dp[i][j]=0; //Basic Condition 
				for(int t=0; t<=k; t++) //Elements by elements
				{
					//Remember the different between two adjacent numbers will not greater than 1
					if(abs(t-j)>1)
						continue;
					dp[i][j]+=dp[i-1][t]/(1.+k);
				}
			}
		
		double sum=0;
		for(int i=0; i<=k; i++)
			sum+=dp[n][i];
		
		printf("%.5lf\n", 100*sum);
	
	}
	
	return 0;
}
