#include <iostream>
using namespace std;

int prime[4000]={0};

void build()
{
	int index=0;
	for(int i=2; i<35000; i++)
	{
		int d=2, p=1;
		while(d<=i/2 && p)
			if(i%d==0)
				p=0;
			else
				d++;
		if(p)
		{
			prime[index]=i;
			index++;
		}	
	}
}

int main()
{
	build();
	int n;
	while(cin>>n && n)
	{
		int ans=0;
		for(int i=1; i<=n; i++)
			ans=(ans+prime[n-i])%i;
		
		cout<<ans+1<<endl;
	}
	return 0;
}
