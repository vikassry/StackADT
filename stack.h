#include <stdio.h>
#include "linkedList.h"

typedef struct stack Stack;

struct stack{
	LinkedList *list;
	node_ptr top;
};

void print_stack(Stack);
void free_stack(Stack*);

Stack createStack(void);
int push(Stack*, void *);
void *pop(Stack*);