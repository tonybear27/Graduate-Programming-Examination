#include <stdio.h>

char map[100][100];
int height, width;

bool isSquare(int x, int y, int rad)
{
	int top, left, buttom, right;
	char center=map[x][y];
	
	top=x-rad;
	buttom=x+rad;
	left=y-rad;
	right=y+rad;
	
	if(top<0 || buttom>=height || left<0 || right>=width)
		return false;
	
	for(int i=top; i<=buttom; i++)
		for(int j=left; j<=right; j++)
			if(map[i][j]!=center)
				return false;
	
	return true;
}

int main()
{
	int times;
	scanf("%d", &times);
	while(times--)
	{
		int n, x, y, r;
		scanf("%d %d %d", &height, &width, &n);
		printf("%d %d %d\n", height, width, n);
		scanf(" ");
		for(int i=0; i<height; i++)
			gets(map[i]);
		
		for(int i=1; i<=n; i++)
		{
			scanf("%d%d", &x, &y);
			r=0;
			while(isSquare(x, y, r))
				r++;
			printf("%d\n", 2*r-1);
		}
			
	}
	
	return 0;
}
