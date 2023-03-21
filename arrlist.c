#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arrlist.h"

void print_list(arrlist_t* lp) {
	for (int i = 0; i < lp->size; ++i) {
		printf("%s ", str(lp->array[i]));
	}
}

void add_list(arrlist_t* lp, elem_t val) {
	//printf("값 %s를 리스트 맨 끝에 추가합니다.\n", str(val));
	lp->array[lp->size++] = val;
}

void insert_list(arrlist_t* lp, int pos, elem_t val) {
	printf("값 %s를 %d 번째에 삽입합니다.\n", str(val), pos);
	for (int k = lp->size - 1; k >= pos; k--)
		lp->array[k + 1] = lp->array[k];
	lp->array[pos] = val;
	lp->size++;
}

elem_t delete_list(arrlist_t* lp, int pos) {
	elem_t result = lp->array[pos];
	for (int k = pos; k < lp->size - 1; k++)
		lp->array[k] = lp->array[k + 1];
	printf("%d번째 값을 삭제합니다. 값 = %s\n", pos, str(result));
	lp->size--;
	return result;
}


elem_t update_list(arrlist_t* lp, int pos, elem_t val) {
	elem_t result = lp->array[pos];
	lp->array[pos] = val;
	printf("%d 번째 값을 %s로 변경합니다. 이전값 = %s\n", pos, str(val), str(result));
	return result;
}

elem_t get(arrlist_t* lp, int index) {
	return lp->array[index];
}


int find(arrlist_t* lp, elem_t val) {
	for (int i = 0; i < lp->size; i++) {
		if (compare(lp->array[i], val) == 0)
			return i; // 찾으면 인덱스 반환
	}
	return -1; // 못찾으면 -1
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