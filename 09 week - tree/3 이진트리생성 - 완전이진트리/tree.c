#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int elem_t;
typedef struct tnode {
	elem_t data;
	int cc;
	int level; // 다음에 넣은 요소의 높이
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
	tnode_t* node = (tnode_t*)malloc(sizeof(tnode_t)); //임시 노드
	node->data = data; //데이터넣기
	node->cc = 1;
	node->left = NULL; //왼쪽 비우기
	node->right = NULL; //오른쪽 비우기
	return node; //임시 노드 반환
}

int max_n(int n) { // 그 줄이 꽉찼을 때 몇개인가?
	if (n == 1) {
		return 1;
	}
	else {
		return max_n(n-1) + pow(2, n - 1);
	}
}
	
int is_full(tnode_t* node) { //포화트리인가?
	for (int n = 1; n < node->cc; n++) {
		if (node->cc == max_n(n)) { // cc가 최대값에 있는가?
			return 1; // 포화가 맞다.
		}
	}
	return 0; // 최대값이 아니다
}

int what_n(tnode_t* node) { // 몇번째 줄에 있는가?
	for (int n = 1; n < node->cc; n++) {
		if (node->cc >= max_n(n) && node->cc < max_n(n + 1)) { 
			return n;
		}
	}
}

	//for (int n = 1; n < 100; n++) {
	//	if (node->cc == 1 + ((n - 1) * pow(2, n - 1))) { // 꽉찾을 경우
	//		return n;
	//	}
	//	else if ((node->cc > 1 + (n - 2) * pow(2, n - 2)) && (node->cc < 1 + (n - 1) * pow(2, n - 1))) { // 덜찼을경우
	//		return n;
	//	}
	//}





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
	else if ((what_n(node->left) == what_n(node->right)) && is_full(node->left) && is_full(node->right)) { // 줄이 같고 모두 포화상태인가?
		add_node(node->left, newp);
	}
	else if ((what_n(node->left) >= what_n(node->right)) && is_full(node->left)) { // 줄이 왼쪽이 더 크고, 왼쪽은 포화가 아니다.
		add_node(node->right, newp);
	}
	else{ 
		add_node(node->left, newp);
	}


	//if (node->left == NULL) { //왼쪽이 비면
	//	node->left = newp;
	//	node->level++;
	//}
	//else if (node->right == NULL) { //오른쪽이 비면
	//	node->right = newp;
	//}
	//else if (node->left->cc == node->right->cc) { // 양쪽다 포화이진트리인 경우
	//	add_node(node->left, newp); // 왼쪽
	//	node->left->level++;
	//}
	//else if (node->left->level - node->right->level > 0) {//왼쪽 빈 경우
	//	add_node(node->left, newp);
	//	if (is_full(node->left)) {
	//		node->left->level++;
	//	}
	//}
	//else if (node->left->level - node->right->level == 2){// 왼쪽이 꽉차고 오른쪽이 아예 빈 경우
	//	add_node(node->right, newp);
	//	node->right->level++;
	//}
	//else //왼쪽이 꽉차고 오른쪽이 조금 남아있는 경우
	//{
	//	add_node(node->right, newp);
	//	if (is_full(node->right)) {
	//		node->right->level++;
	//	}
	//}
	node->cc++;
	
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

	// srand(1);
	for (int i = 1; i <= 50; i++) {
		// data = rand() % 100;
		data = i;

		/*if (data > 95) {
			break;
		}*/

		node = new_node(data);//노드를 생성
		root = add_node(root, node);//트리에 추가
		
	}
	print_tree(root, 0);
}