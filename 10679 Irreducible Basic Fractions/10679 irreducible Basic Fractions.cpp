#include <iostream>
using namespace std;

int phi(int n)
{
	int p = n;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			while (n % i == 0)
				n /= i;
			p -= p / i;
		}
	}

	if (n > 1)
		p -= p / n;

	return p;
}

int main()
{
	int n;
	while (cin >> n)
		cout << phi(n) << endl;
	return 0;
}
