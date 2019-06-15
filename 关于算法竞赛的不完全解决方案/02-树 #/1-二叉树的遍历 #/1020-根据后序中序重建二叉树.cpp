Tree Traversals (25)

Suppose that all the keys in a binary tree(二叉树) are distinct positive integers. 
Given the postorder and inorder traversal sequences, 
you are supposed to output the level order traversal sequence of the corresponding binary tree.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (<=30), 
the total number of nodes in the binary tree. 
The second line gives the postorder(后序) sequence and the third line gives the inorder(中序) sequence. 
All the numbers in a line are separated by a space.

Output Specification:
For each test case, print in one line the level(层级) order(顺序) traversal sequence of the corresponding binary tree. 
All the numbers in a line must be separated by exactly one space, 
and there must be no extra space at the end of the line.

Sample Input:
7
2 3 1 5 7 6 4	//后序——左子树->右子树->根节点
1 2 3 4 5 6 7	//中序——左子树->根节点->右子树
Sample Output:
4 1 6 3 5 7 2  	//level(层级) order(顺序)


#include <cstdio>
#include <queue>
using namespace std;

const int MAXN = 35;

struct node{
	int data;
	node* lChild;
	node* rChild;
};

int N, postorder[MAXN], inorder[MAXN];

node* create(int postL, int postR, int inL, int inR) {  //create  create  create  create   // 后序区间[postL,postR] 中序区间[inL,inR]
	// 递归边界
	if(postL > postR) {
		return NULL;
	}
	// 新建节点，给新建节点的数据域赋值
	node* root = new node;
	root->data = postorder[postR];
	// 寻找inorder里当前根节点的位置k
	int k;  // k的作用范围 
	for(k=inL; k<=inR; k++) {
		if(inorder[k] == postorder[postR])
			break;
	}
	//// 计算左子树的结点个数，得到下次递归的后序遍历的左子树的范围：postL, postL + numL - 1, ...
		//（在后续遍历序列中划分左右子树，因为root的左右子树的头结点分别在左右子树序列的最后一个，
		// 所以才有下面的：postL + numL - 1 而不是 postR - 1）
	int numL =  k - inL;
	// 递归式，给新建节点的左右孩子的指针域赋值
	root->lChild = create(postL, postL + numL - 1, inL, k - 1);
		// 如上面所述，注意：create(postL, postR - 1, inL, k - 1); 错 
	root->rChild = create(postL + numL, postR - 1, k + 1, inR);	
		// 若 "..k + 1,.." 写为"inL + k + 1" ，则：递归调用层数太多，提示段错误
	return root;
}

void bfs(node* root) {
	queue<node*> q;  // 注意：node* ，输出时：printf("%d",now->data);
	q.push(root);
	while(!q.empty()) {
		node* now = q.front();  ////
		printf("%d",now->data);  // 
		q.pop();
		if(now->lChild != NULL)  //
			q.push(now->lChild);
		if(now->rChild != NULL)
			q.push(now->rChild);
		if(!q.empty())  //
			printf(" ");
	}
}

int main() {
	scanf("%d",&N);
	for(int i=0; i<N; i++) {
		scanf("%d",&postorder[i]);
	}
	for(int i=0; i<N; i++) {
		scanf("%d",&inorder[i]);
	}
	// 建树
	node* root = create(0, N-1, 0, N-1);
	// 层序遍历
	bfs(root);

	return 0;
}

code2 --------------------------------
#include <cstdio>
#include <queue>
using namespace std;
const int MAXN = 40;
int N, postOrder[MAXN], inOrder[MAXN];
struct node {
	int data;
	node* l;  ////
	node* r;
};
node* create(int lPost, int rPost, int lIn, int rIn) {
	if(lPost > rPost) return NULL;  ////
	node* root = new node;
	root->data = postOrder[rPost];
	int i;
	for(i=lIn; i<=rIn; i++)  ////
		if(inOrder[i] == postOrder[rPost]) break;
	int lenL = i - lIn;
	root->l = create(lPost, lPost + lenL - 1, lIn, i - 1);
	root->r = create(lPost + lenL, rPost - 1, i + 1, rIn);  ////
	return root;
}
void BFS(node* root) {
	queue<node*> q;
	q.push(root);
	while(!q.empty()) {
		node* now = q.front();
		printf("%d",now->data);
		q.pop();
		if(now->l != NULL)  ////
			q.push(now->l);
		if(now->r != NULL)
			q.push(now->r);
		if(!q.empty()) printf(" ");
	}
}
int main() {
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		scanf("%d",&postOrder[i]);
	for(int i=0; i<N; i++)
		scanf("%d",&inOrder[i]);
	node* root = create(0, N-1, 0, N-1);
	BFS(root);
	return 0;
}