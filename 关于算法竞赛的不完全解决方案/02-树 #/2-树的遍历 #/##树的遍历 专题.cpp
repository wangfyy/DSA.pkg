树的遍历

【一】--------------------------------------------------------------------------------
Total Sales(所有零售商总共卖多少钱) of Supply Chain (25)

A supply chain(供应链) is a network of :
retailers（零售商）, distributors（经销商）, and suppliers（供应商）

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

【二】--------------------------------------------------------------------------------
Highest Price in Supply Chain (25)

Sample Input:
9 1.80 1.00
1 5 4 4 -1 4 5 3 6   // 每一个数字Si为第i个节点的供应商的下标
Sample Output:
1.85 2

#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 100010;

struct {
    vector<int> child;  // 不用struct也行，child[i][j]
} Node[MAXN];

int N, root;
double P, r, Price[MAXN];

void dfs(int index, int depth) {  //////
    // 边界
    if(Node[index].child.size() == 0) {
        Price[index] = P * pow((1 + r), depth);
    }
    // 递归式
    for(int i=0; i<Node[index].child.size(); i++) {
        dfs(Node[index].child[i], depth + 1);
    }
}

int main() {
    // scanf
    scanf("%d%lf%lf",&N,&P,&r);
    r /= 100;
    for(int i=0; i<N; i++) {
        int c;
        scanf("%d",&c);
        if(c != -1) {
            Node[c].child.push_back(i);  ////
        } else {
            root = i;
        }
    }

    dfs(root, 0);

    double maxPrice = 0;
    int numPrice = 0;
    for(int i=0; i<N; i++) {
        if(Price[i] > maxPrice) {
            maxPrice = Price[i];
        }
    }
    for(int i=0; i<N; i++) {
        if(Price[i] == maxPrice) {
            numPrice ++;
        }
    }

    printf("%0.2lf %d",maxPrice,numPrice);

    return 0;
}

【三】--------------------------------------------------------------------------------
https://logn.me/problem/1024

10 8
2 6 1 2 0 9 5 0 3 6
0 1
0 2
0 3
1 4
1 5
3 6
7 8
8 9

2
775 36

有点像图~

#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 1010;

int N, M, cnt = 0, sum;
bool vis[MAXN];
vector<int> number;

struct node {s
    int data;
    vector<int> child;  //////数组下标方式
} Node[MAXN];

int solve() {
    int len2 = number.size();
    int x = 0, p = 1;
    for(int i=len2-1; i>=0; i--) {
        x += number[i] * p;
        p *= 10;
    }
    //number.clear();  ////////////
    return x;
}

void DFS(int index) {
    if(Node[index].child.size() == 0) {
        number.push_back(Node[index].data);
        sum += solve();
        number.pop_back();  /////////
        return;
    }
    for(int i=0; i<Node[index].child.size(); i++) {
        number.push_back(Node[index].data);
        DFS(Node[index].child[i]);
        number.pop_back();  ///////////
    }
}

int main() {
    scanf("%d%d",&N,&M);
    for(int i=0; i<N; i++) {
        scanf("%d",&Node[i].data);
    }
    for(int i=0; i<M; i++) {
        int c1, c2;
        scanf("%d%d",&c1,&c2);
        Node[c1].child.push_back(c2);
        vis[c2] = true;
    }
    for(int i=0; i<N; i++) {
        if(vis[i] == false) {
            cnt++;
        }
    }
    printf("%d\n",cnt);

    for(int i=0; i<N; i++) {
        if(vis[i] == false) {
            sum = 0;
            DFS(i);
            printf("%d",sum);
            if(i != cnt-1) printf(" ");
        }
    }

    return 0;
}
