#include <stdio.h>
#include <stdlib.h>

#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif // !max



typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode* new_node(int item);


TreeNode* insert_node(TreeNode* node, int key) {

	// if tree is empty
	if (node == NULL) return new_node(key);

	
	if (key < node->key) { //작으면 외쪽 트리로 내려감
		node->left = insert_node(node->left, key);
	}
	else {
		node->right = insert_node(node->right, key);
	}
	
	return node;
}

TreeNode* new_node(int item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void print_tab(int level) {
	for (int i = 0; i < level; i++) {
		printf("... ");
	}
}

void print_tree(TreeNode* node, int level) {
	if (node == NULL) {
		return;
	}

	print_tab(level);
	printf("%d\n", node->key);
	print_tree(node->left, level + 1);
	print_tree(node->right, level + 1);
}

int main(void) {

	TreeNode n4 = { 25, NULL, NULL };
	TreeNode n5 = { 31, NULL, NULL };
	TreeNode n3 = { 26, &n4, &n5 };
	TreeNode n2 = { 7, NULL, NULL };
	TreeNode n1 = { 18, &n2, &n3 };

	print_tree(&n1, 0);
	insert_node(&n1, 6);
	printf("\n----After Insert----\n");
	print_tree(&n1, 0);

	return 0;
}