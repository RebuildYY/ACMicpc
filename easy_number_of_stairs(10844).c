#include<stdio.h>
int main() {
	int n;
	int i, j;
	int sum;
	int dp[101][11] = { 0, };
	scanf("%d", &n);
	for (i = 1; i < 10; i++) {
		dp[0][i] = 1;
	}
	for (i = 1; i < n; i++) {
		//0�� ���� ��ܿ��� �޾ƿ� �� �ۿ� ����, 9���� �Ʒ����� �޾ƿ;��Ѵ�.
		//�� �̿��� ���� �� �Ʒ����� �޾ƿ� �� �ִ�.
		dp[i][0] = dp[i - 1][1];
		for (j = 1; j < 9; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1])%1000000000;
		}
		dp[i][9] = dp[i - 1][8];
	}
	sum = 0;
	for (i = 0; i < 10; i++) {
		sum += dp[n - 1][i];
		sum = sum % 1000000000;
	}
	printf("%d\n", sum);
	return 0;
}