#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	int tmp, i;
	string s;
	while(getline(cin, s) && s!="")
	{
		int sum=0, x=1;
		
		for(i=0; i<s.length(); i++)
		{
			if(isdigit(s[i]))
				tmp=s[i]-'0';
			else if(islower(s[i]))
				tmp=s[i]-'a'+36;
			else if(isupper(s[i]))
				tmp=s[i]-'A'+10;
			else
				continue;
				
			if(x<tmp)
				x=tmp;
			sum+=tmp;
		}
		
		for(i=x; i<62; i++)
			if(!(sum%i))
			{
				cout<<i+1<<endl;
				break;
			}
		
		if(i==62)
			puts("such number is impossible!");	
	}
	
	return 0;
}
