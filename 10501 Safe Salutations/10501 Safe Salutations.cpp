#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
	int n;
	while (cin >> n)
	{
		ll fac = 1, fact = 1;
		for (ll i = n + 1; i <= 2 * n; i++)
			fac *= i;
		for (ll i = 1; i <= n + 1; i++)
			fact *= i;

		cout << fac / fact << endl;
	}

	return 0;
}