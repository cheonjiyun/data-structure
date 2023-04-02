#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elem.h"
#include "stack.h"

typedef struct {
	elem_t array[100]; // 배열 정의
	int size; // 현재 리스트에 저장된 항목들의 개수
} arrlist_t;

//elem_t get_next() { // int
//	int n = rand() % 100;
//	//scanf_s("%d", &n);
//	return n;
//}
//
//char outbuf[20];
//char* str(elem_t e) {
//	sprintf_s(outbuf, 20, "%d", e);
//	return outbuf;
//}
//
//void free_elem() {
//}
//
//int compare(elem_t e1, elem_t e2) {
//	return e1 - e2;
//}

//int
//elem_t get_next() {
//	char buf[20];
//	scanf_s("%s", buf, 20);
//	char* chptr = (char*)malloc((strlen(buf) + 1) * sizeof(char));
//	strcpy_s(chptr, (strlen(buf) + 1), buf);
//	return chptr;
//}
//
//char* str(elem_t e) {
//	return e;
//}
//
//void free_elem(elem_t e) {
//	free(e);
//}
//
//int compare(elem_t e1, elem_t e2) {
//	return strcmp(e1, e2);
//}


// stack
elem_t get_next() {
	int num;
	scanf_s("%d", &num);
	return num;
}
char outbuf[20];
char* str(elem_t e) {
	sprintf_s(outbuf, 20, "%d", e);
	return outbuf;
}
void free_elem(elem_t e) {

}