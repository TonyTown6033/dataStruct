#include <iostream>

typedef int ElemType;
#include "LinkList.h"

using namespace std;
int main(){
    LinkList L;
    int a = 5;
    Init_LinkList(L);
    List_HeadInsert(L,a);
    LinkList p=L->next;
    cout<<p->data<<endl;
    return 0;
}