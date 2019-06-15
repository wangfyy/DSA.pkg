Counting Leaves(数叶子).

A family hierarchy is usually presented by a pedigree tree.(家族谱系通常由系谱树来表示) 
Your job is to count those family members(成员) who have no child.

Input
Each input file contains one test case. Each case starts with a line containing 
	0 < N < 100, the number of nodes(节点) in a tree,   节点数
	M (< N), the number of non-leaf nodes.   非叶节点数
Then M lines follow, each in the format: 
	ID 
	K 
	ID[1] ID[2] ... ID[K]
	where ID is a two-digit(双位数字的) number representing(代表) a given non-leaf node(非叶节点), 
	K is the number of its children, 
	followed by(接着) a sequence of two-digit ID's of its children. '
For the sake(目的) of simplicity, let us fix the root ID to be 01.(为了简单起见，让我们将根ID固定为01)

Output
For each test case, 
you are supposed to(应该) count those family members 
	who have no child for every seniority(资历;年资;年长) level starting from the root. 
The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.

The sample case represents a tree with only 2 nodes, 
where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 0 leaf node;
and on the next level, there is 1 leaf node. Then we should output "0 1" in a line.

Sample Input 1
2 1
01 1 02
Sample Output 2
0 1

Sample Input 2
6 2
01 3 02 03 04
02 2 05 06
Sample Output 2
0 2 2

// 代码 -------------------------------------------------------------------------
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 110;
int N, M;
int leafNum[MAXN], levelNum[MAXN], maxLevelNum;
struct node {
	vector<int> child;
} Node[MAXN];
void BFS(int st) {
	levelNum[st] = 0;
	queue<int> q;
	q.push(st);
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		if(Node[front].child.size() != 0) {
			for(int i=0; i<Node[front].child.size(); i++) {
				q.push(Node[front].child[i]);
				levelNum[Node[front].child[i]] = levelNum[front] + 1;
				maxLevelNum = levelNum[Node[front].child[i]];
			}
		} else leafNum[levelNum[front]]++;
	}
}
int main() {
	scanf("%d%d",&N,&M);
	for(int i=0; i<M; i++) {
		int ID, K;
		scanf("%d%d",&ID,&K);
		for(int j=0; j<K; j++) {
			int currentChild;
			scanf("%d",&currentChild);
			Node[ID].child.push_back(currentChild);
		}
	}
	BFS(1);
	for(int i=0; i<=maxLevelNum; i++) {
		printf("%d",leafNum[i]);
		if(i != maxLevelNum) printf(" ");
	}
	return 0;
}


// 代码 -------------------------------------------------------------------------
先生成一棵树，再层序遍历之输出每层上的叶子节点数
// BFS版
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 110;

vector<int> G[MAXN];  //用邻接表存储树

int leafNodePerH[MAXN];  //每层叶子节点的数目
int HPerNode[MAXN];  //用HPerNode数组(而没用结构体)，记录每个节点所在的层数
int maxH;  //最大层数

void BFS(int root) {
	queue<int> Q;
	Q.push(root);
	while(!Q.empty()) {
		int id = Q.front();  ////
		Q.pop();
		maxH = HPerNode[id];
		if(G[id].size() == 0) {
			leafNodePerH[HPerNode[id]]++;
		}		
		for(int i=0; i<G[id].size(); i++) {
			Q.push(G[id][i]);
			HPerNode[G[id][i]] = HPerNode[id] + 1;
		}
	}
}

int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	int parent,k,child;
	for(int i=0; i<m; i++) {
		scanf("%d%d",&parent,&k);
		for(int j=0; j<k; j++) {
			scanf("%d",&child);
			G[parent].push_back(child);
		}
	}

	HPerNode[1] = 1;  //根节点的层数为1

	BFS(1);

	for(int i=1; i<=maxH; i++) {
		if(i == maxH) {
			printf("%d",leafNodePerH[i]);
		} else {
			printf("%d ",leafNodePerH[i]);
		}
	}

	return 0;
}
// DFS版 可以用DFS，原理也是那俩数组，只不过是把遍历的方式换了而已
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 110;

vector<int> G[N];  //用邻接表存储树
int leaf[N] = {0};  //存放每层的叶子节点数，用于输出
int max_h = 1;  //树的深度，用于控制输出

void DFS(int index, int h) {  //当前遍历到的节点编号，用于边界和递归式中 //当前深度，用于记录leaf[h]
	max_h = max(h, max_h);
	// 边界
	if(G[index].size() == 0) {
		leaf[h]++;
		return;  // 返回
	}
	// 递归式
	for(int i=0; i<G[index].size(); i++) {
		DFS(G[index][i], h + 1);
	}
}

int main() {
	// 输入
	int n,m;  //节点总数 //叶节点数
	scanf("%d%d",&n,&m);
	int parent,k,child;
	for(int i=0; i<m; i++) {
		scanf("%d%d",&parent,&k);
		for(int j=0; j<k; j++) {
			scanf("%d",&child);
			G[parent].push_back(child);  //非：G[parent][j] = child;  //把孩子节点连到父节点上(即加边)
		}
	}
	// 处理
	DFS(1,1);
	// 输出
	for(int i=1; i<=max_h; i++) {  //输出每层的孩子节点的个数
		if(i == max_h) {  //这样写就算只输出一个数，也可以使其后面无空格
			printf("%d",leaf[i]);
		}else {
			printf("%d ",leaf[i]);
		}
	}
	return 0;
}