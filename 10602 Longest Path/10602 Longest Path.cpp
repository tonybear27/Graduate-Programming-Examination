#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int longest(bool map[105][105], vector<int>& dis, int s, int n)
{
	queue<int> next;
	next.push(s);
	vector<bool> isQueue(n+1, false);
	
	while(!next.empty())
	{
		int current=next.front();
		next.pop();
		isQueue[current]=false;
		
		for(int i=1; i<=n; i++)
		{
			if(map[current][i] && dis[current]+1>dis[i])
			{
				dis[i]=dis[current]+1;
				if(!isQueue[i])
				{
					next.push(i);
					isQueue[i]=true;
				}
			}
		}
	}
	
	int max=1;
	for(int i=2; i<=n; i++)
		if(dis[i]>dis[max])
			max=i;
			
	return max;
}

int main()
{
	int n;
	int numbers=0;
	while(cin>>n && n)
	{
		int s;
		cin>>s;
		
		bool map[105][105]={false};
		
		int p, q;
		while(cin>>p>>q && p && q)
			map[p][q]=true;
			
		vector<int> dis(n+1, 0);
		
		int final=longest(map, dis, s, n);
		
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n", ++numbers, s, dis[final], final);
	}
	
	return 0;
}
