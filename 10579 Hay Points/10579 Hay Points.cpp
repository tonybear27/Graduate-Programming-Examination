#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	int m, n;
	cin>>m>>n;
	map<string, int> p;
	
	while(m--)
	{
		string word;
		int value;
		cin>>word>>value;
		p[word]=value;
	}
	
	while(n--)
	{
		int sum=0;
		string s;
		while(cin>>s && s!=".")
			sum+=p[s];
			
		cout<<sum<<endl;
	}
	
	return 0;
}
