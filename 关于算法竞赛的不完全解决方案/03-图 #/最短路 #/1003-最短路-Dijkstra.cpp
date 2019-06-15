Emergency (紧急时刻).
 
As an emergency rescue(营救) team leader of a city, you are given a special map of your country. 
The map shows several scattered(分散的) cities connected by some roads. 
Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. 
// 每个城市的救援队数量和每条城市之间每条道路的长度都在地图上标出。
When there is an emergency call to you from some other city, 
your job is to lead your men to the place as quickly as possible, 
and at the mean time, call up as many hands on the way as possible.
// 当有来自其他城市的紧急电话给你时，你的工作就是尽快把你的人带到那个地方去，同时，尽可能多地打电话。
Input
Each input file contains one test case. For each test case, 
the first line contains 4 positive integers(正整数): 
	N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1), 
	M - the number of roads, 
	C1 and C2 - the cities that you are currently(当前) in and that you must save, (你所在的城市和你必须拯救的城市) respectively. 
The next line contains N integers, 
	where the i-th integer(第i个整数) is the number of rescue teams in the i-th city. 
Then M lines follow, 
	each describes a road with three integers c1, c2 and L, 
	which are the pair of cities connected by a road and the length of that road, respectively. 
It is guaranteed that there exists at least one path from C1 to C2.(保证从C1到C2至少存在一条路径)
Output
For each test case, print in one line two numbers: 
	the number of different shortest paths between C1 and C2, 
	and the maximum amount of rescue teams you can possibly gather(聚集).
All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.
Sample Input
5 6 0 2       // 5个节点，6条边，C1 and C2（即：你所在的城市，你必须拯救的城市）
1 2 1 5 3     // 每个城市中救援队的数目——即：点权
0 1 1         // c1, c2 and L
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output
2 4           // C1 and C2 间的最短路径的条数  // 最大点权和
求最短路径的条数及最短路径上的救援小组的数目之和，如果有多条最短路径，则输出数目之和最大的那条。
// 代码 -------------------------------------------------------  
// 内置数组
#include <cstdio>
using namespace std;
const int MAXN = 520;
const int INF = 1000000000;
int G[MAXN][MAXN], N, M, st, ed;
bool vis[MAXN];
int d[MAXN];
int weight[MAXN], numberPathsPerPoint[MAXN], maxWeightSumPerPoint[MAXN];
void Dijkstra(int s) {
	for(int i=0; i<N; i++) d[i] = INF;
	d[s] = 0;
	numberPathsPerPoint[s] = 1;
	maxWeightSumPerPoint[s] = weight[s];
	for(int i=0; i<N; i++) {
		int u = -1, MIN = INF;
		for(int j=0; j<N; j++) {
			if(d[j] < MIN && !vis[j]) {
				u = j;
				MIN = d[u];
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v=0; v<N; v++) {
			if(!vis[v] && G[u][v] != INF) {
				if(d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];  //更新
					numberPathsPerPoint[v] = numberPathsPerPoint[u];  ////		
					maxWeightSumPerPoint[v] = maxWeightSumPerPoint[u] + weight[v];	
				} else if(d[u] + G[u][v] == d[v]) {
					numberPathsPerPoint[v] += numberPathsPerPoint[u];  ////
					if(maxWeightSumPerPoint[u] + weight[v] > maxWeightSumPerPoint[v])
						maxWeightSumPerPoint[v] = maxWeightSumPerPoint[u] + weight[v];
				}
			}
		}
	}
}
int main() {
	scanf("%d%d%d%d",&N, &M, &st, &ed);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			G[i][j] = INF;
	for(int i=0; i<N; i++)
		scanf("%d",&weight[i]);
	for(int i=0; i<M; i++) {
		int C1, C2;
		scanf("%d%d",&C1,&C2);
		scanf("%d",&G[C1][C2]);
		G[C2][C1] = G[C1][C2];
	}
	Dijkstra(st);
	printf("%d %d\n",numberPathsPerPoint[ed], maxWeightSumPerPoint[ed]);
	return 0;
}
// Dijkstra+DFS
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 520;
const int INF = 1000000000;
int G[MAXN][MAXN], N, M, st, ed;
bool vis[MAXN];
int d[MAXN];
int weight[MAXN];
vector<int> pre[MAXN], tempPath, path;
int num = 0, maxWeightSum = 0;
void Dijkstra(int s) {
	fill(d, d + MAXN, INF);
	d[s] = 0;
	for(int i=0; i<N; i++) {
		int u = -1, MIN = INF;
		for(int j=0; j<N; j++) {  //寻找d最小的中间点u
			if(d[j] < MIN && !vis[j]) {
				u = j;
				MIN = d[u];
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v=0; v<N; v++) {  //以u为中间点，为与u相连的v们的d赋值
			if(!vis[v] && G[u][v] != INF) {
				if(d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];  //更新
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
		num++;
		tempPath.push_back(v);
		int tempValueWeight = 0;
		for(int i=0; i<tempPath.size(); i++)
			tempValueWeight += weight[tempPath[i]];
		if(tempValueWeight > maxWeightSum) maxWeightSum = tempValueWeight;
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for(int i=0; i<pre[v].size(); i++) DFS(pre[v][i]);
	tempPath.pop_back();
}
int main() {
	scanf("%d%d%d%d",&N, &M, &st, &ed);
	fill(G[0], G[0] + MAXN * MAXN, INF);
	for(int i=0; i<N; i++)
		scanf("%d",&weight[i]);
	for(int i=0; i<M; i++) {
		int C1, C2;
		scanf("%d%d",&C1,&C2);
		scanf("%d",&G[C1][C2]);
		G[C2][C1] = G[C1][C2];  //无向图
	}
	Dijkstra(st);
	DFS(ed);
	printf("%d %d\n", num, maxWeightSum);
	return 0;
}
