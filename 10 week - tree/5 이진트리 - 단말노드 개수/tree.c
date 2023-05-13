#include <stdio.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

int get_leaf_count(TreeNode* node) {
	
	int count = 0;

	if (node != NULL) {
		if (node->left == NULL && node->right == NULL) {	// leaf
			return 1;
		}
		else{
			count = get_leaf_count(node->left) + get_leaf_count(node->right);
		}
	}

	return count;
}


int main(void) {

	TreeNode n4 = { 500, NULL, NULL };
	TreeNode n5 = { 200, NULL, NULL };
	TreeNode n3 = { 100, &n4, &n5 };
	TreeNode n2 = { 50, NULL, NULL };
	TreeNode n1 = { 0, &n2, &n3 };

	printf("단말 노드 개수 = %d \n", get_leaf_count(&n1));
	return 0;
}