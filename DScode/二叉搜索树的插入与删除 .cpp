//二叉搜索树的插入与删除 

BinTree Insert(BinTree BST,ElementType X){
	if(!BST){
		BST=(BinTree)malloc(sizeof(struct TNode));
		BST->Data=X;
		BST->Left=BST->Right=NULL;
	}else{
		if(X<BST->Data) 
			BST->Left=Insert(BST->Left,X);
		else if(X>BST->Data) 
			BST->Right=Insert(BST->Right,X);
	}
	return BST;
}

BinTree Delete(BinTree BST,ElementType X){
	Position Tmp;
	if(!BST){
		printf("要删除的元素没找到")； 
	}else{
		if(X<BST->Data)
			BST->Left=Delete(BST->Left,X)
		else if(X>BST->Data)
			BST->Right=Delete(BST->Right,X)
		else{
			if(BST->Left && BST->Right){
				Tmp=FindMin(BST->Right);
				BST->Data=Tmp->Data;
				BST->Right=Delete(BST->Right,BST->Data)
			}else{
				Tmp=BST;
				if(!BST->Left)	//没有左孩子 (有右孩子或无子节点)
					BST=BST->Right;
				else
					BST=BST->Left;	//有左孩子 (有左孩子或无子节点)
				free(Tmp);
					
			}
		}
	}
	return BST;
}
