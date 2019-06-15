Battle Over Cities.(沦陷的城市)

Sample Input:
3 2 3   // 城市数目 路的数目 检查的数目
1 2  // 路
1 3  // 路
1 2 3  // 检查   如果城市1沦陷了，需修1条公路才能将其他的城市连起来; 如果城市2沦陷了...
Sample Output:
1  // 如果城市1沦陷了，需修1条公路才能将其他的城市连起来;
0  // 如果城市2沦陷了...
0

做法一 图的遍历 略

做法二 并查集————【并查集思想：用数组father[i]表示元素i的父节点】
	判断无向图中"每条边的两个顶点"是否在同一集合内，若在，则不做处理，
	若不在，则将这两个顶点加入到同一集合(构建集合)，
	最后统计集合个数。

【代码框架】
main()部分：
 1. 建图。
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