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

For each test case, print in one line "Yes" if N is a reversible(����) prime with radix D, 
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


���N����������N��Radix�����·�ת�������ʮ������Ҳ�����������yes,����no


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

			// 10����N ת��Ϊ D���� ����������
			int len = 0;  // ˳��ȡ��λ��len
			do{
				number[len++] = N % D;  //�����
				N /= D;
			} while(N != 0);  // ����ʱ NΪ0

			// ������number[]�е�����ÿλ���ؾ��ط�ת��Ϊһ������N��PS:��Ϊnumber[]���ǵ���ģ������������Ϊ��ת
			for(int i=0; i<len; i++) {
				N = N * D + number[i]; ////��ת���ʮ����
			}

			if(isPrime(N)) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}


���淶����ģ�壺��
---------------------------------------
	�����������ʮ������N_shiתΪR�������浽����number[]��
int len = 0;
do {
	number[len++] = N_shi % R;
	N_shi /= R;
} while(N_shi != 0)

---------------------------------------
	ֱ�ӽ�R������N_rתʮ����N_shi���������飬Ч�ʵ����ؾ���
int N_shi = 0, product = 1;
while(N_r != 0) {
	N_shi += N_r % 10 * product;
	N_r /= 10;
	product *= R;
}

---------------------------------------
	�ؾ��أ��������ڵ�R������תΪʮ������N_shi
	��֪�� number[] �� number[]�ĳ���len
int N_shi = 0;
for(int i=0; i<len; i++) {
	N_shi += N_shi * R + number[i];  //��һ��ѭ��ʱ����ʽ=number[0]
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