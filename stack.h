#pragma once

#define MAX_STACK_SIZE 100
typedef int elem_t;
typedef struct {
	elem_t data[MAX_STACK_SIZE];
	int top;
} stack_t;
// 함수 전방선언
void push(stack_t* s, elem_t e);
elem_t pop(stack_t* s);
int is_empty(stack_t* s);
int is_full(stack_t* s);
void init_stack(stack_t* s);
void print_stack(stack_t* s);
void free_stack(stack_t* s);