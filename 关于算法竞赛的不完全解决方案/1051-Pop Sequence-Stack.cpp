// PAT-A-1051-Pop Sequence-Stack
#include <cstdio>
#include <stack>
using namespace std;
const int maxn = 1010;
int arr[maxn];  //保存题目给定的出栈序列
stack<int> st;  //定义栈，用以存放int型数组
int main(){
	int m,n,K;  //m:栈容量  n:每个样例(检查序列)的元素数目  K:样例(检查序列)的个数
	scanf("%d%d%d",&m,&n,&K);
	while(K--){  //循环执行K次
		//清空栈
		while(!st.empty()){
			st.pop();
		}
		//读入数据
		for(int i=1;i<=n;i++){
			scanf("%d",&arr[i]);
		}
		int current = 1;  //指向出栈序列中的待出栈元素
		bool flag = true;
		for(int i=1;i<=n;i++){
			st.push(i);  //把i压入栈
			if(st.size() > m){  //如果此时栈中元素个数大于容量m，则序列非法
				flag = false;
				break;
			}
			//栈顶元素与出栈序列的当前位置的元素相同时
			//抽象建模时用极端情况————令检查序列为：1,2,3,4,5
			while(!st.empty() && st.top() == arr[current]){
				st.pop();  //反复弹栈并令current++
				current++;
			}
		}
		if(st.empty() == true && flag == true){
			printf("YES\n");  //栈空且flag==true时表明合法
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
//	5 7 5
//	1 2 3 4 5 6 7
//	YES
//	3 2 1 7 5 6 4
//	NO
//	7 6 5 4 3 2 1
//	NO
//	5 6 4 3 7 2 1
//	YES
//	1 7 6 5 4 3 2
//	NO


//5 7 5
//1 2 3 4 5 6 7
//3 2 1 7 5 6 4
//7 6 5 4 3 2 1
//5 6 4 3 7 2 1
//1 7 6 5 4 3 2
#include <cstdio>
#include <stack>
using namespace std;
//const int maxn = 1010;
stack<int> st;
int main() {
	int M, N, K;  //M:栈的容量  N:每个待检查序列的长度  K:待检查序列的个数 
	scanf("%d%d%d",&M,&N,&K);
	int arr[N+1];
	while(K--) {
		for(int i=1;i<=N;i++) {
			scanf("%d",&arr[i]);
		}	
		int i = 1, s = 1, flag = 1;
		//for(int i=1;i<=N;i++) {
		while(1) {
			if(s > N) {
				if(st.size() == 0) {
					printf("YES\n");	
				} else {
					printf("NO\n");
				}
				break;
			}
			if(flag == 0) {
				printf("NO\n");
				break;			
			}
			if (st.size() != 0 && st.top() == arr[s]) {
				st.pop();
				s++;
				continue;
			}
			if(i != arr[s]) {
				st.push(i);
				if(st.size() > M) flag = 0;
			} else {
				s++;
			}
			i++;
			//printf(" s:%d ",s);
		}	
	}
	return 0;
}