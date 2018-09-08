#include<stdio.h>
#include<stdlib.h>
int main() {
	int n, k;
	int i, j;
	int* coin;
	int** dp;
	scanf("%d %d", &n, &k);
	coin = (int*)malloc(sizeof(int)*n);
	dp = (int**)malloc(sizeof(int*)*(n+1));
	for (i = 0; i < n; i++) {
		scanf("%d", &(coin[i]));
		dp[i] = (int*)calloc(k+1, sizeof(int));
	}
	dp[n] = (int*)calloc(k+1, sizeof(int));
	for (i = 0; i <= n; i++) {
		dp[i][0] = 1;
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= k; j++) {
			if (j < coin[i - 1]) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = dp[i - 1][j] + dp[i][j - coin[i - 1]];
			}
		}
	}
	printf("%d\n", dp[n][k]);
	for (i = 0; i <= n; i++) {
		free(dp[i]);
	}
	free(dp);
	free(coin);
	return 0;
}