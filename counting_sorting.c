#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void counting(int a[], int n, int max)
{
	int* f = calloc(max + 1, sizeof(int));
	int* b = calloc(n, sizeof(int));

	for (int i = 0; i <= max; i++)
	{
		f[i] = 0;
	}
	for (int i = 0; i < n; i++) f[a[i]]++;
	for (int i = 1; i <= max; i++) f[i] += f[i - 1];
	for (int i = n - 1; i >= 0; i--) b[--f[a[i]]] = a[i];
	for (int i = 0; i < n; i++) a[i] = b[i];

	free(b);
	free(f);
}

int main(void)
{
	int nx;
	const int max = 100;
	printf("enter number of A array: ");
	scanf("%d", &nx);

	int* a = calloc(nx, sizeof(int));
	for (int i = 0; i < nx; i++)
	{
		do {
			printf("a[%d]: ", i);
			scanf("%d", &a[i]);
		} while (a[i]<0 || a[i]>max);
	}

	counting(a, nx, max);
	puts("array A and B is merged & saved at array C");
	for (int i = 0; i < nx; i++)
	{
		printf("c[%d] = %2d\n", i, a[i]);
	}
	free(a);
	return 0;

}