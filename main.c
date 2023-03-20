#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int elem_t;

typedef struct {
	elem_t array[100]; // �迭 ����
	int size; // ���� ����Ʈ�� ����� �׸���� ����
} arrlist_t;


elem_t get_next() { // int
	int n = rand() % 100;
	//scanf_s("%d", &n);
	return n;
}

//elem_t get_next() {
//	char buf[20];
//	scanf_s("%s", buf, 20);
//	char* chptr = (char*)malloc((strlen(buf) + 1) * sizeof(char));
//	strcpy_s(chptr, (strlen(buf) + 1), buf);
//	return chptr;
//}

//��¶�� ���ڿ��� ���
char outbuf[20];
char* str(elem_t e) {
	sprintf_s(outbuf, 20, "%d", e);
	return outbuf;
}

//char* str(elem_t e) {
//	return e;
//}


void free_elem() {
}

//void free_elem(elem_t e) {
//	free(e);
//}



int compare(elem_t e1, elem_t e2) {
	return e1 - e2;
}

//int compare(elem_t e1, elem_t e2) {
//	return strcmp(e1, e2);
//}


// ������ŭ ����Ʈ�� ������ ����ϴ� �Լ�
void print_list(arrlist_t* lp) {
	for (int i = 0; i < lp -> size; ++i) {
		printf("%s ", str(lp -> array[i]));
	}
}

void add_list(arrlist_t* lp, elem_t val) {
	printf("�� %s�� ����Ʈ �� ���� �߰��մϴ�.\n", str(val));
	lp -> array[lp -> size++] = val;
}

void insert_list(arrlist_t* lp, int pos, elem_t val) {
	printf("�� %s�� %d ��°�� �����մϴ�.\n", str(val), pos);
	for (int k = lp -> size - 1; k >= pos; k--)
		lp -> array[k + 1] = lp -> array[k];
	lp -> array[pos] = val;
	lp -> size++;
}

elem_t delete_list(arrlist_t* lp, int pos) {
	elem_t result = lp -> array[pos];
	for (int k = pos; k < lp -> size - 1; k++)
		lp -> array[k] = lp -> array[k + 1];
	printf("%d��° ���� �����մϴ�. �� = %s\n", pos, str(result));
	lp -> size--;
	return result;
}


elem_t update_list(arrlist_t* lp, int pos, elem_t val) {
	elem_t result = lp -> array[pos];
	lp -> array[pos] = val;
	printf("%d ��° ���� %s�� �����մϴ�. ������ = %s\n", pos, str(val), str(result));
	return result;
}

elem_t get(arrlist_t* lp, int index) {
	return lp->array[index];
}


int find(arrlist_t* lp, elem_t val) {
	for (int i = 0; i < lp->size; i++) {
		if (compare(lp->array[i], val) == 0)
			return i; // ã���� �ε��� ��ȯ
	}
	return -1; // ��ã���� -1
}


int len(arrlist_t* lp) {
	return lp->size;
}



void init_list(arrlist_t* lp) {
	lp->size = 0;
}

void clear(arrlist_t* lp) {
	for (int i = 0; i < lp->size; i++) {
		free(lp->array[i]);
		lp->size = 0;
	}
}


void input_list(arrlist_t* lp, int size) {
	lp->size = size;
	for (int i = 0; i < lp->size; ++i) {
		lp->array[i] = get_next();
	}
}

void free_list(arrlist_t* lp) {
	clear(lp);
}

//
//
//void run_menu(arrlist_t* lp) {
//	int pos;
//	elem_t val;
//	int menu;
//	while (1) {
//		printf("\n(1) ���� �� �߰� \n(2) pos��°�� �� �߰�\n");
//		printf("(3) pos��° ���� \n(4) pos��° �� ���� \n(5) val�� �˻� \n(6)����");
//		printf(" �޴����� => ");
//		scanf_s("%d", &menu);
//		if (menu >= 6) break;
//		switch (menu) {
//		case 1:
//			printf("���� �߰��� ��: ");
//			val = get_next();
//			add_list(lp, val);
//			break;
//		case 2:
//			printf("�߰��� ��ġ�� ��: ");
//			scanf_s("%d", &pos);
//			insert_list(lp, pos, get_next());
//			break;
//		case 3:
//			printf("������ ��ġ: ");
//			scanf_s("%d", &pos);
//			elem_t val = delete_list(lp, pos);
//			free_elem(val);
//			break;
//		case 4:
//			printf("������ ��ġ�� ��: ");
//			scanf_s("%d", &pos);
//			val = update_list(lp, pos, get_next());
//			free_elem(val);
//			break;
//		case 5:
//			printf("ã������ �� : ");
//			val = get_next();
//			pos = find(lp, val);
//			if (pos == -1)
//				printf("%s�� ���� ���Դϴ�\n", str(val));
//			else
//				printf("%s��[%d]�� �ֽ��ϴ�\n", str(val), pos);
//			break;
//		default:
//			break;
//		}
//		print_list(lp);
//	}
//	free_list(lp);
//}


void main() {
	int num;
	srand(1);
	arrlist_t org_list, new_list;
	init_list(&org_list);
	input_list(&org_list, 100);
	printf("original list : \n"); print_list(&org_list);
	printf("\n");
	init_list(&new_list, 0);
	for (int i = len(&org_list) - 1; i >= 0; i--) {
		num = get(&org_list, i);
		if (num > 50) {
			num = delete_list(&org_list, i);
			add_list(&new_list, num);
		}
	}
	printf("50 ���� list : \n"); print_list(&org_list);
	printf("\n");
	printf("50 �ʰ� list : \n"); print_list(&new_list);


	//arrlist_t mylist;
	//int size;
	//printf("������ ������ �Է��Ͻÿ� : ");
	//scanf_s("%d", &size);
	//input_list(&mylist, size);
	//run_menu(&mylist);
	//printf("\n�ȳ��� ������\n");
}