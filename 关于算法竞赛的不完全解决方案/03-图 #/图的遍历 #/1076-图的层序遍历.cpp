Forwards on Weibo.

Weibo is known as the Chinese version of Twitter. 
One user on Weibo may have many followers, and may follow many other users as well. 
Hence a social network is formed with followers relations. When a user makes a post on Weibo, 
all his/her followers can view and forward his/her post, which can then be forwarded again by their followers. 
Now given a social network, you are supposed to calculate the maximum potential amount of forwards for any specific user, 
assuming that only L levels of indirect followers are counted.

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers: 
N (<=1000), the number of users; and L (<=6), 
		the number of levels of indirect(间接) followers that are counted.  间接追随者的数量。
Hence it is assumed(假定) that all the users are numbered from 1 to N. Then N lines follow, each in the format:
M[i] user_list[i]
		where M[i] (<=100) is the total number of people that user[i] follows; 
and user_list[i] is a list of the M[i] users that are followed by user[i]. 
It is guaranteed that no one can follow oneself. All the numbers are separated by a space.
Then finally a positive K is given, followed by K UserID's for query.  '

Output Specification:
For each UserID, you are supposed to print in one line the maximum potential amount of forwards this user can triger, 
assuming that everyone who can view the initial post will forward it once, 
and that only L levels of indirect followers are counted.

Sample Input:
7 3     // 转发层数上限
3 2 3 4     // 1号用户关注了3个用户！！！ 分别为2、3、4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6     // 2,6为最初发布消息的用户
Sample Output:
4    // 2号发布消时，第一层转发的用户是1号，第二层转发的用户是4号，第三层转发的用户是5和6号，总共4个转发。
5    // 6号发布消时，........ ，总共5个转发。


有向图，若1关注了2，则有2指向1的一条边。。。
即：从某个起点出发，指定深度内的节点的个数。
两种方式：
1.	给定起点的情况下，遍历整个图，得到的所有节点的深度记录到deep[]里，然后统计深度少于某值的节点的个数。
	缺点：得遍历完整个图，费时
2.	给定起点的情况下，遍历图的一部分，从起点开始遍历，并记录遍历过的节点的数目，当遇到深度大于规定值时，则停止遍历。
	优点：省时


#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 1010;
int N, L, K, num_forwards;
vector<int> followers[MAXN];
int deep[MAXN];  // 用来记录每个节点的深度，也可以用结构体来记录
bool vis[MAXN];  /// 注意：一个用户只能转发一次，防止互粉后疯狂刷转发量

int bfs(int start) {
	queue<int> q;
	q.push(start);  /// (初始)入  // 注：此处转发次数不++
	deep[start] = 0;  //记录深度    //////// 不管是循环内外，所有操作都紧接push后完成
	vis[start] = true;  // 惯例访问过的，也即：发布信息的本人不可转发
	while(!q.empty()) {
		int front = q.front();
		q.pop();  /// (循环内)出
		if(deep[front] < L) {
			for(int i=0; i<followers[front].size(); i++) {  /// (循环内)入：front节点的所有下一步节点
				if(vis[followers[front][i]] == false) {  // 全TM包进来，逻辑！！
					q.push(followers[front][i]);  /// (循环内)入
					deep[followers[front][i]] = deep[front] + 1;
						// 注意：followers的[front][i]]和[front]的关系，[front]不是[front][i]]的层，而是其前驱
					num_forwards ++;  // 转发次数 ++
					vis[followers[front][i]] = true;
				}
			}			
		}else{
			return num_forwards;
		}
	}
	return num_forwards; //
}

int main() {
	scanf("%d%d",&N,&L);
	for(int i=1; i<=N; i++) {
		int N_followers;
		scanf("%d",&N_followers);
		for(int j=0; j<N_followers; j++) {
			int i_followers;
			scanf("%d",&i_followers);
			followers[i_followers].push_back(i);  // 有向图
		}
	}
	scanf("%d",&K);
	for(int i=0; i<K; i++) {
		int start;
		scanf("%d",&start);
		num_forwards = 0;
		memset(vis,false,sizeof(vis));
		printf("%d\n",bfs(start));  // 给定起点
	}

	return 0;
}