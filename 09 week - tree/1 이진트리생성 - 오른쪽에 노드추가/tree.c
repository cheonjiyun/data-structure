#include <stdio.h>
#include <stdlib.h>

typedef int elem_t;
typedef struct tnode {
	elem_t data;
	struct tnode* left, * right;
} tnode_t;
tnode_t* new_node(elem_t e);
tnode_t* add_node(tnode_t* root, tnode_t* newp);
void print_tree(tnode_t* node, int level);
void print_tab(int level);

tnode_t* new_node(elem_t data) {
	tnode_t* node = (tnode_t*)malloc(sizeof(tnode_t)); //�ӽ� ���
	node->data = data; //�����ͳֱ�
	
	node->left = NULL; //���� ����
	node->right = NULL; //������ ����
	return node; //�ӽ� ��� ��ȯ
}

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
	else {//������ ���� �����ʿ� �ϳ� ��
		add_node(node->right, newp);
	}
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

	srand(1);
	while (1) {
		data = rand() % 100;
		if (data > 90) {
			break;
		}
		node = new_node(data);//��带 ����
		root = add_node(root, node);//Ʈ���� �߰�
	}
	print_tree(root, 0);
}