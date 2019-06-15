Build A Binary Search Tree (30)

BST的定义:
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.

	Given the structure of a binary tree and a sequence of distinct integer keys, 
	there is only one way to fill these keys into the tree so that the resulting tree satisfies the definition of a BST. 

You are supposed to output the level order traversal sequence of that tree. The sample is illustrated by Figure 1 and 2.

Input Specification:
Each input file contains one test case. For each case, 
the first line gives a positive integer N (<=100) which is the total number of nodes in the tree. 
The next N lines each contains 
	the left and the right children of a node in the format "left_index right_index", 
	provided that the nodes are numbered from 0 to N-1, and 0 is always the root. 
	If one child is missing, then -1 will represent the NULL child pointer. 
	Finally N distinct integer keys are given in the last line.

Output Specification:
For each test case, print in one line the 
	level order traversal sequence of that tree. 
All the numbers must be separated by a space, with no extra space at the end of the line.

//指定了树结构的BST
Sample Input:
//给定了树结构，输入顺序为结点编号(0~N-1)(Node[]下标)，root为0结点，-1代表无孩子
9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
//给定了需要的放入那些固定位置的结点的值
73 45 11 58 82 25 67 38 42
Sample Output:
//层序遍历
58 25 82 11 38 67 45 73 42
//将给定的二叉树结点中序遍历，他们应该是有序的，所以将这些节点的下标（Node[]里的下标）存放到a[]中用来被赋值，
//将给定的数排序成number[]，对应赋值即：index=0; for(){ Node[a[index++]] = number[index++];
//最后遍历
//code:
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 2020;
struct node{
	int data;
	int lChild;  //静态（数组）存储
	int rChild;
} Node[MAXN];
int N, number[MAXN], a[MAXN], index = 0;
void inOrder(int root) {
	if(root == -1) return;
	inOrder(Node[root].lChild);
	a[index++] = root;  //a[]存放的是下标
	inOrder(Node[root].rChild);
}
void solve() {
	index = 0;
	for(int i=0; i<N; i++)
		Node[a[i]].data = number[index++];
}
void levelOrder(int root) {
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		printf("%d",Node[now].data);
		if(Node[now].lChild != -1) q.push(Node[now].lChild);
		if(Node[now].rChild != -1) q.push(Node[now].rChild);
		if(!q.empty()) printf(" ");
	}
}
int main() {
	scanf("%d",&N);
	for(int i=0; i<N; i++) {
		int left_index, right_index;
		scanf("%d%d",&left_index,&right_index);
		if(left_index != -1) Node[i].lChild = left_index;
		else Node[i].lChild = -1;  ////不用NULL，既然是数组
		if(right_index != -1) Node[i].rChild = right_index;
		else Node[i].rChild = -1;
	}
	for(int i=0; i<N; i++)
		scanf("%d",&number[i]);
	sort(number, number + N);
	inOrder(0);
	solve();  //对应赋值
	levelOrder(0);
	return 0;
}