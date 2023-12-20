#include <iostream>
#include <vector>
using namespace std;
vector<int> primes;

void generateprime()
{
	for(int i=2; i<=10020; i++)
	{
		int p=1;
		int d=2;
		while(d<=i/2 && p)
			if(i%d==0)
				p=0;
			else
				d++;
		if(p)
			primes.push_back(i);
	}
}

int main()
{
	generateprime();
	int N, sum, count;
	while(cin>>N && N)
	{
		count=0;
		for(int i=0; primes[i]<=N; i++)
		{
			sum=primes[i];
			for(int j=i+1; sum<N; j++)
				sum+=primes[j];
			if(sum==N)
				count++;
		}
		
		cout<<count<<endl;
	}
	
	return 0;
}
