Is It a Binary Search Tree (25)

二叉搜索树的定义：
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.

	镜像二叉搜索树MBST的定义
	If we swap the left and right subtrees of every node, then the resulting tree is called the Mirror Image of a BST.

Now given a sequence of integer keys, 
you are supposed to tell 
	if it is the preorder traversal sequence of a BST or the mirror image of a BST.

Input Specification:
Each input file contains one test case. For each case, 
the first line contains a positive integer N (<=1000). 
Then N integer keys are given in the next line. 
All the numbers in a line are separated by a space.

Output Specification:
For each test case, 
first print in a line "YES" if the sequence is the preorder traversal sequence of a BST or the mirror image of a BST, 
or "NO" if not. 
Then if the answer is "YES", print in the next line the postorder traversal sequence of that tree. 
All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.


Sample Input 1:
7					// 节点数量
8 6 5 7 10 8 11		// 节点   // 如果这个节点的序列是一棵‘二叉搜索树 或 镜像二搜索叉树’的先序，则输出YES
Sample Output 1:
YES
5 7 6 8 11 10 8   // Yes的话，输出这颗树的后序


Sample Input 2:
7
8 10 11 8 6 7 5
Sample Output 2:
YES
11 8 10 7 5 6 8


Sample Input 3:
7
8 6 8 5 10 9 11
Sample Output 3:
NO


给定N个整数作为BST的结点插入顺序，创建一棵BST：
	如果 '这棵BST的先序'=='输入顺序' || '这棵BST的镜像的先序'=='输入顺序' ，则输出YES，并输出此BST的后序；
	否则输出NO 。


注意：二叉搜索树的插入，每个节点的插入始终是从root开始比较的。


#include <cstdio>
#include <vector>
using namespace std;

int N;
vector<int> origin;
vector<int> preOrder_vector;
vector<int> preOrder_mirror_vector;
int j;  //

struct node {
	int data;
	node* lChild;
	node* rChild;
};

void insert(node* &root, int data) {
         ////////// 插入时，需要原地址，所以node* &root
         // 注意：二叉树的插入，每个节点的插入始终是从root开始比较的。
	// 边界
	if(root == NULL) {  // 即为需要插入的位置
		root = new node;  // 申请空间            ？？？为啥别的变量不用申请空间 ？？？
		root->data = data;
		root->lChild = root->rChild = NULL;
		return;
	}
	// 递归式
//	if(data > root->data)
//		insert(root->rChild, data);
//	else
//		insert(root->lChild, data);  // 左子树上的所有节点小于等于根结点

	if(data >= root->data)
		insert(root->rChild, data);  // 右子树上的所有节点等于大于根结点
	else
		insert(root->lChild, data);
}

void insert_mirror(node* &root,int data) {     ////////// 插入时，需要原地址，所以node* &root
	// 边界
	if(root == NULL) {
		root = new node;
		root->data = data;
		root->lChild = root->rChild = NULL;
		return;
	}
	// 递归式
//	if(data > root->data)
//		insert_mirror(root->lChild, data);
//	else
//		insert_mirror(root->rChild, data);

	if(data >= root->data)
		insert_mirror(root->lChild, data);
	else
		insert_mirror(root->rChild, data);
}

void preOrder(node* root, vector<int>& vi) {		////////// 使用时，不需要原地址，所以node* root
													////////// 而push vi时，需要原地址，所以vector<int>& vi
	// 边界
	if(root == NULL) {
		return;
	}
	// 递归式
	vi.push_back(root->data);
	preOrder(root->lChild, vi);
	preOrder(root->rChild, vi);
}

void preOrder_mirror(node* root, vector<int>& vi) {
	// 边界
	if(root == NULL) {
		return;
	}
	// 递归式
	vi.push_back(root->data);
	preOrder_mirror(root->lChild, vi);
	preOrder_mirror(root->rChild, vi);
}

void postOrder(node* root) {
	// 边界
	if(root == NULL) {
		return;
	}
	// 递归式
	postOrder(root->lChild);
	postOrder(root->rChild);
	if(j != N) {
		printf("%d ",root->data);
		j ++;
	} else {
		printf("%d",root->data);
	}

}

