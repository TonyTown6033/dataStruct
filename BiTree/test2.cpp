#include "iostream"
#include "BiThrTree.h"

void print_T(ElemTypeBT e){
	std::cout<<e<<' ';
}

void InitTestTree(BiThrTree &A){    
    A = new BiThrNode;
    A->data = 'A';
	BiThrTree B = new BiThrNode;
	A->lchild = B;
	B->data = 'B';
	BiThrTree C = new BiThrNode;
	A->rchild = C;
	C->data = 'C';
	BiThrTree D = new BiThrNode;
	B->lchild = D;
	D->data = 'D';
	BiThrTree E = new BiThrNode;
	B->rchild = E;
	E->data = 'E';
	BiThrTree G = new BiThrNode;
	E->rchild = G;
	G->data = 'G';
	BiThrTree F = new BiThrNode;
	C->rchild = F;
	F->data = 'F';

}

using namespace std;
int main(){
	BiThrTree T ;
	InitTestTree(T);
    InOrderTraverse_Thr(T);
    InOrderPrint(T);
	return 0;

}
