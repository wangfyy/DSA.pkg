//DSC-���еĶ��������/���Ӳ���-���� 

typedef int Position;
struct QNode{
	ElementType *Data;
	Position Front,Rear;
	int MaxSize;
}; 
typedef struct QNode *Queue;
Queue CreateQueue(int MaxSize){
	//�������д��룬�ľߴ�����
	Queue Q=(Queue)malloc(sizeof(struct QNode));	//����Q 
	Q->Data=(ElementType *)malloc(Maxsize*sizeof(ElementType));	//����Q���ڲ�(Data/Front/Rear) 
	Q->Front=Q->Rear=0;
	Q->MaxSize=MaxSize;
	return Q;
}

bool IsFulll(Queue Q) return ((Q->Rear+1)%Q->MaxSize==Q->Front);//ѭ�����е���ʽ����ĳ��������Ԫ�صĸ������� 


bool AddQ(Queue Q,ElementType X){
	if(IsFull(Q)){
		printf("������")��
		return false; 
	}else{
		Q->Rear=(Q->Rear+1)%Q->MaxSize;//ѭ�����е���ʽ����ĳ��������Ԫ�صĸ������� 
		Q-Data[Q->Rear]=X;
		return ture;
	}
}

bool IsEmpty(Queue Q) return (Q->Rear==Q->Front);

ElementType Delete(Queue Q){
	if(IsEmpty(Q)){
		printf("���п�")��
		return ERROR; 
	}else{
		Q->Front=(Q->Front+1)%Q->MaxSize;//ѭ�����е���ʽ����ĳ��������Ԫ�صĸ������� 
		return Q->Data[Q->Front];
	}
}












