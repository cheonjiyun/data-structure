#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "elem.h"

void main() {
	stack_t sp;
	int menu, count, cap;
	printf("������ ���񽺿� ���Ű��� ȯ���մϴ� :)\n���� â�� �� �뷮�� �Է����ּ���.\n\n");
	printf("�� ��� �뷮: ");
	scanf_s("%d", &cap);
	init_stack(&sp, cap);
	while (1) {
		printf("(1) �԰� (2) ��� (3) ����... ");
		scanf_s("%d", &menu);
		if (menu == 1) {
			printf("�԰� ����: ");
			scanf_s("%d", &count);
			receive(&sp, count);
		}
		else if (menu == 2) {
			printf("��� ����: ");
			scanf_s("%d", &count);
			release(&sp, count);
		}
		else break;
		print_stat(&sp);
	}
	printf("�ȳ��� ������ :)");
}