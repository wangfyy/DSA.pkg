1061. Dating (20)

Sherlock(夏洛克) Holmes received a note with some strange strings: 
	"Let's date! 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm". 
It took him only a minute to figure out that those strange strings are actually referring to the coded time "Thursday 14:04"
since the first common capital English letter (case sensitive) shared by 
	the first two strings is the 4th capital letter 'D', 
	representing the 4th day in a week; 
	the second common character is the 5th capital letter 'E', 
	representing the 14th hour
	(hence(因此) the hours from 0 to 23 in a day are represented by the numbers from 0 to 9 and the capital letters from A to N, 
	respectively); 
	and the English letter shared by the last two strings is 's' at the 4th position, 
	representing the 4th minute. 
Now given two pairs of strings, you are supposed to help Sherlock decode the dating time.

Input Specification:
Each input file contains one test case. 
Each case gives 
	4 non-empty strings of no more than 60 characters without white space in 4 lines.

Output Specification:
For each test case, print the decoded time in one line, in 
	the format "DAY HH:MM", 
	where "DAY" is a 3-character abbreviation for the days in a week -- that is, 
	"MON" for Monday, 
	"TUE" for Tuesday, 
	"WED" for Wednesday, 
	"THU" for Thursday, 
	"FRI" for Friday, 
	"SAT" for Saturday, 
	"SUN" for Sunday. 
It is guaranteed that the result is unique for each case.


Sample Input:
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm

Sample Output:
THU 14:04


Sample Input:
3485djCkxh4hhG2
2985akCfkkkkgG2dsb
s&hgsfdk
d&igscvnm

Sample Output:
WED 16:03


1.	星期(一-七) --- A-G
2.	时间(0-23) --- 0-9,A-N
3.	s&hgsfdk 
	d&Hyscvnm
	其中两个s(因为没说,所以是大小写)第4个(从0开始计数)代表第4分钟


#include <cstdio>
#include <cstring>

char DAY[10][10] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
char HH[30] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N'};
int flag = 0;

void zhuanhuan(char x) {
	if(flag == 0) {
		printf("%s ",DAY[x-'A']);  ///
	}else {
		for(int i=0; i<24; i++) {
			if(HH[i] == x) printf("%02d:",i);
		}
	}
}

int min(int a, int b) {
	if(a > b)
		return b;
	else
		return a; 
}

int main() {
	char str1[100], str2[100], str3[100], str4[100];
	gets(str1);
	gets(str2);
	gets(str3);
	gets(str4);

	for(int i=0; i<min(strlen(str1),strlen(str2)); i++) {
		if(flag == 0) {  //因为不同的判断条件
			if(str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G') {
				zhuanhuan(str1[i]);	
				flag ++;			
			}
		}else if(flag == 1) {
			if(str1[i] == str2[i] && ((str1[i] >= 'A' && str1[i] <= 'N') || (str1[i] >= '0' && str1[i] <= '9'))) {
				zhuanhuan(str1[i]);		
				flag ++;  //因为需要只判断第一个
			}
		}
	}
	flag = 0;
	for(int i=0; i<min(strlen(str3),strlen(str4)); i++) {
		if(flag == 0 && str3[i] == str4[i] && ((str3[i] >= 'a' && str3[i] <= 'z') || (str3[i] >= 'A' && str3[i] <= 'Z'))) {
			printf("%02d",i);	
			flag ++;	
		}
	}

	return 0;
}