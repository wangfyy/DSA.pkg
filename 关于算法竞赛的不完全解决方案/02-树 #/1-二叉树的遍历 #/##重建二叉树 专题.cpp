重建二叉树

---后序中序--------------------------------------------------------------------------
【一】PAT-A 170304 原题 D
//给出一个树的中序和后序遍历结果，求它的Z字型层序遍历，也就是偶数层从左往右，奇数层从右往左遍历

// 8
// 12 11 20 17 1 15 8 5    中序
// 12 20 17 11 15 8 5 1    后序

// 1 11 5 8 17 12 20 1     zigzagging sequence

#include <cstdio>
#include <queue>
using namespace std;

struct node {
    int data;
    node* l;
    node* r;
    int layer;
};

const int MAXN = 1010;

int N, inOrder[MAXN], postOrder[MAXN], cnt = 0, cnt2 = 0;
node* layerOrder[MAXN];
int leftIndex = 0, rightIndex = 0;

node* create(int inL, int inR, int postL, int postR) {
    if(postL > postR) {
        return NULL;  ////NULL  NULL  NULL  NULL  NULL
    }
    node* root = new node;
    root->data = postOrder[postR];
    int i;
    for(i=0; i<N; i++) {
        if(root->data == inOrder[i]) break;
    }
    int lenL = i - inL;  ////// - inL - inL  因为每次的inL不一样，第一次是0，以后就不是了(例如根节点的右子树的左子树的左下标)
    root->l = create(inL,i-1,postL,postL+lenL-1);  ////// 但是每次的i的值是对的，所以可以直接用i
    root->r = create(i+1,inR,postL+lenL,postR-1);

    return root;
}

void BFS(node* root) {
    queue<node*> q;
    q.push(root);
    root->layer = 1;
    while(!q.empty()) {
        node* now  = q.front();
        layerOrder[cnt++] = now;
        q.pop();
        if(now->l != NULL) {
            q.push(now->l);
            now->l->layer = now->layer + 1;
        }
        if(now->r != NULL) {
            q.push(now->r);
            now->r->layer = now->layer + 1;
        }
    }
}

void print() {
    //printf("\n[%d %d]\n",leftIndex,rightIndex);
    if(layerOrder[leftIndex]->layer % 2 == 0) {
        for(int i=leftIndex; i<=rightIndex; i++) {
            printf("%d",layerOrder[i]->data);
            cnt2++;
            if(cnt2 != cnt) printf(" ");
        }
    } else {
        for(int i=rightIndex; i>=leftIndex; i--) {
            printf("%d",layerOrder[i]->data);
            cnt2++;
            if(cnt2 != cnt) printf(" ");
        }
    }

}

int main() {
	scanf("%d",&N);
	int i;
	for(i=0; i<N; i++) {
		scanf("%d",&inOrder[i]);
	}
	for(i=0; i<N; i++) {
		scanf("%d",&postOrder[i]);
	}
	node* root = create(0,N-1,0,N-1);  //////N-1  N-1  N-1  N-1  N-1  N-1
	BFS(root);

    for(i=0; i<N-1; i++) {
        rightIndex = i;
        if(layerOrder[i]->layer != layerOrder[i+1]->layer) {
            print();
            leftIndex = i+1;
        }
    }
    leftIndex = rightIndex;
    rightIndex = cnt - 1;
    //printf("\n[%d %d]\n",leftIndex,rightIndex);
    print();

//    printf("\n");
//	for(i=0; i<N; i++) {
//		printf("%d ",layerOrder[i]->layer);
//	}


	return 0;
}

【二】PAT-A 1020

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

---先序中序--------------------------------------------------------------------------
PAT-A 1086

123456的push顺序为先序，pop顺序为中序，求后序

Sample Input:
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
Sample Output:
3 4 2 6 5 1


#include <cstdio>
#include <cstring>
#include <stack>
#include <ostream>
using namespace std;

const int MAXN = 35;

struct node{
    int data;
    node* lChild;
    node* rChild;
};

int N;
int preOrder[MAXN], inOrder[MAXN];
int preL, preR, inL, inR;

