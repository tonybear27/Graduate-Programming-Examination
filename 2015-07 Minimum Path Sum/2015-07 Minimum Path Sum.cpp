//Recrusion 
#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;
int mincost(int **map, int m, int n)
{
	if(n<0 || m<0)
		return INT_MAX;
	else if(m==0 && n==0)
		return map[m][n];
	else 
		return map[m][n]+min(mincost(map, m, n-1), mincost(map, m-1, n));	
}

int main()
{
	int times;
	cin>>times;
	while(times--)
	{
		int r, c;
		cin>>r>>c;
		int **map=new int *[r];
		for(int i=0; i<r; i++)
			map[i]=new int [c];
		
		for(int i=0; i<r; i++)
			for(int j=0; j<c; j++)
				cin>>map[i][j];
		
		cout<<mincost(map, r-1, c-1)<<endl;
	}
	
	return 0;
}
