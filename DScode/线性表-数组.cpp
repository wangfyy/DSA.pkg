//线性表的定义与操作-顺序表（数组实现） 


typedef int Position;
typedef struct LNode *List;	//指针别名 
struct LNode {
    ElementType Data[MAXSIZE];	//定义存放ElementType类型元素的数组，长度为 MAXSIZE
    Position Last;	//最后一个元素的下标 
};
 
/* 初始化 */
List MakeEmpty()
{
    List L;	//定义指向结构体LNode(List类型)的指针 
 
    L = (List)malloc(sizeof(struct LNode));	//为指针指向的开辟空间 
    L->Last = -1;
 
    return L;
}
 
/* 查找 */
#define ERROR -1
 
Position Find( List L, ElementType X )
{
    Position i = 0;
 
    while( i <= L->Last && L->Data[i]!= X )
        i++;
    if ( i > L->Last )  return ERROR; /* 如果没找到，返回错误信息 */
    else  return i;  /* 找到后返回的是存储位置 */
}
 
/* 插入 */
/*P是存储下标位置（从0开始）*/
bool Insert( List L, ElementType X, Position P ) 
{ /* 在L的指定位置P前插入一个新元素X */
    Position i;
 
    if ( L->Last == MAXSIZE-1) {
        /* 表空间已满，不能插入 */
        printf("表满"); 
        return false; 
    }  
    if ( P<0 || P>L->Last+1 ) { /* 检查插入位置的合法性 */	//P=Last+2不行 
        printf("位置不合法");
        return false; 
    } 
    for( i=L->Last; i>=P; i-- )	//注意顺序
        L->Data[i+1] = L->Data[i]; /* 将位置P及以后的元素顺序向后移动 */
    L->Data[P] = X;  /* 新元素插入 */
    L->Last++;       /* Last仍指向最后元素 */
    return true; 
} 
 
/* 删除 */
/*P是存储下标位置（从0开始）*/
bool Delete( List L, Position P )
{ /* 从L中删除指定位置P的元素 */
    Position i;
 
    if( P<0 || P>L->Last ) { /* 检查空表及删除位置的合法性 */
        printf("位置%d不存在元素", P ); 
        return false; 
    }
    for( i=P+1; i<=L->Last; i++ )	//注意顺序 
        L->Data[i-1] = L->Data[i]; /* 将位置P+1及以后的元素顺序向前移动 */
    L->Last--; /* Last仍指向最后元素 */
    return true;   
}
