#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	int times;
	cin>>times;
	while(times--)
	{
		int num;
		cin>>num;
		vector<int> a(num);
		for(int i=0; i<num; i++)
			cin>>a[i];
		
		sort(a.begin(), a.end());
		
		int mid=a[num/2];
		int ans=0;
		for(int i=0; i<num; i++)
			ans+=abs(a[num/2]-a[i]);
		
		cout<<ans<<endl;
		
		a.clear();
	}
	
	return 0;
}
