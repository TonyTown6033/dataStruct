#ifndef _homework
#define _homework
typedef int ElemType;
#include "LinkList.h"
#define MAXSIZE 200


void print_List(LinkList L){
    LinkNode *p = L->next;
    while (p!=NULL)
    {
        std::cout<<p->data<<' ';
        p = p ->next;
    }
    std::cout<<std::endl;
}

void Init_test(LinkList &L){
    //建立一个测试链表 链表的内容是
    // 头节点->5->6->9->7->4->5->5->6
    Init_LinkList(L);
    int i;
    int arr[8]={11,52,55,4,4,4,7,8};
    for(i=0;i<8;i++){
        List_TailInsert(L,arr[i]);
    }
    print_List(L);
}

//1.删除单链表中所有值为x的节点
void exam1(LinkList &L,ElemType x){
    LinkNode *p=L->next;
    LinkNode *temp,*pre;
    while(p!=NULL){
        if(p->data==x){
            if(p->next!=NULL){
                temp = p->next;
                while(temp->data==x & temp!=NULL){
                    pre = temp;
                    temp = temp->next;
                    delete pre;
                    L->data--;
                }
                p->data = temp->data;
                p->next = temp->next;
                delete temp;

            }else{
                pre->next = NULL;
                delete p;
                L->data--;
            }
        }
        pre = p;
        p = p->next;
    }
}

//3.反向输出链表元素
void reverse_output(LinkList L){    
    // 定义一个Stack
    ElemType arr[MAXSIZE];
    int top=-1;
    LinkNode *p = L->next;
    //Push LinkList into Stack
    while(p){
        arr[++top] = p->data;
        p = p->next;
    }
    //Pop Stack Elem
    while (top>=0)
    {
        std::cout<<arr[top--]<<' ';
    }  

    std::cout<<std::endl;
}

//4.删除链表中的最小值节点
void exam4(LinkList &L){
    LinkNode *min=L->next,*pre=L,*temp;
    LinkNode *p = L->next;
    while(p){
        if(p->data <= min->data) {
            min = p;
            temp = pre;
        }
        pre = p;
        p = p->next;
    }
    if(min->next){
        temp = min->next;
        min->data = temp->data;
        min->next = temp->next;
        delete temp;
        L->data--;
    }else{
        temp->next = NULL;
        delete min;
        L->data--;
    }
}

//5.就地逆置链表 要求空间复杂度为O(1)
void swap(LinkList &r,LinkList &t){
    ElemType temp;
    temp = r->data;
    r->data = t->data;
    t->data = temp;
}

void exam5(LinkList &L){
    LinkNode *r,*t;
    int i,j;
    int lenth = L->data;
    for(i=0,r=L->next;i<lenth;i++,r=r->next){
        for(j=0,t=L->next;j<lenth-i-1;j++,t=t->next){
            swap(t,t->next);
        }
    }
}

//6.给单链表排序
void sort(LinkList &L){
    LinkNode *r,*t;
    int i,j;
    int lenth = L->data;
    for(i=0,r=L->next;i<lenth;i++,r=r->next){
        for(j=0,t=L->next;j<lenth-i-1;j++,t=t->next){
            if(t->data<t->next->data)   swap(t,t->next);
        }
    } 
}

//7.删除单链表中某个区间内的节点
void exam7(LinkList &L,ElemType low,ElemType high){
// 删除值在 low-high之间的节点
    LinkNode *p=L->next;
    LinkNode *temp,*pre;
    while(p!=NULL){
        if(p->data<=high && p->data>=low){
            if(p->next!=NULL){
                temp = p->next;
                while((temp->data<=high && temp->data>=low )& temp!=NULL){
                    pre = temp;
                    temp = temp->next;
                    delete pre;
                    L->data--;
                }
                p->data = temp->data;
                p->next = temp->next;
                delete temp;

            }else{
                pre->next = NULL;
                delete p;
                L->data--;
            }
        }
        pre = p;
        p = p->next;
    }
}

//8.找两个链表的公共节点(未测试)
LinkNode *SameNode(LinkList L1,LinkList L2){
    LinkNode *arr1[MAXSIZE],*arr2[MAXSIZE];
    int top1 = -1 , top2= -1;
    LinkNode *p1=L1->next,*p2=L2->next;
    while (p1){
        arr1[++top1] = p1;
        p1 = p1->next;
    }
    while (p2){
        arr2[++top2] = p2;
        p2 = p2->next;
    }

    LinkNode *shareNode=NULL;
    bool flag=true;
    while(flag){
        if(arr1[top1--]==arr2[top2--]){
            shareNode = arr1[top1+1];
            flag = true;
        }else{
            flag = NULL;
        }
    }
    
    return shareNode;
}

//9.以递增次序输出链表元素，并释放空间(要求不使用数组做辅助空间)
void exam9(LinkList &L){
    LinkNode *min=L->next,*pre=L,*temp;
    LinkNode *p = L->next;
    int lenth = L->data;
    int i;
    for(i=0;i<lenth;i++){
        min=L->next;
        pre=L;
        temp=NULL;
        p=L->next;
        
        while(p){
            if(p->data <= min->data) {
                min = p;
                temp = pre;
            }
            pre = p;
            p = p->next;
        }
        //访问最小节点
        std::cout<<min->data<<" ";
        //删除最小的节点
        if(min->next){
            temp = min->next;
            min->data = temp->data;
            min->next = temp->next;
            delete temp;
            L->data--;
        }else{
            temp->next = NULL;
            delete min;
            L->data--;
        }   
    }
    std::cout<<std::endl;
}



#endif