#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
// ���� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ���� ���� ���� �Լ�
void init_queue(queue_t* q)
{
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(queue_t* q)
{
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(queue_t* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// ���� �Լ�
void enqueue(queue_t* q, elem_t item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// ���� �Լ�
elem_t dequeue(queue_t* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// ���� �Լ�
elem_t peek(queue_t* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
// ����ť ��� �Լ�
void print_queue(queue_t* q)
{
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i <= q->front && q->front < q->rear)
			;									//  i <<  --
		else if (q->front < i && i <= q->rear)
			printf("\t%s\n", str(q->data[i]));  // << i --
		else if (i <= q->rear && q->rear < q->front)
			printf("\t%s\n", str(q->data[i]));  //  i -- ___ <<
		else if (i > q->front && q->rear < q->front)
			printf("\t%s\n", str(q->data[i]));  //  -- ___ << i
	}
}
