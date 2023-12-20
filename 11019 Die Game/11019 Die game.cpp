#include <stdio.h>
#include <string.h>
int main()
{
	char word[10];
	int a, n, s, w, e, up, down, t;
	
	while(scanf("%d", &a) && a)
	{
		up=1, n=2, w=3, e=4, s=5, down=6;
		scanf(" ");
		while(a--)
		{
			scanf("%s", word);
			if(!strcmp(word, "north"))
			{
				t=up;
				up=s;
				s=down;
				down=n;
				n=t;
			}
			else if(!strcmp(word, "south"))
			{
				t=up;
				up=n;
				n=down;
				down=s;
				s=t;	
			}
			else if(!strcmp(word, "east"))
			{
				t=up;
				up=w;
				w=down;
				down=e;
				e=t;
			}
			else if(!strcmp(word, "west"))
			{
				t=up;
				up=e;
				e=down;
				down=w;
				w=t;
			}
		}
		
		printf("%d\n", up);
	}
	
	return 0;
}
