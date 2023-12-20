#include <iostream>
#include <algorithm>
using namespace std;

int lcs(string s1, string s2, int m, int n)
{
	int **l = new int *[m + 1];
	for (int i = 0; i <= m; i++)
		l[i] = new int[n + 1];

	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (!i || !j)
				l[i][j] = 0;
			else if (s1[i - 1] == s2[j - 1])
				l[i][j] = l[i - 1][j - 1] + 1;
			else
				l[i][j] = max(l[i - 1][j], l[i][j - 1]);
		}
	}

	return l[m][n];
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
		cout << lcs(s1, s2, s1.length(), s2.length()) << endl;

	return 0;
}