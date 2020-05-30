#include <stdio.h>
#include <math.h>

void printArray(int *array, int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n\n");
	return;
}

void sortarePrinNumarare(int *idx, int *newArray, int *array, int arraySize, int exp) {
	int i;

	printf("Iteratia %d:\n", exp+1);

	for (i = 0; i < 10; i++) idx[i] = 0;

	int auxNo = pow(10, exp);

	for (i = 0; i < arraySize; i++) {
		idx[(array[i]/auxNo)%10]++;
	}

	printArray(idx, 10);

	for (i = 1; i < 10; i++) {
		idx[i] += idx[i - 1];
	}


	for (i = arraySize-1; i >= 0; i--) {
		newArray[--idx[(array[i]/auxNo)%10]] = array[i];
	}

	for (i = 0; i < arraySize; i++) {
		array[i] = newArray[i];
	}
	printArray(newArray, arraySize);
}

int getMaxNo(int *array, int arraySize) {
	int max = array[0];
	for (int i = 1; i < arraySize; i++)
		if (array[i] > max) max = array[i];
	return max;
}

int main() {
	int array[] = { 170, 45, 75, 90, 802, 24, 2, 66};
	int newArray[8], idx[10] = { 0 };
	int i;
	int arraySize = sizeof(array) / sizeof(array[0]);

	int maxNo = getMaxNo(array, arraySize);

	printf("%d\n", maxNo);

	maxNo = maxNo * 10;
	for (i = 1; maxNo /= 10; i++) {
		sortarePrinNumarare(idx, newArray, array, arraySize, i-1);
	}

	printArray(array, arraySize);

	return;
}