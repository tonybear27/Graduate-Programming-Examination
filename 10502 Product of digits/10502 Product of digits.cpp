#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int times;
	cin>>times;
	while(times--)
	{
		int n;
		cin>>n;
		int ans[100]={};
		int size=0;
		
		if(n==1)
			puts("1");
		else
		{
			for(int i=9; i>=2; i--)
			{
				while(!(n%i))
				{
					n/=i;
					ans[size++]=i;
				}
			}
			
			sort(ans, ans+size);
			
			if(n==1)
			{
				for(int i=0; i<size; i++)
					cout<<ans[i];
				puts("");
			}
			else
				puts("-1");
		}
	}
	
	return 0;
}
