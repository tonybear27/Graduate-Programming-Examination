#include <stdio.h>
using namespace std;

int main()
{
	long long dp[30005]={1};
	int money[]={10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
	int part1, part2;
	
	for(int i=10; i>=0; i--) //Start from smallest change 
		for(int j=money[i]; j<=30000; j++) //No greater than $300.00
			dp[j]+=dp[j-money[i]];
			
	while(scanf("%d.%d", &part1, &part2)!=EOF && (part1 || part2))
		printf("%3d.%02d%17lld\n", part1, part2, dp[part1*100+part2]);
	
	return 0;
}
