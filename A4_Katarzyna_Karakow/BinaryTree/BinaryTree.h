#include<stdio.h>
#include "node.h"

struct node* root = NULL;

void insert(struct node*, struct node*);
void walk(struct node*);

void hand_build_test_tree() {
	struct node* n1 = (struct node*)malloc(sizeof(struct node));
	n1->value = 1;
	n1->left = NULL;
	n1->right = NULL;

	struct node* n2 = (struct node*)malloc(sizeof(struct node));
	n2->value = 2;
	n2->left = NULL;
	n2->right = NULL;

	struct node* n3 = (struct node*)malloc(sizeof(struct node));
	n3->value = 3;
	n3->left = NULL;
	n3->right = NULL;

	struct node* n4 = (struct node*)malloc(sizeof(struct node));
	n4->value = 4;
	n4->left = NULL;
	n4->right = NULL;

	// Connect the nodes into a tree
	root = n2;
	n2->left = n1;
	n2->right = n3;
	n3->right = n4;
}

void add(int num) {
	struct node* n = (struct node*)malloc(sizeof(struct node));
	n->value = num;
	n->left = NULL;
	n->right = NULL;

	insert(n, root);
}

void insert(struct node* n, struct node* top) {
	// Tree is empty
	if (root == NULL) {
		root = n; 
		return;
	}

	if (n->value > top->value) {
		if (top->left == NULL) {
			top->left = n; // Make this node the left child
		}
		else {
			insert(n, top->left); // Insert into branch headed by left child
		}
	}
	else {
		if (top->right == NULL) {
			top->right = n;
		}
		else {
			insert(n, top->right);
		}
	}
}

void print() {
	walk(root);
}

void walk(struct node * top) {
	// 1. Print the left children
	if (top->left != NULL) {
		// Walk the left branch
		walk(top->left);
	}

	// 2. Print myself
	printf(" %d ", top->value);

	// 3. Print my right children
	if (top->right != NULL) {
		// walk the right branch
		walk(top->right);
	}
}

void delete(int num) {

	struct node* parent = NULL;
	struct node* current = root;

	//search(current, num, parent);
	if (current == NULL)
		return;

	if (current->left == NULL && current->right == NULL)
	{
		if (current != root)
		{
			if (parent->left == current)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		else
			root = NULL;
		free(current);
	}
	else if (current->left && current->right)
	{
		struct node* success = findMinimum(current->right);
		int val = success->value;
		delete(root, success->value);
		current->value = val;
	}
	else
	{
		struct node* child = (current->left) ? current->left : current->right;
		if (current != root)
		{
			if (current == parent->left)
				parent->left = child;
			else
				parent->right = child;
		}
		else
			root = child;
		free(current);
	}
}

struct node* findMinimum(struct node* current) {
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}

