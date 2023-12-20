#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#define LENGTH 1000000

int bengola[LENGTH] = {0};

int sumOfDigit(int n)
{
	int sum = 0;
	while (n)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

void buildTable()
{
	bool isPrime[LENGTH];
	for (int i = 0; i < LENGTH; i++)
	{
		isPrime[i] = true;
	}
	isPrime[0] = false;
	isPrime[1] = false;
	for (long long int i = 2; i < LENGTH; i++)
	{
		if (isPrime[i])
		{
			for (long long int j = i * i; j < LENGTH; j += i)
			{
				isPrime[j] = false;
			}
			bengola[i] = bengola[i - 1] + ((isPrime[sumOfDigit(i)]) ? 1 : 0);
		}
		else
		{
			bengola[i] = bengola[i - 1];
		}
	}
}

int main()
{
	buildTable();
	int testCase, lower, upper;
	scanf("%d", &testCase);
	while (testCase--)
	{
		scanf("%d%d", &lower, &upper);
		printf("%d\n", bengola[upper] - bengola[lower - 1]);
	}
	return 0;
}