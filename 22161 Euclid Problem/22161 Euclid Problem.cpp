//Extended Euclidean Algorithm 
#include<iostream>
using namespace std;

void gcd(int a, int b, int& x, int& y, int& ans)
{
	if(!b)
	{
		ans=a;
		x=1;
		y=0;
	}
	else
	{
		gcd(b, a%b, y, x, ans);
		y-=x*(a/b);
	}
}

int main()
{
	int a, b, x, y, ans;
	while(cin>>a>>b)
	{
		gcd(a, b, x, y, ans);
		cout<<x<<" "<<y<<" "<<ans<<endl;
	}
	
	return 0;
}
