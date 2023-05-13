#include <stdio.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

//      +
//  *      +
// 1 4   16 25

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, NULL, NULL };
TreeNode n3 = { '*', &n1, &n2};
TreeNode n4 = { 16, NULL, NULL };
TreeNode n5 = { 25, NULL, NULL };
TreeNode n6 = { '+', &n4, &n5 };
TreeNode n7 = { '+', &n3, &n6 };
TreeNode* exp = &n7;


int evalute(TreeNode* root) {
	if (root == NULL) return 0;
	if (root->left == NULL && root->right == NULL) return root->data; //���ڳ��
	else {
		double result = 0;
		double op1 = evalute(root->left);
		double op2 = evalute(root->right);
		printf("%f %c %f�� ����մϴ�.\n", op1, root->data, op2);
		switch (root->data){
		case '+': return op1 + op2;
		case '-': return op1 - op2;
		case '*': return op1 * op2;
		case '/': return op1 / op2;
		}
	}
	return 0;
}


int main(void) {
	printf("������ ���� %d�Դϴ�. \n", evalute(exp));
	return 0;
}