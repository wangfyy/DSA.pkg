Rational Sum (20)

Given N rational numbers in the form "numerator/denominator", you are supposed to calculate their sum.

Input Specification:

Each input file contains one test case. Each case starts with a positive integer N (<=100), followed in the next line N rational numbers "a1/b1 a2/b2 ..." where all the numerators and denominators are in the range of "long int". If there is a negative number, then the sign must appear in front of the numerator.

Output Specification:

For each test case, output the sum in the simplest form "integer numerator/denominator" where "integer" is the integer part of the sum, "numerator" < "denominator", and the numerator and the denominator have no common factor. You must output only the fractional part if the integer part is 0.


Sample Input 1:
5
2/5 4/15 1/30 -2/60 8/3
Sample Output 1:
3 1/3

Sample Input 2:
2
4/3 2/3
Sample Output 2:
2

Sample Input 3:
3
1/3 -1/6 1/8
Sample Output 3:
7/24



Sample Input 1:
5
2/5 4/15 1/30 -2/60 8/3
Sample Output 1:
3 1/3

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
int N;
struct Fraction{
	ll up;
	ll down;
};
ll gcd(ll a, ll b) {  //// 求a和b的最大公约数
	return b == 0 ? a : gcd(b, a%b);  ////////
}
Fraction reduction(Fraction result) {  // 约分化简，即：分子分母分别他们的最大公约数
	if(result.down < 0) {  // 分母为负，则令分子分母变为相反数
		result.up = -result.up;
		result.down = -result.down;
	}
	if(result.up == 0){  // 分子为0
		result.down = 1;  // 令分母为1
	} else {
		int d = gcd(abs(result.up),abs(result.down));  //分子分母的最大公约数，注意取绝对值
		result.up /= d;
		result.down /= d;
	}
	return result;
}
Fraction add(Fraction a, Fraction b) {  //实现加减  //直接通分加
	Fraction result;
	result.up = a.up * b.down + a.down * b.up;
	result.down = a.down * b.down;
	return reduction(result);  //必须在每一步加法后都进行约分，如果最后约分，中途可能就溢出了
}
Fraction multi(Fraction a, Fraction b) {  //直接乘
	Fraction result;
	result.up = a.up * b.up;
	result.down = a.down * b.down;
	return reduction(result);  //必须在每一步加法后都进行约分，如果最后约分，中途可能就溢出了
}
Fraction divide(Fraction a, Fraction b) {  //直接交叉乘
	Fraction result;
	result.up = a.up * b.down;
	result.down = a.down * b.up;
	return reduction(result);  //必须在每一步加法后都进行约分，如果最后约分，中途可能就溢出了
}
void showResult(Fraction r) {
	reduction(r);  //输出前的约分化简，非必要
	if(r.down == 1) {  // 整数
		printf("%lld",r.up);
	} else if(abs(r.up) > r.down) {  // 假分数，注意绝对值 
		printf("%lld %lld/%lld",r.up/r.down,abs(r.up) % r.down,r.down);  // 注意绝对值，若有负号在前面整数部分显示
	} else {  // 真分数
		printf("%lld/%lld",r.up,r.down);
	}
}
int main() {
	scanf("%d",&N);
	Fraction sum, temp;
	sum.up = 0;  ////
	sum.down = 1;
	for(int i=0; i<N; i++) {
		scanf("%lld/%lld",&temp.up,&temp.down);
		sum = add(sum,temp);
	}
	showResult(sum);
	return 0;
}