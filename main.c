#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size;
char* numbers[100]; // �ִ� ũ�� 100���� �迭������ ����


int find(char* val) {
	for (int i = 0; i < size; i++) {
		if (strcmp(numbers[i], val) == 0)
			return i; // ã���� �ε��� ��ȯ
	}
	return -1; // ��ã���� -1
}

char* get_next() {
	char buf[20];
	scanf_s("%s", buf, 20);
	char* chptr = (char*)malloc((strlen(buf) + 1) * sizeof(char));
	strcpy_s(chptr, (strlen(buf) + 1), buf);
	return chptr;
}

void input_list() {
	for (int i = 0; i < size; ++i) {
		numbers[i] = get_next();
	}
}

// ������ŭ ����Ʈ�� ������ ����ϴ� �Լ�
void print_list() {
	for (int i = 0; i < size; ++i) {
		printf("%s ", numbers[i]);
	}
}

void add_list(char* val) {
	printf("�� %s�� ����Ʈ �� ���� �߰��մϴ�.\n", val);
	numbers[size++] = val;
}

void insert_list(int pos, char* val) {
	printf("�� %s�� %d ��°�� �����մϴ�.\n", val, pos);
	for (int k = size - 1; k >= pos; k--)
		numbers[k + 1] = numbers[k];
	numbers[pos] = val;
	size++;
}

char* delete_list(int pos) {
	char* result = numbers[pos];
	for (int k = pos; k < size - 1; k++)
		numbers[k] = numbers[k + 1];
	printf("%d��° ���� �����մϴ�. �� = %s\n", pos, result);
	size--;
	return result;
}

char* update_list(int pos, char* val) {
	char* result = numbers[pos];
	numbers[pos] = val;
	printf("%d ��° ���� %s�� �����մϴ�. ������ = %s\n", pos, val, result);
	return result;
}

void free_list() {
	for (int i = 0; i < size; i++)
		free(numbers[i]);
}

void run_menu() {
	int pos;
	char* val;
	int menu;
	while (1) {
		printf("\n(1) ���� �� �߰� \n(2) pos��°�� �� �߰�\n");
		printf("(3) pos��° ���� \n(4) pos��° �� ���� \n(5) val�� �˻� \n (6)����");
		printf(" �޴����� => ");
		scanf_s("%d", &menu);
		if (menu >= 6) break;
		switch (menu) {
		case 1:
			printf("���� �߰��� ��: ");
			add_list(get_next());
			break;
		case 2:
			printf("�߰��� ��ġ�� ��: ");
			scanf_s("%d", &pos);
			insert_list(pos, get_next());
			break;
		case 3:
			printf("������ ��ġ: ");
			scanf_s("%d", &pos);
			val = delete_list(pos);
			free(val);
			break;
		case 4:
			printf("������ ��ġ�� ��: ");
			scanf_s("%d", &pos);
			val = update_list(pos, get_next());
			free(val);
			break;
		case 5:
			printf("ã������ �� : ");
			val = get_next();
			pos = find(val);
			if (pos == -1)
				printf("%s�� ���� ���Դϴ�\n", val);
			else
				printf("%s��[%d]�� �ֽ��ϴ�\n", val, pos);
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
	run_menu();
	printf("\n�ȳ��� ������\n");
}