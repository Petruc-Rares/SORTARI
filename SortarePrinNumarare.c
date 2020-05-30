#include <stdio.h>

void printArray(int *array, int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n\n");
	return;
}

void sortarePrinNumarare (int *idx, int *newArray, int *array, int arraySize){
	int i;
	for (i = 0; i < arraySize; i++) {
		idx[array[i]]++;
	}

	for (i = 1; i < 10; i++) {
		idx[i] += idx[i - 1];
	}

	for (i = 0; i < arraySize; i++) {
		newArray[--idx[array[i]]] = array[i];
	}

	for (i = 0; i < arraySize; i++) {
		array[i] = newArray[i];
	}
}

int getMaxNo(int *array, int arraySize) {
	int max = array[0];
	for (int i = 1; i < arraySize; i++)
		if (array[i] > max) max = array[i];
	return max;
}

int main() {
	int array[] = {1, 2, 1, 1, 3, 4, 1, 7};
	int newArray[8], idx[10] = { 0 };
	int i;
	int arraySize = sizeof(array) / sizeof(array[0]);

	sortarePrinNumarare(idx, newArray, array, arraySize);

	printArray(idx, 10);

	printArray(array, arraySize);
}