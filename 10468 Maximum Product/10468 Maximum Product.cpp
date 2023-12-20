#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{  
    int Case=1; 
	int N;
    while (cin>>N)
    {
        vector<long long> seq(N);
        for (int i=0; i<N; i++)
            cin>>seq[i];

        // Try all possibilities.
        long long product = 0;
        for (int i=0; i<seq.size(); i++)
            for (int j=i; j<seq.size(); j++)
            {
                long long temp = 1;
                for (int k=i; k<=j; k++)
                    temp *= seq[k];
                product = max(product, temp);
            }
        
        cout << "Case #"<< Case++<< ": The maximum product is "<< product<< ".\n\n";
    }
    return 0;
}
