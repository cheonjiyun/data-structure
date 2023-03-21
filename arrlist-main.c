#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elem.h"
#include "arrlist.h"

// lp�� ����Ű�� ����Ʈ�� e�� ���� ���� ������ 1, ������ 0 
int contains(arrlist_t* lp, elem_t e) {
	if (find(lp, e) != -1) {
		return 1;
	}
	else {
		return 0;
	}
}

// lp�� ���� ��Ҹ� �ߺ����� ���ο� ����Ʈ�� �߰��ؼ� �����ش�
arrlist_t* remove_redundancy(arrlist_t* lp) {
	arrlist_t* newlp = (arrlist_t*)malloc(sizeof(arrlist_t));
	init_list(newlp);
	//newlp�� ���� ���� ���� ���� ����
	for (int i = 0; i < len(lp); i++) {
		if (contains(newlp, get(lp, i)) == 0) {
			add_list(newlp, get(lp, i));
		}
	}
	
	return newlp;
}

// �� ����Ʈ�� �������� ������ ����Ʈ�� ����� ��ȯ�Ѵ�
arrlist_t* compute_subset(arrlist_t* aptr, arrlist_t* bptr) {
	arrlist_t* newlp = (arrlist_t*)malloc(sizeof(arrlist_t));
	init_list(newlp);

	//aptr�� ���� ���� ���� ���� ����
	for (int i = 0; i < len(bptr); i++) {
		if (contains(aptr, get(bptr, i)) == 1) {
			add_list(newlp, get(bptr, i));
		}
	}

	return newlp;
}

// bptr�� ���� ��Ҹ� ��� aptr�� ����Ű�� ����Ʈ�� ��� �߰��Ѵ�.
void copy_list(arrlist_t* aptr, arrlist_t* bptr) {
	for (int i = 0; i < len(bptr); i++) {
		if (contains(aptr, get(bptr, i)) == 0) {
			add_list(aptr, get(bptr, i));
		}
	}

}

//������
arrlist_t* compute_superset(arrlist_t* aptr, arrlist_t* bptr) {
	arrlist_t* newlp = (arrlist_t*)malloc(sizeof(arrlist_t));
	init_list(newlp);
	
	//aprt���� newlp�� ���� ���� ���� ���� ����(�ߺ�����)
	for (int i = 0; i < len(aptr); i++) {
		if (contains(newlp, get(aptr, i)) == 0) {
			add_list(newlp, get(aptr, i));
		}
	}

	//bptr���� �̹� aptr�� ���� newlp�� ���� ���� ���� ���� ����(�ߺ�����)
	for (int i = 0; i < len(bptr); i++) {
		if (contains(newlp, get(bptr, i)) == 0) {
			add_list(newlp, get(bptr, i));
		}
	}

	return newlp;
}

void main() {
	arrlist_t lista, listb;
	init_list(&lista);
	input_list(&lista, 20);
	init_list(&listb);
	input_list(&listb, 20);
	printf("lista: \n"); print_list(&lista);
	printf("\nlistb: \n"); print_list(&listb);
	arrlist_t* aptr = remove_redundancy(&lista);
	arrlist_t* bptr = remove_redundancy(&listb);
	printf("\nlista �ߺ�����: \n"); print_list(aptr);
	printf("\nlistb �ߺ�����: \n"); print_list(bptr);

	arrlist_t* subset = compute_subset(&lista, &listb);
	printf("\n������: \n"); print_list(subset);
	arrlist_t* superset = compute_superset(&lista, &listb);
	printf("\n������: \n"); print_list(superset);
}