#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int elem_t;

int size;
int numbers[100]; // �ִ� ũ�� 100���� �迭������ ����


elem_t get_next() { // int
	int n;
	scanf_s("%d", &n);
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

void input_list() {
	for (int i = 0; i < size; ++i) {
		numbers[i] = get_next();
	}
}

int compare(elem_t e1, elem_t e2) {
	return e1 - e2;
}

//int compare(elem_t e1, elem_t e2) {
//	return strcmp(e1, e2);
//}


// ������ŭ ����Ʈ�� ������ ����ϴ� �Լ�
void print_list() {
	for (int i = 0; i < size; ++i) {
		printf("%s ", str(numbers[i]));
	}
}

void add_list(elem_t val) {
	printf("�� %s�� ����Ʈ �� ���� �߰��մϴ�.\n", str(val));
	numbers[size++] = val;
}

void insert_list(int pos, elem_t val) {
	printf("�� %s�� %d ��°�� �����մϴ�.\n", str(val), pos);
	for (int k = size - 1; k >= pos; k--)
		numbers[k + 1] = numbers[k];
	numbers[pos] = val;
	size++;
}

elem_t delete_list(int pos) {
	elem_t result = numbers[pos];
	for (int k = pos; k < size - 1; k++)
		numbers[k] = numbers[k + 1];
	printf("%d��° ���� �����մϴ�. �� = %s\n", pos, str(result));
	size--;
	return result;
}

int find(elem_t val) {
	for (int i = 0; i < size; i++) {
		if (compare(numbers[i], val) == 0)
			return i; // ã���� �ε��� ��ȯ
	}
	return -1; // ��ã���� -1
}

elem_t update_list(int pos, elem_t val) {
	elem_t result = numbers[pos];
	numbers[pos] = val;
	printf("%d ��° ���� %s�� �����մϴ�. ������ = %s\n", pos, str(val), str(result));
	return result;
}

void free_list() {
	for (int i = 0; i < size; i++)
		free(numbers[i]);
}

void run_menu() {
	int pos;
	elem_t val;
	int menu;
	while (1) {
		printf("\n(1) ���� �� �߰� \n(2) pos��°�� �� �߰�\n");
		printf("(3) pos��° ���� \n(4) pos��° �� ���� \n(5) val�� �˻� \n(6)����");
		printf(" �޴����� => ");
		scanf_s("%d", &menu);
		if (menu >= 6) break;
		switch (menu) {
		case 1:
			printf("���� �߰��� ��: ");
			val = get_next();
			add_list(val);
			break;
		case 2:
			printf("�߰��� ��ġ�� ��: ");
			scanf_s("%d", &pos);
			insert_list(pos, get_next());
			break;
		case 3:
			printf("������ ��ġ: ");
			scanf_s("%d", &pos);
			elem_t val = delete_list(pos);
			free_elem(val);
			break;
		case 4:
			printf("������ ��ġ�� ��: ");
			scanf_s("%d", &pos);
			val = update_list(pos, get_next());
			free_elem(val);
			break;
		case 5:
			printf("ã������ �� : ");
			val = get_next();
			pos = find(val);
			if (pos == -1)
				printf("%s�� ���� ���Դϴ�\n", str(val));
			else
				printf("%s��[%d]�� �ֽ��ϴ�\n", str(val), pos);
			break;
		default:
			break;
		}
		print_list();
	}
	free_list();
}


void main() {
	printf("������ ������ �Է��Ͻÿ� : ");
	scanf_s("%d", &size);
	input_list();
	print_list();
	run_menu();
	printf("\n�ȳ��� ������\n");
}