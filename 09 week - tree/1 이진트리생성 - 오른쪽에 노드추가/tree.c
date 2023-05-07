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
	tnode_t* node = (tnode_t*)malloc(sizeof(tnode_t)); //임시 노드
	node->data = data; //데이터넣기
	
	node->left = NULL; //왼쪽 비우기
	node->right = NULL; //오른쪽 비우기
	return node; //임시 노드 반환
}

tnode_t* add_node(tnode_t* root, tnode_t* newp) {
	if (root == NULL) {
		return newp;
	}

	tnode_t* node = root; // 임시노드

	if (node->left == NULL) { //왼쪽이 비면
		node->left = newp; 
	}
	else if (node->right == NULL) { //오른쪽이 비면
		node->right = newp;
	}
	else {//꽉차면 새로 오른쪽에 하나 더
		add_node(node->right, newp);
	}
	return root; //임시노드를 반환
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
		node = new_node(data);//노드를 생성
		root = add_node(root, node);//트리에 추가
	}
	print_tree(root, 0);
}