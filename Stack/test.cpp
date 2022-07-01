#include "iostream"
#include "stack.h"
using namespace std;
int main(){
    Stack S = new StackNode;
    char p;
    InitStack(S);
    char e,r,t;
    e = 's';
    r = 'r';
    t = 't';
    Push(S,r);
    Push(S,e);
    Push(S,t);
    GetTop(S,p);
    cout<<p<<endl;
    Pop(S,p);
    cout<<p<<endl;
    Pop(S,p);
    cout<<p<<endl;
    Pop(S,p);
    cout<<p<<endl;
    Pop(S,p);
    cout<<p<<endl;
    if(isEmpty(S)) cout<<"the stack is Empty"<<endl;
    else cout<<"the stack is not Empty"<<endl;
 
    return 0;
}