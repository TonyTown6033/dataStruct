#include <iostream>

typedef int ElemType;
#include "LinkList.h"
#include "examwork.h"

using namespace std;
int main(){
    LinkList L;
    int a=3,b=5;
    Init_test(L);
    cout<<L->data<<endl;
    exam9(L);
    print_List(L);
    return 0;
}