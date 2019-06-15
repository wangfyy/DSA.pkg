Complete Binary Search Tree (30)

BST的定义：
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.

CBT的定义：
A Complete Binary Tree (CBT) (完全二叉树(CBT)) is a tree that is completely filled, 
with the possible exception of the bottom level, which is filled from left to right.

Now given a sequence of distinct(截然不同的) non-negative integer keys, 
a unique(独一无二的) BST can be constructed(构造) if it is required that the tree must also be a CBT. (要求树也必须是CBT)
You are supposed to output the level order traversal sequence of this BST.(输出层序遍历)

Input Specification:
Each input file contains one test case. For each case, 
the first line contains a positive integer N (<=1000). 
Then N distinct non-negative integer keys are given in the next line. 
All the numbers in a line are separated by a space and are no greater than 2000.

Output Specification:
For each test case, 
print in one line the level order traversal sequence of the corresponding complete binary search tree. 
All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.


----------------------------------------------------------------------------------------------
Sample Input:
10
1 2 3 4 5 6 7 8 9 0
Sample Output:
6 3 8 1 5 7 9 0 2 4
----------------------------------------------------------------------------------------------
This is a valuable Test.
【Thinking】
	用这些节点构建一棵完全二叉排序树CBT（考察：BST或CBT的中序序列有序 和 完全二叉树中节点的插入方式），
	然后层序遍历之（考察：完全二叉树中层序遍历的实现方法只需要顺序输出数组即可）
【考察】
	1. CBT数组的存储与赋值
	2. 性质：BST或CBT的中序序列有序
	3. 注意不能用插入的方式，因为插入的树形是随机的。
----------------------------------------------------------------------------------------------


#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 2010;

int N, number[MAXN], index = 0;
int CBT[MAXN];  ////

void inorder(int root) {  ////中序遍历时顺便赋值
	// 边界
	if(root > N) return;  ////  root > N   root > N   root > N
	// 递归式
	inorder(root * 2);  ////
	CBT[root] = number[index ++];  ////顺便赋值
	inorder(root * 2 + 1);  ////
}
	////由于CBT的存储在数组里的，它的下标的走向是横向的(以至于最后一层的叶子结点也都是居左的，所以完全~),
	////和树的层序遍历节点的顺序一致,所以层序遍历也即为按CBT下标输出

int main() {
	scanf("%d",&N);
	for(int i=0; i<N; i++) {
		scanf("%d",&number[i]);
	}
	//对输入数字的数组从小到大进行排序
	sort(number, number + N);
	//inorder(因为BST的中序遍历是有序的)
	inorder(1);  //root为1
	for(int i=1; i<=N; i++) {
		printf("%d",CBT[i]);  ////顺序输出即为层序
		if(i != N) printf(" ");
	}

	return 0;
}




----------------------------------------------------------------------------------------------
//用这些节点构建一棵完全二叉排序树CBT，然后层序遍历之
//	1. 完全二叉排序树CBT的数组存储与赋值
//	2. BST以及CBT的中序序列有序
//	3. 注意不能用插入的方式，因为插入的树形是随机的。
//code:
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 2010;
int N, number[MAXN], index = 0;
int CBT[MAXN];
void inorder(int root) {  //中序遍历时赋值
	if(root > N) return;  ////
	inorder(root * 2);
	CBT[root] = number[index ++];  ////
	inorder(root * 2 + 1);
}
int main() {
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		scanf("%d",&number[i]);
	sort(number, number + N);
	inorder(1);
	for(int i=1; i<=N; i++) {
		printf("%d",CBT[i]);  //层序遍历即为顺序输出数组
		if(i != N) printf(" ");
	}
	return 0;
}