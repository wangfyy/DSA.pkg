//取任意数的各个位的数
#include <cstdio>
//求任意数的位数
int ws(int x){
	if(x/10==0) return 1;
	else return ws(x/10)+1;  
}
int main(){
	int x;
	scanf("%d",&x);
	int a[ws(x)],n=-1;
	for(int i=1;;i*=10){
		a[++n]=x/i%10;
		if((n+1)==ws(x)) break;
	}
	//输出
	for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
		printf("%d  ",a[i]);
	}
	printf("\n%d",n);

	return 0;
}


// vector  枚举 