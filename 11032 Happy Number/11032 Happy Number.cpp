#include <iostream>
using namespace std;

int squaresum(int n)
{
	int sum=0;
	while(n)
	{
		int tmp=n%10;
		tmp*=tmp;
		sum+=tmp;
		n/=10;
	}
	
	return sum;
}

int main()
{
	int cs=1;
	int n;
	int times;
	cin>>times;
	while(times--)
	{
		cin>>n;
		int tmp=n;
		do
		{
			tmp=squaresum(tmp);
		}while(tmp>=10);
		
		cout<<"Case #"<<cs++<<": ";
		if(tmp==1)
			cout<<n<<" is a Happy number.\n";
		else
			cout<<n<<" is an Unhappy number.\n";
	}
	
	return 0;
}
