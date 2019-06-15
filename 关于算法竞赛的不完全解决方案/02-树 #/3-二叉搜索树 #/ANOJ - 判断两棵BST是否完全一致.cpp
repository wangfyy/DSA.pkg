//题目：给定1~N的两个排列，使用这两个排列分别构建两棵二叉查找树（也就是通过往一棵空树中依次插入序列元素的构建方式）。
//如果这两棵二叉查找树完全相同，那么输出YES；否则输出NO。之后，输出第一个排列对应的二叉查找树的后序序列、层序序列。
//code1:分别建两棵BST，然后把它们遍历到数组中，判断两个数组是否一致
#include <queue>
#include <vector>
using namespace std;
int N;
vector<int> a;
vector<int> b;
struct node{
	int data;
	node* L;
	node* R;
};
void insert(node* &root, int data) {
	if(root == NULL) {  ////
		root = new node;
		root->data = data;
		root->L = NULL;
		root->R = NULL;	
		return;
	}
	if(data <= root->data) insert(root->L, data);
	else insert(root->R, data);
}
void dfs1(node* tempRoot) {
	if(tempRoot == NULL) {
		return;
	}
	a.push_back(tempRoot->data);
	dfs1(tempRoot->L);
	dfs1(tempRoot->R);
}
void dfs2(node* tempRoot) {
	if(tempRoot == NULL) {
		return;
	}
	b.push_back(tempRoot->data);
	dfs2(tempRoot->L);
	dfs2(tempRoot->R);
}
int num2 = 0;
void dfs(node* root) {
	if(root == NULL) return;
	dfs(root->L);
	dfs(root->R);
	printf("%d",root->data);
	num2++;
	if(num2 == N) printf("\n");
	else printf(" ");
}
void bfs(node* root) {
	queue<node*> q;
	q.push(root);
	while(!q.empty()) {
		node* now = q.front();
		printf("%d",now->data);
		q.pop();
		if(now->L != NULL) q.push(now->L);
		if(now->R != NULL) q.push(now->R);
		if(!q.empty()) printf(" ");
	}
}
int main() {
	scanf("%d",&N);
	node* root = NULL;  ////
	node* root2 = NULL;
	for(int i=0; i<N; i++) {
		int temp;
		scanf("%d",&temp);
		insert(root,temp);
	}
	for(int i=0; i<N; i++) {
		int temp;
		scanf("%d",&temp);
		insert(root2,temp);
	}
	dfs1(root);
	dfs2(root2);
	if(a == b) printf("YES\n");
	else printf("NO\n");
	dfs(root);
	bfs(root);
	return 0;
}
//code2:建一棵BST，判别其他序列是否与该树一致
#include <cstdio>
#include <queue>
using namespace std;
int N, cnt = 0
struct node {
	int v;
	node* l;
	node* r;
	bool vis;
}
void insert(node* &root, int x) {
	if(root == NULL) {
		root = new node;
		root->v = x;
		root->l = root->r = NULL;
		return;
	}
	if(x <= root->v) insert(root->l, x);
	else  insert(root->r, x);
}
//二个序列一致即每个节点一一对应
//如果在前面出现过，而且还等于当前节点，那么返回false;如果未在前面出现过，那么只允许为当前节点，否则返回false
bool check(node* root, int x) {
	if(root->vis) {  //判断经过的节点是否在前面出现过
		if(x < root->v) check(root->l, x);
		else if(x > root->v)  check(root->r, x);
		else return false;  //如果在前面出现过，而且还等于当前节点，那么返回false
	} else {  //如果未在前面出现过，那么只允许为当前节点，否则返回false
		if(root->v == x) {
			root->vis = true;
			return true;
		} else return false;
	}
}
void postOrder(node* root) {
	if(root == NULL) return;
	postOrder(root->l);
	postOrder(root->r);
	printf("%d",root->v);
	cnt++;
	if(cnt != N) printf(" ");
}
void layerOrder(node* root) {
	queue<node*> q;
	q.push(root);
	while(!q.empty()) {
		node* now = q.front();
		printf("%d",now->v);
		q.pop();
		if(now->l != NULL) q.push(now->l);
		if(now->r != NULL) q.push(now->r);
		if(!q.empty()) printf(" ");
	}
}
int main() {
	scanf("%d",&N);
	node* root = NULL;  ////
	for(int i=0; i<N; i++) {
		int temp;
		scanf("%d",&temp);
		insert(root,temp);
	}
	int num = 0;
	for(int i=0; i<N; i++) {
		int temp;
		scanf("%d",&temp);
		if(check(root,temp)) num++;
	}
	if(num == N) printf("YES\n");
	else printf("NO\n");
	cnt = 0;
	postOrder(root);
	printf("\n");
	cnt = 0;
	layerOrder(root);
	return 0;
}