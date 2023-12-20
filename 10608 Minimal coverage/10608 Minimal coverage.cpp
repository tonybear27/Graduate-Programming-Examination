//Greedy
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Segment
{
    int L, R;
};

bool comp(const Segment &s1, const Segment &s2)
{
    return s1.L < s2.L;
}

int main()
{  
    int T;
    cin >> T;
    while ( T-- )
    {
        int M;
        cin >> M;
        
		vector<Segment> S(1);
        while (cin>>S[0].L>>S[0].R && (S[0].L || S[0].R))
            S.push_back(S[0]);
		    
		// Sort S by increasing left endpoint.
        sort(S.begin() + 1, S.end(), comp);
        
		int curL = 0, rReach = 0;
        int i = 1;
        vector<Segment> segments;
        while (rReach < M)
        {
            // Choose the segment which L <= curL and extends the farthest 
            // to right.
            int newL = curL;
            int farthest = 0;    
            for ( ; i < S.size(); i++)
                if (S[i].L > curL)
                    break;
                else if (S[i].R >= newL)
                {
                    newL = S[i].R;
                    farthest = i;
                }
            
            if (farthest == 0)
                break;
            segments.push_back(S[farthest]);
            curL = rReach = newL;
        }
        
        if (rReach >= M)
        {
            cout << segments.size() << endl;
            for (int i = 0; i < segments.size(); i++)
                cout << segments[i].L << " " << segments[i].R << endl;
        }
        else
            cout << "0" << endl;
        
		if (T)
            cout << endl;
    }
    return 0;
}
