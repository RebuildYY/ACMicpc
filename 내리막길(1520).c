#include<stdio.h>
#include<stdlib.h>
//ó������ ���ʰ� ���ʸ��� ���ؼ� ���Ѵ�.
//�ι�° ���Ŀ��� �����¿� ��� ���Ͽ� ���Ѵ�.
int** dp;
int** grape;
void function(int n, int k, int t) {
	int i, j, l;
	for (l = 0; l < t; l++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < k; j++) {
				if (i == 0 && j == 0) continue;
				dp[i][j] = 0;
				if (i - 1 >= 0 && grape[i - 1][j] > grape[i][j]) {//���� ū���
					dp[i][j] += dp[i - 1][j];
				}
				if (i + 1 < n&& grape[i + 1][j] > grape[i][j]) {//�Ʒ��� ū���
					dp[i][j] += dp[i + 1][j];
				}
				if (j - 1 >= 0 && grape[i][j - 1] > grape[i][j]) {//������ ū���
					dp[i][j] += dp[i][j - 1];
				}
				if (j + 1 < k&&grape[i][j + 1] > grape[i][j]) {//�������� ū���
					dp[i][j] += dp[i][j + 1];
				}
			}
		}
	}
}
int main() {
	int n, k, i, j;
	scanf("%d %d", &n, &k);
	grape = (int**)malloc(sizeof(int*)*n);
	dp = (int**)malloc(sizeof(int*)*n);
	for (i = 0; i < n; i++) {
		grape[i] = (int*)malloc(sizeof(int)*k);
		dp[i] = (int*)malloc(sizeof(int)*k);
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < k; j++) {
			scanf("%d", &(grape[i][j]));
		}
	}
	dp[0][0] = 1;
	for (i = 1; i < k; i++) {
		if (grape[0][j - 1] > grape[0][j]) {
			dp[0][i] = dp[0][i - 1];
		}
		else {
			dp[0][i] = 0;
		}
	}
	for (i = 1; i < n; i++) {
		if (grape[i - 1][0] > grape[i][0]) {
			dp[i][0] = dp[i - 1][0];
		}
		else {
			dp[i][0] = 0;
		}
		for (j = 1; j < k; j++) {
			dp[i][j] = 0;
			if (grape[i - 1][j] > grape[i][j]) {
				dp[i][j] += dp[i - 1][j];
			}
			if (grape[i][j - 1] > grape[i][j]) {
				dp[i][j] += dp[i][j - 1];
			}
		}
	}//1�� ����
	function(n, k, n);//���� ������ŭ �ݺ��ؼ� �������ָ� ��Ȯ�� ����� ������ �� �� �ִ�.

	printf("%d\n", dp[n - 1][k - 1]);
	for (i = 0; i < n; i++) {
		free(dp[i]);
		free(grape[i]);
	}
	free(dp);
	free(grape);
	return 0;
}