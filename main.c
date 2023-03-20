#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size;
char* numbers[100]; // 최대 크기 100으로 배열포인터 선언


int find(char* val) {
	for (int i = 0; i < size; i++) {
		if (strcmp(numbers[i], val) == 0)
			return i; // 찾으면 인덱스 반환
	}
	return -1; // 못찾으면 -1
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

// 개수만큼 리스트의 정수를 출력하는 함수
void print_list() {
	for (int i = 0; i < size; ++i) {
		printf("%s ", numbers[i]);
	}
}

void add_list(char* val) {
	printf("값 %s를 리스트 맨 끝에 추가합니다.\n", val);
	numbers[size++] = val;
}

void insert_list(int pos, char* val) {
	printf("값 %s를 %d 번째에 삽입합니다.\n", val, pos);
	for (int k = size - 1; k >= pos; k--)
		numbers[k + 1] = numbers[k];
	numbers[pos] = val;
	size++;
}

char* delete_list(int pos) {
	char* result = numbers[pos];
	for (int k = pos; k < size - 1; k++)
		numbers[k] = numbers[k + 1];
	printf("%d번째 값을 삭제합니다. 값 = %s\n", pos, result);
	size--;
	return result;
}

char* update_list(int pos, char* val) {
	char* result = numbers[pos];
	numbers[pos] = val;
	printf("%d 번째 값을 %s로 변경합니다. 이전값 = %s\n", pos, val, result);
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
		printf("\n(1) 끝에 값 추가 \n(2) pos번째에 값 추가\n");
		printf("(3) pos번째 삭제 \n(4) pos번째 값 변경 \n(5) val값 검색 \n (6)종료");
		printf(" 메뉴선택 => ");
		scanf_s("%d", &menu);
		if (menu >= 6) break;
		switch (menu) {
		case 1:
			printf("끝에 추가할 값: ");
			add_list(get_next());
			break;
		case 2:
			printf("추가할 위치와 값: ");
			scanf_s("%d", &pos);
			insert_list(pos, get_next());
			break;
		case 3:
			printf("삭제할 위치: ");
			scanf_s("%d", &pos);
			val = delete_list(pos);
			free(val);
			break;
		case 4:
			printf("변경할 위치와 값: ");
			scanf_s("%d", &pos);
			val = update_list(pos, get_next());
			free(val);
			break;
		case 5:
			printf("찾으려는 값 : ");
			val = get_next();
			pos = find(val);
			if (pos == -1)
				printf("%s는 없는 값입니다\n", val);
			else
				printf("%s는[%d]에 있습니다\n", val, pos);
			break;
		default:
			break;
		}
		print_list();
	}
	free_list();
}


void main() {
	printf("문자의 개수를 입력하시오 : ");
	scanf_s("%d", &size);
	input_list();
	run_menu();
	printf("\n안녕히 가세요\n");
}