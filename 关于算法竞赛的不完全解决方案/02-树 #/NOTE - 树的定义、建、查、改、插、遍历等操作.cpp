// 树节点的定义
struct node{
	typename data;
	node* lchild;
	node* rchild;
};
node* root = NULL;

// 新建节点
node* newNode(int v) {
	node* Node = new node;  //申请一个node型变量的地址空间
	Node->data = v;
	Node->lchild = Node->rchild = NULL;
	return Node;
}

// 节点的查找修改
void search(node* root, int x, int newdata) {  //newdata为要改成的值
	if(root == NULL) {
		return;
	}
	if(root->data == x) {
		root->data = newdata;
	}
	search(root->lchild, x, newdata);
	search(root->rchild, x, newdata);
}

// 插入新节点
void insert(node* &root, int x) {  //注意引用。。。
	if(root == NULL) {
		root = newNode(x);
		return;
	}
	if(/*由二叉树的性质，x应该插在左子树*/) {  //插入位置根据树的具体状态而定
		insert(root->lchild,x);
	}else {
		insert(root->rchild,x);
	}
}

// 新建二叉树
node* Create(int data[], int n) {
	node* root = NULL;  //新建空根节点root
	for(int i=0; i<n; i++) {
		insert(root,data[i]);
	}
	return root;
}

// 此处没写树的DFS/BFS，但注意：DFS是通过递归来实现的，BFS是通过队来实现的。

// 二叉树先序遍历
void preorder(node* root) {
	if(root == NULL) return;
	printf("%d\n",root->data);
	preorder(root->lchild);
	preorder(root->rchild);
}
// 二叉树中序遍历
void inorder(node* root) {
	if(root == NULL) return;
	preorder(root->lchild);
	printf("%d\n",root->data);
	preorder(root->rchild);
}
// 二叉树后序遍历
void inorder(node* root) {
	if(root == NULL) return;
	preorder(root->lchild);
	preorder(root->rchild);
	printf("%d\n",root->data);
}
// 二叉树层序遍历
void LayerOrder(node* root) {
	queue<node*> q;  //注意队列里存的是地址
	q.push(root);
	while(!q.empty()) {
		node* now = q.front();
		q.pop();
		printf("%d\n",now->data);
		if(now->lchild != NULL) q.push(now->lchild); 
		if(now->rchild != NULL) q.push(now->rchild);
	}
}
// 当题目要计算每个节点所处的层次时：
struct node{
	int data;
	int layer;
	node* rchild;
	node* lchild;
};
void LayerOrder(node* root) {
	queue<node*> q;  //注意队列里存的是地址
	root->layer = 1;
	q.push(root);
	while(!q.empty()) {
		node* now = q.front();
		q.pop();
		printf("%d\n",now->data);
		if(now->lchild != NULL) {
			now->lchild->layer = now->layer + 1;
			q.push(now->lchild); 
		}
		if(now->rchild != NULL) {
			now->rchild->layer = now->layer + 1;
			q.push(now->rchild);
		}
	}
}

// p294 给定一棵二叉树的先序遍历和中序遍历序列，重建这个二叉树：
node* create(int preL,int preR,int inL,int inR) {  // 先序序列区间[preL,preR];  先序序列区间[inL,inR]
	// 递归边界
	if(preL > preR) {
		return NULL;
	}
	// 这就是每次递归的目的，即:明确每次的根节点
	node* root = new node;
	root->data = pre[preL];
	// 确定左子树的个数，作为偏移量使用
	int k;
	for(k=inL, k<=inR; k++) {
		if(in[k] == pre[preL]) break;
	}
	int numLeft = k - inL;  //左子树的节点个数，在递归式中划分区间时，作为偏移量使用
	//递归式
	root->lchild = create(preL + 1,preL + number,inL,k - 1);
	root->rchild = create(preL + number + 1,preR,,k + 1,inR);
	//返回
	return root;
}
// 给定一棵二叉树的后序遍历和中序遍历序列，重建这个二叉树
// 给定一棵二叉树的层序遍历和中序遍历序列，重建这个二叉树

