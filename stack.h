#include <stdio.h>
#include "linkedList.h"

typedef struct stack Stack;

struct stack{
	LinkedList list;
	node_ptr top;
};

Stack createStack(void);
int push(Stack*, void *);
void *pop(Stack*);