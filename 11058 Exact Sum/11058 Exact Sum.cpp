#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		int have;
		vector<int> books(n);
		for(int i=0; i<n; i++)
			cin>>books[i];
		
		cin>>have;
		
		sort(books.begin(), books.end());
		
		int sum=0, mi=99999;
		int ans1, ans2, difference;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(i!=j)
				{
					sum=books[i]+books[j];
					difference=abs(books[i]-books[j]);
					if(sum==have && difference<mi)
					{
						ans1=i;
						ans2=j;
						mi=difference;
					}
				}
			}
		}
		
		cout<<"Peter should buy books whose prices are "<<books[ans1]<<" and "<<books[ans2]<<".\n\n";
		
		books.clear();
	}
	
	return 0;
}
