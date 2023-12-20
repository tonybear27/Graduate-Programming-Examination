#include <iostream>
#include <cmath>
#define ERROR 1E-8
using namespace std;

int main()
{
	unsigned int n;
	while(cin>>n && n)
	{
		unsigned int sq=(int)(sqrt(n)+ERROR);
		if((double)(sq*sq)==n)
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
	
	return 0;
}
