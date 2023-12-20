//DP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lis(vector<int> &a, int n)
{
	int *lis=new int [n];
	
	for(int i=0; i<n; i++)
		lis[i]=0;
	
	for(int i=0; i<n; i++)
		for(int j=0; j<i; j++)
			if(a[i]>a[j])
				lis[i]=max(lis[i], lis[j]+1);
					
	int l=0;
	for(int i=0; i<n; i++)
		l=max(l, lis[i]);
	
	return l;
} 

int main()
{
	vector<int> v;
	int n, x;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>x;
		v.push_back(x);
	}
	
	cout<<lis(v, v.size())+1<<endl;
	v.clear();
	return 0;
}
