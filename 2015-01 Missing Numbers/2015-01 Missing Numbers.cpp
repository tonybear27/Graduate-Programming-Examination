#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int m, n;
	while(cin>>m>>n)
	{
		string num;
		vector<string> t1, t2;
		for(int i=0; i<n; i++)
		{
			cin>>num;
			t1.push_back(num);
		}
		m--;
		n--;
		
		while(m--)
		{
			for(int i=0; i<n; i++)
			{
				cin>>num;
				t2.push_back(num);
			}
			
			for(int i=0; i<t1.size(); i++)
				if(find(t2.begin(), t2.end(), t1[i])==t2.end())
					cout<<t1[i]<<endl;
						
			t1.clear();
			for(int i=0; i<t2.size(); i++)
			{
				string t=t2[i];
				t1.push_back(t);
			}
			t2.clear();
			n--;
		}
		
		t1.clear();
		t2.clear();
	}
	
	return 0;
}
