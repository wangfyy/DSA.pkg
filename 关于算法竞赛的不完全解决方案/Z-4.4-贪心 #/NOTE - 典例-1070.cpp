Mooncake (25)

Mooncake is a Chinese bakery product traditionally eaten during the Mid-Autumn Festival. 
Many types of fillings and crusts can be found in traditional mooncakes according to the region's culture.     '
Now given the inventory amounts and the prices of all kinds of the mooncakes, 
together with the maximum total demand of the market, 
you are supposed to tell the maximum profit that can be made.
Note: partial inventory storage can be taken. 
The sample shows the following situation: 
given three kinds of mooncakes with inventory amounts being 180, 150, and 100 thousand tons, 
and the prices being 7.5, 7.2, and 4.5 billion yuans. If the market demand can be at most 200 thousand tons, 
the best we can do is to sell 150 thousand tons of the second kind of mooncake, 
and 50 thousand tons of the third kind. Hence the total profit is 7.2 + 4.5/2 = 9.45 (billion yuans).

Input Specification:
Each input file contains one test case. For each case, 
the first line contains 2 positive integers N (<=1000), 
the number of different kinds of mooncakes, and D (<=500 thousand tons), 
the maximum total demand of the market. 
Then the second line gives the positive inventory amounts (in thousand tons), 
and the third line gives the positive prices (in billion yuans) of N kinds of mooncakes. 
All the numbers in a line are separated by a space.

Output Specification:
For each test case, print the maximum profit (in billion yuans) in one line, accurate up to 2 decimal places.

【典例】

3 200
180 150 100
7.5 7.2 4.5

9.45


// 注意是"单价"最高(可见其贪...)！


#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 10010;

struct node{
	double perPrices;
	double amounts;
	double prices;
} Node[MAXN];

int N;
double maxDemand, profit = 0;

bool cmp(node a, node b) {
	return a.perPrices > b.perPrices;
}

int main() {
	scanf("%d%lf",&N,&maxDemand);
	for(int i=0; i<N; i++) {
		scanf("%lf",&Node[i].amounts);
	}
	for(int i=0; i<N; i++) {
		scanf("%lf",&Node[i].prices);
	}
	for(int i=0; i<N; i++) {
		Node[i].perPrices = Node[i].prices / Node[i].amounts;
	}
	sort(Node,Node+N,cmp);

	for(int i=0; i<N; i++) {
		if(maxDemand < Node[i].amounts) {
			double x = Node[i].prices/Node[i].amounts;		
			profit += x*maxDemand;			
			printf("%0.2lf",profit);
			return 0;
		} else if(maxDemand == Node[i].amounts) {
			profit += Node[i].prices;
			printf("%0.2lf",profit);
			return 0;
		} else {
			profit += Node[i].prices;
			maxDemand -= Node[i].amounts;
		}
	}
	printf("%0.2lf",profit);

	return 0;
}