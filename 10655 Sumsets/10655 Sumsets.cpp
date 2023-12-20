#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while(cin>>n && n)
	{
		int *data=new int [n];
		for(int i=0; i<n; i++)
			cin>>data[i];
		
		sort(data, data+n);
		int ans;
		bool found=false;
		for(int d=n-1; d>=0 && !found; d--)
		{
			for(int a=0; a<n && !found; a++)
			{
				if(a==d)
					continue;
				for(int b=a+1; b<n && !found; b++)
				{
					if(b==d)
						continue;
					for(int c=b+1; c<n && !found; c++)
					{
						if(c==d)
							continue;
						if(data[a]+data[b]+data[c]==data[d])
						{
							ans=data[d];
							found=true;
						}
					}
						
				}
			}
		}
		
		if(found)
			cout<<ans<<endl;
		else
			cout<<"no solution\n";
		delete []data;
	}
	
	return 0;
}
