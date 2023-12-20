#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int Case=1;
	string bitstring;
	while(cin>>bitstring)
	{
		int n;
		cin>>n;
		cout<<"Case "<<Case++<<":\n";
		
		while(n--)
		{
			int i, j;
			cin>>i>>j;
			if(i>j)
				swap(i, j);
			string substring=bitstring.substr(i, j-i+1);
			if(substring.size()<=1 || unique(substring.begin(), substring.end())==substring.begin()+1)
				puts("Yes");
			else
				puts("No");
		}
	}
	
	return 0;
}
