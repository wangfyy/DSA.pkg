Maximum Subsequence Sum.

Given a sequence of K integers { N1, N2, ..., NK }. 
A continuous subsequence is defined to be { Ni, Ni+1, ..., Nj } where 1 <= i <= j <= K. 
The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. 
For example, given sequence { -2, 11, -4, 13, -5, -2 }, 
its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.
Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.
  现在，您应该找到最大的和，以及最大子序列的【【第一个】和【最后一个数字】】

Input Specification:
Each input file contains one test case. Each case occupies two lines. 
The first line contains a positive integer K (<= 10000). The second line contains K numbers, separated by a space.

Output Specification:
For each test case, output in one line the largest sum, 
together with the first and the last numbers of the maximum subsequence. 
The numbers must be separated by one space, but there must be no extra space at the end of a line. 

In case that the maximum subsequence is not unique, 
output the one with the smallest indices i and j (as shown by the sample case). 
  如果最大子序列不是唯一的，输出最小索引i和j的一个（如示例例子所示）。
If all the K numbers are negative, then its maximum sum is defined to be 0, 
and you are supposed to output the first and the last numbers of the whole sequence.
  如果所有k个数都是负的，那么它的最大和定义为0，你应该输出整个序列的第一个和最后一个数字。

Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4

//代码
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100100;
int K, number[MAXN], dp[MAXN];
int find(int x, int id2) { //寻找前缀
	if(x == number[id2]) return id2;
	for(int i=id2; i>=0; i--) {
		x -= number[i];
		if(x == 0) return i;
	}
}
int main() {
	scanf("%d",&K);
	int cnt = 0;
	for(int i=0; i<K; i++) {
		scanf("%d",&number[i]);
		if(number[i] < 0) cnt++;
	}
	if(cnt == K) {
		//如果所有k个数都是负的，那么它的最大和定义为0，你应该输出整个序列的第一个和最后一个数字
		printf("0 %d %d",number[0],number[K - 1]);
		return 0;
	}
	// 边界
	dp[0] = number[0];
	//状态转移方程
	for(int i=1; i<K; i++)
		dp[i] = max(number[i], dp[i-1] + number[i]);
	int maxResult = 0, maxResultId1, maxResultId2;
	for(int i=0; i<K; i++) {
		if(maxResult < dp[i]) {
			maxResult = dp[i];
			maxResultId2 = i;
			maxResultId1 = find(maxResult, maxResultId2);
		}
	}
	printf("%d %d %d",maxResult,number[maxResultId1],number[maxResultId2]);
		//最大的和，以及最大子序列的第一个数字和最后一个数字
	return 0;	
}
//以上代码测评姬返回一个段错误。。

//学习一下柳神的代码 极致！
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n); //初始化空间为n
    int leftindex = 0, rightindex = n - 1, sum = -1, temp = 0, tempindex = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        temp = temp + v[i];
        if(temp < 0) { //出现负值则抛弃(注释均为自己加的)
            temp = 0;
            tempindex = i + 1;
        } else if (temp > sum) { //出现极值则记录前后位置
            sum = temp;
            leftindex = tempindex;
            rightindex = i;
        } //无负值且无极值出现则不做操作
    }
    if (sum < 0) sum = 0;
    printf("%d %d %d", sum, v[leftindex], v[rightindex]);
    return 0;
}