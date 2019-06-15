// 二叉查找树(Binary Search Tree -- BST)

// 查找
void search(node* root,int x) {
	if(root == NULL) {
		printf("空树\n");
		return;
	}
	if(x == root->data) {
		printf("%d\n",root->data);
	}else if(x > root->data) {
		search(root->lchild,x);
	}else {
		search(root->rchild,x);
	}
}  //最坏时间复杂度O(h),h为BST的高度

// 插入
void insert(node* &root,int x) {  //注意引用
	if(root == NULL) {
		root = newNode(x);
		return;
	}
	if(x == root->data) {
		printf("已存在\n");
		return;
	}else if(x > root->data) {
		insert(root->lchild,x);
	}else {
		insert(root->rchild,x);
	}
}  //最坏时间复杂度O(h),h为BST的高度

// 建BST
node* Create(int data[],int n) {
	node* root = NULL;
	for(int i=0; i<n; i++) {
		insert(root,data[i]);
	}
	return root;
}

// BST的删除
// 寻找以root为根节点的树中的最大权值节点
node* findMax(node* root) {
	while(root->rchild != NULL) {
		root = root->rchild;
	}
	return rchild;
}
// 寻找以root为根节点的树中的最小权值节点
node* findMin(node* root) {
	while(root->lchild != NULL) {
		root = root->lchild;
	}
	return lchild;
}
// 删除以root为根节点的树中权值为x的节点  （树的操作就用递归递归递归递归递归递归递归递归）
void deleteNode(node* &root,int x) {  //注意引用
	if(root == NULL) return;
	if(root->data == x) {
		if(root->lchild == NULL && root->rchild == NULL) {
			root = NULL;
		}else(root->lchild != NULL) {  //有左孩子
			node* pre = findMax(root->lchild);  ////
			root->data = pre->data;
			deleteNode(root->lchild,pre->data);
		}else{  //有右孩子
			node* next = findMin(root->rchild);  ////
			root->data = next->data;
			deleteNode(root->rchild,next->data);
		}
	}else if(root->data > x) {
		deleteNode(root->lchild,x);
	}else{
		deleteNode(root->rchild,x);
	}
}