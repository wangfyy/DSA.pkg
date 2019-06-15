Kuchiguse (20)

The Japanese language is notorious for its sentence ending particles. 
Personal preference of such particles can be considered as a reflection of the speaker's personality.   '
Such a preference is called "Kuchiguse" and is often exaggerated artistically in Anime and Manga. 
For example, 
the artificial sentence ending particle "nyan~" is often used as a stereotype for characters with a cat-like personality:
Itai nyan~ (It hurts, nyan~)
Ninjin wa iyada nyan~ (I hate carrots, nyan~)
Now given a few lines spoken by the same character, can you find her Kuchiguse?

Input Specification:
Each input file contains one test case. 
For each case, the first line is an integer N (2<=N<=100). 
Following are N file lines of 0~256 (inclusive) characters in length, 
each representing a character's spoken line. The spoken lines are case sensitive.    '

Output Specification:
For each test case, print in one line the kuchiguse of the character, 
i.e., the longest common suffix of all N lines. If there is no such suffix(后缀), write "nai".


Sample Input 1:
3
Itai nyan~
Ninjin wa iyadanyan~
uhhh nyan~
Sample Output 1:
nyan~


Sample Input 2:
3
Itai!
Ninjinnwaiyada T_T
T_T
Sample Output 2:
nai


#include <cstdio>
#include <cstring>

const int MAXN = 50; 

int N, x = 1, index;

char s[MAXN][MAXN];
char temp[MAXN];

bool check() {
	for(int i=0; i<N-1; i++) {
		if(temp[i] != temp[i+1]) return false;
	}
	return true;
}

int main() {
	scanf("%d ",&N);  ////// "%d 后面有个空格，接收N后面的换行符 
	for(int i=0; i<N; i++) {
		gets(s[i]);  ////
	}
	// 最小长度
	int min = 1000000;
	for(int i=0; i<N; i++) {
		int len = strlen(s[i]);
		if(len < min) min = len;
	}	
	for(int j=0; j<min; j++) {   // 循环min次
		for(int i=0; i<N; i++) {
			int len = strlen(s[i]);
			index = len - x; 
			temp[i] = s[i][index];  // temp[i]为s[i]的“当前最后”一个字符
		}	
		if(!check()) {
			break;
		}
		x++;		
	}
	// 输出
	for(int i=(strlen(s[0])-x+1); i<strlen(s[0]); i++) {
		printf("%c",s[0][i]);
	}
	if(x == 1) printf("nai");

	return 0;
}

为啥编译错误？？？