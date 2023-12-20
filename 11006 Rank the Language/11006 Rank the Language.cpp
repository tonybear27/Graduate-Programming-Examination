//DFS
#include <iostream>
#include <cstring>
using namespace std;

char map[1000][1000]={0};
bool isVisited[1000][1000]={0};

void DFS(int x, int y)
{
	isVisited[x][y]=true;
	if(map[x+1][y]==map[x][y] && !isVisited[x+1][y])
		DFS(x+1, y);
	if(map[x-1][y]==map[x][y] && !isVisited[x-1][y])
		DFS(x-1, y);
	if(map[x][y+1]==map[x][y] && !isVisited[x][y+1])
		DFS(x, y+1);
	if(map[x][y-1]==map[x][y] && !isVisited[x][y-1])
		DFS(x, y-1);
}

int main()
{
	int N, h, w, area;
	int world=1;
	cin>>N;
	while(N--)
	{
		cin>>h>>w;
		memset(isVisited, 0, sizeof(isVisited));
		int letters[30]={0};
		area=0;
		
		for(int i=1; i<=h; i++)
			for(int j=1; j<=w; j++)
				cin>>map[i][j];
				
		for(int i=1; i<=h; i++)
			for(int j=1; j<=w; j++)
				if(!isVisited[i][j])
				{
					area=max(++letters[map[i][j]-'a'], area);
					DFS(i, j);
				}
				
		cout<<"World #"<<world++<<endl;
		
		for(int i=area; i>=1; i--)
			for(int j=0; j<26; j++)
				if(letters[j]==i)
					cout<<(char)('a'+j)<<": "<<i<<endl;
	}
	
	return 0;
}
