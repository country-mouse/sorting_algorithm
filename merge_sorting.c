#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void merge(const int a[], int na, const int b[], int nb, int c[])
{
	int pa = 0;
	int pb = 0;
	int pc = 0;

	while (pa < na && pb < nb)
		c[pc++] = (a[pa] <= b[pb]) ? a[pa++] : b[pb++];
	while (pa < na)
		c[pc++] = a[pa++];
	while (pb < nb)
		c[pc++] = b[pb++];
}

int main(void)
{
	int na, nb;
	printf("enter number of A array: ");
	scanf("%d", &na);
	printf("enter number of B array: ");
	scanf("%d", &nb);
	int* a = calloc(na, sizeof(int));
	int* b = calloc(nb, sizeof(int));
	int* c = calloc(na+nb, sizeof(int));
	printf("a[0]: ");
	scanf("%d", &a[0]);
	for (int i = 01; i < na; i++)
	{
		do {
			printf("a[%d]: ", i);
			scanf("%d", &a[i]);
		} while (a[i] < a[i - 1]);
	}
	printf("b[0]: ");
	scanf("%d", &b[0]);
	for (int i = 01; i < nb; i++)
	{
		do {
			printf("b[%d]: ", i);
			scanf("%d", &b[i]);
		} while (b[i] < b[i - 1]);
	}
	merge(a, na, b, nb, c);
	puts("array A and B is merged & saved at array C");
	for (int i = 0; i < na + nb; i++)
	{
		printf("c[%2d] = %2d\n", i, c[i]);
	}
	free(a);
	free(b);
	free(c);
	return 0;

}