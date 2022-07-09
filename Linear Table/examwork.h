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
    int arr[11]={4,4,4,7,8,11,11,52,52,52,55};
    for(i=0;i<11;i++){
        List_TailInsert(L,arr[i]);
    }
   // print_List(L);
}

void Init_Test_2(LinkList &L,int a[],int len){
    Init_LinkList(L);
    for(int i=0;i<len;i++){
        List_TailInsert(L,a[i]);
    }
    //print_List(L);
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

//8.找两个链表的第一个公共节点(未测试)
void Init_Cross_LinkList(LinkList &A,LinkList &B){
    LinkList C;
    int c[]={5,6,7};
    int lenC=3;
    Init_Test_2(C,c,lenC);
    int a[]={1,2,3,4};
    int lenA=4;
    int b[]={9,8};
    int lenB=2;
    Init_Test_2(A,a,lenA);
    Init_Test_2(B,b,lenB);
    LinkNode *p,*r;
    p = A->next;
    r = B->next;
    while (p->next) p = p->next;
    while (r->next) r = r->next;
    p->next = C->next;
    r->next = C->next;
    C->next = NULL;
}



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
            flag = true;
        }else{
            flag = NULL;
        }
    }
    shareNode = arr1[top1+1];
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

//10. 将链表A分成两个A&B，A保存序号为奇数的节点，B保存偶数节点
void exam10(LinkList &A,LinkList &B){
    Init_LinkList(B);
    LinkNode *p = A->next,*pre = A;
    int flag=0;
    while(p){
        if(flag==1){
            flag=0;
        // 在B中添加这个节点
            List_TailInsert(B,p->data);
        // 在A中删除这个节点

            if(p->next) p->data = p->next->data;
            pre->next = p->next;
            delete p;
            p = pre;
        }else{
            flag=1;
        }
        pre = p;
        p = p ->next;
    }
}

//11. C={a1,b1,a2,b2,...,an,bn} 将它拆成两个链表A&B
// 其中 A={a1,a2,..,an} B={bn,...,b2,b1}
// 要求空间复杂度为O(1)
void exam11(LinkList C,LinkList &A,LinkList &B){
    Init_LinkList(A);
    Init_LinkList(B);
    LinkNode *p=C->next;
    int flag=0;
    while(p){
        if(flag==0){
            flag=1;
            List_TailInsert(A,p->data);
        }else{
            flag=0;
            List_HeadInsert(B,p->data);
        }
        p = p->next;
 }
}

//12.去除递增有序单链表内的重复元素
void exam12(LinkList &L){
    LinkNode *p=L->next;
    LinkNode *pre=L;
    while(p->next){
        pre=p;
        p=p->next;
        if(pre->data==p->data){
            pre->next = p->next;
            pre->data = p->data;
            delete p;
            p = pre;
        }
    }
}

//13.讲两个递增的单链表合并成一个递减的单链表，要求不删除并利用原始的链表节点。
//NOT PASS
void exam13(LinkList &A,LinkList &B,LinkList &C){
    Init_LinkList(C);
    LinkNode *p=A->next;
    LinkNode *r=B->next;
    LinkNode *t=C;
 
    LinkNode *Stack[MAXSIZE];
    int top=-1;
 
    while(p!=NULL ||  r!=NULL){
        if(p->data <= r->data){
        Stack[++top] = p;
        p = p ->next;
    }else{
        Stack[++top] = r;
        r = r->next;
    }
    }
 
    while(top>=0){
        t->next = Stack[top--];
    }
 
    A->next = NULL;
    B->next = NULL;
    
}



//14.将两个递增的单链表中公共的部分，提出来并且不破坏原始链表
LinkList exam14(LinkList A,LinkList B){
    LinkNode *p;
    p = SameNode(A,B);
    return p;
}

//15.求两个有序(递增)链表的交集
//NOT PASS
LinkList mixed(LinkList A,LinkList B){
    LinkNode *r_Head;
    Init_LinkList(r_Head);
    LinkNode *r=r_Head;
    LinkNode *p=A->next,*t=B->next;
    LinkNode *temp;
    ElemType value;
    
    while(p!=NULL & t!=NULL){
        if(p->data==t->data){
            temp = NULL;
            temp = new LinkNode;
            temp->data =p->data;
            r->next = temp;
            r = r->next;
        }else if(p->data<t->data){
            if(p->next){
                p=p->next;
                value = p->data;
            }else{
                break;
            } 
        }else if(p->data>t->data){
            if(t->next){
                t = t ->next;
                value = t->data;
            }else{
                break;
            }
        } 
    }
 
    return r_Head;
}


