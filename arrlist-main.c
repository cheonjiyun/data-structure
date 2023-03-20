#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elem.h"
#include "arrlist.h"

void main() {
	int num;
	srand(1);
	arrlist_t org_list, new_list;
	init_list(&org_list);
	input_list(&org_list, 100);
	printf("original list : \n"); print_list(&org_list);
	printf("\n");
	init_list(&new_list, 0);
	for (int i = len(&org_list) - 1; i >= 0; i--) {
		num = get(&org_list, i);
		if (num > 50) {
			num = delete_list(&org_list, i);
			add_list(&new_list, num);
		}
	}
	printf("50 이하 list : \n"); print_list(&org_list);
	printf("\n");
	printf("50 초과 list : \n"); print_list(&new_list);


	//arrlist_t mylist;
	//int size;
	//printf("문자의 개수를 입력하시오 : ");
	//scanf_s("%d", &size);
	//input_list(&mylist, size);
	//run_menu(&mylist);
	//printf("\n안녕히 가세요\n");
}