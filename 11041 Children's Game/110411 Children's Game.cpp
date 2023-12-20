#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(string& a, string& b)
{
	return(a+b>b+a);
}

int main()
{
	int times;
	while(cin>>times && times)
	{
		string str;
		vector<string> s;
		
		for(int i=0; i<times; i++)
		{
			cin>>str;
			s.push_back(str);
		}
		
		sort(s.begin(), s.end(), compare);
		
		string result;
		
		for(int i=0; i<s.size(); i++)
			result+=s[i];
			
		cout<<result<<endl;
		
		s.clear();
	}
	
	return 0;
}