//16. 有2个整数序列A&B，判断B是否是A的连续子序列
bool exam16(LinkList A, LinkList B){
    //初始化一个队列
    LinkNode *Queue[MAXSIZE];
    int rear=-1,front=-1;
    
    //将B装入队列
    LinkNode *p = B->next;
    while(p){
        Queue[++rear] = p;
        p = p->next;
    }
 
    p = A->next;
    while(p!=NULL & (front<rear)){
        if(p->data == Queue[++front]->data){
            p = p->next;
        }else{
            p = p->next;
            front = -1;  
        }
    }
    //如果队列为空
    if(!(front<rear)) return true;
    return NULL;
}

// 17. 判断带头节点的循环双链表是否对称


// 22.查找单链表倒数第k个位置上的节点，并输出data
int exam22(LinkList L,int k){
    LinkNode *Stack[MAXSIZE];
    int top=-1;
    LinkNode *p=L->next;
    while(p){
        Stack[++top] = p;
        p = p->next;
    }
 
    if(k>top+1) return 0;
 
    for(int i=1;i<=k;i++)  p = Stack[top--];
    std::cout<<p->data<<std::endl;
    return 1;
}

//23. 
//NOT PASS
LinkNode *exam23(LinkList str1,LinkList str2){
    LinkNode *Stack1[MAXSIZE];
    LinkNode *Stack2[MAXSIZE];
    int top1=-1,top2=-1;
    LinkNode *p,*r;
    p = str1->next;
    r = str2->next;
 
    while(p){
        Stack1[++top1] = p;
        p = p->next;
    }
 
    while(r){
        Stack2[++top2] = r;
        r = r->next;
    }
    p=Stack1[top1];r=Stack2[top2];
    while(top1>=0 & top2>=0){
        if(!p->data==r->data) break;
        p = Stack1[--top1];
        r = Stack2[--top2];
       
    }
    LinkNode *rt;
    rt = Stack2[top2+2];//??????
    
    return rt;
}

//24.
int abs(int a){
    if(a>=0) return a;
    else return -a;
}

void exam24(LinkList &L){
 //构造一个辅助数组 特点是a[n] 
    int a[MAXSIZE];
    int temp;
    LinkNode *p;
    int i;

    for(i=0;i<MAXSIZE;i++){
        a[i] = 0;
    }

 //处理链表 同时初始化数组
    p = L->next;
    LinkNode *pre=L,*pre0=L;
    LinkNode *dNode;
    while(p){
        temp = p->data;
        temp = abs(temp);
        
        if(a[temp]==0) {
            a[temp] =1;
        }else if(a[temp]==1){
            if(p->next){
                dNode = p->next;
                //这两行叫交代后事
                p->data = dNode->data;    
                p->next = dNode->next;
                delete dNode;
                L->data--;
                p = pre;
            }else{
                pre->next = NULL;
                delete p;
                L->data--;
                p = pre;
            }
        }        
        pre = p;
        p = p->next;
    }
/*
    for(i=0;i<20;i++){
        std::cout<<a[i]<<' ';
    }
 */
}

//25.

LinkList exam25(LinkList L){
    //初始化队列
    ElemType Queue[MAXSIZE];
    int rear=-1,front=-1;
    LinkNode *p=L->next;

    while(p){
        Queue[++rear] = p->data;
        p = p->next;
    }
 
    LinkNode *rt_head;
    Init_LinkList(rt_head);
    LinkNode *rt=rt_head;
    LinkNode *Node_I;

    int flag=0;
    int temp;
    while(front<rear){
        if(flag==0){
            flag = 1;
            temp = Queue[++front];
        }else if(flag==1){
            flag=0;
            temp = Queue[rear--];
        }
        Node_I = NULL;
        Node_I = new LinkNode;
        Node_I->data = temp;
        Node_I->next = NULL;
        rt->next = Node_I;
        rt = rt->next;
        
    }
    return rt_head;
}

#endif