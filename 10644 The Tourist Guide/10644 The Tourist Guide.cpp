//Graph
#include <stdio.h>
#include <math.h>
#include <algorithm>
#define MAXN 100
#define INF INT_MAX
#define NINF INT_MIN
using namespace std;
int d[MAXN][MAXN]; //distance from i node to j node

//Floyd-Warshall Algorithm
void floyd(int n)
{
	for(int k=0; k<n; k++)
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				d[i][j]=max(d[i][j], min(d[i][k], d[k][j]));
}

int main()
{
	int n, e, u, v, w;
	int cs=0;
	while(scanf("%d%d", &n, &e) && n && e)
	{
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				d[i][j]=NINF;
		
		for(int i=0; i<e; i++)
		{
			scanf("%d%d%d", &u, &v, &w);
			u--;
			v--;
			d[u][v]=d[v][u]=w;	
		}
		
		floyd(n);
		scanf("%d%d%d", &u, &v, &w);
		u--;
		v--;
		printf("Scenario #%d\n", ++cs);
		int trip=ceil((double)w/(d[u][v]-1));
		printf("Minimal Number of Trips = %d\n\n", trip);
	}
	
	return 0;
}

