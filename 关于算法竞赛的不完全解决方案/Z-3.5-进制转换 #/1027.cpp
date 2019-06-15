1027. Colors in Mars (20)

People in Mars represent the colors in their computers in a similar way as the Earth people. 
That is, a color is represented by a 6-digit number, where the first 2 digits are for Red, 
the middle 2 digits for Green, and the last 2 digits for Blue. 
The only difference is that 
	they use radix 13 (0-9 and A-C) instead of 16. 
Now given a color in three decimal numbers (each between 0 and 168), you are supposed to output their Mars RGB values.

Input
Each input file contains one test case which occupies a line containing 
	the three decimal(十进制) color values.

Output
For each test case you should output the Mars RGB value in the following format: 
	first output "#", 
then followed by a 6-digit number where all the English characters must be upper-cased(大写). 
	If a single color is only 1-digit long, you must print a "0" to the left(在左边).

Sample Input
15 43 71
Sample Output
#123456   
即：
(12 34 56)
15 转为13进制为 12    (除基求余法)
43 转为13进制为 34
71 转为13进制为 56


#include <cstdio>

char c[50][50] = {"0","1","2","3","4","5","6","7","8","9","A","B","C"};

int radix10_To_radix13(int x) {
	int z[10], num = 0;
	do{
		z[num++] = x % 13;
		x = x / 13;
	}while(x != 0);
	if(num == 1) printf("0");
	for(int i=num-1; i>=0; i--) {
		printf("%s",c[z[i]]);
	}
}

int main() {
	int c1_1, c1_2, c1_3, c2_1, c2_2, c3_3;
	scanf("%d%d%d",&c1_1,&c1_2,&c1_3);
	printf("#");
	radix10_To_radix13(c1_1);
	radix10_To_radix13(c1_2);
	radix10_To_radix13(c1_3);

	return 0;
}