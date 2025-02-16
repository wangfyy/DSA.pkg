String Subtraction (20)

Given two strings S1 and S2, 
S = S1 - S2 is defined to be the remaining string after taking all the characters in S2 from S1. 
Your task is simply to calculate S1 - S2 for any given strings. 
However, it might not be that simple to do it fast.

Input Specification:
Each input file contains one test case. 
Each case consists of two lines which gives S1 and S2, respectively. 
The string lengths of both strings are no more than 104. 
It is guaranteed that all the characters are visible ASCII codes and white space, 
and a new line character signals the end of a string.

Output Specification:
For each test case, print S1 - S2 in one line.

Sample Input:
They are students.
aeiou
Sample Output:
Thy r stdnts.

#include <cstdio>
#include <cstring>
using namespace std;
int main() {
	bool HashTable[10010];
	char a[100], b[100];
	gets(a);
	gets(b);
	for(int i=0; i<strlen(b); i++)
		HashTable[b[i]] = true;  //下标为ASCII码
	for(int i=0; i<strlen(a); i++)
		if(HashTable[a[i]] == false)
			printf("%c",a[i]);
	return 0;
}