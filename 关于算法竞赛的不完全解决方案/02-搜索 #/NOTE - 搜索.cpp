// 基础搜索——DFS


void dfs( 状态A ){  // void  void  void  void
	if ( 状态A不合法 ) {
		return;
	}
	if ( 状态A为目标状态 ) {
		输出;
		return;
	}
	if ( 状态A不为目标状态 ) {
		dfs ( A + 偏移 );
	}
}



// 【例1】 凑算式-16蓝桥
//      B   DEF
// A + —— + ———— = 10   //A~I代表1~9的不同的数字，共有多少组解。注DEF代表一个三位数...
//      C   GHI
#include <cstdio>
#include <cmath>
using namespace std;

const int MAXN = 110

int n = 0;
double number[MAXN];
bool vis[MAXN];

void DFS(int index) {
	if(index == 9) {  //////// 9  9  9  9  9  9为number[8]的下一个，number[9]并不参与
		if(fabs(number[0] + number[1]/number[2] + 
		  (number[3]*100.0 + number[4]*10.0 + number[5]) / 
		  (number[6]*100.0 + number[7]*10.0 + number[8]) -
		  10.0) < 1e-5) {
			n++;
		}
		return;
	}
	for(int i=1; i<=9; i++) {  //遍历并递归
		if(vis[i]==false) {
			number[index] = (double)i;
			vis[i] = true;
			DFS(index+1);
			vis[i] = false;  //////因为上上句标记的点:不行(DFS(index+1)遭到返回)或使(index == 9)， 所以此处要清除上上句的对这个点的标记
		}
	}
}

int main() {
	DFS(0);
	printf("%d",n);
	return 0;
}


// "叠数"一般用for方式
// "图中走步"一般用多个方向语句dfs(x,y+1);dfs(x+1,y);dfs(x,y-1);dfs(x-1,y);
// (当然方向语句也是可以用for枚举)
// "DFS"和"套for"同属暴力,但DFS在时间上较优，并且dfs的层数是不固定的


// 【例2】 小学生作业-17.12院选
// 小学生寒假作业：
// □ + □ = □
// □ - □ = □
// □ × □ = □
// □ ÷ □ = □
// 每个方块代表 1~13 中的某一个数，不能重复。
// 如：
// 6 + 7 = 13
// 9 - 8 = 1
// 3 * 4 = 12
// 10 / 2 = 5
//
// 7 + 6 = 13
// 9 - 8 = 1
// 3 * 4 = 12
// 10 / 2 = 5
// 就算两种解法(加法/乘法交换律算不同的方案)
// 共多少种方案
#include <cstdio>

const int MAXN = 110;

int number[MAXN], n = 0;
bool vis[MAXN];

void DFS(int index) {
	if(index == 3 && number[0] + number[1] != number[2])
		return;
	if(index == 6 && number[3] - number[4] != number[5])
		return;
	if(index == 9 && number[6] * number[7] != number[8])
		return;
	//if(index == 12 && number[9] / number[10] == number[11]) {
	if(index == 12 && number[11] * number[10] == number[9]) {  ////
		n++;
		return;
	}
	for(int i=1; i<=13; i++) {
		if(vis[i] == false) {
			vis[i] = true;
			number[index] = i;
			DFS(index+1);
			vis[i] = false;
		}
	}
}

int main() {
	DFS(0);
	printf("%d",n);

	return 0;
}


// 【例3】 方块分割-17蓝桥
// 6x6的方格，沿着格子的边线剪开成两部分。要求这两部分的形状完全相同。
// 如图，就是可行的分割法。
// 试计算：包括这3种分法在内，一共有多少种不同的分割方法。
// 注意：旋转对称的属于同一种分割法 (/4)

// Thinking:
// 因为dfs一定是“一笔画的”,而在题目样图3中，用dfs搜索块显然不能满足。
// 其实只需要剪切的线关于图案的中点中心对称。
// 那么我们可以将格子格子之间接壤的看作边，边与边相交的看作点。
// 则从(3,3)点出发，找一条边到达图案的外圈。
// 从(3,3)出发的是看作两个人出发，两个人的线路一直是对称。
// 对称可由：一步标记两个对称的点，来实现对称的走法。(仅由标记来实现对称)
// 最后除以4

#include <cstdio>

const int MAXN = 110;

int cnt = 0;  // N为
bool vis[MAXN][MAXN];

void DFS(int x, int y) {  //二维
	if(vis[x][y]) return;
	if(x == 0 || y == 0 || x == 6 || y == 6) {  //////先判是否重复选(由上句代码判断)再判是否达到标准
		cnt++;
		return;
	}
	////////////////先返回再标记////////////////
	vis[x][y] = vis[6 - x][6 - y] = true;    //////标记本次的点，而并不是标记下一步的点，因为那样需要标记的点多，费代码
	DFS(x, y + 1);  //上
	DFS(x, y - 1);  //下
	DFS(x - 1, y);  //左
	DFS(x + 1, y);  //右
	vis[x][y] = vis[6 - x][6 - y] = false;

	// 也可以这样写：
	// if(!vis[x][y]) {
	// 	vis[x][y] = vis[6 - x][6 - y] = true;
	// 	DFS(x, y + 1);  //上
	// 	DFS(x, y - 1);  //下
	// 	DFS(x - 1, y);  //左
	// 	DFS(x + 1, y);  //右
	// 	vis[x][y] = vis[6 - x][6 - y] = false;
	// } 

}

