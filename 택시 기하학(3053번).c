#include<stdio.h>
#define PI 3.14159265358979323846264338327950288
int main() {
	double r;
	double area1, area2;
	scanf("%lf", &r);
	area1 = r * r*PI;
	area2 = 2 * r * r;
	printf("%lf\n%lf\n", area1, area2);
	return 0;
}