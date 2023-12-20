//Josephs Problem
#include <iostream>
using namespace std;
int main()
{
	int n, k;
	int i;
	
	while(cin>>n && n)
	{
		n--;
		for(i=1; i<n; i++)
		{
			k=0;
			for(int j=1; j<=n; j++)
				k=(k+i)%j;
			
			if(k==11)
				break;
		}
		
		cout<<i<<endl;
	}
	
	return 0;	
}
