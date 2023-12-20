#include <iostream>
using namespace std;

int C[305][2005]={0};

void build()
{
	C[1][0]=1;
	for(int i=2; i<301; i++)
	{
		for(int j=0; j<2000; j++)
			C[i][j]+=C[i-1][j]*(4*i-2);
			
		for(int j=0; j<2000; j++)
		{
			C[i][j+1]+=C[i][j]/10;
			C[i][j]%=10;
		}
		
		for(int j=1999; j>=0; j--)
		{
			C[i][j-1]+=C[i][j]%(i+1)*10;
			C[i][j]/=(i+1);
		}
		
		for(int j=0; j<2000; j++)
			C[i][j]*=i;
		for(int j=0; j<2000; j++)
		{
			C[i][j+1]+=C[i][j]/10;
			C[i][j]%=10;
		}
	}
}

int main()
{
	build();
	int n;
	while(cin>>n && n)
	{
		int end=1999;
		while(!C[n][end])
			--end;
		while(end>=0)
			cout<<C[n][end--];
		cout<<endl;
	}
	
	return 0;
}
