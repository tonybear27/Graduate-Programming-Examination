#include <iostream>
using namespace std;

long long ways(long long n)
{
	if(n==1)
		return 1;
	if(n==2)
		return 2;
	
	long long *f=new long long [n+1];
	f[0]=0;
	f[1]=1;
	f[2]=2;
	
	for(int i=3; i<=n; i++)
		f[i]=f[i-1]+f[i-2];
	
	long long ans=f[n];
	
	delete []f;
	
	return ans;
}

int main()
{
	long long n;
	while(cin>>n)
		cout<<ways(n)<<endl;
	
	return 0;
}
