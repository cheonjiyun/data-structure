#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include "tnode.h"


typedef int elem_t;
typedef struct tnode {
	elem_t data;
	int cc;
	int level; // 다음에 넣은 요소의 높이
	struct tnode* left, * right;
} tnode_t;

char* str(elem_t data);
tnode_t* new_node(elem_t data);
int is_full(int cc);
int isleft(int lcc, int rcc);
tnode_t* add_node(tnode_t* root, tnode_t* newp);
void print_tree(tnode_t* node, int level);
void print_tab(int tab);

int main(void)
{
	tnode_t* root = NULL, * node = NULL;
	elem_t data = 0, n;
	scanf_s("%d", &n);
	for (int data = 1; data <= n; data++) {
		//data = rand() % 100;
		//if (data == 0)
		//	break;
		node = new_node(data); // 노드를 생성
		root = add_node(root, node); // 트리에 추가
	}
	print_tree(root, 0); // 생성된 트리를 출력
}

char outbuf[10];
char* str(elem_t data) {
	sprintf_s(outbuf, 10, "%3d", data);
	return outbuf;
}

tnode_t* new_node(elem_t data)
{
	tnode_t* node = (tnode_t*)malloc(sizeof(tnode_t));
	if (node == NULL) {
		return NULL;
	}
	node->data = data;
	node->cc = 1;
	node->left = NULL;
	node->right = NULL;
	return node;
}
int is_full(int cc)
{
	int n = log2(cc);
	return (cc == pow(2, n + 1) - 1);
}
int isleft(int lcc, int rcc)
{
	if (!is_full(lcc))
		return 1;
	if (lcc == rcc)
		return 1;
	return 0;
}
tnode_t* add_node(tnode_t* root, tnode_t* newp) {
	if (root == NULL) {
		return newp;
	}
	tnode_t* node = root;
	if (node->left == NULL) {
		node->left = newp;
	}
	else if (node->right == NULL) {
		node->right = newp;
	}
	else if (isleft(node->left->cc, node->right->cc)) {
		add_node(node->left, newp);
	}
	else {
		add_node(node->right, newp);
	}
	node->cc++;
	return root;
}

void print_tree(tnode_t* node, int level)
{
	if (node == NULL)
		return;
	print_tab(level);
	printf("%s\n", str(node->data));
	print_tree(node->left, level + 1);
	print_tree(node->right, level + 1);
}
void print_tab(int tab)
{
	for (int i = 0; i < tab; i++)
		printf("... ");
}