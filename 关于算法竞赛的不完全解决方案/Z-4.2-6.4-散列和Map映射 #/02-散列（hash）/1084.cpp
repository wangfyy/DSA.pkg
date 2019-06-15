Broken Keyboard (20)

On a broken keyboard, some of the keys are worn out. 
So when you type some sentences, the characters corresponding to those keys will not appear on screen.
Now given a string that you are supposed to type, 
and the string that you actually type out, please list those keys which are for sure worn out.

Input Specification:
Each input file contains one test case. 
For each case, the 1st line contains the original string, 
and the 2nd line contains the typed-out string. 
Each string contains no more than 80 characters which are either English letters [A-Z] (case insensitive), 
digital numbers [0-9], or "_" (representing the space). It is guaranteed that both strings are non-empty.

Output Specification:
For each test case, print in one line the keys that are worn out, 
in the order of being detected. 
	The English letters must be capitalized(大写). 
	Each worn out key must be printed once only. 
It is guaranteed that there is at least one worn out key.


Sample Input:
7_This_is_a_test
_hs_s_a_es

Sample Output:
7TI


#include <cstdio>
#include <cstring>
using namespace std;

char a[1010], b[1010];
bool HashTable[30];  // 如果太小就是_的原因。则增大至128

int main() {
	gets(a);
	gets(b);
	int len = strlen(a);
	char tA, tB;
	int j = 0;
	for(int i=0; i<len; i++) {
		tA = a[i];
		tB = b[j];
		if(tA >= 'a' && tA <= 'z') tA -= 32;  // 小写转大写  //// 32   32   32   32   32   32   32  
		if(tB >= 'a' && tB <= 'z') tB -= 32;
		if(tA != tB) {
			if(HashTable[tA - 'A'] == false) {
				printf("%c",tA);
				HashTable[tA - 'A'] = true;
			}
		} else {
			j++;
		}
	}

	return 0;
}