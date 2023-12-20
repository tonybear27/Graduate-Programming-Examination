#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LIS[i] stores the maximum length of S's LIS ending at i.
void doLIS(const vector<int>& S, vector<int>& LIS)
{
    vector<int> L(S.size());
    
	int lisCount=0;
	
    for (int i=0; i<S.size(); i++)
    {
        int pos=lower_bound(L.begin(), L.begin() + lisCount, S[i])-L.begin();

		L[pos] = S[i];
        
		if (pos == lisCount)
            lisCount++;
        
		LIS[i] = pos + 1;
    }
}

int main()
{  
    int N;
    while (cin>>N)
    {
        vector<int> S(N);
        for (int i = 0; i < N; i++)
            cin>>S[i];
        
        vector<int> LIS(N), LDS(N);
        
		doLIS(S, LIS);
		//for(int i=0; i<LIS.size(); i++)
		//	cout<<LIS[i]<<" ";
		//cout<<endl;
        reverse(S.begin(), S.end());
        
		doLIS(S, LDS);
		//for(int i=0; i<LDS.size(); i++)
		//	cout<<LDS[i]<<" ";
		//cout<<endl;
        reverse(LDS.begin(), LDS.end());


/*	Suppose S[] = 1 3 6 5
    LIS[] = 1 2 3 3
	LDS[] = 1 1 2 1
	then we can pick 1 6 5 or 3 6 5.
*/
        int maxLIS = 0;
        for (int i = 0; i < LIS.size(); i++)
            maxLIS = max(maxLIS, 2*min(LIS[i], LDS[i])-1);
        
		cout <<maxLIS<< endl;
    }
    return 0;
}
