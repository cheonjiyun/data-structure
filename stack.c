#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "elem.h"

// 스택 초기화 함수
void init_stack(stack_t* s, int cap) {
	s->capacity = cap; // 입력된 재고 크기만큼 할당
	s->recieve_count = 0;
	s->release_count = 0;
	s->stock = 0;
}
// 입고 함수
void receive(stack_t* s, int count) {
	if (is_full(s, count)) {
		fprintf(stderr, "재고를 초과합니다.\n");
	}
	else {
		s->recieve_count += count;
		s->stock += count;
	}
}
// 출고
void release(stack_t* s, int count) {
	if (is_empty(s, count)) {
		fprintf(stderr, "재고가 부족합니다.\n");
	}
	else {
		s->release_count += count;
		s->stock -= count;
	}
}
// 포화할지 검사 함수
int is_full(stack_t* s, int count) {
	return (s->stock + count > s->capacity);
}
// 바닥날지 검사 함수
int is_empty(stack_t* s, int count) {
	return (s->stock - count < 0);
}
// 스택 출력 함수
void print_stat(stack_t* s) {
	printf("총입고: %d ", s->recieve_count);
	printf("총출고: %d ", s->release_count);
	printf("재고: %d ", s->stock);
	printf("\n");
}
