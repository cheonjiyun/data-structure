#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 공백 상태 검출 함수
void init_queue(queue_t* q)
{
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(queue_t* q)
{
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(queue_t* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 삽입 함수
void enqueue(queue_t* q, elem_t item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
elem_t dequeue(queue_t* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// 삭제 함수
elem_t peek(queue_t* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
// 원형큐 출력 함수
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
