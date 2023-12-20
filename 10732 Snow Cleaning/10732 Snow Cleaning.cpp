#include <stdio.h>
#include <math.h>

int main()
{
	int times;
	scanf("%d", &times);
	while(times--)
	{
		char s[1024];
		scanf(" ");
		gets(s);
		
		double x1, y1, x2, y2;
		double dis=0;
		while(gets(s) && s[0]!='\0')
		{
			sscanf(s, "%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
			dis+=hypot(x1-x2, y1-y2);
		}
		dis/=1000;          //km
		double h=dis*2/20; // *2(with one lane in each direction) 
		
		int m=(int)round(h*60);
		printf("%d:%02d\n", m/60, m%60);
		if(times)
			puts("");
	}
	
	return 0;
}
