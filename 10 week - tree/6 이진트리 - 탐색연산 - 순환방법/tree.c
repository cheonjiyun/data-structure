#include <stdio.h>
#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif // !max




typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode* search(TreeNode* node, int key) {
	if (node == NULL) return NULL;
	if (key == node->key) return node->key;
	else if (key < node->key) { //작으면 외쪽 트리로 내려감
		return search(node->left, key); 
	}
	else {
		return search(node->right, key);
	}
}

int main(void) {

	TreeNode n4 = { 25, NULL, NULL };
	TreeNode n5 = { 31, NULL, NULL };
	TreeNode n3 = { 26, &n4, &n5 };
	TreeNode n2 = { 7, NULL, NULL };
	TreeNode n1 = { 18, &n2, &n3 };

	printf("탐색결과 = %d \n", search(&n1, 25));
	return 0;
}