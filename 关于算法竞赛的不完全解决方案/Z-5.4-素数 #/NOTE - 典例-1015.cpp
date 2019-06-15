Reversible Primes (20)

A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. 
For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.

Now given any two positive integers N (< 105) and D (1 < D <= 10), 
you are supposed to tell if N is a reversible prime with radix D.

Input Specification:

The input file consists of several test cases. 
Each case occupies a line which contains two integers N and D. 
The input is finished by a negative N.

Output Specification:

For each test case, print in one line "Yes" if N is a reversible(回文) prime with radix D, 
or "No" if not.

Sample Input:
73 10    N  Radix
23 2
23 10
-2
Sample Output:
Yes
Yes
No


如果N是素数，且N在Radix进制下翻转后的数在十进制下也是素数则输出yes,否则no


#include <cstdio>
#include <cmath>
using namespace std;

const int MAXN = 100010;

int N, D, lenN, number[MAXN];

bool isPrime(int x) {
	if(x <= 1) return false;  ////
	// int sqr = (int)sqrt(1.0 * x);
	for(int i=2; i<=sqrt(x); i++) {  ////
		if(x % i == 0) return false;
	}
	return true;
}

int main() {
	while(1) {
		int tempN, tempD;
		scanf("%d%d",&tempN,&tempD);
		if(tempN < 0) break;
		N = tempN;
		D = tempD;
		if(!isPrime(N)) {
			printf("No\n");	
		} else {

			// 10进制N 转换为 D进制 存在数组中
			int len = 0;  // 顺便取得位数len
			do{
				number[len++] = N % D;  //倒序的
				N /= D;
			} while(N != 0);  // 结束时 N为0

			// 将数组number[]中的数的每位用秦九韶法转换为一个数字N，PS:因为number[]中是倒序的，所以正序遍历为翻转
			for(int i=0; i<len; i++) {
				N = N * D + number[i]; ////反转后的十进制
			}

			if(isPrime(N)) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}


【规范代码模板：】
---------------------------------------
	求余除基，将十进制数N_shi转为R进制数存到数组number[]中
int len = 0;
do {
	number[len++] = N_shi % R;
	N_shi /= R;
} while(N_shi != 0)

---------------------------------------
	直接将R进制数N_r转十进制N_shi，不用数组，效率低于秦九韶
int N_shi = 0, product = 1;
while(N_r != 0) {
	N_shi += N_r % 10 * product;
	N_r /= 10;
	product *= R;
}

---------------------------------------
	秦九韶，将数组内的R进制数转为十进制数N_shi
	已知： number[] 和 number[]的长度len
int N_shi = 0;
for(int i=0; i<len; i++) {
	N_shi += N_shi * R + number[i];  //第一次循环时，此式=number[0]
}



#include <cstdio>
#include <cmath>
using namespace std;
const int MAXN = 20;
bool isPrime(int x) {
	if(x <= 1) return false;
	for(int i=2; i<=sqrt(x); i++)
		if(x % i == 0)
			return false;
	return true;
}
int main() {
	while(1) {
		int N, D;
		scanf("%d",&N);
		if(N < 0) return 0;
		scanf("%d",&D);
		if(!isPrime(N)) {  // --|||
			printf("No\n");	
			continue;
		}
		int len = 0, number[MAXN];
		do{
			number[len++] = N % D;
			N /= D;
		} while(N != 0);
		for(int i=0; i<len; i++)
			N = N * D + number[i];  // --|||
		if(isPrime(N)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}