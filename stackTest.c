#include "stack.h"
#include "expr_assert.h"

void test_createStack_creates_a_empty_stack_with_stack_pointer_pointing_to_NULL(){
	Stack stack = createStack();
	assert(stack.top == NULL);
	assert(stack.list.head == NULL);
	assert(stack.list.tail == NULL);
}

void test_push_adds_one_int_element_to_top_of_the_stack_and_returns_1_when_stack_is_empty(){
	int a = 4;
	Stack stack = createStack();
	assert(push(&stack, &a) == 1);
}

void test_push_adds_int_element_to_top_of_the_stack(){
	int a = 4;
	Stack stack = createStack();
	push(&stack, &a);
	assert(stack.top->data == &a);
	assert(*(int*)(stack.top->data) == 4);
}

void test_push_adds_float_element_to_top_of_the_stack_for_3_elements(){
	float a = 4.5, b = 5.3, c = 6.25;
	Stack stack = createStack();
	push(&stack, &a);
	push(&stack, &b);
	assert(push(&stack, &c) == 3);
	assert(stack.top->data == &c);
	assert(*(float*)(stack.top->data) == 6.25);
}

void test_push_adds_float_element_to_top_and_3_elements_linked_together(){
	float a = 4.5, b = 5.3, c = 6.25, count;
	Stack stack = createStack(); node_ptr item;
	push(&stack, &a);
	push(&stack, &b);
	item = stack.top;
	count = push(&stack, &c);

	assert(stack.top == item->next);
	assert(count == 3);
}


void test_pop_deletes_the_last_element_from_the_stack(){
	float a = 4.5, b = 5.3;
	Stack stack = createStack();
	push(&stack, &a);
	push(&stack, &b);
	assert(stack.top->data == &b);
	assert(stack.list.count == 2);

	pop(&stack);
	assert(stack.top->data == &a);
	assert(stack.list.count == 1);
}
