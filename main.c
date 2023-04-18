#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
typedef struct {
	int id;
	char name[20];
	int take;    // 요리 시간
} oven_t;
oven_t menus[6] = { // 메뉴 종류
	{1, "AAA", 5},
	{2, "BBB", 3},
	{3, "CCC", 7},
	{4, "DDD", 4},
	{5, "EEE", 3},
	{6, "FFF", 5}
};
order_t order_list[10];
int num_ovens = 6;
int num_orders;
queue_t pizzaq_list[6];
void run_orders();
void print_logs();
void print_menus();
void read_order(order_t* op);

void main() {
	print_menus();
	run_orders();
	print_logs();
}
char outbuf[30];
char* str(elem_t e) {
	sprintf_s(outbuf, 30, "[%2d] %2d분", e->id, e->arrived);
	return outbuf;
}
void print_menu(int i)
{
	printf("[%d] %s %d분\n", menus[i].id, menus[i].name,
		menus[i].take);
}
void print_menus() {
	printf("\n\n====== 메뉴판 ======\n");
	for (int i = 0; i < num_ovens; i++) {
		print_menu(i);
	}
}

void run_orders() {
	printf("주문 개수: ");
	scanf_s("%d", &num_orders);
	for (int i = 0; i < num_orders; i++) {
		read_order(&order_list[i]);
		int pznum = order_list[i].pizza_num - 1;
		enqueue(&pizzaq_list[pznum], &order_list[i]);
	}
}
void read_order(order_t* op)
{
	scanf_s("%d %d %d", &op->id, &op->arrived, &op->pizza_num);
}
void print_logs() {
	printf("오븐 별 요리내역\n");
	for (int i = 0; i < 6; i++) {
		printf("%s (%d건)\n", menus[i].name, pizzaq_list[i].rear);
		printf("번호  주문     시작 --- 완료  (대기시간)\n");

		int start_time = 0; // 요리 시작
		int end_time = 0; // 요리 완료
		int waiting_time = 0; // 대기 시간
		for (int j = 0; j < pizzaq_list[i].rear; j++) {
			elem_t each_order = dequeue(&pizzaq_list[i]); // 주문들 하나하나 뺌

			if (each_order->arrived < end_time) { // 이전 주문이 완료가 안되어있다면
				waiting_time = end_time - each_order->arrived; // 이전 주문이 완료된 시간 - 주문 시간
				start_time = end_time; // 이전 주문이 완료된 시간
				end_time = start_time + menus[i].take; // 시작 시간 + 메뉴의 조리 시간
			}
			else { // 쌓인 주문이 없다면
				waiting_time = 0; // 대기시간 없음
				start_time = each_order->arrived;
				end_time = each_order->arrived + menus[i].take;
			}
			printf("[%2d]  %2d분      %2d       %2d        (%d분)\n", each_order->id, each_order->arrived, start_time, end_time, waiting_time);
		}
		printf("\n");

	}

}