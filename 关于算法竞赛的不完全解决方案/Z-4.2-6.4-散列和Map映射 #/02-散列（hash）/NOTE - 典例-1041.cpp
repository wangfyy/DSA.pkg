Be Unique (20)

Being unique is so important to people on Mars that even their lottery is designed in a unique way. 
The rule of winning is simple: one bets on a number chosen from [1, 104]. 
	The first one who bets on a unique number wins. 
	第一个投注唯一数字的人获胜
For example, 
if there are 7 people betting on 5 31 5 88 67 88 17, then the second one who bets on 31 wins.

Input Specification:
Each input file contains one test case. 
Each case contains a line which begins with a positive integer N (<=105) and then followed by N bets. 
The numbers are separated by a space.

Output Specification:
For each test case, print the winning number in a line. If there is no winner, print "None" instead.


Sample Input 1:
7 5 31 5 88 67 88 17
Sample Output 1:
31    (第一个投注唯一数字的人获胜)


Sample Input 2:
5 888 666 666 888 888
Sample Output 2:
None


#include <cstdio>

int HashTable[150];
int num[150];
int N;

int main() {
	scanf("%d",&N);
	int x;
	for(int i=0; i<N; i++) {
		scanf("%d",&x);
		num[i] = x;
		HashTable[x] ++;
	}
	for(int i=0; i<N; i++) {
		if(HashTable[num[i]] == 1) {
			printf("%d",num[i]);
			return 0;
		}
	}
	printf("None");

	return 0;
}


这些题全是字符hash,字符串hash在B2p109。。