//DSC-队列的定义与入队/出队操作-数组 

typedef int Position;
struct QNode{
	ElementType *Data;
	Position Front,Rear;
	int MaxSize;
}; 
typedef struct QNode *Queue;
Queue CreateQueue(int MaxSize){
	//下面两行代码，颇具代表性
	Queue Q=(Queue)malloc(sizeof(struct QNode));	//创建Q 
	Q->Data=(ElementType *)malloc(Maxsize*sizeof(ElementType));	//创建Q的内部(Data/Front/Rear) 
	Q->Front=Q->Rear=0;
	Q->MaxSize=MaxSize;
	return Q;
}

bool IsFulll(Queue Q) return ((Q->Rear+1)%Q->MaxSize==Q->Front);//循环队列的形式：（某东西）与元素的个数求余 


bool AddQ(Queue Q,ElementType X){
	if(IsFull(Q)){
		printf("队列满")；
		return false; 
	}else{
		Q->Rear=(Q->Rear+1)%Q->MaxSize;//循环队列的形式：（某东西）与元素的个数求余 
		Q-Data[Q->Rear]=X;
		return ture;
	}
}

bool IsEmpty(Queue Q) return (Q->Rear==Q->Front);

ElementType Delete(Queue Q){
	if(IsEmpty(Q)){
		printf("队列空")；
		return ERROR; 
	}else{
		Q->Front=(Q->Front+1)%Q->MaxSize;//循环队列的形式：（某东西）与元素的个数求余 
		return Q->Data[Q->Front];
	}
}












