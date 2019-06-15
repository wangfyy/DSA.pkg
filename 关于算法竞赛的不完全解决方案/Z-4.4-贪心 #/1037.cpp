Magic Coupon (25)

The magic shop in Mars is offering some magic coupons. 
Each coupon has an integer N printed on it, meaning that when you use this coupon with a product, 
you may get N times the value of that product back! What is more, 
the shop also offers some bonus product for free. However, 
if you apply a coupon with a positive N to this bonus product, 
you will have to pay the shop N times the value of the bonus product... but hey, 
magically, they have some coupons with negative N's!    '

For example, given a set of coupons {1 2 4 -1}, 
and a set of product values {7 6 -2 -3} (in Mars dollars M$) where a negative value corresponds to a bonus product. 
You can apply coupon 3 (with N being 4) to product 1 (with value M$7) to get M$28 back; 
coupon 2 to product 2 to get M$12 back; and coupon 4 to product 4 to get M$3 back. On the other hand, 
if you apply coupon 3 to product 4, you will have to pay M$12 to the shop.
Each coupon and each product may be selected at most once. Your task is to get as much money back as possible.

Input Specification:
Each input file contains one test case. For each case, 
the first line contains the number of coupons NC, 
followed by a line with NC coupon integers. 
Then the next line contains the number of products NP, 
followed by a line with NP product values. 
Here 1<= NC, NP <= 105, and it is guaranteed that all the numbers will not exceed 230.

Output Specification:
For each test case, simply print in a line the maximum amount of money you can get back.


4
1 2 4 -15
-2 -3 3 4 5
6
-3 -2 -4 -1 0 7
4
7 6 -2 -3

43



思路：输入后，进行排序，然后现由从两端开始寻找：相同符号的相乘加上到结果中。
	之所以排序，是因为：贪心算法要每次选取最优值



#include <cstdio>
#include <algorithm>
using namespace std;

int N_a, N_b, a[10010], b[10010];
long long result = 0;

int main() {
	scanf("%d",&N_a);
	for(int i=0; i<N_a; i++) {
		scanf("%d",&a[i]);
	}
	scanf("%d",&N_b);
	for(int i=0; i<N_b; i++) {
		scanf("%d",&b[i]);
	}

	sort(a, a+N_a);
	sort(b, b+N_b);

	int i = 0;
	while(1) {
		if(a[i] < 0 && b[i] < 0) {
			result += a[i] * b[i];
			i++;
		}
		else break;
	}	
	i = 0;
	while(1) {
		int j_a = N_a - 1 - i;
		int j_b = N_b - 1 - i;
		if(a[j_a] > 0 && b[j_b] > 0) {
			result += a[j_a] * b[j_b];
			i++;
		}
		else break;
	}	
	printf("%lld",result);

	return 0;
}