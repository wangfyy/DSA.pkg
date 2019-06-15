// 例如：
// n ＝ 5 ，r ＝ 3 ，所有组合为： 
// 1 2 3 
// 1 2 4 
// 1 2 5 
// 1 3 4 
// 1 3 5 
// 1 4 5 
// 2 3 4 
// 2 3 5 
// 2 4 5 
// 3 4 5
#include <cstdio>
int num[100],vis[100],n,r;
void print(){
	for(int j=1;j<=r;j++){
		printf("%d ",num[j]);
	}
	printf("\n");
	return;
}
void dfs(int index){  //index——已经选定的数的个数
	//因为是组合，所以i从上一个选定的数的下一个数开始循环，完成去重
	for(int i=num[index-1]+1;i<=n;i++){
		if(!vis[i]){
			num[index]=i;
			vis[i]=1;  //标记1~n的数中哪个在本轮已经被用了，对应第11行的for循环
			if(index==r)
				print();
			else
				dfs(index+1);
			vis[i]=0;
		}
	}
}
int main(){
	scanf("%d %d",&n,&r);
	dfs(1);
	return 0;
}