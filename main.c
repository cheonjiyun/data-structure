#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 10
typedef int elem_t;
typedef struct {
	int front;
	int rear;
	elem_t data[MAX_QUEUE_SIZE];
} queue_t;
void init_queue(queue_t* q);
void enqueue(queue_t* q, elem_t item);
elem_t dequeue(queue_t* q);
void queue_print(queue_t* q);
int is_full(queue_t* q);
int is_empty(queue_t* q);

int main(void)
{
	int item = 0;
	queue_t q;
	init_queue(&q);
	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 20); queue_print(&q);
	enqueue(&q, 30); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	return 0;
}
void init_queue(queue_t* q)
{
	q->rear = 0;
	q->front = 0;
}
void enqueue(queue_t* q, elem_t item)
{
	if (is_full(q)) {
		printf("큐가 포화상태입니다.");
		return;
	}
	q->data[(q->rear)++] = item;
}
elem_t dequeue(queue_t* q)
{
	if (is_empty(q)) {
		printf("큐가 공백상태입니다.");
		return -1;
	}
	int item = q->data[(q->front)++];
	return item;
}
void queue_print(queue_t* q)
{
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i < q->front || i >= q->rear)
			printf("   | ");
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n");
}
int is_full(queue_t* q)
{
	return (q->rear == MAX_QUEUE_SIZE);
}
int is_empty(queue_t* q)
{
	return (q->front == q->rear);
}
