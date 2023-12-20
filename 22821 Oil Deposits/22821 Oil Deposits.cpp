//Flood Fill Algorithm
#include <iostream>
using namespace std;

const int MAX=100;

void visit(bool isVisited[][MAX+5], char map[][MAX+5], int i, int j)
{
	if(map[i][j]=='@' && !isVisited[i][j])
	{
		isVisited[i][j]=true;
		visit(isVisited, map, i-1, j);
		visit(isVisited, map, i+1, j);
		visit(isVisited, map, i, j+1);
		visit(isVisited, map, i, j-1);
		visit(isVisited, map, i+1, j+1);
		visit(isVisited, map, i+1, j-1);
		visit(isVisited, map, i-1, j+1);
		visit(isVisited, map, i-1, j-1);
	}
}

int main()
{
	int m, n;
	while(scanf("%d%d", &m, &n)!=EOF)
	{
		if(m==0 && n==0)
			break;
		char map[MAX+5][MAX+5]={0};
		gets(map[0]); //for '\n'
		for(int i=1; i<=m; i++)
			gets(map[i]+1);
			
		bool isVisited[MAX+5][MAX+5]={0};
		int count=0;
		for(int i=1; i<=m; i++)
			for(int j=1; j<=n; j++)
				if(map[i][j]=='@' && !isVisited[i][j])
				{
					count++;
					visit(isVisited, map, i, j);
				}
				
		printf("%d\n", count);
	}
	
	return 0;
}
