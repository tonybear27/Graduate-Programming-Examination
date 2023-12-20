#include <iostream>
#include <vector>
#include <sstream>
#include <utility>
#include <algorithm>
using namespace std;

const int maxn=10001;
int ans=0;
vector<pair<int, int> > vp[maxn]; //Distance between i valley

int dfs(int to, int from) //go to + to from
{
	int road=0;
	int temp;
	
	for(int i=0; i<vp[to].size(); i++)
	{
		int go=vp[to][i].first;
		
		if(go!=from) //If you haven't arrived
		{
			temp=dfs(go, to)+vp[to][i].second;
			ans=max(ans, temp+road);
			road=max(temp, road);
		}
	}
	
	return road;
}

int main()
{
	int a, b, c;
	string s;
	
	while(getline(cin, s))
	{
		for(int i=0; i<maxn; i++)
			vp[i].clear();
		ans=0;
		
		while(s.length())
		{
			stringstream ss;
			ss<<s;
			ss>>a>>b>>c;
			vp[a].push_back(make_pair(b, c));
			vp[b].push_back(make_pair(a, c));
			getline(cin, s);
		}
		
		dfs(1, 0);
			
		cout<<ans<<endl;
	}
	
	return 0;
}
