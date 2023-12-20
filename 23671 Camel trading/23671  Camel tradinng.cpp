#include <stdio.h>
int main()
{	
	int times;
	scanf("%d\n", &times);
	while(times--)
	{
		long long num[100]={0};
		char sign[100];
		long long aux[100]={0}; 
		int max=0, min=0;

		for (int i=0; i<100; i++)
		{
			scanf("%lld", &num[i]);
			scanf("%c", &sign[i]);
		
			if(sign[i]=='\n')
				break;
		}
		
		for (int i=0; i<100; i++)
			aux[i]=num[i];

		for (int i=0; i<100; i++)
		{
			if(sign[i]=='+')
			{
				aux[i+1]=aux[i]+aux[i+1];
				aux[i]=0;
			}

			if(sign[i]=='*')
			{
				num[i+1]=num[i]*num[i+1];
				num[i]=0;
			}
		}
		
		long long tots=1;
		long long totm=0;

		for (int i=0; i<100; i++)
		{
			if(aux[i])
				tots*=aux[i];

			totm+=num[i];
		}

		printf("The maximum and minimum are %lld and %lld.\n", tots, totm );
	}

	return 0;
}
