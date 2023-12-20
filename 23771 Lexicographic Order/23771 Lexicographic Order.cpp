#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int t;
	long long f[50]={1};
	for(int i=1; i<50; i++)
		f[i]=f[i-1]*i;
	cin>>t;
	int cases=0;
	while(t--)
	{
		char buf[50];
		long long n;
		cin>>buf>>n;
		cout<<"Case "<<++cases<<": ";
		
		string s(buf);
		sort(s.begin(), s.end());
		
		int len=strlen(buf);
		int ans[50]={}, used[50]={};
		
		for(int i=0; i<len; i++)
		{
			int cnt=0;
			while(n>f[len-i-1])
			{
				n-=f[len-i-1];
				cnt++;
			}
			cnt++;
			for(int j=0; j<len; j++)
			{
				if(!used[j])
					cnt--;
				if(cnt==0)
				{
					used[j]=1;
					ans[i]=s[j];
					break;
				}
			}
		}

		for(int i=0; i<len; i++)
		{
			for(int j=0; j<len; j++)
			{
				if(ans[j]==s[i])
					cout<<buf[j];
			}
		}
		puts("");
	}
	
	return 0;
}
