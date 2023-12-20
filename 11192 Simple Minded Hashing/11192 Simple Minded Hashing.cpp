//DP
#include <iostream>
using namespace std;

int ans[27][27][352]={0}; //Alphabet, Length, Sum

void build()
{
	ans[0][0][0]=1;
	for(int i=1; i<=26; i++) //Alphabet
	{
		for(int j=0; j<=i; j++) //Length
		{
			for(int k=0; k<352; k++) //Sum
			{
				ans[i][j][k]=ans[i-1][j][k]; //If the letter i is not selected
				if(j>0 && k>=i) //Sum must bigger than i and length must bigger than 0 
					ans[i][j][k]+=ans[i-1][j-1][k-i]; //If the letter i is selected
			}
		}
	}
}

int main()
{
	build();
	int L, S;
	int times=1;
	while(cin>>L>>S && L && S)
	{
		cout<<"Case "<<times++<<": ";
		if(L>26 || S>351)
			cout<<"0\n";
		else
			cout<<ans[26][L][S]<<endl;
	}
	
	return 0;
}
