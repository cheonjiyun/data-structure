#pragma once

#include "elem.h"

typedef struct {
	elem_t array[100];
	int size;
} arrlist_t;

void print_list(arrlist_t* lp);
void add_list(arrlist_t* lp, elem_t val);
void insert_list(arrlist_t* lp, int pos, elem_t val);
elem_t delete_list(arrlist_t* lp, int pos);
elem_t update_list(arrlist_t* lp, int pos, elem_t val);
elem_t get(arrlist_t* lp, int index);
int find(arrlist_t* lp, elem_t val);
int len(arrlist_t* lp);
void init_list(arrlist_t* lp);
void clear(arrlist_t* lp);
void input_list(arrlist_t* lp, int sz);
void free_list(arrlist_t* lp);