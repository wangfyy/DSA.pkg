A+B for Polynomials(多项式).

This time, you are supposed to find A+B where A and B are two polynomials.

Input
Each input file contains one test case. Each case occupies 2 lines, 
and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, 
where K is the number of nonzero terms(非零项) in the polynomial, 
Ni and aNi (i=1, 2, ..., K) are the exponents(指数) and coefficients(系数), respectively(分别的). 
It is given that 1 <= K <= 1000，0 <= NK < ... < N2 < N1 <=1000.

Output
For each test case you should output the sum of A and B in one line, with the same format as the input. 
Notice that there must be NO extra space at the end of each line. 
Please be accurate to 1 decimal place. 请精确到1位小数。

Sample Input
2 1 2.4 0 3.2 (A 个数 指数 系数 指数 系数)
2 2 1.5 1 0.5 (B)
Sample Output
3 2 1.5 1 2.9 0 3.2

// 代码2 17'-------------------------------------------------------
#include <cstdio>
#include <map>
using namespace std;
const int MAXN = 1010;
int main(){
	map<int,double> mapp;
	int NumTerms, t = 2, cnt = 0;
	while(t--) {
		scanf("%d",&NumTerms);
		for(int i=0; i<NumTerms; i++) {
			int exponents;
			double coefficients;
			scanf("%d%lf",&exponents,&coefficients);
			if(mapp.find(exponents) != mapp.end()) mapp[exponents] += coefficients;
			else {
				mapp[exponents] = coefficients;
				cnt++;	
			}
		}
	}
	printf("%d",cnt);
	for(map<int,double>::reverse_iterator rit = mapp.rbegin(); rit != mapp.rend(); rit++)
		printf(" %d %.1lf",rit->first,rit->second);
	return 0;
}
// %g 无多余零
// 反向迭代 for(map<int,double>::reverse_iterator rit = mapp.rbegin(); rit != mapp.rend(); rit++)

// 代码1 -------------------------------------------------------
// 开一个数组存放系数，其下标是指数
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
	double num[1010];
	fill(num,num+1010,0.0);  //memset只能设置0或-1
	//输入
	int k,zs;
	double xs;
	for(int i=0; i<2; i++) {
		scanf("%d",&k);
		for(int j=0; j<k; j++) {
			scanf("%d %lf",&zs,&xs);
			num[zs] += xs;
		}
	}
	//计算个数
	int count = 0;
	for(int i=1009; i>=0; i--) {
		if(num[i] != 0.0) {
			count ++;
		}
	}
	printf("%d",count);
	if(count != 0) printf(" ");
	//输出各项
	int count_2 = 0;
	for(int i=1009; i>=0; i--) {
		if(num[i] != 0.0) {
			printf("%d %0.1lf",i,num[i]);
			count_2 ++;
			if(count_2 != count) printf(" ");
		}
	}
	return 0;
}