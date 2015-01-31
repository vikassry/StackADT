#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


Stack createStack(void){
	LinkedList list = createList();
	return (Stack){list, NULL};
}

int push(Stack *stack, void *data){
	node_ptr node = create_node(data);
	add_to_list(&(stack->list), node);
	stack->top = stack->list.tail;
	return stack->list.count;
}

void *pop(Stack *stack){
	void *item = deleteElementAt(&(stack->list), stack->list.count-1);
	stack->top = stack->list.tail;
	return item;
}

// void *pop(Stack *stack){
// 	node_ptr walker; int i=0;
// 	for(walker=stack->top; walker != NULL; walker = walker->next){
// 		if(i == stack->count-2){
// 			walker->next = NULL;
// 			stack->top = walker;
// 			stack->count--;
// 		} i++;
// 	}
// 	return stack->top->data;
// }