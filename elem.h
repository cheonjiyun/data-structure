#pragma once


//typedef int elem_t;
//elem_t get_next();
//char* str(elem_t e);
//void free_elem();
//int compare(elem_t e1, elem_t e2);


typedef char* elem_t;
elem_t get_next();
char* str(elem_t e);
void free_elem(elem_t e);
int compare(elem_t e1, elem_t e2);