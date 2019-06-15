// DP基础

// DP有两种写法———— 递归 / 递推(for循环)
// DP的递归写法（缺点是：不利于节省空间）
// 递归：带有“记忆化搜索(备忘录)”结构的菲波那切数列
	int f(int n){
		if(n == 0 || n == 1) return 1;
		if(dp[n] != -1) return dp[n];
		else{
			dp[n] = f(n - 1) + f(n - 2);  //dp数组用于存放冗余
			return dp[n];
		}
	}
// 菲波那切数列 原代码
	int f(int n){  
		if(n == 0 || n == 1) return 1;
		else return f(n - 1) + f(n - 2);
	}

// 递推：数塔问题
// 因为：例如 路径5->8->7和路径5->3->7都会去计算7下面的路径，造成了冗余（p427），
// 所以令dp[i][j]表示“从第i行第j个数字出发的到达最底层的所有路径中能得到的最大和”，
// ...最后，dp[1][1]就是最终答案。
	const int maxn = 1000;
	int f[maxn][maxn],dp[maxn][maxn];
	int main(){
		int n;
		//输入
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				scanf("%d",&f[i][j]);
			}
		}
		//边界
		for(int j=1;j<=n;j++){
			dp[n][j] = f[n][j];  //数塔的最后一层的dp值总是等于元素本身
		}
		//从第n+1层计算出n层...不断往上计算出dp[i][j]
		for(int i=n-1;i>=1;i--){
			for(int j=1;j<=i;j++){
				//状态转移方程
				dp[i][j] = max(dp[i + 1][j],dp[i + 1][j + 1]) + f[i][j];
			}
		}
		//dp[1][1]即为需要的答案
		printf("%d\n",dp[1][1]);
		return 0;
	}
	//此题还有递归的写法但省略，递归的结构为：自顶向下(即:例如它会先算dp[1][1])。

// 至此总结为：截止目前为止，DP的引入部分已完结，可以看出不管是在“菲波那切数列”还是“数塔”中，
// DP(dp[]数组)都扮演着存储计算冗余的作用。

// 不管是本书还是教程所说的步骤都是：可以先分析出“暴力算法(包括递归或for循环(二者都无备忘录)两种代码结构)”,
// 再改造出“DP算法(即:在暴力的基础上加上“用于存放冗余的dp数组”的算法)”。

// DP的递推写法总是从边界出发！通过状态转移方程扩散至整个dp数组（p427）。
// 递推利于做节省空间的改造。

// 最大连续子序列和
// 因为发现左端点的枚举是不必要的，所以令dp[]存放以A[i]结尾(强制A[i]结尾p430)的连续序列的最大和(p430)
	const int maxn = 10010;
	int A[maxn],dp[maxn];
	int main(){
		//输入
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%d",&A[i]);
		}
		//边界
		dp[0] = A[0];
		//状态转移方程
		for(int i=0;i<n;++i){
			dp[i] = max(A[i],dp[i-1]+A[i]);  ////////////////////////  【 DP's feeling 】  ~ ~ ~ ~
		}
		//输出(遍历出dp[]中的最大值)
		int k = 0;  //下标
		for(int i=0;i<n;i++){
			if(dp[i] > dp[k]){
				k = i;
			}
		}
		printf("%d\n",dp[k]); //对下标的操作
		// int max;
		// for(int i=0;i<n;i++){
		// 	if(dp[i] > max){
		// 		max = dp[i];
		// 	}
		// }
		// printf("%d\n",max); //直接对元素的操作
		return 0;
	}
	
// 最长不下降子序列(Longest Increasing Sequence -- LIS)
// 令dp[]存放以A[i]结尾(强制A[i]结尾p432)的最长不下降子序列的长度(p432)
	const int N = 100;
	int A[N],dp[N];
	int max(int a,int b){
		return a > b ? a : b;  //如果a大于b，则返回a；否则返回b
	}
	int main(){
		//输入
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&A[i]);
		}

		int max = -1;  //记录最大的dp[i]
		for(int i=1; i<=n; i++){  //按顺序计算出dp[i]的值
			dp[i] = 1;  //边界（初始）
			for(int j=1; j<i; j++){ // A[j]们 和 A[i] 依次比较  ////
				if(A[i] >= A[j] && (dp[j] + 1 > dp[i]) ){  ////
					dp[i] = dp[j] + 1;
				}
			}
			max = max(max,dp[i]);
		}
		printf("%d\n",max);

		return 0;
	}

