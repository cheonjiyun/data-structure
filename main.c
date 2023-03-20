#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int elem_t;

int size;
int numbers[100]; // 최대 크기 100으로 배열포인터 선언


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

//어쨋든 문자열로 출력
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


// 개수만큼 리스트의 정수를 출력하는 함수
void print_list() {
	for (int i = 0; i < size; ++i) {
		printf("%s ", str(numbers[i]));
	}
}

void add_list(elem_t val) {
	printf("값 %s를 리스트 맨 끝에 추가합니다.\n", str(val));
	numbers[size++] = val;
}

void insert_list(int pos, elem_t val) {
	printf("값 %s를 %d 번째에 삽입합니다.\n", str(val), pos);
	for (int k = size - 1; k >= pos; k--)
		numbers[k + 1] = numbers[k];
	numbers[pos] = val;
	size++;
}

elem_t delete_list(int pos) {
	elem_t result = numbers[pos];
	for (int k = pos; k < size - 1; k++)
		numbers[k] = numbers[k + 1];
	printf("%d번째 값을 삭제합니다. 값 = %s\n", pos, str(result));
	size--;
	return result;
}

int find(elem_t val) {
	for (int i = 0; i < size; i++) {
		if (compare(numbers[i], val) == 0)
			return i; // 찾으면 인덱스 반환
	}
	return -1; // 못찾으면 -1
}

elem_t update_list(int pos, elem_t val) {
	elem_t result = numbers[pos];
	numbers[pos] = val;
	printf("%d 번째 값을 %s로 변경합니다. 이전값 = %s\n", pos, str(val), str(result));
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
		printf("\n(1) 끝에 값 추가 \n(2) pos번째에 값 추가\n");
		printf("(3) pos번째 삭제 \n(4) pos번째 값 변경 \n(5) val값 검색 \n(6)종료");
		printf(" 메뉴선택 => ");
		scanf_s("%d", &menu);
		if (menu >= 6) break;
		switch (menu) {
		case 1:
			printf("끝에 추가할 값: ");
			val = get_next();
			add_list(val);
			break;
		case 2:
			printf("추가할 위치와 값: ");
			scanf_s("%d", &pos);
			insert_list(pos, get_next());
			break;
		case 3:
			printf("삭제할 위치: ");
			scanf_s("%d", &pos);
			elem_t val = delete_list(pos);
			free_elem(val);
			break;
		case 4:
			printf("변경할 위치와 값: ");
			scanf_s("%d", &pos);
			val = update_list(pos, get_next());
			free_elem(val);
			break;
		case 5:
			printf("찾으려는 값 : ");
			val = get_next();
			pos = find(val);
			if (pos == -1)
				printf("%s는 없는 값입니다\n", str(val));
			else
				printf("%s는[%d]에 있습니다\n", str(val), pos);
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
	print_list();
	run_menu();
	printf("\n안녕히 가세요\n");
}