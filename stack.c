#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "elem.h"

void push(stack_t* s, elem_t e) {
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	s->data[(s->top)++] = e;
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
void init_stack(stack_t* s) {
	s->top = 0;
	for (int i = 0; i < MAX_STACK_SIZE; i++)
		s->data[i] = 0;
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
