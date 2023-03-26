#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "elem.h"

void main() {
	stack_t sp;
	int menu, count, cap;
	printf("재고관리 서비스에 오신것을 환영합니다 :)\n먼저 창고 총 용량을 입력해주세요.\n\n");
	printf("총 재고 용량: ");
	scanf_s("%d", &cap);
	init_stack(&sp, cap);
	while (1) {
		printf("(1) 입고 (2) 출고 (3) 종료... ");
		scanf_s("%d", &menu);
		if (menu == 1) {
			printf("입고 개수: ");
			scanf_s("%d", &count);
			receive(&sp, count);
		}
		else if (menu == 2) {
			printf("출고 개수: ");
			scanf_s("%d", &count);
			release(&sp, count);
		}
		else break;
		print_stat(&sp);
	}
	printf("안녕히 가세요 :)");
}