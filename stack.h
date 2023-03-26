#pragma once

typedef int elem_t;
typedef int element;
typedef struct {
	int capacity; // â�� �뷮
	int recieve_count; // ���԰�
	int release_count; // �����
	int stock; // ���
} stack_t;

// �Լ� ���漱��
void init_stack(stack_t* s, int cap);
void receive(stack_t* s, int count);
void release(stack_t* s, int count);
int is_empty(stack_t* s, int count);
int is_full(stack_t* s, int count);
void print_stat(stack_t* s);


//void free_stack(stack_t* s);