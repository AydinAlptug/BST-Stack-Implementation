#include "stackHeader.h"
//Stack creator
Stack* createStack(int capacity){
	Stack* newStack = (Stack*)malloc(sizeof(Stack));
	newStack->capacity = capacity;
	newStack->top = -1;
	newStack->task = (int*)malloc(sizeof(newStack->task));
	newStack->values = (int*)malloc(sizeof(newStack->values));
}
//Method checks whether stack is full or not
int isFull(Stack* stack){
	return stack->top == stack->capacity;
}

//Method checks whether stack is empty or not
int isEmpty(Stack* stack){
	return stack->top ==-1;
}
//Method that pushs given element
void push(Stack* stack, int t, int item){
	if(!isFull(stack)){
		stack->top = stack->top+1;
		stack->values[stack->top] = item;
		stack->task[stack->top] = t;
	}
}
//Method that pops the element on top
int pop(Stack* stack){
	int result=-1;
	if(!isEmpty(stack)){
		result = stack->top;
		stack->top = stack->top-1;
	}
	return result;
}


