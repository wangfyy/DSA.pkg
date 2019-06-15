以下代码全都不对，则良机重写！



1018. Public Bike Management (30)

There is a public bike service in Hangzhou City which provides great convenience to the tourists from all over the world. 
One may rent a bike at any station and return it to any other stations in the city. 借还不同站

The Public Bike Management Center (PBMC) keeps monitoring(监控) the real-time(实时) capacity of all the stations. 
A station is said to be in perfect condition if it is exactly half-full. 据说如果一个车站恰好处于半满状态，那么它就处于完美状态。
If a station is full or empty, PBMC will collect or send bikes to adjust the condition of that station to perfect. 
And more, all the stations on the way will be adjusted as well.
	如果一个车站是满的或空的，PBMC将收集或发送自行车来调整车站的状况，以完善。
	而且，沿途所有的车站都将进行调整。

When a problem station is reported(报道), PBMC will always choose the shortest path to reach that station. 
If there are more than one shortest path, 
the one that requires the least(最少) number of bikes sent from PBMC (PBMC送出的车) will be chosen.

Figure 1 illustrates an example. The stations are represented by vertices and the roads correspond to the edges. 
The number on an edge is the time taken to reach one end station from another. 
The number written inside a vertex S is the current number of bikes stored at S. 
Given that the maximum capacity of each station is 10. To solve the problem at S3, 
we have 2 different shortest paths:

1. PBMC -> S1 -> S3. In this case, 4 bikes must be sent from PBMC, 
because we can collect 1 bike from S1 and then take 5 bikes to S3, 
so that both stations will be in perfect conditions.

2. PBMC -> S2 -> S3. This path requires the same time as path 1, 
but only 3 bikes sent from PBMC and hence(因此) is the one that will be chosen.

Input Specification:
Each input file contains one test case. For each case, the first line contains 4 numbers: 
Cmax (<= 100), always an even number(偶数), is the maximum capacity of each station; 总是一个偶数，是每个站的最大容量。
N (<= 500), the total number of stations; 
Sp, the index of the problem station (the stations are numbered from 1 to N, and PBMC is represented by the vertex 0); 
	PBMC由顶点0表示。
and M, the number of roads. 
The second line contains N non-negative numbers Ci (i=1,...N) where each Ci is the current number of bikes at Si respectively. 
Then M lines follow, each contains 3 numbers: Si, Sj, and Tij 
which describe the time Tij taken to move betwen stations Si and Sj. 
All the numbers in a line are separated by a space.

Output Specification:
For each test case, print your results in one line. 
First output the number of bikes that PBMC must send. Then after one space, 
output the path in the format: 0->S1->...->Sp. Finally after another space, 
output the number of bikes that we must take back to PBMC after the condition of Sp is adjusted to perfect.

Note that if such a path is not unique, 
output the one that requires minimum number of bikes that we must take back to PBMC. 
The judge's data guarantee that such a path is unique.  '
	请注意，如果这样的路径不是唯一的，输出需要最少数量的我们必须带回PBMC的自行车的那条路径。
	判题系统的数据保证了这样一条道路是独一无二的。 ？？？


Sample Input:
10 3 3 5     // Cmax--每个站的最大容量；N--站的数量；Sp--问题站的编号；M--路的数目。
6 7 0        // N个：当前在每个站的自行车数目(点权)
0 1 1        // 以下M行： Si, Sj, Tij --- the time(时间) taken to move betwen stations Si and Sj(相当于距离).
0 2 1
0 3 3
1 3 1
2 3 1
Sample Output:
3 0->2->3 0     //少了的话，需要PBMC发出的    //多了的话，需要PBMC收入的


【代码框架】
1.	建图。
2.	0号为起点，Sp为终点。
3.	Dijkstra(起点0),生成pre数组。
4.	DFS(终点Sp) 有多条最短路径时，选择点权最优的那条输出。
	最优：选择PBMC送出/收入的车最少的那条。
		实现：[路径上所有的结点的自行车的数量和(点权和)] - [(10 / 2) * 节点数] 差的绝对值   为最小。


----- 代码 -----
#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 510;
const int INF = 1000000000;

int Cmax, N, Sp, M;
int diff_ThisPath, minShouru = INF, minFachu = INF;	
// 本条路径上的点权和与完美值的差值(为正时,与minShouru比较;为负时,与minFachu比较)；
// 当前所有路径的收入/发出的车数值的最优值 ----- 都用于DFS()中
int G[MAXN][MAXN], d[MAXN];  //// 起点到达各顶点的最短距离(注意这不是题目给出的)   //// 初始时，除d[s]=0外，其他各点的d[i]均为INF
int weight[MAXN];	// 图(两下标代表结点,值代表两节点的距离) ----- dijkstra()中；点权 ----- 用于DFS()中
vector<int> pre[MAXN];				// 前驱 ----- dijkstra()和DFS()的连接纽带
vector<int> path, tempPath;			// 最优路径，临时路径 ----- 用于DFS()中
bool vis[MAXN] = {false};

