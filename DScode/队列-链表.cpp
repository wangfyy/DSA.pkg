//DSC-���еĶ�������Ӳ���-��ʽ 

struct Node{
	ElementType Data;	//ElementTypeΪԪ������ 
	PtrToNode Next;
};
typedef struct Node *PtrToNode;
typedef PrtToNode Position;	//����PositionΪָ��ڵ�(Node)��ָ�� 
struct QNode{
	Position Front,Rear;	//�����ͷ��ɾ��������β��������� 
	int MaxSize;
};
typedef struct QNode *Queue;

bool IsEmpty(Queue Q) return(Q->Front==NULL);	//��������ӹ��̣��� ����ʼ��ΪFront=Rear 

ElementType DeleteQ(Queue Q){
	Position FrontCell;
	ElementType FrontElem;
	
	if(IsEmpty(Q)){
		printf("���п�");
		return ERROR; 
	}else{
		FrontCell=Q->Front;
		
		if(Q->Front==Q->Rear){	//��������ֻ��һ��Ԫ�� 
			Q->Front==Q->Rear==NULL;
		} else{
			Q->Front==Q->Front->next;
		}	
		
		FrontElem=FrontCell;
		free(FrontCell);
		return FrontElem�� 	
		 
	}
}
