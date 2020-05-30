#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printarray(int v[], int sizev) {
	for (int i = 0; i < sizev; i++)
		printf("%d ", v[i]);
}

void interschimbare(int* a, int* b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}

int partition(int *v, int low, int high) {
	int pivot = v[high];
	int curridx = low;
	int lowidx = low - 1;

	for (curridx = low; curridx < high; curridx++) {
		if (v[curridx] < pivot) {
			lowidx++;
			interschimbare(&v[curridx], &v[lowidx]);
		}
	}

	interschimbare(&v[lowidx + 1], &v[high]);
	return lowidx + 1;
}

void quicksort(int v[], int low, int high)

{
	int index, stack[high-low+1];

	int top = -1;
	stack[++top] = low;
	stack[++top] = high;

	while (top >= 0) {
		high = stack[top--];
		low = stack[top--];
		printf("%d\n", top);
		index = partition(v, low, high);

		if (index-1 >= low) {
			stack[++top] = low;
			stack[++top] = index - 1;
		}

		if (index + 1 <= high) {
			stack[++top] = index + 1;
			stack[++top] = high;
		}
	
	}
}

int main()
{
	int v[20];
	srand(time(NULL));
	int i;
	for (i = 0; i < 20; i++) {
		v[i] = (rand() % 51);
	}
	int sizev = sizeof(v) / sizeof(v[0]);

	printf("Vector inainte de sortare\n\n");
	printarray(v, sizev);

	printf("\n\n");

	quicksort(v, 0, sizev - 1);

	printf("Vector dupa sortare\n\n");

	printarray(v, sizev);
}
