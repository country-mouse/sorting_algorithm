#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void shell(int a[], int n)
{
	for (int i = n/2; i > 0; i = i / 2)
	{
		for (int j = i; j < n; j++)
		{
			int tmp = a[j];
			int k;
			for (k = j - i; k >= 0 && a[k] > tmp; k -= i)
			{
				a[k + i] = a[k];
			}
			a[k + i] = tmp;
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
	shell(x, nx);
	for (int i = 0; i < nx; i++)
	{
		printf("x[%d]: %d\n", i, x[i]);
	}
	free(x);
	return 0;

}