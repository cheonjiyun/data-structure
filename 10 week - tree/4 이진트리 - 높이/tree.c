#include <stdio.h>
#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif // !max




typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

int get_height(TreeNode* node) {
	
	int height = 0;

	if (node != NULL) {
		height = 1 + max(get_height(node->left), get_height(node->right));
	}

	return height;
}


int main(void) {

	TreeNode n4 = { 500, NULL, NULL };
	TreeNode n5 = { 200, NULL, NULL };
	TreeNode n3 = { 100, &n4, &n5 };
	TreeNode n2 = { 50, NULL, NULL };
	TreeNode n1 = { 0, &n2, &n3 };

	printf("≥Ù¿Ã = %d \n", get_height(&n1));
	return 0;
}