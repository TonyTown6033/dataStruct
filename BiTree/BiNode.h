#ifndef _BiNode
#define _BiNode
#define MAXSIZE 100

typedef char ElemTypeB;

typedef struct BiNode
{
    ElemTypeB data;
    struct BiNode *lchild;
    struct BiNode *rchild;
}BiNode,*BiTree;

void visit(ElemTypeB e);
// 递归遍历的方法
void PreOrder(BiTree T){
    BiTree p=T;
    if(p){
        visit(p->data);
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

void InOrder(BiTree T){
    BiTree p=T;
    if(p){
        InOrder(p->lchild);
        visit(p->data);
        InOrder(p->rchild);
    }
}

void PostOrder(BiTree T){
    BiTree p=T;
    if(p){
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        visit(p->data);
    }
}


// 非递归的实现
typedef BiTree ElemTypeS;
#include "stack.h"

void PreOrder2(BiTree T){
    Stack S;
    InitStack(S);
    BiTree p = T;
    while(p || !isEmpty(S)){
        if(p){
            Push(S,p);
            visit(p->data);
            p = p -> lchild;
        }else{
            Pop(S,p);
            if(p->rchild) p=p->rchild;
            else p = NULL;
        }
    }
}

void InOrder2(BiTree T){
    Stack S;
    InitStack(S);
    BiTree p = T;
    while(p || !isEmpty(S)){
        if(p){
            Push(S,p);
            p = p->lchild;
        }else{
            Pop(S,p);
            visit(p->data);
            if(p->rchild) p = p->rchild;
            else p = NULL;
        }
    }
}

void PostOrder2(BiTree T){
    Stack S;
    InitStack(S);
    BiTree p = T;
    BiTree r = NULL;
    while(p || !isEmpty(S)){
        if(p){
            Push(S,p);
            p = p->lchild;
        }else{
            GetTop(S,p);
            if(p->rchild && p->rchild!=r){
                 p = p->rchild;
            }else{
                Pop(S,p);
                visit(p->data);
                r = p;
                p = NULL;
            }
        }
    }

}

//  层次遍历

void LayerOrder(BiTree T){
    BiTree p;
    int front=-1,rear=-1;
    BiTree Nodes[MAXSIZE];
    if(T){
        Nodes[++rear] = T;
        while(front<rear){
            p = Nodes[++front];
            visit(p->data);
            if(p->lchild) Nodes[++rear] = p->lchild;
            if(p->rchild) Nodes[++rear] = p->rchild;
        }
    }
}

int Depth(BiTree T){
    BiTree p;
    int front=-1,rear=-1;
    int depth = 0;
    int r;
    BiTree Nodes[MAXSIZE];
    if(T){
        Nodes[++rear] = T;
        r = rear;
        while (front<rear){
            p = Nodes[++front];
            if(p->lchild) Nodes[++rear] = p->lchild;
            if(p->rchild) Nodes[++rear] = p->rchild;
            if (front == r){
                depth++;
                r = rear;
            }
        }
    }
    return depth;
}

#endif