#include <cstdio>
#include <cmath>
const int N = 4;
const double EPS = 1e-5;
const double ans[N];
bool vis[N];
bool flag = false;
void dfs(int cur){  //当前已经处理完的数字
	if(flag) return;
	if(cur == N){
		for(int i=0;i<N;i++){
			if(!vis[i] && abs(i)-24.0 < EPS) flag = ture;
		}
		return;
	}
	for (int i=0;i<N;i++){  //首先对这个数组进行顺序遍历
		if(vis[i]) continue;
		for(int j=0;j<N;j++){
			//////////////
		}
	}
}
int main(){

	return 0；
}
//https://www.bilibili.com/video/av15330851/?from=search&seid=10340109661145465912