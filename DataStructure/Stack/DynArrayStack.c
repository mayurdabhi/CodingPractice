struct DynArrayStack{
    int capacity;
    int top;
    int *arrayStack;
};

struct DynArrayStack  *CreateDynStack(int capacity){

    struct DynArrayStack *s = malloc(sizeof(struct DynArrayStack));

    if(!s){
        return NULL;
    }
    s->capacity = capacity;
    s->top = -1;
    s->arrayStack = malloc(s->capacity*sizeof(int));

    if(s->arrayStack == NULL){
        return NULL;
    }
    printf("Stack is created Successfully!\n");
    return s;

};

void DoubleStackSize(struct DynArrayStack *s)
{
    s->capacity *=2;
    s->arrayStack =realloc(s->arrayStack,s->capacity);

}
int IsDynStackFull(struct DynArrayStack *s){
    return (s->top == s->capacity-1);
}

int IsDynStackEmpty(struct DynArrayStack *s){
    return (s->top <0);
}

int DynStackPop(struct DynArrayStack *s){
    if(IsDynStackEmpty(s)){
        printf("Stack UnderFlow!!\n");
        return INT_MIN;
    }
    else
    {
        return s->arrayStack[s->top--];
    }
}

void DynStackPush(struct DynArrayStack *s, int data){
    if(IsDynStackFull(s))
    {
        printf("Stack is OverFlow, increasing Stack Size!!\n");
        DoubleStackSize(s);
    }
    s->arrayStack[++s->top]=data;
}

void DeleteDynStack(struct DynArrayStack *s){
    if(s){
        if(s->arrayStack){
            free(s->arrayStack);
        }
        free(s);
    }
}
