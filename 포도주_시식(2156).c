#include<stdio.h>
#include<stdlib.h>
int main() {
	int n, i, j, max;
	int* arr;
	int* acc;
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int)*n);
	acc = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++) {
		scanf("%d", &(arr[i]));
	}
	acc[0] = arr[0];
	acc[1] = arr[0] + arr[1];
	acc[2] = arr[0] + arr[2] > arr[1] + arr[2] ? arr[0] + arr[2] : arr[1] + arr[2];
	for (i = 3; i < n; i++) {
		max = 0;
		for (j = i - 3; j >= 0; j--) {//!3�� ������ �ȵǰ� ���籸�Ϸ��� ������ 3ĭ ���� �κк��� 0���� �����Ͽ� ���� ū �������� ���� ���� ���Ѵ�.
			if (max < acc[j]) {
				max = acc[j];
			}
		}
		if (acc[i - 2] > max + arr[i - 1]) {//���� ��ġ���� -2�� ���� �������� ū ���
			acc[i] = acc[i - 2] + arr[i];
		}
		else {//���� ��ġ -3�� ���� �������� ������ġ -1�� ���� ���� ū ���
			acc[i] = max + arr[i - 1] + arr[i];
		}
	}
	max = 0;
	for (i = 0; i < n; i++) {//��ü ���������� ���� ū ���� ���Ͽ� ����Ѵ�.
		if (max < acc[i]) {
			max = acc[i];
		}
	}
	printf("%d\n", max);
	free(arr);
	free(acc);
	return 0;
}