Invert(反) a Binary Tree (25)

The following is from Max Howell @twitter:
Google: 90% of our engineers use the software you wrote (Homebrew), 
but you can't invert a binary tree on a whiteboard so fuck off.
Now it's your turn to prove that YOU CAN invert a binary tree!

Input Specification:
Each input file contains one test case. For each case, 
the first line gives a positive integer N (<=10) which is 
the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N-1. 
Then N lines follow, each corresponds to a node from 0 to N-1, 
and gives the indices of the left and right children of the node. 
If the child does not exist, a "-" will be put at the position. 
Any pair of children are separated by a space.

Output Specification:
For each test case, print in the first line the level-order, 
and then in the second line the in-order traversal sequences of the inverted tree. 
There must be exactly one space between any adjacent numbers, 
and no extra space at the end of the line.

Sample Input:
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
Sample Output:
3 7 2 6 4 0 5 1       // 层序遍历
6 5 7 4 3 2 0 1       // 后序遍历


#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;

const int MAXN = 20;

struct node{
    int lChild, rChild;
} Node[MAXN];

int N;

void bfs(int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int now = q.front();  ////
        printf("%d",now);
        q.pop();
        if(Node[now].rChild != -1)
            q.push(Node[now].rChild);
        if(Node[now].lChild != -1)
            q.push(Node[now].lChild);
        if(!q.empty())
            printf(" ");
    }
}

int i = 1;
void dfs_2(int root) {  //中序
    //递归边界
    if(root == -1) return;
    //递归式
    dfs_2(Node[root].rChild);
    if(i != N) {
        printf("%d ",root);
            /////////////// 以“下标”代替“结构体里的数据域(int data;)”   前提为：数据域连续
            /////////////// 然而若不是静态表示，则没有数组下标的概念，则只能定义为：struct node{ int data; node* lChild; node* rChild; }; PAT-A-1020
        i++;
    } else {
        printf("%d",root);
    }
    dfs_2(Node[root].lChild);
}

int main() {
    scanf("%d",&N);
    bool vis[N] = {false};  // 寻找root
    char c_1, c_2;
    for(int i=0; i<N; i++) {
        scanf(" %c",&c_1);
        scanf(" %c",&c_2);  //// 因为是把回车和空格也当做字符输入了，所以：“ %c”，在%c前面加“ ”。
        //// scanf("%*c%c %c",&c_1,&c_2);  // 都可以，小技巧（p293）
        if(c_1 != '-') {
            Node[i].lChild = c_1 - '0';
            vis[c_1 - '0'] = true;
        } else {
            Node[i].lChild = -1;
        }
        if(c_2 != '-') {
            Node[i].rChild = c_2 - '0';
            vis[c_2 - '0'] = true;
        } else {
            Node[i].rChild = -1;
        }
    }
    int root;  // 根结点的下标
    for(int i=0; i<N; i++) {
        if(vis[i] == false) {
            root = i;
        }
    }
    bfs(root);
    printf("\n");

    dfs_2(root);

    return 0;
}
