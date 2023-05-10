#include <stdio.h>
#include <stdlib.h>


typedef char elem_t;
typedef struct tnode {
	elem_t data;
	int cc;
	int level; // 다음에 넣은 요소의 높이
	struct tnode* left, * right;
} tnode_t;




tnode_t* new_node(elem_t data)
{
	tnode_t* node = (tnode_t*)malloc(sizeof(tnode_t));
	if (node == NULL) {
		return NULL;
	}
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}


elem_t get_next() {
	char buf[10];
	scanf_s("%s", buf, 10);
	return buf[0];
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

tnode_t* next_subtree() {
	char data = '\0';
	data = get_next(); // char글자 입력받기

	tnode_t* parent = NULL, * node = NULL;

	if (data != '(') {  // 입력이 괄호가 아니라면
		parent = new_node(data);
		return parent;
	}

	parent = new_node(get_next()); // 부모노드 만들기

	node = next_subtree(); // 왼쪽
	add_node(parent, node); // 넣기

	node = next_subtree(); // 오른쪽
	add_node(parent, node); // 넣기

	data = get_next(); // 닫는 괄호

	return parent; // 부모노드 반환
}



void print_tab(int tab)
{
	for (int i = 0; i < tab; i++)
		printf("... ");
}

char outbuf[10];
char* str(elem_t data) {
	sprintf_s(outbuf, 10, "%c", data);
	return outbuf;
	
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

void main() {
	tnode_t* root = NULL;
	root = next_subtree();
	print_tree(root, 0);
}