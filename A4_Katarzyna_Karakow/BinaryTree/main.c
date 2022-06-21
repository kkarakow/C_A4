#include<stdio.h>
#include<stdlib.h>
#include "BinaryTree.h"

int main()
{
	int num;
	while (1) {
		printf("\nEnter a number (-1 to stop): ");
		scanf_s("%d", &num);
		if (num == -1) {
			break;
		}
		add(num);
	}

	print();

	// Assignment 4
	printf("\nEnter a number to be deleted from the tree: ");
	scanf_s("%d", &num);
	delete(num);

	print();
}