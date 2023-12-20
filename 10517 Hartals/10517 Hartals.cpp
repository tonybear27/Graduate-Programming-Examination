#include <stdio.h>
int main()
{
	int T, N, P;
	scanf("%d", &T);
	while(T--)
	{
		int day[3651]={0};
		int x, tmp;
		scanf("%d%d", &N, &P);
		
		for(int i=0; i<P; i++)
		{
			scanf("%d", &x);
			tmp=x;
			
			while(x<=N)
			{
				day[x]=1;
				x+=tmp;	
			}
		}
		
		int count=0;
		for(int i=1; i<=N; i++)
			if(day[i]==1 && (i%7!=0) && (i%7!=6))
				count++;
		
		printf("%d\n", count);
	}
	
	return 0;
}
