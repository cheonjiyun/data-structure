#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "elem.h"


void push(stack_t* s, element item)
{
	if (is_full(s)) {
		s->capacity *= 2;
		s->data = (element*)malloc(s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = item;
}

elem_t pop(stack_t* s) {
	
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	return s->data[--(s->top)];
}
// 공백 상태 검사 함수
int is_empty(stack_t* s) {
	return (s->top == 0);
}
// 포화 상태 검사 함수
int is_full(stack_t* s) {
	return (s->top == MAX_STACK_SIZE);
}
// 스택 초기화 함수
void init_stack(stack_t* s)
{
	s->capacity = 16; // 처음 사이즈는 작게 잡는다 2^4
	s->data = (element*)malloc(s->capacity * sizeof(element));
	s->top = 0;

}
// 스택 출력 함수
void print_stack(stack_t* s) {
	for (int i = 0; i < s->top; i++)
		printf("%s ", str(s->data[i]));
	printf("\n");
}
// 스택 해지 함수
void free_stack(stack_t* s)
{
	for (int i = 0; i < s->top; i++)
		free_elem(s->data[i]);
	s->top = 0;
}
// 스택은 초기에 비어있는 상태로 출발하므로 input_stack은 불필요


void ReallocExample() {
	char* buffer = (char*)malloc(4);

	buffer = (char*)realloc(buffer, 8);
}