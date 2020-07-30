#include <stdio.h>

/*
4x4   -> 4  = 4*1  = 4*4^0
8x8   -> 16 = 4*4  = 4^4^1
16*16 -> 64 = 4*16 = 4*4^2
*/

void subdivide(int n, int m, int a[][n], int p[][m], int q[][m], int r[][m], int s[][m])
{
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
			p[i][j] = a[i][j];
		for (int j = m; j < n; ++j)
			q[i][j-m] = a[i][j];
	}
	for (int i = m; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			r[i-m][j] = a[i][j];
		for (int j = m; j < n; ++j)
			s[i-m][j-m] = a[i][j];
	}
}

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter the size: \n");
	scanf("%d", &n);

	int a[n][n];
	printf("Enter the elements of the matrix: \n");
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &a[i][j]);
		}
	}

	int m = n / 2;
	int p[m][m], q[m][m], r[m][m], s[m][m];

	subdivide(n, m, a, p, q, r, s);

	printf("P:\n");
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
			printf("%d ", p[i][j]);
		printf("\n");
	}
	printf("Q:\n");
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
			printf("%d ", q[i][j]);
		printf("\n");
	}
	printf("R:\n");
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
			printf("%d ", r[i][j]);
		printf("\n");
	}
	printf("S:\n");
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
			printf("%d ", s[i][j]);
		printf("\n");
	}
	return 0;
}