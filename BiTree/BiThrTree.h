#ifndef _BiThrTree
#define _BiThrTree

typedef char ElemTypeBT;
void print_T(ElemTypeBT e);
typedef struct BiThrNode
{
    ElemTypeBT data;
    BiThrNode *lchild,*rchild;
    int ltag=0,rtag=0;
}BiThrNode,*BiThrTree;

BiThrTree pre;

void visit(BiThrTree &T){
    if(!T->lchild){
        T->lchild = pre;
        T->ltag = 1;
    }
    if(pre){
        if(!pre->rchild){
            pre->rchild = T;
            pre->rtag = 1;
        }
    }
    pre = T;
}

void InThreading(BiThrTree &p){
    if(p){
        if(p->ltag==0) InThreading(p->lchild);
        visit(p);
        if(p->rtag==0) InThreading(p->rchild);
    }
}

void InOrderTraverse_Thr(BiThrTree &T){
    if(T){
        pre = nullptr;
        InThreading(T);
        pre->rtag==1;
        pre->rchild=nullptr;
    }
}

BiThrTree FirstNode(BiThrTree p){
    if(p){
        while (p->ltag==0) p = p->lchild;
        return p;
    }
    return nullptr;
}

BiThrTree NextNode(BiThrTree p){
    if(p->rtag==1) return p->rchild;
    else return FirstNode(p->rchild);
}

void InOrderPrint(BiThrTree T){
    for(BiThrNode *p=FirstNode(T);p!=nullptr;p=NextNode(p)){
        print_T(p->data);
    }
}




#endif