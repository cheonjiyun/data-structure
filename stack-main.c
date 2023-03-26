#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "elem.h"

int main(void)
{
	
	stack_t s;
	
	init_stack(&s);
	
	push(&s, 1);
	
	push(&s, 2);
	
	push(&s, 3);
	
	printf("%s\n", str(pop(&s)));
	printf("%s\n", str(pop(&s)));
	printf("%s\n", str(pop(&s)));
}