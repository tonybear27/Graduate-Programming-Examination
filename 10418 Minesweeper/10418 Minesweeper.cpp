#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int Case=1;
	int n, m;
	while(cin>>n>>m && m && n)
	{
		if(Case>1)
			cout<<endl;
		
		vector<vector<char> > field(n+2, vector<char>(m+2, '.'));
		for(int r=1; r<=n; r++)
			for(int c=1; c<=m; c++)
				cin>>field[r][c];
				
		cout<<"Field #"<<Case++<<":\n";
		
		for(int r=1; r<=n; r++)
		{
			for(int c=1; c<=m; c++)
			{
				if(field[r][c]=='*')
					cout<<'*';
				else
				{
					int mines=0;
					for(int i=r-1; i<=r+1; i++)
						for(int j=c-1; j<=c+1; j++)
							if(field[i][j]=='*')
								mines++;
					cout<<mines;
				}
			}
			cout<<endl;
		}
	
	}

	return 0;
}
