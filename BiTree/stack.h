#ifndef stack_
#define stack_
#include "cstddef"

typedef struct StackNode
{
    ElemTypeS data;
    struct StackNode *pre;
    struct StackNode *top;
}StackNode,*Stack;

Stack InitStack(Stack &S){
    S = new StackNode;
    S->pre = NULL;
    S->top = NULL;
    return S;
}

void Push(Stack &S, ElemTypeS e){
    Stack add_elem = new StackNode;
    add_elem->data = e;
    add_elem->pre = S->top;
    S->top = add_elem;
}

void Pop(Stack &S, ElemTypeS &p){
    if(S->top){
        p = S->top->data;
        if(S->top->pre){
            S->top = S->top->pre;
        }else{
            S->top = NULL;
        }
    }else{
        p = NULL;
    }
}

void GetTop(Stack S, ElemTypeS &p){
    if(S->top) p = S->top->data;
    else p = NULL;
}
bool isEmpty(Stack S){
    if(S->top==S->pre) return true;
    else return NULL;
}









#endif