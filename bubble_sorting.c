#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
	int tmp = *a;
	*a =* b;
	*b = tmp;
}
void bubble(int a[], int s)
{
	for (int i = 0; i < s - 1; i++)
	{
		for (int j = s-1; j > i; j--)
		{
			if(a[s-1-j]>a[s-j])
				swap(&a[s - 1 - j],&a[s-j]);
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
	bubble(x, nx);
	for (int i = 0; i < nx; i++)
	{
		printf("x[%d]: %d\n", i, x[i]);
	}
	free(x);
	return 0;

}