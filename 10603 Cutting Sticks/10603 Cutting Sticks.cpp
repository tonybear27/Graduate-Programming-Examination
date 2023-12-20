//DP
#include <iostream>
#include <climits>
using namespace std;

int main()
{
	int n, L;
	int A[52]={0};
	while(cin>>L  && L)
	{
		cin>>n;
		int dp[52][52]={0};
		
		for(int a=1; a<=n; a++)
			cin>>A[a];
		A[++n]=L;
		
		//optimal(first, end)=optimal(first, d)+optimal(d, end)+end-first.
		//In these for loops, b represents first, c represents end.
		for(int a=2; a<=n; a++)
		{
			//cutting from 0, end at c=n;
			for(int b=0, c=a+b; c<=n; b++, c++)
			{
				int min=INT_MAX;
				for(int d=b+1; d<c; d++)
				{
					if(min>dp[b][d]+dp[d][c]+A[c]-A[b])
						min=dp[b][d]+dp[d][c]+A[c]-A[b];	
				}
				//The senction
				dp[b][c]=min;	
			}
		}
		
		cout<<"The minimum cutting is "<<dp[0][n]<<".\n";
	}
	
	return 0;
}
