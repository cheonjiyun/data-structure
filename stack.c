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
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	return s->data[--(s->top)];
}
// ���� ���� �˻� �Լ�
int is_empty(stack_t* s) {
	return (s->top == 0);
}
// ��ȭ ���� �˻� �Լ�
int is_full(stack_t* s) {
	return (s->top == MAX_STACK_SIZE);
}
// ���� �ʱ�ȭ �Լ�
void init_stack(stack_t* s)
{
	s->capacity = 16; // ó�� ������� �۰� ��´� 2^4
	s->data = (element*)malloc(s->capacity * sizeof(element));
	s->top = 0;

}
// ���� ��� �Լ�
void print_stack(stack_t* s) {
	for (int i = 0; i < s->top; i++)
		printf("%s ", str(s->data[i]));
	printf("\n");
}
// ���� ���� �Լ�
void free_stack(stack_t* s)
{
	for (int i = 0; i < s->top; i++)
		free_elem(s->data[i]);
	s->top = 0;
}
// ������ �ʱ⿡ ����ִ� ���·� ����ϹǷ� input_stack�� ���ʿ�


void ReallocExample() {
	char* buffer = (char*)malloc(4);

	buffer = (char*)realloc(buffer, 8);
}