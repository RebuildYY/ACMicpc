#include<stdio.h>
#include<stdlib.h>
typedef struct _grape {
	int acc_r;//누적된 값을 저장.
	int n;//뒤에 이어지는 그래프 노드의 갯수를 저장.
	int* a;//뒤에 이어지는 그래프 노드를 저장
}grape;
grape* gr;
int* build_time;

void fuction(int n) {//변경된 값과 이어진 다음노드 모두를 변화시키기 위한 함수
	int i;
	for (i = 0; i < gr[n].n; i++) {
		if (gr[n].acc_r + build_time[gr[n].a[i]] > gr[gr[n].a[i]].acc_r) {//"현재 위치의 누적값+ 다음 위치의 건축시간 > 다음위치의 누적건축시간"인 경우 누적값이 변함으로 뒤에 이어지는 모든 노드들을 바꾸어준다.
			gr[gr[n].a[i]].acc_r = gr[n].acc_r + build_time[gr[n].a[i]];
			fuction(gr[n].a[i]);
		}
	}
}

int main() {
	int t, n, k;
	int t_i, n_i, k_i;
	int start, end;
	int des;
	scanf("%d", &t);
	for (t_i = 0; t_i < t; t_i++) {
		scanf("%d %d", &n, &k);
		build_time = (int*)malloc(sizeof(int)*n);
		gr = (grape*)malloc(sizeof(grape)*n);
		for (n_i = 0; n_i < n; n_i++) {
			scanf("%d", &(build_time[n_i]));
			gr[n_i].acc_r = build_time[n_i];
			gr[n_i].n = 0;//초기화..그래프가 아직 이어지지 않으니 0으로 초기화한다.
		}
		for (k_i = 0; k_i < k; k_i++) {
			scanf("%d %d", &start, &end);
			start--;
			end--;
			if (gr[start].n == 0) {//처음은 malloc으로 초기화해준다.
				gr[start].n = 1;
				gr[start].a = (int*)malloc(sizeof(int));
				gr[start].a[0] = end;
			}
			else {//처음이 아니므로 realloc으로 늘려준다.
				gr[start].n++;
				gr[start].a = (int*)realloc(gr[start].a, sizeof(int)*gr[start].n);
				gr[start].a[gr[start].n - 1] = end;
			}
		}
		//1부터 시작해서 누적하기.(배열상에서는 0부터시작)
		for (n_i = 0; n_i < n; n_i++) {
			fuction(n_i);
		}
		scanf("%d", &des);
		printf("%d\n", gr[des - 1].acc_r);
		//초기화부분
		free(build_time);
		free(gr);//free를 좀더 구체적으로 해주자.
	}
	return 0;
}