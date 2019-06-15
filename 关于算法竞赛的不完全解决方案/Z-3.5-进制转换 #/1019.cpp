General Palindromic Number (20)

Input Specification:
...

Output Specification:

For each test case, first print in one line "Yes" if N is a palindromic(回文) number in base b, 
or "No" if not. Then in the next line, print N as the number in base b in the form "ak ak-1 ... a0". 
Notice that there must be no extra space at the end of output.

Sample Input 1:
27 2
Sample Output 1:
Yes
1 1 0 1 1
Sample Input 2:
121 5
Sample Output 2:
No
4 4 1



#include <cstdio>
int N, b, z[50],num = 0;

bool judge() {
  for(int i=0; i<num/2; i++) {
    if(z[i] != z[num-1-i])
      return false;
  }
  return true;
}

int main() {
  scanf("%d%d",&N,&b); 
  do{
    z[num ++] = N % b;
    N = N/b;
  }while(N != 0);
  if(judge() == true) printf("Yes\n");
  else printf("No\n");
  for(int i=num-1; i>=0; i--) {
    printf("%d",z[i]);  
    if(i != 0) printf(" ");
  }
  
  return 0;
}




第二遍---------------------------------------------
#include <cstdio>
const int NAXN = 1010;
int N, R, number[NAXN], len = 0;
bool check() {
  for(int i=0; i<len/2; i++) {
    if(number[i] != number[len - 1 - i]) return false;
  }
  return true;
}
int main() {
  scanf("%d%d",&N,&R);
  do{
    number[len++] = N % R;  // 除基求余法
    N /= R;
  } while(N != 0);
  if(check()) printf("Yes\n");
  else printf("No\n");
  for(int i=len - 1; i>=0; i--) {
    printf("%d",number[i]);
    if(i != 0) printf(" ");
  }
  return 0;
}








NO.1------------------------------------------------------------------------------------------
// 10进制N转换为D进制存在数组中。   【来源于：上述代码 以及《3.5 进制转换-第二片代码》】
      int len = 0;  // 顺便取得位数len
      do{  // 因为0的某进制也是零呀~
        number[len++] = N % D;
        N /= D;
      } while(N != 0);  // 结束时 N为0
// 区分于：字符串的方式取位数（如果光取位数还行，要是需要再转换成数的话，这种方法就麻烦了）
NO.2------------------------------------------------------------------------------------------
// p进制x直接转为十进制y，“除基求余法”，实质就是：以p为基数的多项式求和
// PS:不生成数组，不能用秦九韶法，因为秦九韶法先算高位数字，而这是从低位开始
      // while循环版   【来源于：《3.5 进制转换-第一片代码》】
      int y = 0, product = 1;
      while(x != 0) {
        y += (x % 10) * product;  // 从个位开始
        x /= 10;  // 个位 转到 十位...
        product *= p;
      }
      // for循环不如上面的while循环，for循环需要事先知道位数，while循环的条件是‘x!=0’，中间不需要事先知道位数，甚至可以顺便求位数
NO.3------------------------------------------------------------------------------------------
// p进制x转十进制y，将x的每位存到数组(这步麻烦)，再用秦九韶公式就和
// 以下代码是：将数组number[](上步：10进制N转换为D进制存在数组中 时生成的)中的数的每位用秦九韶法转换为一个D进制的数字N  【来源于：上述代码】
      int N = 0;
      for(int i=0; i<len; i++) {
        N = N * D + number[i]; ////
      }
// ‘ZJU-DS-MOOC’中也提及秦九韶法就多项式和
// ‘算法笔记-BOOK1-4.2.2字符串hash初步(p109)’中也提及秦九韶法就多项式和(Note: 括号里的为p，p的初值为0)
------------------------------------------------------------------------------------------