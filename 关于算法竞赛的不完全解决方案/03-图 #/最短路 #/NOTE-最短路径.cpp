// 最短路径

### 若是没有边属性的话，则一般用邻接表存储；(图的遍历一般没有边权，所以一般用邻接表)
### 若有边属性的话，则直接用矩阵。


// 【【Dijkstra算法】】-单源最短路
// 算法概述：找一个‘未访问过的’‘d[u]最小’的u作为源点到v的中介，若d[u] + G[u][v] < d[v]，则d[v] = d[u] + G[u][v]
// 【**题型一】求解输出：起点到各点的最短距离，即————求d[]
// 邻接矩阵版
const MAXV = 1000;
const INF = 1000000000;
int n,G[MAXV][MAXV];  // n为顶点个数
int d[MAXV];  //起点到达各顶点的最短距离。注意是数组，下标为顶点号，元素为源点到该顶点的最短距离。
bool vis[MAXV] = {false};
void Dijkstra(int s) {  //s为起点
	fill(d,d+MAXV,INF);
	d[s] = 0;
	for(int i=0; i<n; i++) {  //循环n次
		//寻找未被访问过的顶点u中d[u]最小的那个u
		int u = -1, MIN = INF;
		for(int j=0; j<n; j++) {
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		//若未找到上述u，说明剩下的顶点和起点s不连通
		if(u == -1) return;
		//找到符合上述要求的u后
		vis[u] = true;
		for(int v=0; v<n; v++) {  //枚举从u可到达的顶点v
			if(int vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]) {  // 中介u
				d[v] = d[u] + G[u][v];
			}
		}
	}
}  //时间复杂度为: O(V^2)
// 邻接表版
struct Node {
	int v;  //边的目标顶点
	int dis;  //边的权值
};
vector<Node> Adj[MAXV];
int n;
int d[MAXV];  //起点到达各顶点的最短距离
bool vis[MAXV] = {false};
void Dijkstra(int s) {  //s为起点
	fill(d,d+MAXV,INF);
	d[s] = 0;
	for(int i=0; i<n; i++) {  //循环n次
		//寻找未被访问过的顶点u，使d[u]最小
		int u = -1, MIN = INF;
		for(int j=0; j<n; j++) {
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		//若未找到上述u，说明剩下的顶点和起点s不连通
		if(u == -1) return;
		//找到符合上述要求的u后
		vis[u] = true;
		for(int j=0; j<Adj[u].size(); j++) {  //枚举从u可到达的顶点v
			int v = Adj[u][j].v;
			if(int vis[v] == false && d[u] + Adj[u][j].dis < d[v]) {
				d[v] = d[u] + Adj[u][j].dis;
			}
		}
	}
}  //时间复杂度为: O(V*V + E)

// 【**题型二】求解输出：从‘给定的起点s’到‘给定的终点v’的最短的路径
// 即增设：记录v的前驱顶点是u ———— pre[v] = u
// 邻接矩阵版
const MAXV = 1000;
const INF = 1000000000;
int n,G[MAXV][MAXV];
int d[MAXV];  //起点到达各顶点的最短距离
int pre[MAXV];  //////pre[v]表示：从起点到v的最短路径上v的前一个顶点 
bool vis[MAXV] = {false};
void Dijkstra(int s) {  //s为起点
	fill(d,d+MAXV,INF);
	for(int i=0; i<n; i++) pre[i] = i; //////初始状态设每个点的前驱为自身   为什么都为本身？？而不是直接pre[s] = s; ？？
	d[s] = 0;
	for(int i=0; i<n; i++) {  //循环n次
		//寻找未被访问过的顶点u，使d[u]最小
		int u = -1, MIN = INF;
		for(int j=0; j<n; j++) {
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		//若未找到上述u，说明剩下的顶点和起点s不连通
		if(u == -1) return;
		//找到符合上述要求的u后
		vis[u] = true;
		for(int v=0; v<n; v++) {  //枚举从u可到达的顶点v
			if(int vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]) {
				d[v] = d[u] + G[u][v];
				pre[v] = u;  ////// 记录v的前驱顶点是u
			}
		}
	}
}
void DFS(int s,int v) {  //s是起点编号(可以设为全局变量)，v为当前访问的顶点编号(从终点开始递归，见下文：DFS(s,pre[v]);)
	if(s == v) {  //如果当前已到达起点，则输出起点并返回
		printf("%d\n",s);
		return;
	}
	DFS(s,pre[v]);
	printf("%d\n",v);  //从深处return回来之后输出每一层的顶点号，所以输出顺序是：起点到终点
}

// 【**题型三 - 方法一】Dijkstra算法+内置数组 ，解决第二标尺：边权、点权、条数
// 新增边权(代表花费)注意与d[]区分 （替换Dijkstra中的“枚举从u可到达的顶点v”部分代码）
cost[u][v]代表：u->v的花费，由题目输入；
"c[u]"代表：起点s->u的最少花费，初始化时只有c[s]为0、其余c[u]均为INF；
for(int v=0; v<n; v++) {  //枚举从u可到达的顶点v（代替上面的此部分代码）
	if(int vis[v] == false && G[u][v] != INF) {
		if(d[u] + G[u][v] < d[v]) {
			d[v] = d[u] + G[u][v];
			c[v] = c[u] + cost[u][v];
			pre[v] = u;  // 记录v的前驱顶点是u
		}else if(d[u] + G[u][v] == d[v] && c[u] + cost[u][v] < c[v]) {
			c[v] = c[u] + cost[u][v];
			pre[v] = u;  // 记录v的前驱顶点是u
		}
	}
}
// 新增点权(代表城市中能收集到的物资)（替换Dijkstra中的“枚举从u可到达的顶点v”部分代码）
weight[u]代表：u中的物资数目，由题目输入；
"w[u]"代表：从起点s到达u可收集到的最大物资，初始化时只有w[s]为weight[s]、其余w[u]均为0；
for(int v=0; v<n; v++) {  //枚举从u可到达的顶点v
	if(int vis[v] == false && G[u][v] != INF) {
		if(d[u] + G[u][v] < d[v]) {
			d[v] = d[u] + G[u][v];
			w[v] = w[u] + weight[v];
			pre[v] = u;  // 记录v的前驱顶点是u
		}else if(d[u] + G[u][v] == d[v] && w[u] + weight[v] > w[v]) {
			w[v] = w[u] + weight[v];
			pre[v] = u;  // 记录v的前驱顶点是u
		}
	}
}
// 新增求最短路径条数（替换Dijkstra中的“枚举从u可到达的顶点v”部分代码）
"num[u]"代表：从起点s到达u的最短路径条数，初始化时只有num[s]为1、其余num[u]均为0；
for(int v=0; v<n; v++) {  //枚举从u可到达的顶点v
	if(int vis[v] == false && G[u][v] != INF) {
		if(d[u] + G[u][v] < d[v]) {  //当以u为中介时，可是d[v]更小
			d[v] = d[u] + G[u][v];
			num[v] = num[u];  ////num[v]继承num[u]
			pre[v] = u;  // 记录v的前驱顶点是u
		}else if(d[u] + G[u][v] == d[v]) {  //以u为中介时，d[v]一样
			num[v] += num[u];  ////将num[u]加到num[v]上
			pre[v] = u;  // 记录v的前驱顶点是u
		}
	}
}


// 【***题型三 - 方法二】Dijkstra算法+DFS ，解决第二标尺：边权、点权、条数
最新笔记---------------------------------------------------------------------
// Dijkstra+DFS ---------------------------------------------------------
#include <cstdio>
const int MAXV = 1000;
const int INF = 1000000000;
int n, G[MAXV][MAXV], d[MAXV], optValue;
bool vis[MAXV];
vector<int> pre[MAXV], tempPath[MAXV], path[MAXV];
void Dijkstra(int s) {
	fill(d, d+MAXV, INF);
	d[s] = 0;
	for(int i=0; i<n; i++) {
		//寻找未被访问过的d[u]最小的u
		int u = -1, MIN = INF;
		for(int u=0; u<n; u++) {
			if(vis[u] == false && d[u] < MIN) {
				u = u;
				MIN = d[u];
			}
		}
		if(u == -1) return;
		vis[u] = true;
		//若d[u]+G[u][v]<d[v]，则d[v]=d[u]+G[u][v]  
		for(int v=0; v<n; v++) {
			if(vis[v] == false && G[u][v] != INF) {
				if(d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				} else if(d[u] + G[u][v] == d[v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
}
void DFS(int v) {
	if(v == st) {
		tempPath.push_back(v);  ///
		int value = 0;
		//求边权和
		for(int i=tempPath.size()-1; i>=0; i++) {//因为tempPath里的路径是倒着的
			int id = tempPath[i], idNext = tempPath[i-1];
			value += V[id][idNext];
		}
		//求点权和
		for(int i=tempPath.size()-1; i>=0; i++) {
			int id = tempPath[i];
			value += w[id];
		}
		//求对短路条数
		// 既可以按之前的方法：  在Dijkstra中添加数组num[]（即起点到u的最短路条数为num[u]，注意是数组：下标为u，元素为源点到u的最短路条数）；
		// 也可以：              开一个全局变量来记录对短路的条数，当DFS到达叶子节点st时，全局变量++ 。
		if(value优于optValue) {
			optValue = value;
			path = tempPath;
		}
		tempPath.pop_back();  ///
	}
	tempPath.push_back(v);  ///
	for(int i=0; i<prte[v].size(); i++) {
		DFS(pre[v][i]);
	}
	tempPath.pop_back();  ///
}
int main() {
	fill(G[0], G[0]+MAXV, INF);
	//读入
	Dijkstra(起点);
	DFS(终点);
	//输出
	return 0;
}

之前笔记---------------------------------------------------------------------
// 即：先在Dijkstra算法中记录下所有最短路径(值考虑距离)，然后从这些最短路中选出一条第二标尺最优的路径
// Dijkstra部分：(邻接矩阵版)
const MAXV = 1000;
const INF = 1000000000;
int n,G[MAXV][MAXV];
int d[MAXV];  //起点到达各顶点的最短距离  //// 初始时，除d[s]=0外，其他各点的d[i]均为INF
//int pre[MAXV];  //pre[v]表示：从起点到v的最短路径上v的前一个顶点 
bool vis[MAXV] = {false};
vector<int> pre[MAXV];
void Dijkstra(int s) {  //s为起点
	fill(d,d+MAXV,INF);
	d[s] = 0;
	// for(int i=0; i<n; i++) {  //////不需要：“初始状态设每个点的前驱为自身”了，因为下面有语句:pre[v].clear();
	// 	pre[i] = i;
	// }
	for(int i=0; i<n; i++) {  //循环n次
		//寻找未被访问过的d[u]最小的顶点u
		int u = -1, MIN = INF;
		for(int j=0; j<n; j++) {
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		//若未找到上述u，说明剩下的顶点和起点s不连通
		if(u == -1) return;
		//找到符合上述要求的u后
		vis[u] = true;
		for(int v=0; v<n; v++) {  //枚举从u可到达的顶点v
			if(vis[v] == false && G[u][v] != INF) {
				if(d[u] + G[u][v] < d[v]) {  //当以u为中介时，可使d[v]更小
					d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);  // 记录v的前驱顶点是u
				}else if(d[u] + G[u][v] == d[v]) {  //以u为中介时，d[v]一样。此处与上个方法比，少了比较的代码，拿到dfs中了
					pre[v].push_back(u);  // 记录v的前驱顶点是u
				}
			}
		}
	}
}
// DFS部分：
int optvalue;  ////第二标尺的最优值
vector<int> pre[MAXV];  //存放节点的前驱节点  //MAXV项，每项无限长
vector<int> path,tempPath;  ////最优路径、临时路径  //一项，此项无限长

void DFS(int v) {
	//v为当前访问的节点，在“调DFS函数的那条语句中”设定了起始DFS的点v，v是路径的末端。而p383图10-37中路径末端在树头，路径前端在树尾。
	
	//递归边界
	if(v == st) {  //如果当前已到达叶子节点st，即路径起点
		tempPath.push_back(v);  //将起点st加入到临时路径tempPath的最后面    ////////////////// 与‘下方第11行’的代码的作用相同
		int value = 计算路径tempPath上的value的值(见下面代码)  ////用于存放临时路径tempPath的第二标尺的值
		if(value优于optvalue) {  //// 最优路径、临时路径
			optvalue = value;
			path = tempPath;  //赋值而非指针
		}
		tempPath.pop_back();  //将刚加入的节点删除                          ////////////////// 与‘下方第8行’的代码的作用相同
		return;  //// 返回
	}

	//递归式
	tempPath.push_back(v);  //将当前访问的节点加入临时路径tempPath的最后面  //////////////////
	for(int i=0; i<pre[v].size(); i++) {  //遍历节点v的前驱节点并递归
		DFS(pre[v][i]);
	}
	tempPath.pop_back();  //遍历完所有前驱节点，将当前节点v删除             //////////////////

}

// "计算临时路径tempPath上的value的值"部分: (上述代码中省略的，可根据实际需要来填写)
	// 注意：由于pre[],由于递归，致使 ““tempPath中的路径节点是逆序的”” ，因此访问节点需要倒着进行，
	// 但若仅是对边权或点权进行求和，那么正序访问也是可以的。

////////////// 注意区分：边权、距离、d[]
			// G[i][j]里的值是i->j的距离，二维数组V[id][idNext]里的是i->j的边权，而d[]则是Dijkstra的标配
			// 例如：‘距离’作为两个城市间的距离；‘边权’作为从城市1去城市2的路费；d[]则是Dijkstra的工具。

// 求边权和
value = 0;
for(int i=tempPath.size()-1; i>0; i--) {
	int id = tempPath[i], idNext = tempPath[i-1];  //当前节点 //“下”个节点
	value += V[id][idNext];  // 数组V[id][idNext] 为 id->idNext 的边权
}
// 求点权和
value = 0;
for(int i=tempPath.size()-1; i>0; i--) {
	int id = tempPath[i];  //当前节点
	value += W[id];  // 数组W[id] 为 节点id 的点权
}
// 求最短路条数
// 既可以按之前的方法：  在Dijkstra中添加数组num[]（即起点到u的最短路条数为num[u]，注意是数组：下标为u，元素为源点到u的最短路条数）；
// 也可以：              开一个全局变量来记录对短路的条数，当DFS到达叶子节点st时，全局变量++ 。


---------------------------------------------------------------------------------------------


// 【【BF算法(Bellman-Ford)】】  时间复杂度O(V*E)
// 邻接表版
struct Node{
	int v;  //边的目标顶点
	int dis;  //边权
};
vector<Node> Adj[MAXV];
int n;
int d[MAXV];  //起点到各点的最短路径长度
bool Bellman(int s) {  //s为源点
	fill(d,d+MAXV,INF);
	d[s] = 0;
	//求解d[]数组
	for(int i=0; i<n-1; i++) {  //执行n-1轮操作，n为顶点数
		for(int u=0; u<n; u++) {  //每轮操作都遍历每个顶点，目的是：每轮操作都遍历所有边
			for(int j=0; j<Adj[u].size(); j++) {  //遍历与u相连的所有顶点，目的是：遍历与u相连的所有边
				int v = Adj[u][i].v;
				int dis = Adj[u][j].dis;
				if(d[u] + dis < d[v]) {
					d[v] = d[u] + dis;  //松弛操作
				}
			}
		}
	}
	//判断负环
	for(int u=0; u<n; u++) {  //对每条边进行判断
		for(int j=0; j<Adj[u].size(); j++) {
			int v = Adj[u][j].v;
			int dis = Adj[u][j].dis;
			if(d[u] + dis < d[v]) {  //是否仍可被松弛
				return false;  //说明图中有从原点可达的负环
			}
		}
	}
	return true;
}


// 【【SPFA算法(Shortest Path Faster Algorithm)】】  时间复杂度O(k*E)，当有源点可达负环时退化为O(V*E)
// SPFA主体部分伪代码：
queue<int> Q;
源点s入队;
while(队非空) {
	取出队首元素u;
	for(u的所有邻接边u->v) {
		if(d[u] + dis < d[v]) {  //dis为u->v的距离
			d[v] = d[u] + dis;
			if(v当前不在队列) {
				v入队;
				if(v入队的次数大于n-1) {
					说明有可达负环，return false;
				}
			}
		}
	}
}
return true;
// SPFA邻接表版(BFS实现)
vector<Node> Adj[MAXV];
int n,d[MAXV],num[MAXV];  //num[MAXV]记录顶点的入队次数。如果事先知道图中无负环，num[]可以去掉
bool inq[MAXV];  //区别于前面的“是否入过队”，此处代表“是否在队中” 
bool SPFA(int s) {
	//初始化
	memset(inq,false,sizeof(inq));
	memset(num,0,sizeof(num));
	fill(d,d+MAXV,INF);
	//源点入队
	queue<int> Q;
	Q.push(s);
	inq[s] = true;  //源点在队中
	num[s] ++;  //源点入队次数++
	d[s] = 0;  //源点到各点的最短路径长度为0
	//主体部分
	while(!Q.empty()) {
		int u = Q.front();  //取出队首元素u
		Q.pop();
		inq[u] = false;  //设置u不在队列中
		//遍历u的所有邻接边u->v
		for(int j=0; j<Adj[u].size(); j++) {
			int v = Adj[u][j].v;
			int dis = Adj[u][j].dis;
			// 松弛操作
			if(d[u] + dis < d[v]) {  //dis为u->v的距离
				d[v] = d[u] + dis;
				if(!inq[v]) {  //v当前不在队列
					Q.push(v);  //v入队
					inq[v] = true;  //设置v在队中
					num[v] ++;  //v的入队次数++
					if(num[v] > n-1) {
						return false;  //说明有可达负环
					}
				}
			}
		}
	}
	return true;
}


---------------------------------------------------------------------------------------------


// 【【*Floyd算法】】-多源最短路：求任意两点间的最短路径长度
// 算法思路：
//	 如果：dis[i][k] + dis[k][j] < dis[i][j]
// 	 则：  dis[i][j] = dis[i][k] + dis[k][j]
const int INF = 1000000000;
const int MAXV = 200;
int n,m;  //顶点数 边数
int dis[MAXV][MAXV];  //// dis[i][j]表示从顶点i到顶点j的最短距离
void Floyd() {

	for(int k=0; k<n; k++) {  //枚举中介结点k，范围[1,n]
		for(int i=0; i<n; i++) {  //枚举结点i，范围都是[1,n]
			for(int j=0; j<n; j++) {  //枚举结点j，范围都是[1,n]  ....  三个for()，致使时间复杂度为O(n^3)

				if(dis[i][k] != INF && dis[k][j] != INF && dis[i][k] + dis[k][j] < dis[i][j]) {
					//// 如果：‘ i <-> k ’ 和 ‘ j <-> k ’ 分别相连  且  dis[i][k] + dis[k][j] < dis[i][j]
					dis[i][j] = dis[i][k] + dis[k][j];
				}

			}
		}		
	}
}
int main() {
	int u,v,w;
	// 输入
	scanf("%d%d",&n,&m);
	for(int i=0; i<m; i++) {
		scanf("%d%d%d",&u,&v,&w);
		dis[u][v] = w;
	}
	// 初始化
	fill(dis[0],dis[0] + MAXV * MAXV,INF);
	for(int i=0; i<n; i++) {
		dis[i][i] = 0;  //// 将顶点i到i的距离初始化为0
	}

	Floyd();
	// 输出
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			printf("%d\n",dis[i][j]);
		}
		printf("\n");
	}

	return 0;
}