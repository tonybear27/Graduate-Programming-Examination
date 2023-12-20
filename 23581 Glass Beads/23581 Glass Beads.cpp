#include <iostream>
#include <algorithm>
#include <cstring>
#define maxn 10005
using namespace std;

int main()
{
	int t;
	cin>>t;
	char s[maxn];
	while(t--)
	{
		memset(s, 0, sizeof(s));
		cin>>s;
		int len=strlen(s);
		int p=0, q=1;
		while(p<len && q<len)
		{
			int i;
			for(i=0; i<len; i++)
				if(s[(p+i)%len]!=s[(q+i)%len])
					break;
			
			if(i==len)
				break;
			
			if(s[(p+i)%len]>s[(q+i)%len])
				p+=i+1;
			else
				q+=i+1;
			
			if(p==q)
				q++;	
		}
		
		cout<<min(q, p)+1<<endl;
	}
	
	return 0;
}
