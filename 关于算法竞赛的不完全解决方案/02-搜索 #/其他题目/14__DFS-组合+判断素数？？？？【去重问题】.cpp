// 例如:
// 当 n=4，k＝3，4 个整数分别为 3，7，12，19 时，可得全部的组合与它们的和为：
//     3＋7＋12=22　　3＋7＋19＝29　　7＋12＋19＝38　　3＋12＋19＝34。
// 现在，要求你计算出和为素数共有多少种。
// 例如上例，只有一种的和为素数：3＋7＋19＝29。

#include <cstdio>
#include <cmath>
int a[100],n,r,s=0,sum;
void print(){
  for(int j=0;j<r;j++){
    printf("%d ",a[j]);
  }
  printf("\n");
}
bool isprime(int x){
  if(x>=2){
    for(int i=2;i<=sqrt(x);i++){
      if(x%i==0) return false;
    }
    return true;
  }else{
    return false;
  }
}
void solve(){
  sum=0;  //每次都要初始化！
  for(int i=0;i<r;i++){
    sum+=a[i];
  }
  if(isprime(sum)){  //素数拼写：prime !
      s++;
      print();
  }
}
void dfs(int index){
  if(index==r){
    solve();
    return;
  }
  for(int i=index;i<n;i++)
  {
    //因为数组a[100]已有元素，所以用以下方式：
    int temp=a[index];  //a[index]与a[i]交换的目的是啥
    a[index]=a[i];
    a[i]=temp;
    
    dfs(index+1);
    
    temp=a[index];  //还原交换
    a[index]=a[i];
    a[i]=temp;
  }
}
// void dfs(int index){  //index——已经选定的数的个数
//   //因为是组合，所以i从上一个选定的数的下一个数开始循环，完成去重
//   for(int i=num[index-1]+1;i<=n;i++){
//     if(!vis[i]){
//       num[index]=a[i];
//       vis[i]=1;  //标记1~n的数中哪个在本轮已经被用了，对应第11行的for循环
//       if(index==r){
//         //print();
//         solve();
//         return;
//       }else{
//         dfs(index+1);
//       }
//       vis[i]=0;
//     }
//   }
// }
int main(){
  scanf("%d %d",&n,&r);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  dfs(0);
  printf("%d\n",s);
  return 0;
}


// 输入：
// 4 3
// 3 7 12 19

// 输出：
// 3 7 19
// 3 19 7
// 7 3 19
// 7 19 3
// 19 7 3
// 19 3 7
// 6
// 有重复 ！！

// 以下是治表不治本的方法：
// void solve(){
//   sum=0;  //每次都要初始化！
//   for(int i=0;i<r;i++){
//     sum+=a[i];
//   }
//   if(isprime(sum)){  //素数拼写：prime !
//     if(sum!=k){
//       s++;
//       print();
//       k=sum;
//     }
//   }
// }

// 以下就尴尬了...所以治根啊 T_T
// 1 2 3 5
// 1 3 4 5
// 1 3 5 2
// 1 4 3 5
// 1 5 3 2
// 1 5 4 3
// 1 5 2 3
// 3 1 4 5
// 3 1 5 2
// 3 4 1 5
// 3 5 1 2
// 3 5 4 1
// 3 5 2 1
// 4 3 1 5
// 5 2 3 1
// 5 3 4 1
// 5 3 1 2
// 5 4 3 1
// 5 1 3 2
// 5 1 4 3
// 5 1 2 3
// 21