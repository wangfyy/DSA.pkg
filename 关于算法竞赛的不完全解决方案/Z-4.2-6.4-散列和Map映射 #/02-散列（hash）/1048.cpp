Find Coins (25)

Eva loves to collect coins from all over the universe, 
including some other planets like Mars. 
One day she visited a universal shopping mall which could accept all kinds of coins as payments. 
However, there was a special requirement of the payment: for each bill, 
she could only use exactly two coins to pay the exact amount. Since she has as many as 105 coins with her, 
she definitely needs your help. You are supposed to tell her, 
for any given amount of money, 
whether or not she can find two coins to pay for it.

Input Specification:
Each input file contains one test case. 
For each case, the first line contains 2 positive numbers: N (<=105, the total number of coins) 
and M(<=103, the amount of money Eva has to pay). The second line contains N face values of the coins, 
which are all positive numbers no more than 500. All the numbers in a line are separated by a space.

Output Specification:
For each test case, 
print in one line the two face values V1 and V2 (separated by a space) such that V1 + V2 = M and V1 <= V2. 
If such a solution is not unique, output the one with the smallest V1. 
If there is no solution, output "No Solution" instead.


Sample Input 1:
8 15
1 2 8 7 2 4 11 15

Sample Output 1:
4 11


Sample Input 2:
7 14
1 8 7 2 4 11 15

Sample Output 2:
No Solution



#include <cstdio>

int HashTable[10010];
int N, money;

int main() {
	scanf("%d%d",&N,&money);
	int x;
	for(int i=0; i<N; i++) {
		scanf("%d",&x);
		HashTable[x]++;
	}
	// for(int i=1; i<=20; i++) {
	// 	printf("%d ",HashTable[i]);
	// }
	int y;
	for(int i=1; i<=money; i++) {
		if(money % i == 0 && HashTable[i] >= money / i) {  ///
			for(int j=0; j<money/i; j++) {
				printf("%d",i);
				if(j != money/i - 1) printf(" ");
			}
			return 0;
		}
		y = money - i;  ///
		if(y != i && HashTable[i] != 0 && HashTable[y] != 0) {
			printf("%d %d",i,y);
			return 0;
		}
	}
	printf("No Solution");

	return 0;
}