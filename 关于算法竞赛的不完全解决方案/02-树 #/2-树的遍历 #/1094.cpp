The Largest Generation (25)

A family hierarchy is usually presented by a pedigree tree where all the nodes on the same level belong to the same generation. 
Your task is to find 
    the generation with the largest population.

Input Specification:
Each input file contains one test case. 
Each case starts with two positive integers 
    N (<100) which is the total number of family members in the tree 
    (and hence assume that all the members are numbered from 01 to N), 
    and M (<N) which is the number of family members who have children.(非叶节点)
Then M lines follow, 
each contains the information of a family member in the following format:
    ID K ID[1] ID[2] ... ID[K]
where 
    ID is a two-digit number representing(代表) a family member, 
    K (>0) is the number of his/her children, 
    followed by a sequence of two-digit ID's of his/her children. For the sake of simplicity,     '
    let us fix the root ID to be 01. 
All the numbers in a line are separated by a space.

Output Specification:
For each test case, print in one line 
    the largest population number and the level of the corresponding(相应的) generation. 
It is assumed that such a generation is unique, and the root level is defined to be 1.



Sample Input:
23 13           // N 所有成员数(1->N)rootID is 01      // M 有孩子的成员数
21 1 23         // ID K ID[1] ID[2] ... ID[K]     // ID为这个家庭成员的编号  // K为这个家庭成员的孩子数   // K个数为这个家庭成员的孩子们的编号
01 4 03 02 04 05
03 3 06 07 08
06 2 12 13
13 1 21
08 2 15 16
02 2 09 10
11 2 19 20
17 1 22
05 1 11
07 1 14
09 1 17
10 1 18
Sample Output:
9 4    // 那一代(层)的人口数(成员数)最多,输出：最多成员数 和 那一层

-------------------------
01 4 03 02 04 05
02 2 09 10
03 3 06 07 08
05 1 11
06 2 12 13
07 1 14
08 2 15 16
09 1 17
10 1 18
11 2 19 20
13 1 21
17 1 22
21 1 23




#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 110;

struct node {
    vector<int> child;
    int layer;  ////
} Node[MAXN];

int N, M, Log[MAXN];

//void dfs(int index, int depth) {
//    // 边界
//    if(Node[index].child.size() == 0) {
//        Log[index] = depth;
//        return;
//    }
//    // 递归式
//    for(int i=0; i<Node[index].child.size(); i++) {
//        dfs(Node[index].child[i], depth+1);
//    }
//}

void bfs(int root) {
    queue<int> q;
    Node[root].layer = 1;
    q.push(root);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int i=0; i<Node[now].child.size(); i++) {
            q.push(Node[now].child[i]);
            Node[Node[now].child[i]].layer = Node[now].layer + 1;
        }
    }
}

int main() {
    // scanf
    scanf("%d%d",&N,&M);
    for(int i=0; i<M; i++) {
        int index, K;
        scanf("%d",&index);
        scanf("%d",&K);
        for(int j=0; j<K; j++) {
            int child;
            scanf("%d",&child);
            Node[index].child.push_back(child);
        }
    }

    int root = 1;

    // dfs(root, 1);

    bfs(root);

    // 寻找一代，这代里的成员数最多
    int max = 0, num, g;
    for(int i=1; i<=23; i++) {
            num = 0;
        for(int j=1; j<=N; j++) {
            if(Node[j].layer == i) {
                num ++;
            }
        }
        if(num > max) {
            max = num;
            g = i;
        }
    }
    printf("%d %d",max, g);

    return 0;
}
