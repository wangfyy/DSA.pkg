
### 若是没有边属性的话，则一般用邻接表存储；(图的遍历一般没有边权，所以一般用邻接表)
### 若有边属性的话，则直接用矩阵。


// 图的存储和遍历

// 存储图
// 顶点数较大(一般大于1000)时，需要邻接表而非邻接矩阵来存储图：
struct Node {
	int v;  //顶点编号
	int w;  //权值
	Node (int _v, int _w) : v(_v), w(_w) {}  //构造函数
}
vector<Node> Adj[N];
Adj[1].push_back(Node(3,4));  // 添加数据


//【注意】：
// DFS —— 深度优先 —— 抓住一个点直到底 —— 是通过递归来实现的；
// BFS —— 广度优先 —— 层序遍历 —— 是通过队来实现的。

// DFS遍历图
const MAXV = 1000;
const INF = 1000000000;
// 邻接矩阵版
int n,G[MAXV][MAXV];
bool vis[MAXV] = {false};
void DFS(int u, int depth) {
	vis[u] = true;
	// 此处可以添加对u一些操作
	for(int v=0; v<n; v++) {  //遍历“从u出发能够到达的顶点v”并递归
		if(vis[v] == false && G[u][v] != INF) {
			DFS(v,depth+1);
		}
	}
}
void DFSTrave() {
	for(int u=0; u<n; u++) {  //使其访问到每个连通块
		if(vis[u] == false) {
			DFS(u,1);
		}
	}
}
// 邻接表版
int n;
vector<int> Adj[MAXV];  //数组Adj[MAXV]有MAXV项，每个项都是一个变长数组   // "Adj"--邻接的
bool vis[MAXV] = {false};
void DFS(int u, int depth) {
	vis[u] = true;
	// 此处可以添加对u一些操作
	for(int i=0; i<Adj[u].size(); i++) {  //遍历“从u出发能够到达的顶点v”并递归
		int v = Adj[u][i];
		if(vis[v] == false) {
			DFS(v,depth+1);
		}
	}
}
void DFSTrave() {
	for(int u=0; u<n; u++) {  //使其访问到每个连通块
		if(vis[u] == false) {
			DFS(u,1);
		}
	}
}
// 例 PAT-A-1034 p354

// BFS遍历图
// 邻接矩阵版
int n,G[MAXV][MAXV];
bool inq[MAXV] = {false};  //若顶点i曾入过队，则inq[i]==true
void BFS(int u) {
	queue<int> q;
	q.push(u);
	inq[u] = true;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int v=0; v<n; v++) {
			if(inq[v] == false && G[u][v] != INF) {
				q.push(v);
				inq[v] = true;
			}
		}
	}
}
void BFSTrave() {
	for(int u=0; u<n; u++) {  //使其访问到每个连通块
		if(inq[u] == false) {
			BFS(q);  // ? u
		}
	}
}
// 邻接表版
int n;
vector<int> Adj[MAXV];  //数组Adj[MAXV]有MAXV项，每个项都是一个变长数组
bool inq[MAXV] = {false};
void BFS(int u) {
	queue<int> q;
	q.push(u);
	inq[u] = true;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i=0; i<Adj[u].size(); i++) {
			int v = Adj[u][i];
			if(inq[v] == false) {
				q.push(v);
				inq[v] = true;
			}
		}
	}
}
void BFSTrave() {
	for(int u=0; u<n; u++) {  //使其访问到每个连通块
		if(inq[u] == false) {
			BFS(q);  // ? u
		}
	}
}
// 当需要:给定起始点的情况下，输出该连接块内所有顶点的层号。BFS函数如下：
struct Node {
	int v;
	int layer;
};
int n;
vector<Node> Adj[MAXV];  //数组Adj[MAXV]有MAXV项，每个项都是一个变长数组
bool inq[MAXV] = {false};
void BFS(int s) {  //s为起始点
	queue<Node> q;
	Node start;
	start.v = s;
	start.layer = 0;
	q.push(start);
	inq[start] = true;
	while(!q.empty()) {
		Node topNode = q.front();
		q.pop();
		int u = topNode.v;
		for(int i=0; i<Adj[u].size(); i++) {
			Node next = Adj[u][i];
			next.layer = topNode.layer + 1;
			if(inq[next] == false) {  //为下次出队而准备(即入队操作)
				q.push(next);
				inq[next.v] = true;
			}
		}
	}
}
// 例 PAT-A-1076 p363