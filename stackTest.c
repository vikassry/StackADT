#include "stack.h"
#include <stdlib.h>
#include "expr_assert.h"


void test_createStack_creates_a_empty_stack_with_stack_pointer_pointing_to_NULL(){
	Stack stack = createStack();
	assert(*stack.top == NULL);
	assert(stack.list->head == NULL);
	assert(stack.list->tail == NULL);
	assert(stack.list->count == 0);
	free(stack.list);
}

void test_push_adds_one_int_element_to_top_of_the_stack_and_returns_1_when_stack_is_empty_and_top_is_head_of_the_stack_list(){
	int a = 4;
	Stack stack = createStack();
	assert(push(stack, &a) == 1);
	assert((*stack.top)->data == &a);
	assert(*(int*)((*stack.top)->data) == 4);
	assert((*stack.top) == stack.list->head);
	assert((*stack.top) == stack.list->tail);
	free(stack.list);
}

void test_push_adds_one_double_element_to_top_of_the_stack_and_returns_1_when_stack_is_empty(){
	double a = 4;
	Stack stack = createStack();
	assert(push(stack, &a) == 1);
	assert((*stack.top)->data == &a);
	assert(*(double*)((*stack.top)->data) == 4);
	assert((*stack.top) == stack.list->head);
	free(stack.list);
}

void test_push_adds_one_unsigned_int_element_to_top_of_the_stack_and_returns_1_when_stack_is_empty(){
	unsigned int a = 43332211;
	Stack stack = createStack();
	assert(push(stack, &a) == 1);
	assert((*stack.top)->data == &a);
	assert(*(stack.top) == stack.list->head);
	assert(*(unsigned int*)((*stack.top)->data) == 43332211);
	free(stack.list);
}

void test_push_adds_one_char_element_to_top_of_the_stack_and_returns_1_when_stack_is_empty(){
	char a = 'A';
	Stack stack = createStack();
	assert(push(stack, &a) == 1);
	assert((*stack.top)->data == &a);
	assert((*stack.top) == stack.list->head);
	assert(*(char*)((*stack.top)->data) == 'A');
	free(stack.list);
}

void test_push_adds_one_string_element_to_top_of_the_stack_and_returns_1_when_stack_is_empty(){
	string a = "ABCdsd";
	Stack stack = createStack();
	assert(push(stack, &a) == 1);
	assert((*stack.top)->data == &a);
	assert((*stack.top) == stack.list->head);
	assert(*(string*)((*stack.top)->data) == "ABCdsd");
	free(stack.list);
}

void test_push_adds_float_element_to_top_of_the_stack_for_3_elements(){
	float a = 4.5, b = 5.3, c = 6.25;
	Stack stack = createStack();
	push(stack, &a);
	push(stack, &b);
	assert(push(stack, &c) == 3);

	assert(stack.list->head->next->data == &b);
	assert(stack.list->head->next->next == (*stack.top));
	assert((*stack.top)->data == &c);
	assert(*(float*)((*stack.top)->data) == 6.25);
	free(stack.list);
}

void test_push_adds_unsigned_char_element_to_top_of_the_stack_for_3_elements(){
	unsigned char a = 45, b = 53, c = 125;
	Stack stack = createStack();
	push(stack, &a);
	push(stack, &b);
	assert(push(stack, &c) == 3);
	assert((*stack.top)->data == &c);
	assert(*(unsigned char*)((*stack.top)->data) == 125);
	free(stack.list);
}

void test_push_adds_float_element_to_top_and_3_elements_linked_together(){
	double a = 4.5, b = 5.3, c = 6.25, count;
	Stack stack = createStack(); node_ptr item;
	push(stack, &a);
	push(stack, &b);
	item = (*stack.top);
	count = push(stack, &c);

	assert((*stack.top) == item->next);
	assert(count == 3);
	free(stack.list);
}

