//DSC-树的遍历（4种） 

struct TNode{
	ElementType Data;
	BinTree Left;
	BinTree Right;
};
typedef struct TNode *Position;
typedef Position BinTree;

void InorderTraversal(BinTree BT){
	if(BT){
		InorderTraversal(BT->Left);
		printf("%d",BT->Data);
		InorderTraversal(BT->Right);
	}
}

void PreorderTraversal(BinTree BT){
	if(BT){
		printf("%d",BT->Data);
		PreorderTraversal(BT->Left);
		PreorderTraversal(BT->Right);
	}
}

void PostorderTraversal(BinTree BT){
	if(BT){
		PostorderTraversal(BT->Left);
		PostorderTraversal(BT->Right);
		printf("%d",BT->Data);
	}
}

void LevelorderTraversal(BinTree Bt){	//层序遍历 
	Queue Q;
	BinTree T;
	
	if(!BT) return;
	
	Q=CreatQueue();
	Add(Q,BT);	//BT为树的头结点 
	while(!IsEmpty(Q))	//循环：出一个（父），入两个（左右子树） 
		T=DeleteQ(Q);
		Printf("%d",T-Data);
		if(T-Left) Add(Q,T->Left);
		if(T-Right) Add(Q,T->Right);
}




