int main() {
	DFS(3,3);
	printf("%d",cnt/4);

	return 0;
}


// 【例4】 马走棋盘*
// 如图5*5国际象棋盘，马走“日”
// 问一个马从第一个格子开始走，走遍整个5*5棋盘有多少方案

#include <cstdio>

const int MAXN = 110;

int cnt = 0;
bool vis[MAXN][MAXN];

void DFS(int x, int y, int cur) {  //cur为走了多少个格子
	if(x < 0 || x > 4 || y < 0 || y > 4) return;
	if(vis[x][y]) return;
	if(cur == 5 * 5 - 1) {  //因为起始点在(0,0)处,所以1+24步=25个格
		cnt++;  // 当走完最后一步(第24步),此时在第25个格上,当这个格没有被走过并且没有在边界外，才算是一次走完的方案
		return;
	}
	vis[x][y] = true;
	//往8个方向走 
	DFS(x-1,y-2,cur+1);
	DFS(x-1,y+2,cur+1);
	DFS(x-2,y-1,cur+1);
	DFS(x-2,y+1,cur+1);
	DFS(x+1,y-2,cur+1);
	DFS(x+1,y+2,cur+1);
	DFS(x+2,y-1,cur+1);
	DFS(x+2,y+1,cur+1);
	vis[x][y] = false;
}

int main() {
	DFS(0,0,0);
	printf("%d",cnt);

	return 0;
}


// 【例5】 n皇后*
// 在 “n*n的棋盘上放置n个皇后”，使彼此不受攻击的方法是：
// 一个皇后若不(受)攻击，那么她在棋盘上的那行、那列、那(主/副)对角线上都不能再放第二个皇后
// 共有多少放法。

#include <cstdio>

int n, ans = 0;
int vis[3][20];
// vis[][] 是一个三行的二维数组：
// 因为本解法是按行(cur++)，所以行数天然不冲突，仅判其他三个条件即可
// 第一行记录的是第i列【整个一列(而不是和上例一样仅代表一个格)】有没有放皇后。例如：vis[0][i]==1;指的是棋盘上第i列已经有皇后。从而判断是否有列冲突
// 第二行记录的是副对角线【整个一条】上有没有放皇后。
// 第三行记录的是主对角线【整个一条】上有没有放皇后。

void dfs(int cur) {  //cur——此题中表示行
	if(cur == n) {  //放满n行了，n个皇后也就放好了
		ans++;
		return;
	}
	//if(vis[0][i] || vis[1][cur+i] || vis[2][cur-i+n]) return;  //如果加在这的话，i必须有值，使i有值的话，dfs的形参就复杂了
	for(int i=0; i<n; i++) {  // 在cur这行里，枚举列  【解决n皇后的有效途径——步cur为行，dfs内枚举列】
		if(!vis[0][i] && !vis[1][cur+i] && !vis[2][cur-i+n]) {  //因为递归只传了cur一个值，所以判断语句只能加在这
			//检查：列、主对角线、副对角线 是否有冲突
			//小技巧：格子中(x+y)值相等的在同一副对角线上，(x-y)值相等的在同一主对角线上
			vis[0][i] = 1;  //标记 列
			vis[1][cur+i] = 1;  //标记 行+列 -> 副对角线
			vis[2][cur-i +n] = 1;  //标记 行-列 +n(防止负) -> 主对角线			
			dfs(cur+1);  //到下一行
			vis[0][i] = 0;  //清除标记
			vis[1][cur+i] = 0;
			vis[2][cur-i+n] = 0;
		}
	}
}
int main(){
	scanf("%d",&n);
	dfs(0);   // 从第0行开始
	printf("%d",ans);
	return 0;
}


---------------------------------------------------------------------
// 另外，还有一种“通过交换”来实现递归的方式：
// 例：1,2,3...9 这九个数字组成一个分数，其值恰好为1/3，如何组
#include <stdio.h>

void test(int x[]) {
	int a = x[0]*1000 + x[1]*100 + x[2]*10 + x[3];
	int b = x[4]*10000 + x[5]*1000 + x[6]*100 + x[7]*10 + x[8];
	
	if(a*3==b) printf("%d / %d\n", a, b);
}

void f(int x[], int k) {
	int i,t;
	if(k>=9) {
		test(x);
		return;
	}
	
	for(i=k; i<9; i++) {

		t=x[k]; 
		x[k]=x[i]; 
		x[i]=t;

		f(x,k+1);

		t=x[k]; 
		x[k]=x[i]; 
		x[i]=t;
	}
}
	
int main() {
	int x[] = {1,2,3,4,5,6,7,8,9};
	f(x,0);	
	return 0;
}


---------------------------------------------------------------------
// BFS
// 没写BFS的例子————BFS通过队实现,DFS通过递归实现