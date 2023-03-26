#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "elem.h"

void main() {
	int rnum;
	stack_t mystack;
	init_stack(&mystack);
	while (1) {
		rnum = rand() % 100;
		if (rnum == 0)
			break;
		if (rnum < 60) {
			rnum = rand() % 100;
			push(&mystack, rnum);
			printf("push <= %4d\t", rnum);
		}
		else {
			rnum = pop(&mystack);
			printf("pop = > %4d\t", rnum);
		}
		print_stack(&mystack);
	}
}