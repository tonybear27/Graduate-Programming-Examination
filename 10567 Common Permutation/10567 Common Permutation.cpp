#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string a, b;
	while(getline(cin, a))
	{
		getline(cin, b);
		if(a=="\n" || b=="\n")
		{
			cout<<endl;
			continue;
		}
		int ca[26]={0};
		int cb[26]={0};
		
		for(int i=0; i<a.length(); i++)
			ca[a[i]-'a']++;
		for(int i=0; i<b.length(); i++)
			cb[b[i]-'a']++;
		
		for(int i=0; i<26; i++)
			for(int j=min(ca[i], cb[i]); j>0; j--)
				cout<<(char)('a'+i);
		cout<<endl;
	}
	
	return 0;
}