// 最长公共子序列(Longest Common Subsequece--LCS)
	const int N = 100;
	char A[N],B[N];  //char A[]
	int dp[N][N];  //二维
	int main(){
		int n;
		gets(A+1);  //从下标为1开始读入  //gets()
		gets(B+1);  //
		int lenA = strlen(A+1);  //读取长度也从下标为1开始  //strlen()
		int lenB = strlen(B+1);  //
		//边界
		for(int i=0;i<=lenA;i++){
			dp[i][0] = 0;
		}
		for(int i=0;i<=lenB;i++){
			dp[0][i] = 0;
		}
		//状态转移方程 ———— dp[i][j]表示：串A的i号位 和 串B的i号位 之前的LCS的长度
		for(int i=1;i<=lenA;i++){
				for(int j=1;i<=lenB;j++){
					if(A[i] == B[j]){
						dp[i][j] = dp[i-1][j-1] + 1;
					}else{
						dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);  ////max(dp[i - 1][j],dp[i][j - 1])
					}
			}
		}
		//输出
		printf("%d\n",dp[lenA][lenB]);
		return 0;
	}
// 17蓝桥省赛_CPP/B No.6————最大公共子串
	#include <cstdio> 
	#include <cstring>
	const int N=256;
	int f(const char* s1, const char* s2){
	//int f(const char s1[N], const char s2[N]){ //等效
	//int f(const char s1[], const char s2[]){ //等效
		int a[N][N];  //【a[i][j]同样表示：串s1的第i号位之前和串s2的第j号位之前的最大公共子串的长度】
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		int i,j;
		memset(a,0,sizeof(int)*N*N);  //即 边界：a[0][j] = a[i][0] = 0;
		int max = 0;
		for(i=1;i<=len1;i++){
			for(j=1;j<=len2;j++){
				if(s1[i-1]==s2[j-1]){
					a[i][j]=a[i-1][j-1]+1;  //填空 即：状态转移方程     【即表示：最大公共子串的长度+1 (说法很重要)】
					if(a[i][j]>max) max=a[i][j];
				} 
				////// 没有else代码，说明当不相等的话串就断了(a[i][j]值为0)，
				////// 【区分题目是“串(本题)”还是“序列(BookAN p434最长公共子序列LCS)”】
			}
		}
		return max;
	}
	int main(){
		printf("%d\n", f("abcdkkka", "baabcdadabc"));    //答案 4
		return 0;
	}

// 最长回文子串
	const int maxn = 1010;
	char A[maxn];
	int dp[maxn][maxn];
	int main(){
		gets(S);
		int len = strlen(S),ans = 1;
		memset(dp,0,sizeof(dp));
		//边界
		for(int i=0;i<len;i++){
			dp[i][i] = 1;
			if(i < len - 1){
				if(S[i] == S[i + 1]){
					dp[i][i + 1] = 1;
					ans = 2;
				}
			}
		}
		//状态转移
		//要点在于往后枚举，使得每位都可计算。对于其中的衔接根本不用顾虑，虽然不好理解，但事实就如此。
		for(int L=3;L<=len;L++){  //枚举子串的长度
			for(int i=0;i+L-1<len;i++){  //枚举子串的起始端点(即左端点)
				int j = i + L - 1;  //子串右端点
				if(S[i] == S[j] && dp[i + 1][j - 1] == 1){  //如果(i+1)和(j-1)之间是回文的
					dp[i][j] = 1;  //表示i和j之间是回文的  //否则为0
					ans = L;  //更新最长回文子串长度
				}
			}
		}
		printf("%d\n",ans);
		return 0;
	}

// get!!：在“最长公共子序列”和“最长回文子串”中，dp[i][j]这个二维数组的两个维度(分别)巧妙的表示为：
// (串A的i号位)和(串B的i号位)之前的LCS的长度 ; (串的i号位)和(串的j号位)之间是否回文 。
// 而不必深究二维表每个格子位示图。






---------------------------背包知识点最新笔记 begin----------------------------
题目：
有n件物品，每件物品的重量为w[i]，价值为c[i]，
现有一个容量为V的背包，问如何选取物品放入背包使得背包内的物品的总价值最大，输出最大价值。
	若为：其中每种物品都只有 1件，则用01背包 
	若为：其中每种物品都只有 无穷件，则用完全背包
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 510;
int main() {
	int n, V, w[MAXN], c[MAXN], dp[MAXN][MAXN];
		//dp[i][v]表示前i件物品(1<=i<=n;0<=v<=V)(即:前i件物品中有的放有的不放)
		//恰好(即:放完后可能还有空间,但再加任何一件都装不下)
		//装入容量为V的背包中所能获得的最大价值
	scanf("%d %d",&n, &V);
	for(int i=0; i<n; i++)
		scanf("%d",&w[i]);
	for(int i=0; i<n; i++)
		scanf("%d",&c[i]);
	for(int v=0; v<=V; v++)
		dp[0][v] = 0;
	for(int i=1; i<n; i++)//当前物品
		for(int v=w[i]; v<=V; v++)//当前容量  ////为什么需要枚举v??????
			dp[i][v] = max(dp[i-1][v], dp[i-1][v-w[i]] + c[i]);//01背包 
			//若为完全背包：dp[i][v] = max(dp[i-1][v], dp[i][v-w[i]] + c[i]);
				//不同之处：完全背包里选择当前物品后的物品数量是不变的(无穷件)
	int maxmial = -1;
	for(int v=1; v<=V; v++)
		maxmial = max(maxmial, dp[n-1][v]);
	printf("%d\n",maxmial);
	//或直接输出：printf("%d %d",dp[n-1][V]);
	return 0;
}
//01包样例： 
// 5 8
// 3 5 1 2 2
// 4 5 2 1 3
//输出10 
---------------------------背包知识点最新笔记 end----------------------------


