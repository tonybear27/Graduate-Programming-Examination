#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int *move=new int [n];
		char word[6];
		int index=0;
		int ans=0;
		
		while(n--)
		{
			cin>>word;
			if(!strcmp(word, "LEFT"))
				move[index]=-1;
			else if(!strcmp(word, "RIGHT"))
				move[index]=1;
			else if(!strcmp(word, "SAME"))
			{
				char as[2];
				cin>>as;
				int d;
				cin>>d;
				move[index]=move[d-1];	
			}
			index++;		
		}
		
		for(int i=0; i<index; i++)
			ans+=move[i];
			
		cout<<ans<<endl;
	}
	
	return 0;
}