void test_pop_deletes_the_last_element_from_the_int_stack(){
	int a = -32467, b = 32567;
	Stack stack = createStack();
	push(stack, &a);
	push(stack, &b);
	
	assert(stack.list->head->next == (*stack.top));
	assertEqual(*(int*)(*stack.top)->data, 32567);
	assert(stack.list->count == 2);
	pop(stack);
	assert((*stack.top)->data == &a);
	assert(*(int*)(*stack.top)->data == -32467);
	assert(stack.list->count == 1);
	free(stack.list);
}

void test_pop_deletes_the_last_element_from_the_float_stack(){
	float a = 4.5, b = 5.3;
	Stack stack = createStack();
	push(stack, &a);
	push(stack, &b);
	assert(*(float*)(*stack.top)->data == (float)5.3);
	assert(stack.list->count == 2);
	assert(stack.list->head->next == (*stack.top));

	pop(stack);
	assert((*stack.top)->data == &a);
	assert(*(float*)(*stack.top)->data == 4.5);
	assert(stack.list->count == 1);
	assert(stack.list->head == (*stack.top));
	free(stack.list);
}

void test_pop_deletes_the_last_element_from_the_double_stack(){
	double a = 4.5, b = 5.33, c=748.75;
	Stack stack = createStack();
	push(stack, &a);
	push(stack, &b);
	push(stack, &c);
	assert(*(double*)(*stack.top)->data == 748.75);
	assert(stack.list->count == 3);
	pop(stack);
	assert(*(double*)(*stack.top)->data == 5.33);
	assert(stack.list->count == 2);
	free(stack.list);
}

void test_pop_deletes_the_last_element_from_the_char_stack(){
	char a = 'x', b = 'X';
	Stack stack = createStack();
	push(stack, &a);
	push(stack, &b);
	assertEqual(*(char*)(*stack.top)->data, 88);
	assert(stack.list->count == 2);
	pop(stack);
	assert((*stack.top)->data == &a);
	assert(*(char*)(*stack.top)->data == 120);
	assert(stack.list->count == 1);
	free(stack.list);
}

void test_pop_deletes_the_last_element_from_the_string_stack(){
	string a = "", b = "sdcdac";
	Stack stack = createStack();
	push(stack, &a);
	push(stack, &b);
	assert(*(string*)(*stack.top)->data == "sdcdac");
	assert(stack.list->count == 2);
	pop(stack);
	assert((*stack.top)->data == &a);
	assert(*(string*)(*stack.top)->data == "");
	assert(stack.list->count == 1);
	free(stack.list);
}

void test_pop_deletes_the_last_element_and_list_head_is_stack_top_when_only_1_element_is_in_stack(){
	string a = "", b = "sdcdac";
	Stack stack = createStack();
	push(stack, &a);
	push(stack, &b);
	assert(*(string*)(*stack.top)->data == "sdcdac");
	pop(stack);
	assert(*(string*)(*stack.top)->data == "");
	assert((*stack.top) == stack.list->head);
	assert((*stack.top) == stack.list->tail);
	assert(stack.list->count == 1);
	free(stack.list);
}

void test_pop_makes_the_top_and_list_head_and_tail_becomes_NULL_when_only_1_element_is_in_stack(){
	string a = "sdcdac";
	Stack stack = createStack();
	push(stack, &a);
	assert(*(string*)(*stack.top)->data == "sdcdac");
	assert(stack.list->count == 1);
	pop(stack);
	assert((*stack.top) == NULL);
	assert(stack.list->head == NULL);
	assert(stack.list->tail == NULL);
	assert(stack.list->count == 0);
	free(stack.list);
}

void test_stack_gives_data_15_at_index_2(){
	Stack stack = createStack();
	int data[] = {12,13,15,16}, count, index, i;
	for(i=0;i<4;i++)
		count = push(stack, &data[i]);
	index = indexOf(*stack.list, &data[2]);

	assertEqual(count,4);
	assertEqual(index,2);
	assert(*(int*)(*stack.top)->data == data[3]);
}