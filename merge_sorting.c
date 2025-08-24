#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

static int* buff;
static void __mergesort(int a[], int left, int right)
{
	if (left < right)
	{
		int center = (left + right) / 2;
		int p = 0;
		int i;
		int j = 0;
		int k = left;
		__mergesort(a, left, center);
		__mergesort(a, center + 1, right);
		for (i = left; i <= center; i++)
			buff[p++] = a[i];
		while (i <= right && j < p)
			a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];
		while (j < p)
			a[k++] = buff[j++];
	}
}

int mergesort(int a[], int n)
{
	if ((buff = calloc(n, sizeof(int))) == NULL)
		return -1;
	__mergesort(a, 0, n - 1);
	free(buff);
	return 0;
}

int main(void)
{
	int nx;
	printf("enter number of A array: ");
	scanf("%d", &nx);
	
	int* a = calloc(nx, sizeof(int));
	printf("a[0]: ");
	scanf("%d", &a[0]);
	for (int i = 0; i < nx; i++)
	{
		printf("a[%d]: ", i);
		scanf("%d", &a[i]);
	}

	mergesort(a, nx);
	puts("array A and B is merged & saved at array C");
	for (int i = 0; i < nx; i++)
	{
		printf("c[%2d] = %2d\n", i, a[i]);
	}
	
	return 0;

}