node* create(int preL, int preR, int inL, int inR) {
    // 递归边界
    if(preL > preR){
        return NULL;
    }
    // data
    node* root = new node;
    root->data = preOrder[preL];
    // k
    int k;
    for(k=0; k<N; k++) {
        if(preOrder[preL] == inOrder[k])
            break;
    }
    // 计算左子树个数
    int numLeft = k - inL;
    // 递归式
    root->lChild = create(preL+1, preL+numLeft, inL, inL+numLeft-1);
    //或者写 create(preL+1, preL+numLeft, inL, k-1);  都可以，因为numLeft来源于k: numLeft = k - inL
    root->rChild = create(preL+numLeft+1, preR, inL+numLeft+1, inR);
    //或者写 create(preL+numLeft+1, preR, k+1, inR);
    //上面式子最好上下对应写，即：先写先序的左子树和右子树，在写中序的左右

    return root;
}

int j = 1;
void dfs(node* root) {  //左->右->中
    // 递归边界
    if(root == NULL) return;
    // 递归式
    dfs(root->lChild);
    dfs(root->rChild);
    if(j != N){
        printf("%d ",root->data);
        j++;
    } else {
        printf("%d",root->data);
    }

}

int main() {
    scanf("%d",&N);
    stack<int> s;
    char how[5];  //
    int x;
    int j_1 = 0, j_2 = 0;
    for(int i=0; i<N*2; i++) {
        scanf("%s",how);  //
        if(strcmp(how, "Push") == 0) {  //
            scanf("%d",&x);
            preOrder[j_1++] = x;
            s.push(x);
        } else {
            inOrder[j_2++] = s.top();  //
            s.pop();
        }
    }

    node* root = create(0, N-1, 0, N-1);

    dfs(root);

//    for(int i=0; i<N; i++) {
//        printf("%d ",preOrder[i]);
//    }
//    for(int i=0; i<N; i++) {
//        printf("%d ",inOrder[i]);
//    }
    return 0;
}

---层序中序--------------------------------------------------------------------------
ANOJ 180311 模拟 D

给一棵二叉树的层序遍历序列和中序遍历序列，求这棵二叉树的先序遍历序列和后序遍历序列。

7
3 5 4 2 6 7 1
2 5 3 6 4 7 1

3 5 2 4 6 7 1
2 5 6 1 7 4 3

#include <cstdio>

const int maxn = 10010;
int n, num, layer[maxn], in[maxn];

struct tree {
    tree *l, *r;
    int data;
    tree() {
        l = r = NULL;
        data = 0;
    }
};

void PreOrder(tree* root) {
    if(root != NULL) {
        printf("%d",root->data);
        num++;
        if(num != n) printf(" ");
        PreOrder(root->l);
        PreOrder(root->r);
    }
}

void PostOrder(tree * root) {
    if(root != NULL) {
        PostOrder(root->l);
        PostOrder(root->r);
        printf("%d",root->data);
        num++;
        if(num != n) printf(" ");
    }
}

tree* CreateTree(int* layer, int* in, int t) {  //t为当前数组(layer,in)的元素个数
    if(t == 0) return NULL;
    int Llayer[maxn], Rlayer[maxn];
    int Lin[maxn], Rin[maxn];
    tree* node = new tree;
    node->data = layer[0];
    // 在in数组中找出当前根结点的位置
    int i;
    for(i = 0; i < t; i++)
        if(in[i] == layer[0])
            break;
    // 找出in数组中的左子树和右子树
    int cnt = 0;  //count
    for(int j = 0; j < i ; j++)
        Lin[cnt++] = in[j];
    cnt = 0;
    for(int j = i+1; j < t; j++)
        Rin[cnt++] = in[j];
    cnt--;
    // 找出layer数组中的左子树和右子树
    int Llayercnt = 0;
    int Rlayercnt = 0;
    for(int j = 1; j < t ; j++)
        for(int k = 0 ; k < i ; k++)
            if(layer[j] == in[k])
                Llayer[Llayercnt++] = layer[j];
    for(int j = 1; j < t; j++)
        for(int k = i ; k < t; k++)
            if(layer[j] == in[k])
                Rlayer[Rlayercnt++] = layer[j];
    node->l = CreateTree(Llayer,Lin,Llayercnt);
    node->r = CreateTree(Rlayer,Rin,Rlayercnt);
    return node;
}

int main() {
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",&layer[i]);
    for(int i=0; i<n; i++) scanf("%d",&in[i]);
    tree* root;  // 或：tree* root = NULL;
    root = CreateTree(layer,in,n);

    num = 0;
    PreOrder(root);
    printf("\n");

    num = 0;
    PostOrder(root);

    return 0;
}