void Dijkstra(int s) {
	// 初始化 d[]
	fill(d,d+MAXN,INF);
	d[s] = 0;
	// 循环n次
	for(int i=0; i<N + 1; i++) {
		// 寻找未访问过的d[u]最小的u，作为中介
		int u = -1, MIN = INF;
		for(int j=1; j<N + 1; j++) {
			if(vis[j] == false && d[j] < MIN) {
				MIN = d[j];
				u = j;
			}
		}
		// 若找不到
		if(u == -1) {
			return;
		}
		// 找到u后
		vis[u] = true;
		for(int v=1; v<N; v++) {  //枚举从u可到达的顶点v
			if(G[u][v] != INF && vis[v] == false) {
				if(d[u] + G[u][v] < d[v]) {  //当以u为中介时，可使d[v]更小
					d[v] = d[u] + G[u][v];
					pre[v].clear();  // 把v原来的前驱节点清空
					pre[v].push_back(u);  // 把u作为v的前驱节点
				} else if(d[u] + G[u][v] == d[v]) {
					pre[v].push_back(u);  // 把u作为j的前驱节点
				}
			}
		}
	}
}

void DFS(int v) {

	// 递归边界
	int flag = 0;
	for(int i=0; i<pre[v].size(); i++) {
		if(pre[v][i] == 0) flag = 1;
	}
	if(flag == 1) {
		tempPath.push_back(v);    ////////
		int value = 0;  // 归零
		for(int i=0; i<tempPath.size(); i++) { ///////////////// 本函数里四句(带有..../////....标记) 成就了:此处使用的tempPath ！！
			value += weight[tempPath[i]];
		}
		if(value >= (Cmax / 2) * tempPath.size()) {  // 收回
			if(value - (Cmax / 2) * tempPath.size()< minShouru) {  //
				minShouru = value - (Cmax / 2) * tempPath.size();
				path = tempPath;
			}
		} else {  // 发出
			if((Cmax / 2) * tempPath.size()- value < minFachu) {  //
				minFachu = (Cmax / 2) * tempPath.size()- value;
				path = tempPath;
			}
		}
		tempPath.pop_back();    ////////
		return;
	}

	// 递归式
	tempPath.push_back(v);    //////// 将当前访问的节点加入临时路径tempPath的最后面
	for(int i=0; i<pre[v].size(); i++) {  // 遍历并递归v的所有前驱节点
		DFS(pre[v][i]);
	}
	tempPath.pop_back();    //////// 遍历完所有前驱节点，将当前节点v删除
}

int main() {
	// 输入
	scanf("%d%d%d%d",&Cmax,&N,&Sp,&M);
	for(int i=0; i<N; i++) {
		scanf("%d",&weight[i]);
	}
	fill(G[0], G[0] + MAXN * MAXN, INF);
	for(int i=0; i<M; i++) {
		int s1, s2;
		scanf("%d%d",&s1,&s2);
		scanf("%d",&G[s1][s2]);
	}

	Dijkstra(0);  // 起点为0号站PBMC，目的为得到前驱pre[]
	
	DFS(Sp);  // 因为是利用的pre[]所以刚开始输入的参数为终点，终点为Sp号问题车站，目的为得到路径path[]

	// 输出
	if(minFachu <= minShouru) {    //
		printf("%d ",minFachu);
	} else {
		printf("0 ");
	}
	for(int i = path.size() - 1; i >= 0; i--) {
		if(i != 0) {
			printf("%d->",path[i]);
		}else {
			printf("%d",path[i]);
		}
	}
	if(minFachu > minShouru) {    //
		printf(" %d",minShouru);
	} else {
		printf(" 0");
	}

	return 0;
}




第二遍代码-----------------------------------------------------------------------
Sample Input:
10 3 3 5     // Cmax--每个站的最大容量；N--站的数量；Sp--问题站的编号；M--路的数目。
6 7 0        // N个：当前在每个站的自行车数目(点权)
0 1 1        // 以下M行： Si, Sj, Tij --- the time(时间) taken to move betwen stations Si and Sj(相当于距离G[a][b]的值).
0 2 1
0 3 3
1 3 1
2 3 1
Sample Output:
3 0->2->3 0     //少了的话，需要PBMC发出的    //多了的话，需要PBMC收入的



#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000000;

