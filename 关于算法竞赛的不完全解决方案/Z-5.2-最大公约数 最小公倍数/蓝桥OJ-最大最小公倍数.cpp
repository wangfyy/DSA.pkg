已知一个正整数N，问从1~N中任选出三个数，他们的最小公倍数最大可以为多少。


------GG的暴力代码------
#include <stdio.h>

int gcd(int a, int b) {  //最大公约数(最大公因子) 
	return !b ? a : gcd(b, a % b);
}

int lcm(int a, int b) {  //最小公倍数 
	return a / gcd(a, b) * b;
}

int main(){  // 从1~n中任选出三个数，他们的最小公倍数最大为多少
	int n, max = 0;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			for(int k=1; k<=n; k++) {
				if(i != j && j != k) {
					int x = lcm(lcm(i,j),k);
					if(x > max) max = x; 
				}
			}
		}
	} 
	printf("%d",max);
//	int a, b, c;
//	scanf("%d%d%d",&a,&b,&c);
//	printf("%d %d",gcd(gcd(a,b),c),lcm(lcm(a,b),c));  //输出他们的最大公约数和最小公倍数 
	
	return 0;
}


------贪心代码------
【分析一波:】
首先确定是从大到小开始看，
	当第一个数是奇数时，奇偶奇，其中两个奇数中间差2，但奇数没有因子2。
		因为：lcm(a,b) = a * b / gcd(a,b) ,当最大公因数gcd(a,b)不为1时,lcm(a,b)就可能被减小
		所以：当n为奇数时，答案一定是n*(n-1)*(n-2)
	当第一个数是偶数时，n,n-1,n-2是 偶奇偶，这时候两个偶数之间一定会有公共因子2(由于和上面一样的原因，所以不要有非1的公共因子)，
		然后需要n-2再往后推一个取n-3，即：n,n-1,n-3（偶奇奇）,但这时候要注意，n，n-3之间可能会有公共因子3（如：1 2 3 .... '9' 10 11 '12'），
		这时候就需要判断n能否被3整除，如果可以，n-3也会被3整除，这样就不能取这三个数了，就不能再取n了，整体往后前一个，取n-1,n-2,n-3.
#include <stdio.h>
typedef long long ll;

int main(){  // 从1~n中任选出三个数，他们的最小公倍数最大为多少
	ll n, max = 0;
	scanf("%d",&n);
	if(n<=2) max = n;
	else if(n % 2 != 0) max = n * (n-1) * (n-2);
	else {
		if(n % 3 == 0) max = (n-1) * (n-2) * (n-3);
		else max = n * (n-1) * (n-3);
	}
	printf("%lld",max);
	
	return 0;
}