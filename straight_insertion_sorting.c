#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void insertion(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int s = a[i];
		int j = 0;
		int flag;
		while (a[i] < a[i - 1-j])
		{
			j++;
		}
		flag = j;
		for (int k = i; k >i-j; k--)
		{
			swap(&a[k], &a[k - 1]);
		}
	}

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
	insertion(x, nx);
	for (int i = 0; i < nx; i++)
	{
		printf("x[%d]: %d\n", i, x[i]);
	}
	free(x);
	return 0;

}