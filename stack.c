#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


void print_stack(Stack s){
	print_list(*s.list);
}

Stack createStack(void){
	LinkedList *list = (LinkedList*)calloc(1,sizeof(LinkedList));
	return (Stack){list, &list->tail};
}

int push(Stack stack, void *data){
	node_ptr node = create_node(data);
	add_to_list(stack.list, node);
	return stack.list->count;
}

void *pop(Stack stack){
	return deleteElementAt(stack.list, stack.list->count-1);
}