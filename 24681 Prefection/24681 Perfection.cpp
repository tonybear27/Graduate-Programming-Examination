#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
	int n;
	puts("PERFECTION OUTPUT");
	while(cin>>n)
	{
		if(n==0)
		{
			puts("END OF OUTPUT");
			break;	
		}
		
		vector<int> factors;
		for(int i=1; i<=n/2; i++)
		{
			if(!(n%i))
				factors.push_back(i);
		}
		
		int sum=0;
		for(int i=0; i<factors.size(); i++)
			sum+=factors[i];
		
		cout<<setw(5)<<n;
		if(sum==n)
			puts("  PERFECT");
		else if(sum>n)
			puts("  ABUNDANT");
		else
			puts("  DEFICIENT");
	}
	
	return 0;
}
