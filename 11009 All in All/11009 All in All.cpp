#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string s1, s2;
	while(cin>>s1>>s2)
	{
		int sindex=0;
		for(int i=0; i<s2.length(); i++)
		{
			if(s2[i]==s1[sindex])
				sindex++;
			if(sindex==s1.length())
				break;
		}
		
		if(sindex==s1.length())
			puts("Yes");
		else
			puts("No");
	}
	
	return 0;
}
