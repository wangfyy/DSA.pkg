Linked List Sorting (25)

A linked list consists of a series of structures, which are not necessarily adjacent in memory. 
We assume that each structure contains an integer key and a Next pointer to the next structure. 
Now given a linked list, you are supposed to sort the structures according to their key values in increasing order.

Input Specification:
Each input file contains one test case. For each case, 
the first line contains a positive N (< 105) and an address of the head node, 
where N is the total number of nodes in memory and the address of a node is a 5-digit positive integer. 
NULL is represented by -1.
Then N lines follow, each describes a node in the format:
Address Key Next
where Address is the address of the node in memory, 
Key is an integer in [-105, 105], and Next is the address of the next node. 
It is guaranteed that all the keys are distinct and there is no cycle in the linked list starting from the head node.

Output Specification:
For each test case, the output format is the same as that of the input, 
where N is the total number of nodes in the list and all the nodes must be sorted order.

------------------------------
Sample Input:
5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345
Sample Output:
5 12345
12345 -1 00001
00001 0 11111
11111 100 22222
22222 1000 33333
33333 100000 -1
------------------------------
Sample Input:
5 00001
11111 100 -1
00001 0 22222
33333 100000 -1
12345 -1 33333
22222 1000 12345
Sample Output:
4 12345
12345 -1 00001
00001 0 22222
22222 1000 33333
33333 100000 -1
------------------------------
Sample Input:
5 55555
11111 100 -1
00001 0 22222
33333 100000 -1
12345 -1 33333
22222 1000 12345
Sample Output:
0 -1
------------------------------

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

int N, firstAddress;
int num = 0, num2 = 0;

struct node {
	int Address, Key, Next;
} Node[MAXN], Node2[MAXN];

bool cmp(node a, node b) {
	return a.Key < b.Key;
}

// void check(int index) {  // 递归,,,,,,,,,,,,,,,,,,运行超时........................
// 	for(int i=0; i<N; i++) {
// 		if(Node[i].Address == index) {
// 			Node2[num].Address = Node[i].Address;
// 			Node2[num].Key = Node[i].Key;
// 			Node2[num].Next = Node[i].Next;
// 			num ++;
// 			if(Node[i].Next != -1)
// 				check(Node[i].Next);
// 			break;
// 		}
// 	}
// 	return;
// }

void check(int index) {  // 递推
	while(1) {
		for(int j=0; j<N; j++) {
			if(Node[j].Address == index) {
				Node2[num].Address = Node[j].Address;
				Node2[num].Key = Node[j].Key;
				Node2[num].Next = Node[j].Next;
				num ++;
				if(Node[j].Next != -1)
					index = Node[j].Next;
	            else
	       	        return;
			} else {
				num2++;
			}
		}
		if(num2 > 100) return;  // 若找不到，则主动退出，否则死循环
	}
}


int main() {
	scanf("%d%d",&N,&firstAddress);
	for(int i=0; i<N; i++) {
		scanf("%d%d%d",&Node[i].Address,&Node[i].Key,&Node[i].Next);
	}

	// check (检索有效点)
	check(firstAddress);
	N = num;

	// sort
	sort(Node2, Node2 + N, cmp);

	// printf("%d\n",num);
	// for(int i=0; i<N; i++) {
	// 	if(Node2[i].Next == -1) {
	// 		printf("%05d %d -1",Node2[i].Address,Node2[i].Key);	
	// 	} else {
	// 		printf("%05d %d %05d",Node2[i].Address,Node2[i].Key,Node2[i].Next);
	// 	}
	// 	if(i != N - 1) printf("\n");
	// }
	// printf("\n");

	// solve
	int lostAddress = -1;
	for(int i = N - 1; i >= 0; i --) {
			Node2[i].Next = lostAddress;
			lostAddress = Node2[i].Address;
	}
	// print
	if(lostAddress == -1) printf("%d -1\n",N);
	else printf("%d %05d\n",N,lostAddress);
	for(int i=0; i<N; i++) {
			if(Node2[i].Next == -1) {
				printf("%05d %d -1",Node2[i].Address,Node2[i].Key);	
			} else {
				printf("%05d %d %05d",Node2[i].Address,Node2[i].Key,Node2[i].Next);
			}
			if(i != N - 1) printf("\n");
	}

	return 0;
}