A+B Format.

Calculate(计算) a + b and output the sum in standard format -- that is,(也就是说) 
the digits must be separated into groups of three by commas(逗号) (unless there are less than four digits).

Input
Each input file contains one test case. 
Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. 
The numbers are separated by a space.

Output
For each test case, you should output the sum of a and b in one line. 
The sum must be written in the standard format.


Sample Input
-1000000 9
Sample Output
-999,991

#include <cstdio>
#include <cmath>
using namespace std;
const int MAXN = 10010;
int main() {
	int long long a, b, c;
	scanf("%lld%lld",&a,&b);
	c = a + b;
	if(c < 0) {
		printf("-");
		c = abs(c);
	}
	long long cnt = 0, number[MAXN];
	do {
		number[cnt++] = c % 10;
		c /= 10;
	} while(c != 0);
	for(int i = cnt - 1; i >= 0; --i) {
		if((i+1) % 3 == 0 && i != cnt - 1) printf(",");
		printf("%lld",number[i]);
	}
	return 0;
}