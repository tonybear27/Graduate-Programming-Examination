#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LIS(int* num, int n)
{
	int *lis=new int [n];
	lis[0]=1;
	
	for(int i=1; i<n; i++)
	{
		lis[i]=1;
		for(int j=0; j<i; j++)
			if(num[i]>num[j] && lis[j]+1>lis[i])
				lis[i]=lis[j]+1;
	}
	
	return *max_element(lis, lis+n);
}

void output(vector<vector <int> > &ANS, vector <int> &temp, int *num, int i, int n, int M)
{
	if (temp.size() == M)
		ANS.push_back(temp);
	
	else 
	{
		for (int j = i; j < n; j++) 
		{
			if ( temp.size() == 0 || num[j] > temp.back() ) 
			{
				temp.push_back(num[j]);
				output(ANS, temp, num, j + 1, n, M);
				temp.pop_back();
			}
		}
	}
	
}

int main()
{
	int t, n;
	cin >> t;
	
	for (int i = 0; i < t; i++) 
	{
		cin >> n;
		int *num=new int [n];
		
		for (int j = 0; j < n; j++)
			cin >> num[j];
		
		int M = LIS(num, n);
		
		vector <vector <int> > ANS;
		vector <int> temp;
		output(ANS, temp, num, 0, n, M);
		
		cout<<ANS.size()<<endl;
		
		for (int j = 0; j < ANS.size(); j++) 
		{
			for (vector<int>::iterator it = ANS[j].begin(); it != ANS[j].end(); it++)
				cout << *it << " ";
			cout << endl;
		}
		
		delete []num;
		temp.clear();
		for(int j=0; j<ANS.size(); j++)
			for(int k=0; k<ANS[j].size(); k++)
				ANS[j].clear();
	}
	
	return 0;
}
