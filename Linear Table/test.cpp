#include <iostream>

typedef int ElemType;
#include "LinkList.h"
#include "examwork.h"

using namespace std;
int main(){
    LinkList L;
    LinkList A;
    LinkList B;
    int a[]={1,2,3,4,5,6,7,8,9,10,11};
    int b[]={3,4,5};
    int len1=11;
    int len2=3;
    Init_Cross_LinkList(A,B);
    print_List(A);
    print_List(B);
    L = exam23(A,B);
    print_List(L);
    return 0;
}