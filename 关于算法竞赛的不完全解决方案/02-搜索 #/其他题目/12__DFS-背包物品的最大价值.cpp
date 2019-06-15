//算法笔记-P271
#include <cstdio>
const int maxn=30;
int n,V,maxValue=0;
int w[maxn],c[maxn];
void dfs(int index,int sumW,int sumC){
	if(index==n){
		return;
	}
	dfs(index+1,sumW,sumC);  //岔路口
	if(sumW+w[index]<=V){
		if(sumC+c[index]>maxValue){
			maxValue=sumC+c[index];
		}
		dfs(index+1,sumW+w[index],sumC+c[index]);  //岔路口
	}
}
int main(){
	scanf("%d%d",&n,&V);
	for(int i=0;i<n;i++){
		scanf("%d",&w[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&c[i]);
	}
	dfs(0,0,0);
	printf("%d",maxValue);
	return 0;
}