#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while(cin>>n && n)
	{
		int max=0;
		map<vector<int>, int> frosh;
		vector<int> v(5);
		
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<5; j++)
				cin>>v[j];
				
			sort(v.begin(), v.end());
			
			//If the element exists in the map container, then return 1
			if(frosh.count(v)==1)
				frosh[v]++;
			else
				frosh[v]=1;	
		}	
		
		map<vector<int>, int>::iterator i;
		
		for(i=frosh.begin(); i!=frosh.end(); ++i)
			if(i->second>max)
				max=i->second;
		
		int count=0;
		
		for(i=frosh.begin(); i!=frosh.end(); ++i)
			if(i->second==max)
				count++;
				
		max*=count;
		
		cout<<max<<endl;
		
		frosh.clear();
	}	
	
	return 0;
}
