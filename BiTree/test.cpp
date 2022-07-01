#include "iostream"
#include "BiNode.h"

void visit(ElemType e){
	std::cout<<e<<' ';
}

void InitTestTree(BiTree &A){
	A->data = 'A';
	BiTree B = new BiNode;
	A->lchild = B;
	B->data = 'B';
	BiTree C = new BiNode;
	A->rchild = C;
	C->data = 'C';
	BiTree D = new BiNode;
	B->lchild = D;
	D->data = 'D';
	BiTree E = new BiNode;
	B->rchild = E;
	E->data = 'E';
	BiTree G = new BiNode;
	E->rchild = G;
	G->data = 'G';
	BiTree F = new BiNode;
	C->rchild = F;
	F->data = 'F';

}

using namespace std;
int main(){
	BiTree T = new BiNode;
	InitTestTree(T);
	cout<<"NLR is :";
	PreOrder2(T);
	cout<<endl;
	cout<<"LNR is :";
	InOrder2(T);
	cout<<endl;
	cout<<"LRN is :";
	PostOrder2(T);
	cout<<endl;
	cout<<"the depth is "<<Depth(T)<<endl;
	return 0;
}
