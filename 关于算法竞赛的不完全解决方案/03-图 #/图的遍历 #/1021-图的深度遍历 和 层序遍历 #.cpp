Deepest Root.(最深的根)

	A graph which is connected and acyclic(无环) can be considered(被认为是) a tree. 
	The height of the tree depends on the selected root. 
Now you are supposed to find the root that results in a highest tree. Such a root is called the deepest root.

Input Specification:
Each input file contains one test case. For each case, 
the first line contains a positive integer N (<=10000) which is the number of nodes, 
and hence the nodes are numbered from 1 to N. Then N-1 lines follow, 
each describes an edge by given the two adjacent nodes' numbers.     '

Output Specification:
For each test case, print each of the deepest roots in a line. 
If such a root is not unique, print them in increasing order of their numbers. 
In case that the given graph is not a tree, 
print "Error: K components (组件)" where K is the number of connected components(组件 即:连通块) in the graph.

Sample Input 1:
5     N个节点
1 2     (N-1)条边
1 3
1 4
2 5
Sample Output 1:
3
4
5

Sample Input 2:
5
1 3
1 4
2 5
3 4
Sample Output 2:
Error: 2 components


本题涉及：
1. 图和树
2. 图转为树的条件————图连通 且 有N-1条边。


【代码框架】
1. 	建图
2. 	因为本题不仅要判断图是否连通，还要知道有多少块(当不连通时)，
	所以要用类似T1013中的“图遍历”或“并查集”两种途径判断：“块数是否为1，否则多少块”。
	(((深度遍历)))
3. 	当连通块数为1时：
		main()中枚举每个节点当做根节点，然后调用树的层序遍历，
		设置一个current_layer[MAXN]存放此树中各节点的层数，最大层数即为树的高度，
		layer[]记录每个当作根结点时树的最大高度。
	(((层序遍历)))
4.	输出layer数组的最大值的下标。

=============================================================================================================
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 10100;
vector<int> G[MAXN];
int layer[MAXN];
bool vis[MAXN];
// 因为本题图为无向无环图，所以“深度遍历(多连接块)”和“层序遍历”中都用到vis[]，
// 若图为有向无环图，则不用vis[]
int blocks = 0;
int N;

void dfs(int v) {
	if(vis[v] == false) {  ////因为是无向图
		vis[v] = true;
		for(int i=0; i<G[v].size(); i++) {
			dfs(G[v][i]);
		}
		//return;
	}
}

void count_blocks() {
	for(int i=1; i<=N; i++) {
		if(vis[i] == false) {
			dfs(i);
			blocks ++;
		}
	}
}

void solve_layer(int v) {  // 求以v作为根结点时树的层数
	queue<int> q;
	q.push(v);  //// 初始仅push(root)
	vis[v] = true;
	int current_layer[MAXN];  // 存放每个节点的层数
	current_layer[v] = 1; 
	while(!q.empty()) {  // 若为空，下面代码就没得pop()，所以判断
		int front = q.front();  // 队列头元素
		//// 先出后入
		q.pop();
		for(int i=0; i<G[front].size(); i++) {
			if(vis[G[front][i]] == false) {  //////////////////// 无向图的存储需要判断；树的存储不需要判断（因为树的存储是有向的）。 
				q.push(G[front][i]);
				vis[G[front][i]] = true;
				current_layer[G[front][i]] = current_layer[front] + 1;							
			} 
		}		
	}
	
	// current_layer[]的最大值 即为树的高度  //其实在上面的代码中就可以实现记录最大深度，从而记录每个根结点时树的深度
	int max_current_layer = -1;
	for(int i=1; i<=N; i++) {
		if(current_layer[i] > max_current_layer)
			max_current_layer = current_layer[i];
	}
	layer[v] = max_current_layer;  // 记录树的高度
}