int Cmax, N, Sp, M;
int G[MAXN][MAXN], d[MAXN];
bool vis[MAXN];
vector<int> pre[MAXN];
int weight[MAXN];
vector<int> path, tempPath;
int flag1;
int minX = INF;

void Dijkstra(int s) {
	fill(d,d+MAXN,INF);
	d[s] = 0;

	for(int i=0; i<N; i++) {
		int u = -1, min = INF;
		for(int j=0; j<N; j++) {
			if(vis[j] == false && d[j] < min) {  ////
				min = d[j];
				u = j;
			}
		}

		if(u == -1) return;
		vis[u] = true;
		for(int v=0; v<N; v++) {
			if(vis[v] == false && G[u][v] != INF) {  ////
				if(d[u] + G[u][v] < d[v]) {
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
	// 递归边界
	int flag = 0;
	for(int i=0; i<pre[v].size(); i++) {
		if(pre[v][i] == 0) flag = 1;
	}
	if(flag == 1) {
		tempPath.push_back(v);
		int num = 0;
		for(int i=0; i<tempPath.size();i++) {
			num += weight[tempPath[i]];
		}
		if(num >= Cmax/2*tempPath.size()) {  //收入
			flag1 = 1;
		} else {  //发出
			flag1 = 2;
		}
		int x = num - Cmax/2*tempPath.size();
		if(x < minX) {
			minX = x;
			path = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	// 递归式
	tempPath.push_back(v);
	for(int i=0; i<pre[v].size(); i++) {
		DFS(pre[v][i]);
	}
	tempPath.pop_back();
}

int main() {
	scanf("%d%d%d%d",&Cmax,&N,&Sp,&M);
	for(int i=0; i<N; i++) {
		scanf("%d",&weight[i]);
	}
	N++;
	fill(G[0],G[0]+MAXN*MAXN,INF);  ////
	for(int i=0; i<M; i++) {
		int Si, Sj;
		scanf("%d%d",&Si,&Sj);
		scanf("%d",&G[Si][Sj]);
	}

	Dijkstra(0);

	DFS(Sp);

	if(flag1 == 2) printf("%d ",minX);
	else printf("0 ");
	for(int i=0; i<path.size(); i++ ) {
		printf("%d",path[i]);
		if(i != path.size()) printf("->");
	}
	if(flag1 == 1) printf(" %d",minX);
	else printf(" 0");

	printf("\n");
	for(int i=0; i<N; i++ ) {
        if(vis[i] == false)
            printf("%d",i);
	}

	return 0;
}



=====================================================================================================================
// 建图，0号为起点，Sp为终点。
// 最优:选择PBMC送出/收入的车最少的那条。即abs([路径上所有的结点的自行车的数量和(点权和)] - [(10 / 2) * 节点数])为最小。
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 1010;
const int INF = 1000000000;
int Cmax, N, Sp, M;
int G[MAXN][MAXN], d[MAXN], weight[MAXN];
bool vis[MAXN];
vector<int> pre[MAXN], path, tempPath;
int flag1, minX = INF;
void Dijkstra(int s) {
	fill(d,d+MAXN,INF);
	d[s] = 0;
	for(int i=0; i<N; i++) {
		int u = -1, min = INF;
		for(int j=0; j<N; j++) {
			if(vis[j] == false && d[j] < min) {
				min = d[j];
				u = j;
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v=0; v<N; v++) {
			if(vis[v] == false && G[u][v] != INF) {
				if(d[u] + G[u][v] < d[v]) {
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
	if(v == 0) {
		int num = 0;
		for(int i=0; i<tempPath.size();i++)
			num += weight[tempPath[i]];
		int x = num - Cmax / 2 * tempPath.size();
		if(abs(x) < abs(minX)) {
			minX = x;
			path = tempPath;
		}
		return;
	}
	tempPath.push_back(v);
	for(int i=0; i<pre[v].size(); i++)
		DFS(pre[v][i]);
	tempPath.pop_back();
}
int main() {
	scanf("%d%d%d%d",&Cmax,&N,&Sp,&M);
	for(int i=0; i<N; i++)
		scanf("%d",&weight[i]);
	N++;  //加上pbmc所在的0结点
	fill(G[0], G[0] + MAXN * MAXN, INF);
	for(int i=0; i<M; i++) {
		int Si, Sj;
		scanf("%d%d",&Si,&Sj);
		scanf("%d",&G[Si][Sj]);
		G[Sj][Si] = G[Si][Sj];
	}
	Dijkstra(0);  //生成前驱
	DFS(Sp);
	if(minX > 0) printf("%d 0",abs(minX));
	else printf("0 0");
	for(int i=0; i<path.size(); i++)
		printf("->%d",path[i]);
	if(minX < 0) printf(" %d",abs(minX));
	else printf(" 0");
	return 0;
}