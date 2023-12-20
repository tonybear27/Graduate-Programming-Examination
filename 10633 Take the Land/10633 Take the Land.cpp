#include <stdio.h>
int main()
{
	int m, n;
	while (scanf("%d%d", &n, &m) && n && m)
	{
		int map[100][100] = {0};
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &map[i][j]);

		int max = 0;
		int tmp, length, width;

		for (int i = 0; i < n; i++)
		{
			int sum[100] = {0};
			for (int j = i; j < n; j++)
			{
				for (int k = 0; k < m; k++)
				{

					sum[k] += !map[j][k];
					//					Initialize
					if (k == 0 || tmp != length * width)
					{
						tmp = 0;
						length = 0;
					}

					length++;
					width = j - i + 1;
					tmp += sum[k];
					//					Found
					if (tmp == length * width)
						max = max > tmp ? max : tmp;
				}
			}
		}

		printf("%d\n", max);
	}

	return 0;
}
