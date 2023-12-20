#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
	int times;
	cin>>times;
	while(times--)
	{
		int num;
		cin>>num;
		
		vector<int> connect(num+1);
		for(int i=1; i<=num; i++)
			connect[i]=i;
			
		int right=0, wrong=0;
		string s;
		cin.ignore();
		
		while(getline(cin, s) && s!="")
		{
			stringstream ss(s);
			char type;
			int comi, comj;
			ss>>type>>comi>>comj;
			
			if(type=='c')
			{
				int groupi=connect[comi], groupj=connect[comj];
				for(int i=1; i<=num; i++)
				{
					if(connect[i]==groupi || connect[i]==groupj)
						connect[i]=min(groupi, groupj);		
				}
			}
			else if(type=='q')
			{
				if(connect[comi] != connect[comj])
					wrong++;
				else
					right++;
			}
		}
		cout<<right<<","<<wrong<<endl;
		if(times)
			puts("");
	}
	
	return 0;
}