---------------------------背包知识点稍早前的笔记 begin----------------------------
	【多阶段动态规划问题：】
		有一类动态规划可解的问题，他可以描述为若干个有序的阶段，
	且每个阶段的状态只和上一个阶段的状态有关，
	一般把这类问题称为多阶段动态规划问题。
		显然对于这种问题，只需要从第一个问题开始，
	按照阶段的顺序解决每个阶段中状态的计算，
	就可以得到最后一个阶段中状态(在这个阶段中枚举每个状态，取其最大值)的解。
		01背包就是一个这样的例子：
	【01背包：】
	（1）边界————前0件物品放入任何容量v的背包都只能获得价值为0
	for(int v=0;v<=V;v++){
		dp[0][v] = 0;
	}
	（2）令dp[i][v]表示前i件物品(1<=i<=n;0<=v<=V)恰好(即:前i件物品中有的放有的不放，放完后可能还有空间,但再加任何一件都装不下)
		装入容量为V的背包中所能获得的最大价值
	for(int i=1;i<=n;i++){
		for(int v=w[i];v<=V;v++){
			dp[i][v] = max(dp[i - 1][v],dp[i - 1][v - w[i]] + c[i]);
		}
	}
	（3）枚举dp[n][v](0<=v<=V)，取最大值即为答案。
		 或直接输出：dp[n][V]
	【Thinking：】
		01背包的每个物品可以都可以看作一个阶段，这个阶段的状态有dp[i][0]~dp[i][V],
	他们均由上一个阶段的状态得到。事实上，对能够划分阶段的问题来说，都可以把阶段作为状态的一维。


	【例】有n件物品，每件物品的重量为w[i]，价值为c[i]，
		现有一个容量为V的背包，问如何选取物品放入背包使得背包内的物品的总价值最大，输出最大价值。
		注：其中每种物品都只有‘1’件。
	#include <cstdio>
	int max(int a,int b){
		return a > b ? a : b;
	}
	int main(){
		int n,V,w[100],c[100],dp[100][100];
		//输入
		scanf("%d %d",&n,&V);
		for(int i=0;i<n;i++){
			scanf("%d",&w[i]);
		}
		for(int i=0;i<n;i++){
			scanf("%d",&c[i]);
		}
		//边界
		for(int v=0;v<=V;v++){
			dp[0][v]=0;
		}
		//状态转移方程
		for(int i=1;i<=n;i++){
			for(int v=w[i];v<=V;v++){
				dp[i][v]=max(dp[i-1][v],dp[i-1][v-w[i]]+c[i]);
			}
		}
		//输出结果
		int max=-1;
		for(int v=1;v<=V;v++){
			if(dp[n][v]>max){
				max=dp[n][v];
			}
		}
		printf("%d\n",max);

		return 0;
	}

	/// 使用滚动数组优化空间后的代码暂时略过。
	

	【完全背包】———— 与01背包的差别在于：“其中每种物品都有‘无穷’件”
	【例 1 】有n件物品，每件物品的重量为w[i]，价值为c[i]，
		现有一个容量为V的背包，问如何选取物品放入背包使得背包内的物品的总价值最大，输出最大价值。
		注：其中每种物品都有‘无穷’件。
	（1）边界————前0件物品放入任何容量v的背包都只能获得价值为0
	for(int v=0;v<=V;v++){
		dp[0][v] = 0;
	}
	（2）令dp[i][v]表示前i件物品(1<=i<=n;0<=v<=V)恰好(即:前i件物品中有的放有的不放，放完后可能还有空间,但再加任何一件都装不下)
		装入容量为V的背包中所能获得的最大价值
	for(int i=1;i<=n;i++){
		for(int v=w[i];v<=V;v++){
			dp[i][v] = max(dp[i - 1][v],dp[i][v - w[i]] + c[i]);
			////区别于01背包:max(dp[i - 1][v],dp[i-1][v - w[i]] + c[i]); 完全背包选择当前物品后的物品数量是不变的(无穷件)。
		}
	}
	（3）枚举dp[n][v](0<=v<=V)，取最大值即为答案。
		 或直接输出：dp[n][V]
	【例 2 】 见：LanQiao-17-C/C++-B-T8 包子凑数 

	/// 同样 使用滚动数组优化空间后的代码暂时略过。
---------------------------背包知识点稍早前的笔记 end----------------------------