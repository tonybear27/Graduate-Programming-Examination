#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main()
{
	vector<string> word;
	string buf;
	while(getline(cin, buf) && buf!="0")
	{
		string s;
		for(int i=0; buf[i]; i++)
		{
			if(isalpha(buf[i]))
			{
				s="";
				while(isalpha(buf[i]))
					s.insert(s.end(), buf[i++]);
				word.push_back(s);
				i--;
				cout<<s;
			}
			else if(isdigit(buf[i]))
			{
				int value=0;
				while(isdigit(buf[i]))
					value=value*10+buf[i++]-'0'; //determine the position of the word
				s=word[word.size()-value]; //determine the word
				word.erase(word.end()-value); //erase the number
				word.push_back(s); //push back the word
				i--;
				cout<<s;
			}
			else
				cout<<buf[i];
		}
		puts("");
	}
	
	return 0;
}