// 二叉树的静态实现
//定义节点
struct node{
	typename data;
	int lchild;
	int rchild;
} Node[maxn];
//生成节点
int index = 0;
int newNode(int v) {
	Node[index].data = v;
	Node[index].lchild = -1;
		//此处是给“地址：Node[index].lchild”指向的格进行赋值,(注意：Node[index].lchild是个地址)。
	Node[index].rchild = -1;
	return index++;  //返回的是在数组中的下标
}
// 节点的查找修改
void search(int root, int x, int newdata) {  //newdata为要改成的值
	if(root == -1) {
		return;
	}
	if(Node[root].data == x) {
		Node[root].data = newdata;
	}
	search(Node[root].lchild, x, newdata);
		//此处(即“search(Node[root].lchild,”)传到“search(int root,”中的是个值，而不是地址，
		//因为“search(int root,”中接受的是“int”型数据，而不是地址型数据
	search(Node[root].rchild, x, newdata);
}
// 插入新节点
void insert(int &root, int x) {  //注意引用。。。
	if(root == -1) {
		root = newNode(x);  //root是数组Node[]的一个下标
		return;
	}
	if(/*由二叉树的性质，x应该插在左子树*/) {  //插入位置根据树的具体状态而定
		insert(Node[root].lchild,x);
			//此处(即“insert(Node[root].lchild,”)传到“insert(int &root,”中的是root的别名，
			//是原数(原地址指向的那个数)，而不是仅仅是个被复制的值，
			//因为“insert(int &root,”中接受的是个引用(即:“int*型 + 值型”的数据,(引用的特点p68))。
	}else {
		insert(Node[root].rchild,x);
	}
}
// 新建二叉树
node* Create(int data[], int n) {
	int root = -1;  //新建空根节点root
	for(int i=0; i<n; i++) {
		insert(root,data[i]);
	}
	return root;
}
// 先序遍历
void preorder(int root) {
	if(root == -1) return;
	printf("%d\n",Node[root].data);
	preorder(Node[root].lchild);
	preorder(Node[root].rchild);
}
// 中序遍历
void inorder(int root) {
	if(root == -1) return;
	preorder(Node[root].lchild);
	printf("%d\n",Node[root].data);
	preorder(Node[root].rchild);
}
// 后序遍历
void inorder(int root) {
	if(root == -1) return;
	preorder(Node[root].lchild);
	preorder(Node[root].rchild);
	printf("%d\n",Node[root].data);
}
// 层序遍历
void LayerOrder(int root) {
	queue<int> q;  //注意队列里存的是下标
	q.push(root);
	while(!q.empty()) {
		node* now = q.front();
		q.pop();
		printf("%d\n",Node[root].data);
		if(Node[root].lchild != -1) q.push(Node[root].lchild); 
		if(Node[root].rchild != -1) q.push(Node[root].rchild);
	}
}

// 树的静态写法
// 树的定义
struct node {
	typename data;
	vector<int> child;  //变长数组 //int child[maxn];  //存放所有子节点的下标
}Node [maxn];
// 建树(即新建节点)
int index = 0;
int newNode(int v) {
	Node[index].data = v;
	Node[index].child.clear();  //清空子节点，对应建二叉树中的Node[index].lchild = -1;
	return index++;
}
// 树的先根遍历
void preorder(int root) {
	if(root == -1) return;
	printf("%d\n",Node[root].data);
	for(int i=0; i<Node[root].child.size(); i++) {
		preorder(Node[root].child[i]);
	}
}
// 树的层序遍历
void LayerOrder(int root) {
	queue<int> q;  //注意队列里存的是下标
	q.push(root);
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		printf("%d\n",Node[front].data);
		for(int i=0; i<Node[front].child.size(); i++) {
			q.push(Node[front].child[i]);
		}
	}
}
// 当题目要计算每个节点所处的层次时：
struct node {
	int data;
	int layer;
	vector<int> child;  //int child[maxn];  //存放所有子节点的下标
} Node[MAXN];
void LayerOrder(node* root) {
	queue<int> q;  //注意队列里仅放下标
	Node[root].layer = 1;
	q.push(root);
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		printf("%d\n",Node[front].data);
		for(int i=0; i<Node[front].child.size(); i++) {
			int child = Node[front].child[i];
			Node[child].layer = Node[root].layer++;  //layer++
			q.push(child);
		}
	}
}