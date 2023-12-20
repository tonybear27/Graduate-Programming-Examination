//BFS
#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Point
{
	int l;
	int r;
	int c;
	int value;
	Point(int l, int r, int c, int value)
	{
		this->l=l;
		this->r=r;
		this->c=c;
		this->value=value;
	}
};

int BFS(string map[][100], int L, int R, int C, int pos_l, int pos_r, int pos_c)
{
	queue<Point> BFS_mem;
	BFS_mem.push(Point(pos_l, pos_r, pos_c, 0));
	
	while(!BFS_mem.empty())
	{
		Point p=BFS_mem.front();
		
		//Out of the map
		if(p.l<0 || p.r<0 || p.c<0 || p.l>=L || p.r>=R || p.c>=C)
		{
			BFS_mem.pop();
			continue;
		}
		
		//Escape
		if(map[p.l][p.r][p.c]=='E')
			return p.value;
		
		if(map[p.l][p.r][p.c]!='.')
		{
			BFS_mem.pop();
			continue;
		}
		
		map[p.l][p.r][p.c]='#';
		BFS_mem.push(Point(p.l+1, p.r, p.c, p.value+1));
		BFS_mem.push(Point(p.l-1, p.r, p.c, p.value+1));
		BFS_mem.push(Point(p.l, p.r+1, p.c, p.value+1));
		BFS_mem.push(Point(p.l, p.r-1, p.c, p.value+1));
		BFS_mem.push(Point(p.l, p.r, p.c+1, p.value+1));
		BFS_mem.push(Point(p.l, p.r, p.c-1, p.value+1));
		
		BFS_mem.pop();
	}
	
	return -1;
}


int main()
{
	int L, R, C;
	while(cin>>L>>R>>C && L && R && C) 
	{
		string map[100][100];
		
		int startl, startr, startc;
		
		for(int i=0; i<L; i++)
		{
			for(int j=0; j<R; j++)
			{
				cin>>map[i][j];
			
				for(int k=0; k<C; k++)
				{
					if( map[i][j][k] == 'S' )
					{
            			startl = i;
            			startr = j;
            			startc = k;
            			map[i][j][k] = '.';
          			}
				}
			}
		}
		
		int x=BFS(map, L, R, C, startl, startr, startc);
		
		if(x==-1)
			cout<<"Trapped!\n";
		else
			cout<<"Escaped in "<<x<<" minute(s).\n";
	}
	
	return 0;
}
