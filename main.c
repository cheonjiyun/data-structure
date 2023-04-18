#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
typedef struct {
	int id;
	char name[20];
	int take;    // �丮 �ð�
} oven_t;
oven_t menus[6] = { // �޴� ����
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
	sprintf_s(outbuf, 30, "[%2d] %2d��", e->id, e->arrived);
	return outbuf;
}
void print_menu(int i)
{
	printf("[%d] %s %d��\n", menus[i].id, menus[i].name,
		menus[i].take);
}
void print_menus() {
	printf("\n\n====== �޴��� ======\n");
	for (int i = 0; i < num_ovens; i++) {
		print_menu(i);
	}
}

void run_orders() {
	printf("�ֹ� ����: ");
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
	printf("���� �� �丮����\n");
	for (int i = 0; i < 6; i++) {
		printf("%s (%d��)\n", menus[i].name, pizzaq_list[i].rear);
		printf("��ȣ  �ֹ�     ���� --- �Ϸ�  (���ð�)\n");

		int start_time = 0; // �丮 ����
		int end_time = 0; // �丮 �Ϸ�
		int waiting_time = 0; // ��� �ð�
		for (int j = 0; j < pizzaq_list[i].rear; j++) {
			elem_t each_order = dequeue(&pizzaq_list[i]); // �ֹ��� �ϳ��ϳ� ��

			if (each_order->arrived < end_time) { // ���� �ֹ��� �Ϸᰡ �ȵǾ��ִٸ�
				waiting_time = end_time - each_order->arrived; // ���� �ֹ��� �Ϸ�� �ð� - �ֹ� �ð�
				start_time = end_time; // ���� �ֹ��� �Ϸ�� �ð�
				end_time = start_time + menus[i].take; // ���� �ð� + �޴��� ���� �ð�
			}
			else { // ���� �ֹ��� ���ٸ�
				waiting_time = 0; // ���ð� ����
				start_time = each_order->arrived;
				end_time = each_order->arrived + menus[i].take;
			}
			printf("[%2d]  %2d��      %2d       %2d        (%d��)\n", each_order->id, each_order->arrived, start_time, end_time, waiting_time);
		}
		printf("\n");

	}

}