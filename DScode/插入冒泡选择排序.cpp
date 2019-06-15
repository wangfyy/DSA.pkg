//简单排序：插入/冒泡/选择 

#include <cstdio>
#define GET_ARRAY_LEN(array,len) {len = (sizeof(array)/sizeof(array[0]));}

//输出函数
void printfA(int *A,int n) {
	for(int i=0;i<n;i++)
		printf("%d ",A[i]);
	printf("\n");
}

//插入排序：开始时一个元素自组一个有序序列，依次选中后面未序的序列中的每个元素，插到已序的序列中（此过程需要找合适的插入位置）。
void insertSort(int *A,int n){
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
	printfA(A,n);
}

//冒泡排序(最大数后置)
void mpSort(int *A,int n){
	for(int i=0;i<n-1;i++){  
	//外层循环控制的是次数，为什么是9：若10个元素，选了9次最大的，那你说剩下那个是什么
		for(int j=0;j<n-1-i;j++){
		//内层循环，从头开始锁定一个元素，将锁定的那个元素往后比较；为什么是9：因为跟a[j+1]比较
			int temp=A[j];
			if(A[j]>A[j+1]){
			 //若遇到大数，则交换，此大数继续往下比。即所谓：大数下沉		
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}
	}
	printfA(A,n);
}
//例子：
//NO.1次外层循环：7 6 5 9 8 4 3 2 1 0  -->  6 5 7 8 4 3 2 1 0 9。  (下次外层循环，只排前9个就行了)
//。。。

//选择排序(最小数提前)
void selectSort(int *A,int n){
	for(i=0;i<n-1;i++){
	//外层循环：因为j=i+1，所以依次从0~8元素(共9个元素)开始。
		for(j=i+1;j<n;j++){
		//内层循环：将（j=i+1;j<10）内的元素依次与a[i] (数值可能随着比较置换而变化) 比较，小的拿到a[i]前，大的不动。
			int temp=a[i];
			if(a[j]<a[i]){
			    a[i]=a[j];
			    a[j]=temp;        	
			}
		}
	}
	printfA(A,n);
} 
//例子：
//NO.1外层循环：
//7 6 5 9 8 4 3 2 1 0
//6 7 5 9 8 4 3 2 1 0
//5 6 7 9 8 4 3 2 1 0
//5 6 7 9 8 4 3 2 1 0
//5 6 7 9 8 4 3 2 1 0
//4 6 7 9 8 5 3 2 1 0
//3 6 7 9 8 5 4 2 1 0
//2 6 7 9 8 5 4 3 1 0
//1 6 7 9 8 5 4 3 2 0
//0 6 7 9 8 5 4 3 2 1 (至此，最小的元素已经在最前了（即：所谓的选择(选择最小的往前放)排序），所以进行下个外层循环直接从第二个元素开始) 


int main(){ 
	int A[]={10,9,8,7,6,5,4,3,2,1};
	
	int len;
	GET_ARRAY_LEN(A,len);
	int n=len;
	
	insertSort(A,n);
	mpSort(A,n);
	selectSort(A,n);
	
	return 0;
}
