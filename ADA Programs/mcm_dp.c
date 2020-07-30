#include <stdio.h>
#define INT_MAX 999

int MatrixChainOrder(int p[], int n) {
    int m[n][n];
    int i, j, k, L, q;

	//INITIALISATION
    for (i=1; i<n; i++)
        m[i][i] = 0;

	//l -> Chain length
      for (L=2; L<n;    L++)
      for (i=1; i<=n-L; i++) {
            j = i+L-1;
            m[i][j] = INT_MAX;
		for (k=i; k<j; k++) {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    return m[1][n - 1];
}
int main() {
    int d[] = { 5, 4, 6, 2, 7 };
    printf("Minimum number of multiplications is %d ",  MatrixChainOrder(d, 5));
    return 0;
}
