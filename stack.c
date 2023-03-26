#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "elem.h"

// ���� �ʱ�ȭ �Լ�
void init_stack(stack_t* s, int cap) {
	s->capacity = cap; // �Էµ� ��� ũ�⸸ŭ �Ҵ�
	s->recieve_count = 0;
	s->release_count = 0;
	s->stock = 0;
}
// �԰� �Լ�
void receive(stack_t* s, int count) {
	if (is_full(s, count)) {
		fprintf(stderr, "��� �ʰ��մϴ�.\n");
	}
	else {
		s->recieve_count += count;
		s->stock += count;
	}
}
// ���
void release(stack_t* s, int count) {
	if (is_empty(s, count)) {
		fprintf(stderr, "��� �����մϴ�.\n");
	}
	else {
		s->release_count += count;
		s->stock -= count;
	}
}
// ��ȭ���� �˻� �Լ�
int is_full(stack_t* s, int count) {
	return (s->stock + count > s->capacity);
}
// �ٴڳ��� �˻� �Լ�
int is_empty(stack_t* s, int count) {
	return (s->stock - count < 0);
}
// ���� ��� �Լ�
void print_stat(stack_t* s) {
	printf("���԰�: %d ", s->recieve_count);
	printf("�����: %d ", s->release_count);
	printf("���: %d ", s->stock);
	printf("\n");
}
