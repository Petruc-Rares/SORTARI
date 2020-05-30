#include <stdio.h>
#include <stdlib.h>

void printArray(int *v, int size_v) {
	for (int i = 0; i < size_v; i++)
		printf("%d ", v[i]);
	printf("\n\n");
}

void merge(int *v, int l, int m, int r) {
	int k = 1, aux1[1000], aux2[1000];
	int i, j;
	int n1 = m - l + 1;
	int n2 = r - m;
	
	for (i = 0; i < n1; i++)
		aux1[i] = v[l + i];

	for (j = 0; j < n2; j++)
		aux2[j] = v[m + 1 + j];

	i = 0;
	j = 0;
	k = l;

	while ((i < n1) && (j < n2)) {
		if (aux1[i] <= aux2[j])
			v[k++] = aux1[i++];
		else if (aux2[j] < aux1[i])
			v[k++] = aux2[j++];


		// Mai merge scris si asa:
		//v[k++] = (aux1[i] < aux2[j]) ? aux1[i++] :
		//	(aux1[i] == aux2[j]) ? aux1[i++] : aux2[j++];
	}

	while (i < n1)
		v[k++] = aux1[i++];

	while (j < n2)
		v[k++] = aux2[j++];

	return;
}

void mergeSort(int *v, int l, int r) {
	int m;
	if (r > l) {
		m = l + (r - l) / 2;

		mergeSort(v, l, m);
		mergeSort(v, m + 1, r);

		merge(v, l, m, r);
	}
}

int main() {
	int v[900];
	int size_v = sizeof(v) / sizeof(v[0]);

	srand(time(NULL));

	for (int i = 0; i < size_v; i++) {
		v[i] = (rand() % 4000);
	}

	printf("Inainte de sortare: \n");
	printArray(v, size_v);

	mergeSort(v, 0, size_v - 1);

	printf("Dupa sortare: \n");
	printArray(v, size_v);
}