Product of Polynomials(多项式的积).

This time, you are supposed to find A*B where A and B are two polynomials.

Input Specification:
Each input file contains one test case. Each case occupies 2 lines, 
and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, 
where K is the number of nonzero terms in the polynomial, 
Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients(指数和系数), respectively. 
	例如：指数为3，系数为3，则即为27.
It is given that 1 <= K <= 2000, 0 <= NK < ... < N2 < N1 <=1000.

Output Specification:
For each test case you should output the product of A and B in one line, 
with the same format as the input. 
Notice that there must be NO extra space at the end of each line. 
Please be accurate up to 1 decimal place.

Sample Input
2         1(指) 2.4(系)     0  3.2
2         2     1.5         1  0.5
Sample Output
3         3     3.6         2  6.0         1 1.6

#include <cstdio>
#include <cstring>
const int MAXN = 10100;
int main() {
	double number1[MAXN], number2[MAXN], number3[MAXN];
	int K1, K2, maxIndex1 = 0, maxIndex2 = 0;
	memset(number1,0.0,MAXN);
	memset(number2,0.0,MAXN);
	memset(number3,0.0,MAXN);
	scanf("%d",&K1);
	for(int i=0; i<K1; i++) {
		int e;
		double c;
		scanf("%d%lf",&e,&c);
		number1[e] += c;
		if(maxIndex1 < e) maxIndex1 = e;
	}
	scanf("%d",&K2);
	for(int i=0; i<K2; i++) {
		int e;
		double c;
		scanf("%d%lf",&e,&c);
		number2[e] += c;
		if(maxIndex2 < e) maxIndex2 = e;
	}
	for(int i=0; i<=maxIndex1; i++)
		for(int j=0; j<=maxIndex2; j++)
			if(number1[i] != 0.0 && number2[j] != 0.0)
				number3[i + j] += number1[i] * number2[j];
	int cnt = 0;
	for(int i=maxIndex1 + maxIndex2; i>=0; i--)
		if(number3[i] != 0.0)
			cnt++;
	printf("%d",cnt);
	for(int i=maxIndex1 + maxIndex2; i>=0; i--)
		if(number3[i] != 0.0)
			printf(" %d %0.1f",i, number3[i]);
			//printf(" %d %g",i, number3[i]);  // %g
	return 0;
}