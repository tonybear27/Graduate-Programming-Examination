#include <stdio.h> 
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
struct Node 
{
	string c;
    map<string, int> next;
    
	//Default Constructor
    Node() 
	{
    	next.clear();
    }
    
	// Public Function
	void init(string s) 
	{
    	c = s;
    	next.clear();
    }
    
} nodes[1048576];

int TreeSize = 0;

void insertTree(vector<string>& s) 
{
	int p = 0;
	for (int i = 0; i < s.size(); i++) 
	{
		if (nodes[p].next.find(s[i]) == nodes[p].next.end()) 
		{
			nodes[++TreeSize].init(s[i]);
			nodes[p].next[s[i]] = TreeSize;
		}
		
		p = nodes[p].next[s[i]];
	}
}

void dfs(int u, int depth) 
{
	if (u) 
	{
		for (int i = 1; i < depth; i++)
			cout<<" ";
		cout<<nodes[u].c.c_str()<<endl;
	}
	for (map<string, int>::iterator it = nodes[u].next.begin(); it != nodes[u].next.end(); it++)
		dfs(it->second, depth + 1);
}

int main() 
{	
	int n;
	char s[100];
	string token;
	while (cin>>n) 
	{
		nodes[0].init("");
		TreeSize = 0;
		for (int i = 0; i < n; i++) 
		{
			cin>>s;
			for (int j = 0; s[j]; j++)
				if (s[j] == '\\')
					s[j] = ' ';
			
			//Transfer C-string to C++ string 
			stringstream sin(s);
			vector<string> d;
			while (sin >> token)
				d.push_back(token);
			insertTree(d);
		}
		dfs(0, 0);
		puts("");
	}
	return 0;
}
