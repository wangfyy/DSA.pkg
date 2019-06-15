Reversing Linked List (25)

Given a constant K and a singly linked list L, 
you are supposed to reverse the links of every K elements on L. For example, 
given L being 1→2→3→4→5→6, if K = 3, then you must output 3→2→1→6→5→4; 
if K = 4, you must output 4→3→2→1→5→6.

Input Specification:
Each input file contains one test case. For each case, 
the first line contains the address of the first node, 
a positive N (<= 105) which is the total number of nodes, 
and a positive K (<=N) which is the length of the sublist(子表) to be reversed. 
The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.
Then N lines follow, each describes a node in the format:
Address Data Next
where Address is the position of the node, Data is an integer, and Next is the position of the next node.

Output Specification:
For each case, output the resulting ordered linked list. 
Each node occupies a line, and is printed in the same format as in the input.
---------------------------------
Sample Input:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
Sample Output:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
---------------------------------
Sample Input:
00100 8 4
00000 4 99999
00100 1 12309
68237 6 11111
33218 3 00000
99999 5 68237
12309 2 33218
11111 7 22222
22222 8 -1
Sample Output:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 22222
22222 8 11111
11111 7 68237
68237 6 99999
99999 5 -1
---------------------------------
Sample Input:
00100 9 4
00000 4 99999
00100 1 12309
68237 6 11111
33218 3 00000
99999 5 68237
12309 2 33218
11111 7 22222
22222 8 44444
44444 9 -1
Sample Output:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 22222
22222 8 11111
11111 7 68237
68237 6 99999
99999 5 44444
44444 9 -1
---------------------------------
Sample Input:
00000 6 3
00000 1 11111
11111 2 22222
22222 3 -1
33333 4 44444
44444 5 55555
55555 6 -1
Sample Output:
22222 3 11111
11111 2 00000
00000 1 -1
---------------------------------
#include <cstdio>

const int MAXN = 100010;

int firstAddress, N, K;
int preAddress, nextAddress, startAddress;
int num_1 = 0, num_2 = 0, num_3 = 0;

struct node{
	int address;
	int next;
} Node[MAXN];

// void solve(int f_A) {
//     if(num_2 == K) return;
// 	for(int i=1; i<=N; i++) {  // 无法二分
// 		if(Node[i].address == f_A) {
//             num_2 ++;
//             nextAddress = Node[i].next;
//             Node[i].next = preAddress;
//             preAddress = Node[i].address;
//             break;
// 		}
// 	}
// 	if(nextAddress != -1) {
// 		solve(nextAddress);
// 	} else {
// 		return;
// 	}
// }

void solve(int f_A) {
	while(1) {	
	    if(num_2 == K) return;
		for(int i=1; i<=N; i++) {
			if(Node[i].address == f_A) {
	            num_2 ++;
	            nextAddress = Node[i].next;
	            Node[i].next = preAddress;
	            preAddress = Node[i].address;
	            break;
			}
		}
		if(nextAddress != -1) {
			f_A = nextAddress;
		} else {
			return;
		}
	}
}

// void print(int f_A) {
//     if(num_1 == N) return;
// 	int i;
// 	for(i=1; i<=N; i++) {
// 		if(Node[i].address == f_A) {
// 			num_1 ++;
// 			if(num_1 != N)
//                 printf("%05d %d %05d\n",Node[i].address,i,Node[i].next);
//             else
//                 printf("%05d %d -1",Node[i].address,i);
// 			break;  //////
// 		}
// 	}
// 	if(Node[i].next != -1) {
// 		print(Node[i].next);
// 	} else {
// 		return;
// 	}
// }

void print(int f_A) {
	while(1) {	
	    if(num_1 == N) return;
		int i;
		for(i=1; i<=N; i++) {
			if(Node[i].address == f_A) {
				num_1 ++;
				if(num_1 != N)
	                printf("%05d %d %05d\n",Node[i].address,i,Node[i].next);
	            else
	                printf("%05d %d -1",Node[i].address,i);
				break;
			}
		}
		if(Node[i].next != -1) {
			f_A = Node[i].next;
		} else {
			return;
		}
	}
}

// int checkN(int f_A) {
// 	int i;
// 	for(i=1; i<=N; i++) {
// 		if(Node[i].address == f_A) {
// 			num_3 ++;
// 			break;  //////
// 		}
// 	}
// 	if(Node[i].next != -1) {
// 		checkN(Node[i].next);
// 	} else {
// 		return num_3;
// 	}
// }

int checkN(int f_A) {
	while(1) {	
		int i;
		for(i=1; i<=N; i++) {
			if(Node[i].address == f_A) {
				num_3 ++;
				break;
			}
		}
		if(Node[i].next != -1) {
			f_A = Node[i].next;
		} else {
			return num_3;
		}
	}
}

int main() {
	// 输入
	scanf("%d%d%d",&firstAddress,&N,&K);
	for(int i=1; i<=N; i++) {
		int tempAddress, tempData, tempNext;
		scanf("%d%d%d",&tempAddress,&tempData,&tempNext);
		Node[tempData].address = tempAddress;
		Node[tempData].next = tempNext;
	}
	// 检查N
	N = checkN(Node[1].address);
    // 反转操作
    int index = 1;
    for(int i=0; i<N / K; i++) {
    	num_2 = 0;
    	firstAddress = Node[index].address;
    	preAddress = Node[(index - 1 + K * 2)].address;
    	if(index - 1 + K * 2 > N) {
    		preAddress = Node[N - N % K + 1].address;  ////
    	}
		solve(firstAddress);
		index += K;
    }
	// 输出
	startAddress = Node[K].address;  // 第一块的最后一个改序节点的地址
	print(startAddress);

	return 0;
}





看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  
看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  
看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  
看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  
看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  
看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  
看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  