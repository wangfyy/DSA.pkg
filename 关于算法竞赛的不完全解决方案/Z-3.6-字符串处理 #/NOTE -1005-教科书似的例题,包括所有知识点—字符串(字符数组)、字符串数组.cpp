Spell It Right.

Given a non-negative(非负) integer N, your task(任务) is to compute(计算) the sum of all the digits of N, 
and output every digit of the sum in English.

Input Specification:
Each input file contains one test case. Each case occupies one line which contains an N (<= 10100).

Output Specification:
For each test case, output in one line the digits of the sum in English words. 
There must be one space between two consecutive words, but no extra space at the end of a line.

Sample Input:
12345
Sample Output:
one five.

#include <cstdio>
#include <cstring>
const int MAXN = 110;
int main() {
    char map[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}; 
    char number[MAXN];
    scanf("%s",number);
    //gets(number);
    int sum = 0;
    for(int i=0; i<strlen(number); i++) {
        sum += number[i] - '0';
    }
    char numberSum[MAXN];
    sprintf(numberSum,"%d",sum);
    for(int i=0; i<strlen(numberSum); i++) {
        printf("%s",map[numberSum[i] - '0']);
        if(i != strlen(numberSum) - 1) printf(" ");
    }
    return 0;
}


【“字符串”单元-重点例题】

Thinking:
读入字符串(字符数组)， //gets(a);
(字符数组的每个字符char减'0'转为int)求每位和， //sum += (a[i] - '0');
多位int数字整体转为字符串(char数组)， //////////char s[20]; sprintf(s,"%d",sum);  ////注意：,"%d",,"%d",,"%d",
该字符串(char数组)的每个字符char减'0'转为int下标，输出  //for(int i=1; i<strlen(s); i++) printf("%s",arr[s[i]-'0']);

--------- 代码 1*** ---------
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
	
    char a[20];  // 一个字符数组.  p47-“字符数组” 
    gets(a);  // 读入一行.  p49- “字符数组”
    
    int sum = 0;
    for (int i = 0; i < strlen(a); i++) ////// strlen(a) 得到字符数组第一个\0前字符的个数.  p50-“string.h”头文件 
        sum += (a[i] - '0');            ////// ASCII码 
        
    char s[20];
    sprintf(s,"%d",sum); //,"%d",  ,"%d",  ,"%d",   ////// int型转为char[]型，printf("%d",sum)即printf(screen,"%d",sum).  p53-“sscanf与sprintf” 
                                        ////// 再例：int型转为char[]型: int ix = 111; char cx[20]; sprintf(cx,"%d",ix);
    
    char arr[10][10] = {"zero", "one", "two", "three", "four", 
		"five", "six", "seven", "eight", "nine"};  // 一个字符串数组  p48-“字符数组”
		
    printf("%s",arr[s[0] - '0']);  // %s 格式用于输出字符串(即char数组)，"arr[0]"表示"zero".  p19-“使用scanf和printf输入输出” 
    for (int i = 1; i < strlen(s); i++)
        printf(" %s",arr[s[i] - '0']);
        
    return 0;
}

--------- 代码 2 ---------
#include <iostream>
#include <sstream>
using namespace std;
string to_string(int x) {  //int型 转 string型 
    stringstream ss;  // 字符流变量 
	ss<<x;  // 位运算 
    string s=ss.str();
    return s;
}
int main() {
    string a;  //// 字符串 p202-“STL-string” ,即： char a[]; 
    cin >> a;  // string类型的输入输出只能用 cin cout 
    int sum = 0;
    for (int i = 0; i < a.length(); i++)  // a.length()  p205-“STL-string” 
        sum += (a[i] - '0');
    string s = to_string(sum);  //调用转换的模板函数 
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};  
		//// 字符串数组 p202-“STL-string” ,即： char a[][]; 
    cout << arr[s[0] - '0'];
    for (int i = 1; i < s.length(); i++)
        cout << " " << arr[s[i] - '0'];
    return 0;
}

--------- 代码 3 ---------
// lowbee代码...不知low到哪里去了... 
//#include <cstdio>
//int weishu_x;
//char danci[10][10] = {"zero","one","two","three","four","five","sex","seven","eight","nine"};
//int weishu(int x) {
//	if(x < 10) return 1;
//	else return weishu(x / 10) + 1;
//}
//int qiuhe(int x) {
//	int o=1, sum = 0, onewei;
//	for(int i=0; i<weishu_x; i++) {
//		onewei = x / o % 10;
//		o *= 10;
//		sum += onewei;
//	}
//	return sum;
//}
//void spell(int x) {
//	int d[20], weishu_2 = weishu(x), o = 1;  //d[]存放x的每位，以便正序输出
//	for(int i=weishu_2-1; i>=0; i--) {
//		d[i] = x / o % 10;
//		o *= 10;
//	}
//	for(int i=0; i<weishu_2; i++) {
//		if(i == weishu_2 - 1) {  //当此项是最后一项时，其后无空格
//			printf("%s",danci[d[i]]);
//		}else {
//			printf("%s ",danci[d[i]]);
//		}
//	}
//}
//int main() {
//	int x;
//	scanf("%d",&x);
//	weishu_x = weishu(x);
//	spell(qiuhe(x));
//	return 0;
//}