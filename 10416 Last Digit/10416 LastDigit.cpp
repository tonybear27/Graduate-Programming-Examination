#include <iostream>
#include <string>
using namespace std;

int maps[]={0, 1, 5, 2, 8, 3, 9, 2, 8, 7, 7, 8, 4, 7, 3, 8, 4, 1, 5, 4};

int main()
{
	string s;
	while(cin>>s && s!="0")
	{
		int value=s[s.length()-1]-'0';
		if(s.length()>1)
			value+=(s[s.length()-2]-'0')*10;
		
//		Because after doing 20 times loops, the last digit is 4 more than the previous one
		cout<<(maps[value%20]+value/20*4)%10<<endl;
	}
	return 0;
}
