#include<stdio.h>
#include<stdlib.h>
typedef struct _grape {
	int acc_r;//������ ���� ����.
	int n;//�ڿ� �̾����� �׷��� ����� ������ ����.
	int* a;//�ڿ� �̾����� �׷��� ��带 ����
}grape;
grape* gr;
int* build_time;

void fuction(int n) {//����� ���� �̾��� ������� ��θ� ��ȭ��Ű�� ���� �Լ�
	int i;
	for (i = 0; i < gr[n].n; i++) {
		if (gr[n].acc_r + build_time[gr[n].a[i]] > gr[gr[n].a[i]].acc_r) {//"���� ��ġ�� ������+ ���� ��ġ�� ����ð� > ������ġ�� ��������ð�"�� ��� �������� �������� �ڿ� �̾����� ��� ������ �ٲپ��ش�.
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
			gr[n_i].n = 0;//�ʱ�ȭ..�׷����� ���� �̾����� ������ 0���� �ʱ�ȭ�Ѵ�.
		}
		for (k_i = 0; k_i < k; k_i++) {
			scanf("%d %d", &start, &end);
			start--;
			end--;
			if (gr[start].n == 0) {//ó���� malloc���� �ʱ�ȭ���ش�.
				gr[start].n = 1;
				gr[start].a = (int*)malloc(sizeof(int));
				gr[start].a[0] = end;
			}
			else {//ó���� �ƴϹǷ� realloc���� �÷��ش�.
				gr[start].n++;
				gr[start].a = (int*)realloc(gr[start].a, sizeof(int)*gr[start].n);
				gr[start].a[gr[start].n - 1] = end;
			}
		}
		//1���� �����ؼ� �����ϱ�.(�迭�󿡼��� 0���ͽ���)
		for (n_i = 0; n_i < n; n_i++) {
			fuction(n_i);
		}
		scanf("%d", &des);
		printf("%d\n", gr[des - 1].acc_r);
		//�ʱ�ȭ�κ�
		free(build_time);
		free(gr);//free�� ���� ��ü������ ������.
	}
	return 0;
}