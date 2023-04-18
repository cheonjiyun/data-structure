#pragma once
typedef struct order {
	int id;  // �ֹ� ���̵�
	int arrived;  // �ֹ��ð�
	int pizza_num; // �ֹ��� ���� ��ȣ
} order_t;
typedef order_t* elem_t;
// ===== ����ť �ڵ� ���� ======
#define MAX_QUEUE_SIZE 20
typedef struct q { // ť Ÿ��
	elem_t  data[MAX_QUEUE_SIZE];
	int  front, rear;
} queue_t;

// ���� �Լ�
void error(char* message);

// ���� ���� ���� �Լ�
void init_queue(queue_t* q);

// ���� ���� ���� �Լ�
int is_empty(queue_t* q);

// ��ȭ ���� ���� �Լ�
int is_full(queue_t* q);

// ����ť ��� �Լ�
void print_queue(queue_t* q);

// ���� �Լ�
void enqueue(queue_t* q, elem_t e);

// ���� �Լ�
elem_t dequeue(queue_t* q);

// ���� �Լ�
elem_t peek(queue_t* q);