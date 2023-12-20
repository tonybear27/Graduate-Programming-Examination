//DP
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int m;
	cin>>m;
	cin.ignore();
	while(m--)
	{
		string s;
		getline(cin, s);
		stringstream ss(s);
		
		vector<int> sums(1, 0);
		int sum=0;
		int k;
		while(ss>>k)
		{
			sum+=k;
			
			int size =sums.size();
			for(int i=0; i<size; i++)
				sums.push_back(sums[i]+k);
		}
		
		if(!(sum%2) && find(sums.begin(), sums.end(), sum/2)!=sums.end())
			cout<<"YES\n";
		else
			cout<<"NO\n";
		
		sums.clear();
	}
	
	return 0;
}
