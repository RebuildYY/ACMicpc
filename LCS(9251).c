#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char str1[1001];
	char str2[1001];
	int l1, l2;
	int** dp;
	int i, j;
	scanf("%s", str1);
	scanf("%s", str2);
	l1 = strlen(str1);
	l2 = strlen(str2);
	dp = (int**)malloc(sizeof(int*)*(l1+1));
	for (i = 0; i <= l1; i++) {
		dp[i] = (int*)calloc(l2+1, sizeof(int));
	}
	for (i = 1; i <= l1; i++) {
		for (j = 1; j <= l2; j++) {
			if (str1[i - 1] == str2[j - 1]) {//���� ������ ���ڸ� ���Ͽ� ���� ��� ���� LCS ���� +1���ش�.
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {//�ٸ� ��� ���� ���ʿ��� ū���� �޾ƿ´�.
				dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
			}
		}
	}
	printf("%d\n", dp[l1][l2]);
	for (i = 0; i <= l1; i++) {
		free(dp[i]);
	}
	free(dp);
	return 0;
}