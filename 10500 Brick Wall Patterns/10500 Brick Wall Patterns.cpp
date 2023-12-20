#include <iostream>
using namespace std;
long long int ans[70];

void answer() 
{
    ans[0] = 1;
    ans[1] = 2;
    for (int i = 2; i < 70; i++) 
        ans[i] = ans[i - 1] + ans[i - 2];
}

int main()
{
    answer();
    int n;
    while (cin>>n && n != 0) 
        cout<<ans[n - 1]<<endl;
}
