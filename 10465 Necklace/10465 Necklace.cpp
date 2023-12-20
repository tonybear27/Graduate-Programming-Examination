#include <stdio.h>
int main()
{
	double vt, v0;
	while(scanf("%lf%lf", &vt, &v0) && vt && v0)
	{
		if(vt<=v0)
			puts("0");
		else if(vt<=2*v0)
			puts("1");
		else
		{
			if(0.5*vt/v0-(int)(0.5*vt/v0)==0.5)
				puts("0");
			else if(0.5*vt/v0-(int)(0.5*vt/v0)<0.5)
				printf("%d\n", (int)(0.5*vt/v0));
			else
				printf("%d\n", (int)(0.5*vt/v0)+1);
		}
	}
	
	return 0;
}

