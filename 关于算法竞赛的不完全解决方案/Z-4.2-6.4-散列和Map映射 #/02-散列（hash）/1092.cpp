To Buy or Not to Buy (20)

Eva would like to make a string of beads with her favorite colors so she went to a small shop to buy some beads. 
There were many colorful strings of beads. However the owner of the shop would only sell the strings in whole pieces. 
Hence Eva must check whether a string in the shop contains all the beads she needs. 
She now comes to you for help: if the answer is "Yes", please tell her the number of extra beads she has to buy; 
or if the answer is "No", please tell her the number of beads missing from the string.
For the sake of simplicity, let's use the characters in the ranges [0-9], [a-z], and [A-Z] to represent the colors.     '
For example, the 3rd string in Figure 1 is the one that Eva would like to make. 
Then the 1st string is okay since it contains all the necessary beads with 8 extra ones; 
yet the 2nd one is not since there is no black bead and one less red bead.

Input Specification:
Each input file contains one test case. 
Each case gives in two lines the strings of no more than 1000 beads which belong to the shop owner and Eva, 
respectively.

Output Specification:
For each test case, print your answer in one line. If the answer is "Yes", 
then also output the number of extra beads Eva has to buy; or if the answer is "No", 
then also output the number of beads missing from the string. 
There must be exactly 1 space between the answer and the number.


Sample Input 1:
ppRYYGrrYBR2258		// 自己的
YrR8RrY				// 参考的

Sample Output 1:
Yes 8


Sample Input 2:
ppRYYGrrYB225
YrR8RrY

Sample Output 1:
No 2



#include <cstdio>
#include <cstring>
using namespace std;

int HashTable[128];
char a[1010], b[1010];
int miss = 0;

int change(char c) {
	if(c >= '0' && c <= '9') return c - '0';
	if(c >= 'a' && c <= 'z') return c - 'a' + 10;
	if(c >= 'A' && c <= 'Z') return c - 'A' + 36;
}

int main() {
	gets(a);
	gets(b);
	int lenA = strlen(a);
	int lenB = strlen(b);
	for(int i=0; i<lenA; i++)
			HashTable[change(a[i])] ++;
	for(int i=0; i<lenB; i++) {
		HashTable[change(b[i])] --;
		if(HashTable[change(b[i])] < 0) miss++;
	}
	if(miss > 0) printf("No %d",miss);	// No--非全有,并输出...
	else printf("Yes %d",lenA - lenB);	// Yes--全有,并输出...

	return 0;
}


这题，，绕难。。难理解。。。

