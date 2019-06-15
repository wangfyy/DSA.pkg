Sort with Swap(0,*) (25)

Given any permutation of the numbers {0, 1, 2,..., N-1}, 
it is easy to sort them in increasing order. 
But what if Swap(0, *) is the ONLY operation that is allowed to use? 
For example, to sort {4, 0, 2, 1, 3} we may apply the swap operations in the following way:

Swap(0, 1) => {4, 1, 2, 0, 3}
Swap(0, 3) => {4, 1, 2, 3, 0}
Swap(0, 4) => {0, 1, 2, 3, 4}

Now you are asked to find the minimum number of swaps need to sort the given permutation of the first N nonnegative integers.

Input Specification:

Each input file contains one test case, 
which gives a positive N (<=105) followed by a permutation sequence of {0, 1, ..., N-1}. 
All the numbers in a line are separated by a space.

Output Specification:

For each case, simply print in a line the minimum number of swaps need to sort the given permutation.



10 
        3 5 7 2 6 4 9 0 8 1
(index: 0 1 2 3 4 5 6 7 8 9)

9



Thinking: 不断swap(0的位置，0的位置的数所在位置)，(即：以0为交换子，交换一个便使得顺序正确一个，例如：第一趟是交换0和7)
Postscript： 解决0在原位时的陷入

感觉没用到贪心呀，，可能“swap(0的位置，0的位置的数所在位置)”这个方案叫贪心。。。


#include <cstdio>
#include <algorithm>
using namespace std;

int N, a[100010], num = 0;

int findANumber() {  // find a number that wrong, return its index
	for(int i=0; i<N; i++) {
		if(a[i] != 0 && a[i] != i) return i;
	}
	return -1;
}

int findTheNumberIndex(int x) {  // find x's index
	for(int i=0; i<N; i++) {
		if(a[i] == x) return i;
	}
}

int find0Index() {  // find 0's index
	for(int i=0; i<N; i++) {
		if(a[i] == 0) return i;
	}
}

void print() {
	printf("\n");
	for(int i=0; i<N; i++) {
		printf("%d ",a[i]);
	}
	printf("\n");
}

void swap(int index1, int index2) {
	int temp = a[index1];
	a[index1] = a[index2];
	a[index2] = temp;
	num++;
	//print();
}

int main() {
	scanf("%d",&N);
	for(int i=0; i<N; i++) {
		scanf("%d",&a[i]);
	}

	int i = find0Index();
	while(1) {
		if(i == 0) {
			int y = findANumber();
			if(y == -1) {
				printf("%d",num);
				return 0;  //如果0在原位，其他全部都在原位上，则为有序即返回
			}
			swap(i,y);  //如果0在原位，则将0和任意一个不在原位上的数字交换，避免陷入
			i = y;
		}
		int j = findTheNumberIndex(i);
		swap(i,j);
		i = j;  //////更新0的位置
	}

	return 0;
}