#include<stdio.h>
#include<math.h>

int knapsack(int n, int max_cap, int price[], int weight[]){
	int T[n+1][max_cap+1];

	for(int i=0; i<=n; i++)
	for(int j=0; j<=max_cap; j++){
		if(i==0 || j==0)
			T[i][j]=0;
		else if(weight[i-1] <= j)
			T[i][j] = fmax(T[i-1][j], price[i-1] + T[i-1][j-weight[i-1]]);
		else
			T[i][j] = T[i-1][j];
	}
	printf("\n");
	for(int i=0; i<=n; i++){
	for(int j=0; j<=max_cap; j++)
		printf("%d ", T[i][j]);
		printf("\n");
	}
	return T[n][max_cap];
}

int main(){
	int n, max_cap;;
	printf("Enter the number of items: ");
	scanf("%d", &n);

	int price[n], weight[n];

	printf("Enter the prices: ");
	for(int i=0; i<n; i++) scanf("%d", &price[i]);
	printf("Enter the weights: ");
	for(int i=0; i<n; i++) scanf("%d", &weight[i]);
	printf("Enter the max_cap: ");
	scanf("%d", &max_cap);

	int profit = knapsack(n, max_cap, price, weight);
	printf("The profit is %d\n", profit);
}
