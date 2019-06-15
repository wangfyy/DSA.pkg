Read Number in Chinese (25)

Given an integer with no more than 9 digits, you are supposed to read it in the traditional Chinese way. 
Output "Fu" first if it is negative. 
For example, -123456789 is read as "Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu". 
Note: zero ("ling") must be handled correctly according to the Chinese tradition. 
For example, 100800 is "yi Shi Wan ling ba Bai".

Input Specification:
Each input file contains one test case, which gives an integer with no more than 9 digits.

Output Specification:
For each test case, print in a line the Chinese way of reading the number. 
The characters are separated by a space and there must be no extra space at the end of the line.


123456789
yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu

-123456789
Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu


100800
yi Shi Wan ling ba Bai
yi Shi  Wan  Qian ba Bai  Shi   ？？？？？？？？？？？？？？？？



原下标0   倒下标(9-1-0)=9  值为1  输出的单位为Yi
原下标1   倒下标(9-1-1)=8  值为2  输出的单位为Qian
原下标2   倒下标7          值为3  输出的单位为Bai
原下标3   倒下标6          值为4  输出的单位为Shi
原下标4   倒下标5          值为5  输出的单位为Wan
原下标5   倒下标4          值为6  输出的单位为Qian
原下标6   倒下标3          值为7  输出的单位为Bai
原下标7   倒下标2          值为8  输出的单位为Shi
原下标8   倒下标1          值为9  输出的单位为



#include <cstdio>
#include <cstring>

const int MAXN = 50;

char number[MAXN];
int len, len2;

char a[10][10] = {"yi","er","san","si","wu","liu","qi","ba","jiu"};
char b[10][10] = {""," Shi "," Bai "," Qian "," Wan "," Shi "," Bai "," Qian "," Yi "};

void speck(int i) {
	if(number[i] != '0') {
		printf("%s",a[number[i] - '1']);
	}
	if(number[0] == '-') {
		printf("%s",b[len2 - i]);
	} else {
		printf("%s",b[len2 - 1 - i]);
	}
}

int main() {
	gets(number);
	len = strlen(number);
	len2 = len;
	if(number[0] == '-') {
		printf("Fu ");
		len2 --;
	}
	for(int i=0; i<len; i++) {
		speck(i);
	}

	return 0;
}




9' 放弃。。。。。。。