int main() {
	// 定义头节点为空
	node* root = NULL;
	node* root_mirror = NULL;
	// 输入 并生成BST
	scanf("%d",&N);
	for(int i=0; i<N; i++) {
		int c;
		scanf("%d",&c);
		origin.push_back(c);  //输入序列
		insert(root, c);  // 向BST中插入c
		insert_mirror(root_mirror, c);  // 向镜像BST中插入c
	}
	preOrder(root, preOrder_vector);
	preOrder_mirror(root_mirror, preOrder_mirror_vector);
	if(preOrder_vector == origin) {  ////vector可以直接比较
		printf("YES\n");
		j = 1;
		postOrder(root);
	} else if(preOrder_mirror_vector == origin) {
		printf("YES\n");
		j = 1;
		postOrder(root_mirror);
	} else {
		printf("NO");
	}

//	printf("\norigin:\n");
//	for(int i=0; i<origin.size(); i++) {
//		printf("%d ",origin[i]);
//	}
//	printf("\npreOrder_vector:\n");
//	for(int i=0; i<preOrder_vector.size(); i++) {
//		printf("%d ",preOrder_vector[i]);
//	}
//	printf("\npreOrder_mirror_vector:\n");
//	for(int i=0; i<preOrder_mirror_vector.size(); i++) {
//		printf("%d ",preOrder_mirror_vector[i]);
//	}
//	printf("\npostOrder(root); :\n");
//	postOrder(root);
//	printf("\npostOrder(root_mirror); :\n");
//	postOrder(root_mirror);

	return 0;
}


====================================================================================================
//给定N个整数作为BST的结点插入顺序，如果这棵BST或镜像BST的先序等于输入顺序，则输出YES，并输出相应BST的后序，否则输出NO
//code:
#include <cstdio>
#include <vector>
using namespace std;
int N;
vector<int> origin;
vector<int> preOrder_vector;
vector<int> preOrder_mirror_vector;
int j;
struct node {
	int data;
	node* lChild;
	node* rChild;
};
void insert(node* &root, int data) {  //二叉树的每次插入，都先从root开始
	if(root == NULL) {
		root = new node; 
		root->data = data;
		root->lChild = root->rChild = NULL;
		return;
	}
	if(data >= root->data) insert(root->rChild, data);  //右子树 >= 根结点
	else insert(root->lChild, data);
}
void insert_mirror(node* &root,int data) {
	if(root == NULL) {
		root = new node;
		root->data = data;
		root->lChild = root->rChild = NULL;
		return;
	}
	if(data >= root->data) insert_mirror(root->lChild, data);
	else insert_mirror(root->rChild, data);
}
void preOrder(node* root, vector<int>& vi) {
	if(root == NULL) return;
	vi.push_back(root->data);
	preOrder(root->lChild, vi);
	preOrder(root->rChild, vi);
}
void preOrder_mirror(node* root, vector<int>& vi) {
	if(root == NULL) return;
	vi.push_back(root->data);
	preOrder_mirror(root->lChild, vi);
	preOrder_mirror(root->rChild, vi);
}
void postOrder(node* root) {
	if(root == NULL) return;
	postOrder(root->lChild);
	postOrder(root->rChild);
	if(j != N) {
		printf("%d ",root->data);
		j ++;
	} else {
		printf("%d",root->data);
	}
}
int main() {
	node* root = NULL;
	node* root_mirror = NULL;
	scanf("%d",&N);
	for(int i=0; i<N; i++) {
		int c;
		scanf("%d",&c);
		origin.push_back(c);
		insert(root, c);
		insert_mirror(root_mirror, c);
	}
	preOrder(root, preOrder_vector);
	preOrder_mirror(root_mirror, preOrder_mirror_vector);
	if(preOrder_vector == origin) {  ////vector可以直接比较
		printf("YES\n");
		j = 1;  //用于控制输出
		postOrder(root);
	} else if(preOrder_mirror_vector == origin) {
		printf("YES\n");
		j = 1;
		postOrder(root_mirror);
	} else {
		printf("NO");
	}
	return 0;
}