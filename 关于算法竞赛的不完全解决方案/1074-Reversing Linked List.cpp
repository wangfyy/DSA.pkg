// 忏悔：此代码为假代码 !...  T_T
#include <cstdio>
const int maxn = 100010;
struct Node {
	int adress;
	int data;
	int next;
} arr_1[maxn], arr_2[maxn], arr_3[maxn];
int adress_first,N,K;
int findByadress_arr_1(int x) {

	for(int i=1; i<=N; i++) {
		if(arr_1[i].adress == x) return i;
	}
	//因为无序，所以二分无法实现
	// int mid, left =  1, right =  N;
	// while(left <= right) {
	// 	mid = (left + right) / 2;
	// 	if(arr_1[mid].adress == x) return mid;
	// 	else if(arr_1[mid].adress > x) {
	// 		right = mid - 1;
	// 	} else {
	// 		left = mid + 1;
	// 	}
	// }
}
int findByadress_arr_2(int x) {

	for(int i=1; i<=N; i++) {
		if(arr_2[i].adress == x) return i;
	}
}
int findBydata_arr_1(int x) {

	for(int i=1; i<=N; i++) {
		if(arr_1[i].data == x) return i;
	}
}
void swap(int &x, int &y) {  //
	int temp;
	temp = x;
	x = y;
	y = temp;
}
int main() {
	scanf("%d%d%d",&adress_first,&N,&K);
	int i_first,i_last;
	for(int i=1; i<=N; i++) {
		scanf("%d%d%d",&arr_1[i].adress,&arr_1[i].data,&arr_1[i].next);
		if(adress_first == arr_1[i].adress) i_first = i;
		if(-1 == arr_1[i].next) i_last = i;
	}
	// 【排序代码】 arr_1[]排序到arr_2[]
	int o_1 = 1;
	int o_2 = findByadress_arr_1(adress_first);
	int T_2 = N;
	while(T_2--) {
		arr_2[o_1++] = arr_1[o_2];
		o_2 = findByadress_arr_1(arr_1[o_2].next);
	}
	//【输出代码】
	// printf("arr_1[]经排序到arr_2[]:\n");
	// for(int i=1; i<=N; i++) {
	// 	printf("%05d %d %05d\n",arr_2[i].adress,arr_2[i].data,arr_2[i].next);
	// }

	// 反转(没设K)
	// for(int i=1; i<=N; i++) {
	// 	swap(arr_1[i].adress,arr_1[i].next);
	// }
	// arr_1[i_first].next = -1;
	// arr_1[i_last].adress = adress_first;
	// //或者：swap(arr_1[i_first].next,arr_1[i_last].adress); //所以说：AC是否高效 取决于 算法设计是否简易。
	// //或者在组内各项交换（所有交换）之前：swap(arr_1[i_first].adress,arr_1[i_last].next);
	
	// 反转(设K)
	int n_f_big,n_f_small,current = 1;
	// if(N % K == 0) n_f_big = N / K;
	// else n_f_big = N / K + 1;
	n_f_big = N / K;
	for(int i=1; i<=n_f_big; i++) {
		if(current == N - (N % K) + 1) n_f_small = N % K;
		else n_f_small = K;
		int per_small_for_begin = current;
		swap(arr_2[per_small_for_begin].adress,arr_2[per_small_for_begin + n_f_small - 1].next);
		for(int j=1; j<=n_f_small; j++) {
			swap(arr_2[current].adress,arr_2[current].next);
			current ++;
		}
	}


	//【输出代码】
	// printf("arr_2[]经K内反转后到arr_2[]:\n");
	// for(int i=1; i<=N; i++) {
	// 	printf("%05d %d %05d\n",arr_2[i].adress,arr_2[i].data,arr_2[i].next);
	// }

	// 【排序代码】 arr_2[]排序到arr_3[]
	int o_2_2 = 1;
	int o_3 = findByadress_arr_2(adress_first);
	int T = N;
	while(T--) {
		arr_3[o_2_2++] = arr_2[o_3];
		o_3 = findByadress_arr_2(arr_2[o_3].next);
	}
	//【输出代码】
	//printf("K内反转后arr_2[]排序到arr_3[]:\n");
	for(int i=1; i<=N; i++) {
		if(arr_3[i].next == -1)
			printf("%05d %d -1\n",arr_1[findBydata_arr_1(arr_3[i].data)].adress,arr_3[i].data);
		else
			printf("%05d %d %05d\n",arr_1[findBydata_arr_1(arr_3[i].data)].adress,arr_3[i].data,arr_1[findBydata_arr_1(arr_3[i + 1].data)].adress);
	}

	return 0;
}

// 00100 6 4
// 
// 00000 4 99999
// 00100 1 12309
// 68237 6 -1
// 33218 3 00000
// 99999 5 68237
// 12309 2 33218
// 
// arr_1[]经排序到arr_2[]:
// 00100 1 12309
// 12309 2 33218
// 33218 3 00000
// 00000 4 99999
// 99999 5 68237
// 68237 6 -0001
// 
// arr_2[]经K内反转后到arr_2[]:
// 12309 1 99999
// 33218 2 12309
// 00000 3 33218
// 00100 4 00000
// 68237 5 -0001
// 99999 6 68237
// 
// K内反转后arr_2[]排序到arr_3[]:
// 00100 4 00000
// 00000 3 33218
// 33218 2 12309
// 12309 1 99999
// 99999 6 68237
// 68237 5 -0001


// 00100 6 4
// 00000 4 99999
// 00100 1 12309
// 68237 6 -1
// 33218 3 00000
// 99999 5 68237
// 12309 2 33218
// arr_1[]经排序到arr_2[]:
// 00100 1 12309
// 12309 2 33218
// 33218 3 00000
// 00000 4 99999
// 99999 5 68237
// 68237 6 -0001
// arr_2[]经K内反转后到arr_2[]:
// 12309 1 99999
// 33218 2 12309
// 00000 3 33218
// 00100 4 00000
// 99999 5 68237
// 68237 6 -0001
// K内反转后arr_2[]排序到arr_3[]:
// 00100 4 00000
// 00000 3 33218
// 33218 2 12309
// 12309 1 99999
// 99999 5 68237
// 68237 6 -0001