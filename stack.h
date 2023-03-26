#pragma once

#define MAX_STACK_SIZE 100
typedef int elem_t;
typedef int element;
typedef struct {
	element* data; // data�� �����ͷ� ���ǵȴ�. 
	int capacity; // ���� ũ��
	int top;
} stack_t;
// �Լ� ���漱��
void push(stack_t* s, elem_t e);
elem_t pop(stack_t* s);
int is_empty(stack_t* s);
int is_full(stack_t* s);
void init_stack(stack_t* s);
void print_stack(stack_t* s);
void free_stack(stack_t* s);