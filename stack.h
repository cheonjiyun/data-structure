#pragma once

typedef int elem_t;
typedef int element;
typedef struct {
	int capacity; // 창고 용량
	int recieve_count; // 총입고
	int release_count; // 총출고
	int stock; // 재고
} stack_t;

// 함수 전방선언
void init_stack(stack_t* s, int cap);
void receive(stack_t* s, int count);
void release(stack_t* s, int count);
int is_empty(stack_t* s, int count);
int is_full(stack_t* s, int count);
void print_stat(stack_t* s);


//void free_stack(stack_t* s);