The Black Hole of Numbers (20)

For any 4-digit(数字) integer except the ones with all the digits being the same, 
if we sort the digits in non-increasing order first, 
and then in non-decreasing order, a new number can be obtained by taking the second number from the first one. 
Repeat in this manner we will soon end up at the number 6174 -- the "black hole" of 4-digit numbers. 
This number is named Kaprekar Constant.

For example, start from 6767, we'll get:  '

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...

Given any 4-digit number, you are supposed to illustrate the way it gets into the black hole.

Input Specification:

Each input file contains one test case which gives a positive integer N in the range (0, 10000).

Output Specification:

If all the 4 digits of N are the same, print in one line the equation "N - N = 0000". 
Else print each step of calculation in a line until 6174 comes out as the difference. 
All the numbers must be printed as 4-digit numbers.


6767

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174


2222

2222 - 2222 = 0000


#include <cstdio>
#include <algorithm>
using namespace std;

int x;
int number[4];

bool cmp(int a, int b) {
	return a > b;
}

void numberToArray() {
	int o = 1000;
	for(int i=0; i<4; i++) {
		number[i] = x / o % 10;
		o /= 10;
	}
}

int arrayToNumber() {
	int num = 0;
	int o = 1000;
	for(int i=0; i<4; i++) {
		num += number[i] * o;
		o /= 10;
	}
	return num;
}

int findMax() {
	numberToArray();
	sort(number,number+4,cmp);
	return arrayToNumber();
}

int findMin() {
	numberToArray();
	sort(number,number+4);
	return arrayToNumber();
}

bool isSame() {
	numberToArray();
	for(int i=0; i<4-1; i++) {
		if(number[i] != number[i+1]) {
			return false;
		}
	}
	return true;
}

int main() {
	scanf("%d",&x);
	if(isSame()) {
		printf("%d - %d = 0000",x,x);
		return 0;
	}
	int max, min;
	int y = 4;
	while(y--) {
		max = findMax();
		min = findMin();
		x = max - min;
		printf("%04d - %04d = %04d\n",max,min,x);
		if(x == 6174) break;
	}

	return 0;
}


。。。15'？？？