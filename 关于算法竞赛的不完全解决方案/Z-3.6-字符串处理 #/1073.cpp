Scientific Notation (20)

Scientific notation is the way that scientists easily handle very large numbers or very small numbers. 
The notation matches the regular expression [+-][1-9]"."[0-9]+E[+-][0-9]+ which means 
that the integer portion has exactly one digit, there is at least one digit in the fractional portion, 
and the number and its exponent's signs are always provided even when they are positive.  '
Now given a real number A in scientific notation, 
you are supposed to print A in the conventional notation while keeping all the significant figures.

Input Specification:
Each input file contains one test case. For each case, 
there is one line containing the real number A in scientific notation. 
The number is no more than 9999 bytes in length and the exponent's absolute value is no more than 9999.  '

Output Specification:
For each test case, print in one line the input number A in the conventional notation, 
with all the significant figures kept, including trailing zeros,


+1.23400E-03
0.00123400

+1234.56E-02
12.3456

+1.23400E0
0.00123400

-1.2E+10
-12000000000

+3.1415E+004
31415

+31.415E+3
31415

-3.1415926E+4
-31415.926

-3.1415926E+3
-3141.5926

-3.1415926E-1
-0.31415926


#include <cstdio>
#include <cstring>

char str[10010];
int len, pos_E, pos_point;

// 输出原数
void numberOrigin(int x) {
	if(x == -1) {
		for(int i=1; i<pos_E; i++) {
			if(i != pos_point) printf("%c",str[i]);
		}
	} else {
		for(int i=1; i<pos_E; i++) {
			if(i != pos_point) printf("%c",str[i]);
			if(i == x) printf(".");  //
		}
	}
}

int main() {
	gets(str);
	len = strlen(str);
	if(str[0] == '-') printf("-");
	// 求E的位置
	pos_E = 0;
	for(int i=0; i<len; i++) {
		if(str[i] != 'E') {
			pos_E ++;
		} else {
			break;
		}
	}
	int flag = 0;  // 初始指数为正
	if(str[pos_E + 1] == '-') flag = 1;  // 纠正指数为负
	// 求指数值
	int exp = 0;
	for(int i=pos_E + 2; i<len; i++) {
		exp = exp * 10 + (str[i] - '0');
	}
	if(exp == 0) {  // 特判指数为0时的输出
        for(int i=1; i<pos_E; i++)
            printf("%c",str[i]);
		return 0;
	}
	// 求小数点的位置
	pos_point = 0;
	for(int i=0; i<pos_E; i++) {
		if(str[i] != '.') {
			pos_point ++;
		} else {
			break;
		}
	}
	// 指数小于0
	if(flag == 1) {
		if(pos_point - 1 > exp) {  // 不需要添加0
			int x = pos_point - 1 - exp;  // 在x处输出一个小数点
			numberOrigin(x);  // 输出在x处有个小数点的去原小数点的数
		} else  {  // 需要添加0
			for(int i=0; i<exp + 2 - pos_point; i++) {
				printf("0");
				if(i == 0) {
					printf(".");
				}
			}
			numberOrigin(-1);
		}
	} else {  // 指数大于0
		if(pos_E - pos_point <= exp) {  // 需要添加0
			numberOrigin(-1);
			for(int i=1; i<exp - (pos_E - pos_point - 1); i++)  //
				printf("0");
		} else {  // 不需要添加0
			int x = pos_point + exp;  // 在x处输出一个小数点
            if(pos_E - pos_point - 1 == exp) x = -1;  //
			numberOrigin(x);  // 输出在x处有个小数点的去原小数点的数
		}
	}

	return 0;
}


13'  两个点没过--