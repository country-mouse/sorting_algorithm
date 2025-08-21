#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do{type t = x; x = y; y = t;}while(0)


void partition(int a[], int n)
{
	int pl = 0;
	int pr = n - 1;
	int x = a[n / 2];
	do {
		while (a[pl] < x) pl++;
		while (a[pr] > x) pr--;
		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);
	printf("pivot value is %d.", x);
	printf("the group under pivot\n");
	for (int i = 0; i <= pl - 1; i++)
	{
		printf("%d", a[i]);
	}
	putchar('\n');
	if (pl > pr + 1)
	{
		printf("피벗과 일치하는 그룹\n");
		for (int i = pr + 1; i <= pl - 1; i++)
		{
			printf("%d", a[i]);
			putchar('\n');
		}
	}
	printf("group over pivot\n");
	for (int i = pr + 1; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	putchar('\n');
}

int main(void)
{
	int nx;
	printf("enter number of an array: ");
	scanf("%d", &nx);
	int* x = calloc(nx, sizeof(int));
	for (int i = 0; i < nx; i++)
	{
		printf("x[%d]: ", i);
		scanf("%d", &x[i]);
	}
	partition(x, nx);
	for (int i = 0; i < nx; i++)
	{
		printf("x[%d]: %d\n", i, x[i]);
	}
	free(x);
	return 0;

}