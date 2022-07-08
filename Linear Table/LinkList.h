#ifndef _linklist
#define _linklist
#include "cstddef"

//在调用头文件前需要声明数据格式
//typedef int ElemType;

//这个头文件是单链表的实现，包含了初始化、头插入、尾插入、、
//获取第i个节点、获取值为e的节点、在第i个节点前插入、删除第i个节点的操作
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode,*LinkList;

//  带头节点的链表 头节点是L
void Init_LinkList(LinkList &L){
    L = new LinkNode;
    L->next = NULL;
    L->data = 0;    //头节点 data用来存储表长
}

void List_HeadInsert(LinkList &L,ElemType e){  
    //在头节点和第一个节点之间插入一个节点。
    if(L){
        LinkNode *p = new LinkNode;
        p->data = e;
        p->next = L->next;
        L->next = p;
        L->data++;
    }else{
        std::cout<<"You don't have LinkList Head Node"<<std::endl;
    }
}

void List_TailInsert(LinkList &L,ElemType e){ 
    //在链表的最后一个节点后面 再加一个节点
    LinkNode *r = L;
    LinkNode *p;
    while(r->next) r = r ->next;
    p = new LinkNode;
    p->data = e;
    p->next = NULL;
    r->next = p;
    L->data++;
}

LinkNode *GetElem(LinkList L, int i){
    // 在链表中查找第i个元素


    // 跳到第一个节点
    LinkNode *p = L->next;
    if(i==1) return p;
    if(i<1) return NULL;
    int j = 1;
    while(j<i & p!=NULL){
        p = p->next;
        j++;
    }
    return p;
}

LinkNode *LocateElem(LinkList L, ElemType e){
    //按值查找元素
    LinkNode *p = L->next;
    while(p!=NULL & p->data!=e) p=p->next;
    return p;
}

bool ListInsert(LinkList &L,int i,ElemType e){
    if(i<1 | i>L->data) return NULL; //这里不允许查找头节点
    LinkNode *s;
    LinkNode *p = new LinkNode;
    p->data = e;
    s = GetElem(L,i-1);
    p->next = s->next;
    s->next = p;
    L->data++;
    return true;
}

bool Delete_Node_Order(LinkList &L,int i){
    //删除第i个节点
    if(i<1 | i>L->data) return NULL; //这里不允许删除头节点
    LinkNode *p,*r; 
    p = GetElem(L,i-1);
    r = p->next;
    p = r->next;
    delete r;
    L->data--;
    return true;
}


#endif