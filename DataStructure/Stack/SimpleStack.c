struct SimpleStack{
    int capacity;
    int top;
    int *arrayStack;
};

struct SimpleStack  *CreateStack(int capacity){

    struct SimpleStack *s = malloc(sizeof(struct SimpleStack));

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

int IsStackFull(struct SimpleStack *s){
    return (s->top == s->capacity-1);
}

int IsStackEmpty(struct SimpleStack *s){
    return (s->top <0);
}

int Pop(struct SimpleStack *s){
    if(IsStackEmpty(s)){
        printf("Stack UnderFlow!!\n");
        return INT_MIN;
    }
    else
    {
        return s->arrayStack[s->top--];
    }
}

void Push(struct SimpleStack *s, int data){
    if(IsStackFull(s))
    {
        printf("Stack Overflow!!\n");
    }
    else
    {
        s->arrayStack[++s->top]=data;
    }
}

void DeleteStack(struct SimpleStack *s){
    if(s){
        if(s->arrayStack){
            free(s->arrayStack);
        }
        free(s);
    }
}

void InsertAtBottom(struct SimpleStack *s, int d ){

    if(IsStackEmpty(s)){
        Push(s,d);
        return;
    }
    else{
        int temp = Pop(s);
        InsertAtBottom(s,d);
        Push(s,temp);
    }
}
//O(n^2) time and O(n) space complexity
//Reverse stack using only push pop, you are not alloweded to use any other stack
int ReverseStack(struct SimpleStack *s){

    if(IsStackEmpty(s)){
       return ;
    }
    int data = Pop(s);
    ReverseStack(s);
    InsertAtBottom(s,data);
}
