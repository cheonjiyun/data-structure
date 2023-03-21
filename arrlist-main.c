#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elem.h"
#include "arrlist.h"

// lp가 가리키는 리스트에 e와 같은 값이 있으면 1, 없으면 0 
int contains(arrlist_t* lp, elem_t e) {
	if (find(lp, e) != -1) {
		return 1;
	}
	else {
		return 0;
	}
}

// lp가 가진 요소를 중복없이 새로운 리스트에 추가해서 돌려준다
arrlist_t* remove_redundancy(arrlist_t* lp) {
	arrlist_t* newlp = (arrlist_t*)malloc(sizeof(arrlist_t));
	init_list(newlp);
	//newlp에 같은 값이 없을 때만 넣음
	for (int i = 0; i < len(lp); i++) {
		if (contains(newlp, get(lp, i)) == 0) {
			add_list(newlp, get(lp, i));
		}
	}
	
	return newlp;
}

// 두 리스트의 교집합을 가지는 리스트를 만들어 반환한다
arrlist_t* compute_subset(arrlist_t* aptr, arrlist_t* bptr) {
	arrlist_t* newlp = (arrlist_t*)malloc(sizeof(arrlist_t));
	init_list(newlp);

	//aptr에 같은 값이 있을 때만 넣음
	for (int i = 0; i < len(bptr); i++) {
		if (contains(aptr, get(bptr, i)) == 1) {
			add_list(newlp, get(bptr, i));
		}
	}

	return newlp;
}

// bptr가 가진 요소를 모두 aptr가 가리키는 리스트에 모두 추가한다.
void copy_list(arrlist_t* aptr, arrlist_t* bptr) {
	for (int i = 0; i < len(bptr); i++) {
		if (contains(aptr, get(bptr, i)) == 0) {
			add_list(aptr, get(bptr, i));
		}
	}

}

//합집합
arrlist_t* compute_superset(arrlist_t* aptr, arrlist_t* bptr) {
	arrlist_t* newlp = (arrlist_t*)malloc(sizeof(arrlist_t));
	init_list(newlp);
	
	//aprt값을 newlp에 같은 값이 없을 때만 넣음(중복없이)
	for (int i = 0; i < len(aptr); i++) {
		if (contains(newlp, get(aptr, i)) == 0) {
			add_list(newlp, get(aptr, i));
		}
	}

	//bptr값을 이미 aptr를 넣은 newlp에 같은 값이 없을 때만 넣음(중복없이)
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
	printf("\nlista 중복제거: \n"); print_list(aptr);
	printf("\nlistb 중복제거: \n"); print_list(bptr);

	arrlist_t* subset = compute_subset(&lista, &listb);
	printf("\n교집합: \n"); print_list(subset);
	arrlist_t* superset = compute_superset(&lista, &listb);
	printf("\n합집합: \n"); print_list(superset);
}