Radix(基数)

Given a pair of positive integers, for example, 
6 and 110, can this equation 6 = 110 be true? The answer is "yes", if 6 is a decimal number and 110 is a binary number.

Now for any pair of positive integers N1 and N2, your task is to find the radix of one number while that of the other is given.
你的任务是找到一个数的基数，而另一个数的基数是给定的。

Input Specification:
Each input file contains one test case. Each case occupies a line which contains 4 positive integers:
N1 N2 tag(标签) radix
Here N1 and N2 each has no more than 10 digits. 
不超过10个数位
A digit is less than its radix and is chosen from the set {0-9, a-z} where 0-9 represent the decimal numbers 0-9, 
and a-z represent the decimal numbers 10-35.
The last number "radix" is the radix of N1 if "tag" is 1, or of N2 if "tag" is 2.
最后一个数字“基数”是N1(如果“标签”是1)的基数，或者N2(如果“标签”是2)的基数。

Output Specification:
For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true. 
If the equation is impossible, print "Impossible". If the solution is not unique, output the smallest possible radix.

Sample Input 1:
6 110 1 10
Sample Output 1:
2  // 6以10为基数 == 110以(2)为基数

Sample Input 2:
1 ab 1 2
Sample Output 2:
Impossible

code1 22分-------------------------------------
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;
const int MAXN = 20;
int main() {
	char a[MAXN], b[MAXN];
	int tag, radix;
	scanf("%s %s %d %d",&a,&b,&tag,&radix);
	if(tag == 2) swap(a,b);
	LL sum1 = 0;
	for(int i=0; i<strlen(a); i++) {
		if(a[i] >= '0' && a[i] <= '9') sum1 = sum1 * radix + (a[i] - '0');  //// (1)不是+= (2)先乘后加 
		else sum1 = sum1 * radix + (a[i] - 'a' + 10);
	}
	for(int x=1; x<=sum1; x++) {
		LL sum2 = 0;
		for(int i=0; i<strlen(b); i++)
			if(b[i] >= '0' && b[i] <= '9') sum2 = sum2 * x + (b[i] - '0');
			else sum2 = sum2 * x + (b[i] - 'a' + 10);
		if(sum1 == sum2) {
			printf("%d",x);
			return 0;	
		}
	}
	printf("Impossible");
}

code2 AC-------------------------------------
（1）数b的进制下界为（所有数位中最大的那个数+1）（例如：2进制最大表示01），上界为（max(下界与数a的十进制值)+1）
（2）经测试，本题中的Redix的最大值为INT_MAX，即2^31-1，因此必须在计算十进制的过程中判断是否溢出。（因为默认是不可能超过longlong的）
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long
LL solve(char n[16], int radix) {
    LL val = 0;
    int len = strlen(n);
    for(int i = 0; i < len; ++i) {
        val *= radix;
        if (n[i] >= '0' && n[i] <= '9') {
            val += (n[i]-'0');
        } else {
            val += (n[i]-'a'+10);
        }
        if (val < 0) {  ////超LL范围
            return -1;
        }
    }
    return val;
}
int main() {
    char n1[16];
    char n2[16];
    int tag, radix;
    scanf("%s %s %d %d", n1, n2, &tag, &radix);
    if (tag == 2) swap(n1, n2);
    LL valN1 = solve(n1, radix);
    LL minR = 0;
    LL maxR = valN1+1;
    LL midR;
    for(int i = 0; n2[i]; ++i) {
        minR = n2[i] > minR ? n2[i] : minR;
    }
    if (minR >= '0' && minR <= '9') {
        minR = minR-'0'+1;
    } else if (minR >= 'a' && minR <= 'z') {
        minR = minR-'a'+10+1;
    }
    while(minR <= maxR) {
        midR = (minR+maxR) / 2;
        LL valN2 = solve(n2, midR);
        if (valN2 == -1 || valN2 > valN1) {
            maxR = midR - 1;
        } else if (valN2 < valN1) {
            minR = midR + 1;
        } else if (valN2 == valN1) {
            printf("%lld\n", midR);
            return 0;
        }
    }
    printf("Impossible\n");
    return 0;
}