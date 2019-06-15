//测试程序 

#include <cstdio>
#include <time.h>
#include <math.h>

#define GET_ARRAY_LEN(array,len) {len = (sizeof(array)/sizeof(array[0]));}
#define MAXK 1e7

clock_t start,stop;		//最大重复调用次数
void printfA(int *A,int n) {
	for(int i=0;i<n;i++)
		printf("%d ",A[i]);
	printf("\n");
}

void insertSort1(int *A,int n){
	for(int i=1;i<=n-1;i++){
		int temp=A[i];
		for(int j=i;j>=1;j--){
			if(A[j-1]>temp){
				A[j]=A[j-1];
				A[j-1]=temp;
			}else{
				break;
			}
		}
	}
	//printfA(A,n);
}

void insertSort2(int *A,int n){
	for(int i=1;i<=n-1;i++){
		int temp=A[i];
		for(int j=i;j>=1;j--){
			if(A[j-1]>temp){
				A[j]=A[j-1];
				A[j-1]=temp;
			}
		}
	}
	//printfA(A,n);
}

int main(){ 
	int A[40]={200,190,180,170,160,150,140,130,120,110,100,90,80,70,60,50,40,30,20,10,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	
	int len;
	GET_ARRAY_LEN(A,len);
	int n=len;
	
	
	start=clock();
	for(int i=0;i<MAXK;i++)
		insertSort1(A,n);
	stop=clock();
	double duration1=((double)(stop-start))/CLK_TCK/MAXK;	//单次调用的时间
	printf("%6.2e\n", duration1);

	start=clock();
	for(int j=0;j<MAXK;j++)
		insertSort2(A,n);
	stop=clock();
	double duration2=((double)(stop-start))/CLK_TCK/MAXK;
	printf("%6.2e\n", duration2);
	
	
	return 0;
}