int main() {
	// 建图
	scanf("%d",&N);
	int a,b;
	for(int i=0; i<N-1; i++) {
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	// 判断块数
	memset(vis,false,sizeof(vis));
	count_blocks();
	if(blocks != 1) {
		printf("Error: %d components",blocks);
		return 0;
	}
	// 枚举每个节点作根
	for(int i=1; i<=N; i++) {
		memset(vis,false,sizeof(vis));
		solve_layer(i);
	}
	// 寻找最大层数(layer[]的最大值)  //用vector会方便一些
	int max_layer = -1;
	int temp[MAXN];  // 存放layer[]的最大值的下标
	int current;
	for(int i=1; i<=N; i++) {
		if(layer[i] == max_layer) {
			temp[current++] = i;  //下标
		}
		if(layer[i] > max_layer) {
			current = 0;
			temp[current++] = i;
			max_layer = layer[i];  ////
		}
	}
	// 输出最大值的下标
	for(int i=0; i<current; i++) {
		printf("%d\n",temp[i]);
	}

	return 0;
}


=============================================================================================================
//存到图中，遍历图计算连通块个数，若为1则遍历每个节点当做树根节点，计算层数，存储有最大层数的节点。
//code1:(AC)
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN = 10010;
vector<int> G[MAXN];
bool vis[MAXN], vis2[MAXN];
int N;
void DFS(int v) {
	if(!vis[v]) {
		vis[v] = true;
		for (int i = 0; i < G[v].size(); ++i)
			DFS(G[v][i]);
	}
}
int countDeep(int v) {
	queue<int> q;
	q.push(v);
	vis2[v] = true;  //因为是无向图 
	int layer[MAXN];  ////计层 
	layer[v] = 1; 
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < G[now].size(); ++i) {
			if(!vis2[G[now][i]]) {
				q.push(G[now][i]);
				vis2[G[now][i]] = true;
				layer[G[now][i]] = layer[now] + 1;	
			}
		}
	}
	int max_layer = -1;
	for(int i=1; i<=N; i++)
		max_layer = max(layer[i], max_layer);
	return max_layer;
}
int main() {	
	scanf("%d",&N);
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);  //无向图
	}
	int cnt = 0;
	for (int i = 1; i <= N; ++i) {
		if(!vis[i]) {
			DFS(i);
			cnt++;
		}
	}
	if (cnt != 1) {
		printf("Error: %d components",cnt);
		return 0;
	}
	vector<int> collect;
	int MAXD = -1;
	for (int i = 1; i <= N; ++i) {
		memset(vis2,false,sizeof(vis2));
		int D = countDeep(i);
		if(D > MAXD) {
			collect.clear();
			collect.push_back(i);
			MAXD = D;  ////UPDATA 
		} else if(D == MAXD) collect.push_back(i);
	}
	for (int i = 0; i < collect.size(); ++i)
		printf("%d\n",collect[i]);
	return 0;
}
//code2:(卡NO.1测试点)  为啥？？
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN = 10010;
vector<int> G[MAXN];
bool vis[MAXN], vis2[MAXN];
int N;
void DFS(int v) {
	if(!vis[v]) {
		vis[v] = true;
		for (int i = 0; i < G[v].size(); ++i)
			DFS(G[v][i]);
	}
}
int countDeep(int v) {
	queue<int> q;
	q.push(v);
	int D = 1;  ////为啥这样的计层不行？测试没错啊
	vis2[v] = true;  //因为是无向图 
	bool flag2;  ////计层标记 
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < G[now].size(); ++i) {
			if(!vis2[G[now][i]]) {
				q.push(G[now][i]);
				vis2[G[now][i]] = true;
				flag2 = true;
				//printf("> %d %d\n",D,G[now][i]); 
			}
		}
		if (flag2) D++;
		flag2 = false;
	}
	//printf("\n");
	return D;
}
int main() {	
	scanf("%d",&N);
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);  //无向图
	}
	int cnt = 0;
	for (int i = 1; i <= N; ++i) {
		if(!vis[i]) {
			DFS(i);
			cnt++;
		}
	}
	if (cnt != 1) {
		printf("Error: %d components",cnt);
		return 0;
	}
	vector<int> collect;
	int MAXD = -1;
	for (int i = 1; i <= N; ++i) {
		memset(vis2,false,sizeof(vis2));
		int D = countDeep(i);
		if(D > MAXD) {
			collect.clear();
			collect.push_back(i);
			MAXD = D;  ////UPDATA 
		} else if(D == MAXD) collect.push_back(i);
	}
	for (int i = 0; i < collect.size(); ++i)
		printf("%d\n",collect[i]);
	return 0;
}