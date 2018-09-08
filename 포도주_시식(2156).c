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
		for (j = i - 3; j >= 0; j--) {//!3개 연속이 안되게 현재구하려는 곳에서 3칸 전인 부분부터 0까지 조사하여 가장 큰 누적값을 가진 값을 구한다.
			if (max < acc[j]) {
				max = acc[j];
			}
		}
		if (acc[i - 2] > max + arr[i - 1]) {//현재 위치에서 -2인 곳의 누적값이 큰 경우
			acc[i] = acc[i - 2] + arr[i];
		}
		else {//현재 위치 -3인 곳의 누적값과 현재위치 -1의 값의 합이 큰 경우
			acc[i] = max + arr[i - 1] + arr[i];
		}
	}
	max = 0;
	for (i = 0; i < n; i++) {//전체 누적값들중 가장 큰 값을 구하여 출력한다.
		if (max < acc[i]) {
			max = acc[i];
		}
	}
	printf("%d\n", max);
	free(arr);
	free(acc);
	return 0;
}