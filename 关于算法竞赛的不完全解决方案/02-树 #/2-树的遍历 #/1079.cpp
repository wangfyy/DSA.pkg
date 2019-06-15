Total Sales(所有零售商总共卖多少钱) of Supply Chain (25)

A supply chain(供应链) is a network of :
retailers（零售商）, distributors（经销商）, and suppliers（供应商）
-- everyone involved in moving a product from supplier to customer.
Starting from one root supplier, 
everyone on the chain buys products from one's supplier in a price P and sell or distribute(分配--分销商) them in a     '
price that is r% higher than P. 
Only the retailers will face the customers. 
It is assumed that each member in the supply chain has exactly one supplier except the root supplier, 
and there is no supply cycle.
Now given a supply chain, you are supposed to tell the total sales from all the retailers.

Input Specification:
Each input file contains one test case. For each case, the first line contains three positive numbers: 
    N (<=105), the total number of the members(成员) in the supply chain (and hence their ID's are numbered from 0 to N-1, 
and the root supplier's ID is 0); 
    P, the unit price given by the root supplier; 
    and r, the percentage(百分比) rate of price increment for each distributor or retailer. 
    Then N lines follow, each describes a distributor or retailer in the following format:
Ki ID[1] ID[2] ... ID[Ki]
where in the i-th line, 
    Ki is the total number of distributors or retailers who receive products from supplier i, 
and is then followed by the 
    ID's of these distributors or retailers. '
    Kj being 0 means that the j-th member is a retailer, then instead the total amount of the product will be given after Kj. 
All the numbers in a line are separated by a space.

Output Specification:
For each test case, print in one line the total sales we can expect from all the retailers, 
accurate up to 1 decimal place. It is guaranteed that the number will not exceed 1010.

Sample Input:
10(节点数) 1.80(其实价格) 1.00(高出的百分比)
3 2 3 5  // 行数是节点的编号0->N-1,rootID is 0  // 3为孩子数  // 3个数为孩子的id
1 9
1 4
1 7
0 7  // 7为叶子结点(零售商)的产品数
2 6 1
1 8
0 9
0 4
0 3
Sample Output:
42.4


树的遍历，即：求最后一层的上各节点(零售商)卖出的价格，
价格=产品数量*单价，
第二层的单价=原始单价+原始单价*利率=原始短单*(1+利率)
第三层的单价=第二层的单价+第二层的单价*利率=第二层的短单*(1+利率)==原始短单*(1+利率)*(1+利率)
所以，关键求出叶子结点的层数


----- 代码1 -----
#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

const int MAXN = 100010;

int N;
double P, r, totalMoney = 0;

struct node {
    vector<int> child;
    int numProduct;
} Node[MAXN];

void dfs(int index, int depth) {  // index为节点， depth为层数
    // 递归边界
    if(Node[index].child.size() == 0){
        totalMoney += Node[index].numProduct * P * pow(1 + r, depth);
        return;
    }
    // 递归式
    for(int j=0; j<Node[index].child.size(); j++) {  // 遍历并递归
        dfs(Node[index].child[j], depth+1);  // 父节点到子节点，层数++
    }
}

int main() {
    // scanf
    scanf("%d%lf%lf",&N,&P,&r);
    r /= 100;
    int k, numProduct;
    for(int i=0; i<N; i++) {
        scanf("%d",&k);
        if(k == 0) {
            scanf("%d",&Node[i].numProduct);
        } else {
            for(int j=0; j<k; j++) {
                int c;
                scanf("%d",&c);
                Node[i].child.push_back(c);
            }
        }
    }

    dfs(0, 0);

    printf("%0.1lf",totalMoney);

    return 0;
}





----- 代码2 -----  求全部的资金了。。。
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

const int MAXN = 110;
int N;
double P, r, rr, totalMoney = 0.0;

struct node {
    vector<int> child;
    int numProduct = 0;  ////// 默认值
    int layer;
} Node[MAXN];

double solveMoney(int cifang) {
    double money = 1;
    for(int i=0; i<cifang; i++) {
        money *= rr;
    }
    return money;
}

void bfs(int root) {
    queue<int> q;
    q.push(root);
    Node[root].layer = 1;
    totalMoney += Node[root].numProduct * solveMoney(Node[root].layer);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int j=0; j<Node[now].child.size(); j++) {
            int child = Node[now].child[j];
            q.push(child);
            Node[child].layer = Node[now].layer + 1;
            totalMoney += Node[root].numProduct * solveMoney(Node[root].layer);
        }
    }
}

int dfs(int root) {
    if(Node[root].child.size() == 0){
        return Node[root].numProduct;
    }
    for(int j=0; j<Node[root].child.size(); j++) {
        Node[root].numProduct += dfs(Node[root].child[j]);
    }
    return Node[root].numProduct;  ////
}

int main() {
    // scanf
    scanf("%d%lf%lf",&N,&P,&r);  //
    r = r / 100;  //
    rr = 1.0 + r;
    int k, numProduct, vis[N] = {0};
    for(int i=0; i<N; i++) {
        scanf("%d",&k);
        if(k == 0) {
            scanf("%d",&Node[i].numProduct);
        } else {
            for(int j=0; j<k; j++) {
                int c;
                scanf("%d",&c);
                vis[c] = 1;
                Node[i].child.push_back(c);
            }
        }
    }
    // 寻找root
    int root;
    for(int i=0; i<N; i++) {
        if(vis[i] == 0)
            root = i;
    }

    dfs(root);  //为每个节点赋numProduct值

    bfs(root);

    printf("%lf",totalMoney);

//    // test printf
//    printf("%d %lf %lf\n",N,P,r);
//    for(int i=0; i<N; i++) {
//        printf("%d ",Node[i].child.size());
//        if(Node[i].child.size() == 0) {
//            printf(" numProduct: %d  layer: %d\n",Node[i].numProduct, Node[i].layer);
//        } else {
//            for(int j=0; j<Node[i].child.size(); j++) {
//                printf("%d ",Node[i].child[j]);
//            }
//            printf(" numProduct: %d  layer: %d\n",Node[i].numProduct, Node[i].layer);
//        }
//    }

    return 0;
}
