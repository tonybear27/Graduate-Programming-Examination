#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
double node[1000000];
double zero[1000000];

//P(n)=P(n-1)+(1-P(n-1))/(n*(n+1))
//(1*1/2)*(1/2*1/3)*(1/3*1/4)*......*(1/n*1/(n+1))

void build()
{
	node[1]=0.5;
	zero[1]=log(2);
	for(int i=2; i<1000000; i++)
	{
		node[i]=1-(1-node[i-1])*(1-(1.0/i)*(1.0/(i+1.0)));
		zero[i]=zero[i-1]+log10(i*(i+1.));
	}
}

int main()
{
	build();
	int n;
	while(scanf("%d", &n)!=EOF)
		printf("%.6lf %d\n", node[n], (int)zero[n]);
	return 0;
}
