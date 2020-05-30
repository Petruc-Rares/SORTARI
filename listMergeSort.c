#include <stdio.h>

#define Item int

typedef struct node {
	Item data;
	struct node* next;
} node;

void printList(node* nod, node* z) {
	while (nod != z) {
		printf("%d ", nod->data);
		nod = nod->next;
	}
}

void insertBegining(node** nod, Item value) {
	node* newNode = (node*)malloc(sizeof(node));

	newNode->next = *nod;
	newNode->data = value;

	(*nod) = newNode;
}

node* merge(node* a, node* b, node *z) {
	node* mergedList;

	mergedList = z;
	do {
		if (a->data <= b->data) {
			mergedList->next = a;
			mergedList = a;
			a = a->next;
		}
		else {
			mergedList->next = b;
			mergedList = b;
			b = b->next;
		}
	} while (mergedList != z);

	mergedList = z->next;
	z->next = z;

	return mergedList;
}

node* mergeSort(node* nod, node* z) {
	node* a, *b;
	if (nod->next != z) {
		a = nod;
		b = nod->next->next->next;

		while (b != z) {
			nod = nod->next;
			b = b->next->next;
		}

		// b is the list starting from the middle of list nod
		// a is the list ending in the middle of the list nod
		b = nod->next; nod->next = z;
		return merge(mergeSort(a, z), mergeSort(b, z), z);
	}
	// one element in list
	return nod;
}

int main() {
	node* nod = (node*)malloc(sizeof(node));
	nod->data = 43;
	nod->next = NULL;

	// sentinel node
	node* z = (node*)malloc(sizeof(node));
	z->data = 30000;
	z->next = z;
	nod->next = z;

	insertBegining(&nod, 11);
	insertBegining(&nod, 25);
	insertBegining(&nod, 18);
	insertBegining(&nod, 23);
	insertBegining(&nod, 1032);
	insertBegining(&nod, 414);

	printList(nod, z);

	printf("\n\n");

	node* newList = mergeSort(nod, z);
	printList(newList, z);
}