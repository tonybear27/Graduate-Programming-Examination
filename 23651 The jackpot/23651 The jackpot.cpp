//DP
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while(cin>>n && n)
	{
		int sequence[1005];
		for(int i=1; i<=n; i++)
			cin>>sequence[i];
		
		int dp[10005]={0};
		int win=0;
		
//		f(i)=max(f(i-1)+a[i], a[i])
		for(int i=1; i<=n; i++)
		{
			dp[i]=max(sequence[i], dp[i-1]+sequence[i]);
			win=max(win, dp[i]);
		}
		
		if(win>0)
			cout<<"The maximum winning streak is "<<win<<".\n";
		else
			cout<<"Losing streak.\n";
	}
	
	return 0;
}
