Highest Price in Supply Chain (25)

A supply chain is a network of retailers（零售商）, distributors（经销商）, 
and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.
Starting from one root supplier, 
everyone on the chain buys products from one's supplier in a price P       '
and sell or distribute them in a price that is r% higher than P. 
It is assumed that each member in the supply chain has exactly one supplier except the root supplier, 
and there is no supply cycle.
Now given a supply chain, you are supposed to tell the highest price we can expect from some retailers.

Input Specification:
Each input file contains one test case. For each case, 
The first line contains three positive numbers: N (<=105), 
the total number of the members in the supply chain (and hence they are numbered from 0 to N-1); 
P, the price given by the root supplier; and r, 
the percentage rate of price increment for each distributor or retailer. 
Then the next line contains N numbers, 
    each number Si is the index of the supplier for the i-th member. 每一个数字Si为第i个节点的供应商的下标
Sroot for 
    the root supplier is defined to be -1. 
All the numbers in a line are separated by a space.

Output Specification:
For each test case, print in one line the highest price we can expect from some retailers, 
accurate up to 2 decimal places, and the number of retailers that sell at the highest price. 
There must be one space between the two numbers. It is guaranteed that the price will not exceed 1010.

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