Battle Over Cities.(沦陷的城市)

It is vitally important to have all the cities connected by highways in a war. 
If a city is occupied by the enemy, all the highways from/toward that city are closed. 
We must know immediately if we need to repair any other highways to keep the rest of the cities connected. 
Given the map of cities which have all the remaining highways marked, 
you are supposed to tell the number of highways need to be repaired, quickly.

For example, if we have 3 cities and 2 highways connecting city1-city2 and city1-city3. 
Then if city1 is occupied by the enemy(沦陷), we must have 1 highway repaired(修复), that is the highway city2-city3.
如果城市1是沦陷，我们必须使1条公路修好，就是city2-city3这条公路。

Input
Each input file contains one test case. Each case starts with a line containing 
3 numbers N (<1000), M and K, 
which are the total number of cities, the number of remaining highways, and the number of cities to be checked, respectively. 
Then M lines follow, each describes a highway by 2 integers, 
which are the numbers of the cities the highway connects. The cities are numbered from 1 to N. 
Finally there is a line containing K numbers, which represent the cities we concern.

Output
For each of the K cities, output in a line the number of highways need to be repaired if that city is lost.
											如果那座城市沦陷了，需要修多少条公路(才能将其他的城市连起来)。

Sample Input
3 2 3

1 2
1 3

1 2 3  //如果城市1沦陷了，需要修1条公路(才能将其他的城市连起来)。
Sample Output
1
0
0


实质为：计算无向图(不包括(去掉)沦陷的节点)中连通块的数目。

实现途径有两种：

一 图的遍历
图的遍历中每次访问单个连通块，并将该连通块的所有节点都标记为已访问，然后去访问下个连通块，最终得到的块数减一就是答案。
【代码框架】
main()部分：
 1.建图。
 2.当每次读入一个被删除的结点currentPoint后，便开始计算这个图内所有连通块的数目:
	for()循环枚举每个"未被删除/未被访问过"的结点，
	调用DFS遍历结点i所在的整个连通块 使这个块内的结点全部被标记(目的：这样接着枚举时就枚举不到之前访问过的块中的结点了)，
	块数 ++。
 3.输出块数-1。
DFS()部分：	
 1.若当前结点为被删除的结点(第一次调用不可能，递归时可能)则返回，(若通过if(非currentPoint)亦可达到相同的目的)
 2.标记当前结点为已访问，
 3.遍历并递归当前结点的所有的未被访问的临接点。

二 并查集 ————  【就是一个数组:father[i]表示元素i的父节点】
判断无向图中"每条边的两个顶点"是否在同一集合内，若在，则不做处理，若不在，则将这两个顶点加入到同一集合(构建集合)，
最后统计集合个数。
【代码框架】
main()部分：
 1.建图。
 2. 构建集合：
 	当每次读入一个被删除的结点currentPoint后，
	枚举每一条边，即：
	for()循环枚举每个结点，然后for()循环枚举这个结点的每一条边("一端是被枚举的结点""一端是与被枚举结点相连的结点")，
	如果这两个节点中都没被删除，则将这两个结点所在的集合合并("Union()")。
 3. 计算集合的数目：(通过计数每个集合的根节点)
 	遍历所有未被删除结点，找到每个结点所在集合的根结点("findFather()")，
 	判断这个根结点有没有被访问，没的话就块数++并且设置其被访问过了。
 4. 输出块数-1。
union()部分：	
 	void union(int a, int b) {
 		int f_a = findFather[a];
 		int f_b = findFather[b];
 		if(f_a != f_b)
 			father[f_b] = f_a;
 	}
findFather()部分：
	int findFather(int x) {
		int a = x;
	 	//主体
	 	while(x != father[x]) {
	 		x = father[x];
	 	}
	 	//路径压缩
	 	while(a != father[a]) {
	 		int z = a;
	 		a = father[a];
	 		father[z] = x;
	 	}
	 	//返回
	 	return x;
	}


 ----- 代码1 -----
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int MAXN = 1010;
vector<int> G[MAXN];
bool vis[MAXN];
int currentPoint;
void dfs(int v) {
	if(v != currentPoint && vis[v] == false) {
		vis[v] = true;
		for(int i=0; i<G[v].size(); i++) {
			dfs(G[v][i]);
		}
	}
}
int main() {
	int N,M,K;
	scanf("%d%d%d",&N,&M,&K);
	int a,b;
	for(int i=0; i<M; i++) {
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i_k=0; i_k<K; i_k++) {
		scanf("%d",&currentPoint);
		int block = 0;
		memset(vis,false,sizeof(vis));
		for(int i=1; i<=N; i++) {
			if(i != currentPoint && vis[i] == false) {
				dfs(i);
				block ++;
			}
		}
		printf("%d\n",block-1);
	}
	return 0;
}


 ----- 代码2 -----
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int MAXN = 1010;
vector<int> G[MAXN];
bool vis[MAXN];
int father[MAXN];
int N,M,K;
int currentPoint;
int findFather(int x) {  //查询根节点时顺便进行路径压缩：把当前查询节点的路径上的所有节点的父亲都设为是根节点
	int a = x;
	while(x != father[x]) {
		x = father[x];  // x即为根节点，返回就是了，其他的代码都是路径压缩
	}
	while (a != father[a]) {
		int z = a;
		a = father[a];
		father[z] = x;  //把当前查询节点的路径上的所有节点的父亲都设为是根节点
	}
	return x;
}
void Union(int a, int b) {
	int f_a = findFather(a);
	int f_b = findFather(b);
	if(f_a != f_b) {
		father[f_a] = f_b;
	}
}
void init() {
	for(int i=0; i<=N; i++) {
		father[i] = i;
		vis[i] = false;
	}
}
int main() {
	scanf("%d%d%d",&N,&M,&K);
	int a,b;
	for(int i=0; i<M; i++) {
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i_k=0; i_k<K; i_k++) {
		scanf("%d",&currentPoint);
		init();
		for(int i=1; i<=N; i++) {
			for(int j=0; j<G[i].size(); j++) {
				int u =i, v = G[i][j];
				if(u != currentPoint && v != currentPoint) {
				//if(findFather(u) != findFather(v))  //此处判断放在union()完成
					Union(u,v);
				}	
			}
		}
		int block = 0;
		for(int i=1; i<=N; i++) {
			int father_i = findFather(i);
			if(i != currentPoint && vis[father_i] == false) {
				vis[father_i] = true;
				block ++;
			}
		}
		printf("%d\n",block-1);
	}
}