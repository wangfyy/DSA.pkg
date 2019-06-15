//DSC-队列的定义与出队操作-链式 

struct Node{
	ElementType Data;	//ElementType为元素类型 
	PtrToNode Next;
};
typedef struct Node *PtrToNode;
typedef PrtToNode Position;	//定义Position为指向节点(Node)的指针 
struct QNode{
	Position Front,Rear;	//链表的头做删除操作，尾做插入操作 
	int MaxSize;
};
typedef struct QNode *Queue;

bool IsEmpty(Queue Q) return(Q->Front==NULL);	//队链的入队过程？？ ：初始化为Front=Rear 

ElementType DeleteQ(Queue Q){
	Position FrontCell;
	ElementType FrontElem;
	
	if(IsEmpty(Q)){
		printf("队列空");
		return ERROR; 
	}else{
		FrontCell=Q->Front;
		
		if(Q->Front==Q->Rear){	//若队列里只有一个元素 
			Q->Front==Q->Rear==NULL;
		} else{
			Q->Front==Q->Front->next;
		}	
		
		FrontElem=FrontCell;
		free(FrontCell);
		return FrontElem； 	
		 
	}
}
