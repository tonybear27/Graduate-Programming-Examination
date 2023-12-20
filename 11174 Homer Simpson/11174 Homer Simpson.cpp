//Greedy
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int m, n, t;
	while(cin>>m>>n>>t)
	{
		int minT=min(m, n);
		int maxT=max(m, n);
		
		int maxA=t/minT;
		int remain=t-maxA*minT;
		
		for(int i=maxA-1; i>=0 && remain ; i--)
		{
			int current=t-i*minT;
			int another=current/maxT;
			
			current-=another*maxT;
			
			if(current<remain)
			{
				maxA=i+another;
				remain=current;
			}
		}
		
		cout<<maxA;
		if(remain)
			cout<<" "<<remain;
		puts("");
	}
	
	return 0;
}
