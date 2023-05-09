#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int elem_t;
typedef struct tnode {
	elem_t data;
	int cc;
	int level; // ������ ���� ����� ����
	struct tnode* left, * right;
} tnode_t;
tnode_t* new_node(elem_t e);
tnode_t* add_node(tnode_t* root, tnode_t* newp);
void print_tree(tnode_t* node, int level);
void print_tab(int level);

int max_n(tnode_t* node);
int is_full(tnode_t* node);
int what_n(tnode_t* node);

tnode_t* new_node(elem_t data) {
	tnode_t* node = (tnode_t*)malloc(sizeof(tnode_t)); //�ӽ� ���
	node->data = data; //�����ͳֱ�
	node->cc = 1;
	node->left = NULL; //���� ����
	node->right = NULL; //������ ����
	return node; //�ӽ� ��� ��ȯ
}

int max_n(int n) { // �� ���� ��á�� �� ��ΰ�?
	if (n == 1) {
		return 1;
	}
	else {
		return max_n(n-1) + pow(2, n - 1);
	}
}
	
int is_full(tnode_t* node) { //��ȭƮ���ΰ�?
	for (int n = 1; n < node->cc; n++) {
		if (node->cc == max_n(n)) { // cc�� �ִ밪�� �ִ°�?
			return 1; // ��ȭ�� �´�.
		}
	}
	return 0; // �ִ밪�� �ƴϴ�
}

int what_n(tnode_t* node) { // ���° �ٿ� �ִ°�?
	for (int n = 1; n < node->cc; n++) {
		if (node->cc >= max_n(n) && node->cc < max_n(n + 1)) { 
			return n;
		}
	}
}

	//for (int n = 1; n < 100; n++) {
	//	if (node->cc == 1 + ((n - 1) * pow(2, n - 1))) { // ��ã�� ���
	//		return n;
	//	}
	//	else if ((node->cc > 1 + (n - 2) * pow(2, n - 2)) && (node->cc < 1 + (n - 1) * pow(2, n - 1))) { // ��á�����
	//		return n;
	//	}
	//}





tnode_t* add_node(tnode_t* root, tnode_t* newp) {
	if (root == NULL) {
		return newp;
	}

	tnode_t* node = root; // �ӽó��


	if (node->left == NULL) { //������ ���
		node->left = newp;
	}
	else if (node->right == NULL) { //�������� ���
		node->right = newp;
	}
	else if ((what_n(node->left) == what_n(node->right)) && is_full(node->left) && is_full(node->right)) { // ���� ���� ��� ��ȭ�����ΰ�?
		add_node(node->left, newp);
	}
	else if ((what_n(node->left) >= what_n(node->right)) && is_full(node->left)) { // ���� ������ �� ũ��, ������ ��ȭ�� �ƴϴ�.
		add_node(node->right, newp);
	}
	else{ 
		add_node(node->left, newp);
	}


	//if (node->left == NULL) { //������ ���
	//	node->left = newp;
	//	node->level++;
	//}
	//else if (node->right == NULL) { //�������� ���
	//	node->right = newp;
	//}
	//else if (node->left->cc == node->right->cc) { // ���ʴ� ��ȭ����Ʈ���� ���
	//	add_node(node->left, newp); // ����
	//	node->left->level++;
	//}
	//else if (node->left->level - node->right->level > 0) {//���� �� ���
	//	add_node(node->left, newp);
	//	if (is_full(node->left)) {
	//		node->left->level++;
	//	}
	//}
	//else if (node->left->level - node->right->level == 2){// ������ ������ �������� �ƿ� �� ���
	//	add_node(node->right, newp);
	//	node->right->level++;
	//}
	//else //������ ������ �������� ���� �����ִ� ���
	//{
	//	add_node(node->right, newp);
	//	if (is_full(node->right)) {
	//		node->right->level++;
	//	}
	//}
	node->cc++;
	
	return root; //�ӽó�带 ��ȯ
}

void print_tab(int level) {
	for (int i = 0; i < level; i++) {
		printf("... ");
	}
}

void print_tree(tnode_t* node, int level) {
	if (node == NULL) {
		return;
	}

	print_tab(level);
	printf("%d\n", node->data);
	print_tree(node->left, level + 1);
	print_tree(node->right, level + 1);
}

void main() {

	tnode_t* root = NULL;
	tnode_t* node = NULL;
	elem_t data = 0;

	// srand(1);
	for (int i = 1; i <= 50; i++) {
		// data = rand() % 100;
		data = i;

		/*if (data > 95) {
			break;
		}*/

		node = new_node(data);//��带 ����
		root = add_node(root, node);//Ʈ���� �߰�
		
	}
	print_tree(root, 0);
}