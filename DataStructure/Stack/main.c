
#include <stdio.h>
#include <stdlib.h>
#define INT_MIN -1

#include "SimpleStack.c"
#include "DynArrayStack.c"

int main()
{
    printf("Hello world!\n");
    struct SimpleStack *Stack = (struct SimpleStack *)malloc(sizeof(struct SimpleStack));
    int c;
    Stack = CreateStack(5);
    Push(Stack,1);
    Push(Stack,2);
    Push(Stack,3);
    ReverseStack(Stack);
    c = Pop(Stack);
    printf("Element Poped :: %d\n",c);
    DeleteStack(Stack);
/*
    struct DynArrayStack *dynStack = malloc(sizeof(struct DynArrayStack));

    dynStack = CreateDynStack(2);
    DynStackPush(dynStack,1);
    DynStackPush(dynStack,2);
    DynStackPush(dynStack,3);
    c = DynStackPop(dynStack);
    printf("Element Poped :: %d\n",c);
    DynStackPush(dynStack,4);
    DynStackPush(dynStack,5);
    DynStackPush(dynStack,6);
    c = DynStackPop(dynStack);
    printf("Element Poped :: %d\n",c);
    DeleteDynStack(dynStack);
*/
    return 0;
}
