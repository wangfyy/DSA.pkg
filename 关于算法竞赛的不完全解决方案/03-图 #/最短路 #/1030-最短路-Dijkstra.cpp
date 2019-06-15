Travel Plan (30)

A traveler''s map gives the distances between cities along the highways,
together with the cost of each highway. 
Now you are supposed to write a program to help a traveler to decide :
the shortest path between his/her starting city and the destination. 
If such a shortest path is not unique, you are supposed to output :
the one with the minimum cost, 
which is guaranteed to be unique.

Input Specification:
Each input file contains one test case. 
Each case starts with a line containing 4 positive integers N, M, S, and D, 
where N (<=500) is the number of cities (and hence the cities are numbered from 0 to N-1); 
M is the number of highways; S and D are the starting and the destination cities, respectively. 
Then M lines follow, each provides the information of a highway, in the format:
City1 City2 Distance Cost
where the numbers are all integers no more than 500, and are separated by a space.

Output Specification:
For each test case, print in one line the cities along the shortest path from the starting point to the destination, 
followed by the total distance and the total cost of the path. 
The numbers must be separated by a space and there must be no extra space at the end of output.

Sample Input
4 5 0 3     // 节点数N(0 to N-1)     边数M    起点S    终点D
0 1 1 20    // City1    City2    Distance(距离)   Cost(边权(花费))
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
Sample Output
0 2 3 3 40    // 最短路径   总距离   总花费


---- 代码 ----
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 550;
const int INF = 1000000000;

int N,M,S,D;
int G[MAXN][MAXN], V[MAXN][MAXN];  // V[a][b]表示a到b的花费
int d[MAXN];  // Dijkstra标配
bool vis[MAXN] = {false};  // 编译器默认填false
vector<int> pre[MAXN];
vector<int> path, tempPath;
int value_jvli, value_cost, perfectValue_cost = INF;

void Dijkstra(int s) {	// 初始化d[]
	fill(d, d+MAXN, INF);
	d[s] = 0;   // s就在此用了一下    d[S] = 0; 也可以。 
	// N次
	for(int i=0; i<N; i++) {
		// 寻找未被访问过的d[u]最小的u
		int u = -1, MIN = INF;
		for(int j=0; j<N; j++) {
			if(vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		// 若没找到u
		if(u == -1) return;
		// 若找到u，先标记，再遍历找v 
		vis[u] = true;
		// 遍历u可达的v，当起点到v的距离，在加入中介u后，变短
		for(int v=0; v<N; v++) {
			if(vis[v] == false && G[u][v] != INF) {
				if(d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];
					pre[v].clear();		// ！！！！！ 
					pre[v].push_back(u);
				}else if(d[u] + G[u][v] == d[v]) {
					pre[v].push_back(u);
				}			
			}
		}
	}	
}

void DFS(int v) {
	// 递归边界
	if(v == S) {   // 到达起点 ！！！！！！ 
		tempPath.push_back(v);		////
		value_cost = 0;  // 归零 ！！！！ 
		// 计算tempPath上的值(本题为边权)
		for(int i=0; i<tempPath.size() - 1; i++) {
			int idNext = tempPath[i];
			int id = tempPath[i + 1];
			value_cost += V[id][idNext];
		}
//		for(int i=tempPath.size() - 1; i>0; i--) {
//			int id = tempPath[i];
//			int idNext = tempPath[i - 1];
//			value_cost += V[id][idNext];
//		}
		if(value_cost < perfectValue_cost) {
			perfectValue_cost = value_cost;
			path = tempPath;
		}
		tempPath.pop_back();			////
		return;
	}
	// 递归式
	tempPath.push_back(v);			////
	// 遍历并递归v的所有前驱节点
	for(int i=0; i<pre[v].size(); i++) {
		DFS(pre[v][i]);
	}
	tempPath.pop_back();				////
}

int main() {
	// 输入,建图
	scanf("%d%d%d%d",&N,&M,&S,&D);
	int c1, c2;
	fill(G[0], G[0]+MAXN*MAXN, INF);  // 初始化G[][]
	// fill(V[0], V[0]+MAXN*MAXN, INF);  // 无所谓 
	for(int i=0; i<M; i++) {
		scanf("%d%d",&c1,&c2);
		scanf("%d%d",&G[c1][c2],&V[c1][c2]);
//		G[c2][c1] = G[c1][c2];   // 无向图！！看题意 
//		V[c2][c1] = V[c1][c2];   //
	}
	
	Dijkstra(S);  // 生成pre[]
	
	DFS(D); // 生成path[],倒叙的
	
	// 输出
	for(int i = path.size() - 1; i >= 0; i--) {
		printf("%d ",path[i]);
	}
	printf("%d %d",d[D],perfectValue_cost);  // d[D] !! 
	return 0;
}






第二遍代码--------------------------------------------------------------------------------
Sample Input
4 5 0 3     // 节点数N(0 to N-1)     边数M    起点S    终点D
0 1 1 20    // City1    City2    Distance(距离)   Cost(边权(花费))
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
Sample Output
0 2 3 3 40    // 最短路径   总距离   总花费


#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000000;

int N, M, st, ed;
int G[MAXN][MAXN], d[MAXN];
int Cost[MAXN][MAXN];
bool vis[MAXN];
vector<int> pre[MAXN], tempPath, path;
int valueCost, minValueCost = INF;

void Dijkstra(int s) {
	fill(d, d + MAXN, INF);
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
		tempPath.push_back(v);
		valueCost = 0; 
//		for(int i=tempPath.size()-1; i>0; i--) {
//			int C1 = tempPath[i], C2 = tempPath[i-1];  //
//			valueCost += Cost[C1][C2];
//		}
		for(int i=0; i<tempPath.size() - 1; i++) {
			int idNext = tempPath[i];
			int id = tempPath[i + 1];
			valueCost += Cost[id][idNext];
		}
		if(valueCost < minValueCost) {
			minValueCost = valueCost;
			path = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for(int i=0; i<pre[v].size(); i++) {
		DFS(pre[v][i]);
	}
	tempPath.pop_back();
}

int main() {
	scanf("%d%d%d%d",&N,&M,&st,&ed);
	fill(G[0],G[0]+MAXN*MAXN,INF);
	for(int i=0; i<M; i++) {
		int C1,C2;
		scanf("%d%d",&C1,&C2);
		scanf("%d%d",&G[C1][C2],&Cost[C1][C2]);
	}

	Dijkstra(st);

	DFS(ed);

	for(int i = path.size() - 1; i >= 0; i--) {
		printf("%d ",path[i]);
	}

	printf("%d %d",d[ed],minValueCost);

//	for(int i = 0; i < N; i++) {
//		for(int j = 0; j < pre[i].size(); j++) {
//			printf("%d ",pre[i][j]);
//		}
//		printf("\n");
//	}

	return 0;
}