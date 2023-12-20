#include <iostream>
using namespace std;

int fact[1005][2600]={0};
int sums[1005]={0};

void build()
{
	fact[0][0]=1;
	for(int i=1; i<1001; i++)
	{
		for(int j=0; j<2570; j++)
			fact[i][j]=fact[i-1][j]*i;
		
		for(int j=0; j<2570; j++)
			if(fact[i][j]>9)
			{
				fact[i][j+1]+=fact[i][j]/10;
				fact[i][j]%=10;
			}
			
		for(int j=0; j<2570; j++)
			sums[i]+=fact[i][j];
	}
}

int main()
{
	build();
	int n;
	while(cin>>n)
		cout<<sums[n]<<endl;
	
	return 0;
}
