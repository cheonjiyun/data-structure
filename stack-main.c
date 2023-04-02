#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "elem.h"


int check_matching(char* in);
int is_open(char ch);
int is_cloing(char ch);

int main(void)
{
	char input[20];
	printf(">> ");
	scanf_s("%s", input, 20);
	printf("%s °ýÈ£°Ë»ç ", input);
	if (check_matching(input))
		printf("¼º°ø\n", input);
	else
		printf("½ÇÆÐ\n", input);
	return 0;
}


int check_matching(char* in) {
	char ch, open_ch;
	stack_t mystack;
	init_stack(&mystack);
	for (int i = 0; i < strlen(in); i++) {
		ch = in[i];
		if (is_open(ch)) {
			push(&mystack, ch);
		}
		else if (is_cloing(ch)) {
			if (is_empty(&mystack))
				return 0; // 1 ´Ý´Â °ýÈ£°¡ ¸¹À½
			open_ch = pop(&mystack);
			if (!matching(open_ch, ch))
				return 0; // 2 °ýÈ£ Â¦ ¿À·ù
		}
		else {
			printf("wrong char %c... Bye\n", ch);
			exit(1);
		}
		printf("[%-20s]\t", in + i);
		print_stack(&mystack, in + (i + 1));
	}
	return is_empty(&mystack); // 3 ¿©´Â °ýÈ£°¡ ¸¹À¸¸é 0


}

int is_open(char ch) {
	return ch == '(' || ch == '{' || ch == '[';
}

int is_cloing(char  ch) {
	return ch == ')' || ch == '}' || ch == ']';
}

int matching(char ch, char open_ch) {
	return (ch == '(' && open_ch == ')')
		|| (ch == '{' && open_ch == '}')
		|| (ch == '[' && open_ch == ']');
}
