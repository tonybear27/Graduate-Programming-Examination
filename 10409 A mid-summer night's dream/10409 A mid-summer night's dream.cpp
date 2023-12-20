#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		int *num=new int [n];
		int ans1=0, ans2=0, ans3=0;
		for(int i=0; i<n; i++)
			cin>>num[i];
		
		sort(num, num+n);
		
		for(int i=0; i<n; i++)
		{
			if(n%2)
			{
				ans1=num[(n-1)/2];
				ans3=1;
				if(num[(n-1)/2]==num[i])
					ans2++;
			}
			
			else
			{
				ans1=num[n/2-1];
				ans3=num[n/2]-num[n/2-1]+1;
				if(num[n/2-1]==num[i])
					ans2++;
				else if(num[n/2]==num[i])
					ans2++;
			}
		}
		
		cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
	}
	
	return 0;
}
