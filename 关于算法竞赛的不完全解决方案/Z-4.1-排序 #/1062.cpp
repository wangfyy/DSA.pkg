Talent and Virtue (25)

About 900 years ago, 
a Chinese philosopher Sima Guang wrote a history book in which he talked about people's talent and virtue. According to his theory,    
a man being outstanding in both talent and virtue must be a "sage（圣人）";     
being less excellent but with one's virtue outweighs talent can be called a "nobleman（君子）"; 
being good in neither is a "fool man（愚人）"; 
yet a fool man is better than a "small man（小人）" who prefers talent than virtue.
Now given the grades of talent and virtue of a group of people, 
you are supposed to rank them according to Sima Guang's theory.     '

Input Specification:
Each input file contains one test case. Each case first gives 3 positive integers in a line: N (<=105), 
the total number of people to be ranked; 
	L (>=60), the lower bound of the qualified grades -- that is, 
	only the ones whose grades of talent and virtue are both not below this line will be ranked; 
	and H (<100), 
	the higher line of qualification -- that is, those with both grades not below this line are considered as the "sages", 
	and will be ranked in non-increasing order according to their total grades. 
	Those with talent grades below H but virtue grades not are cosidered as the "noblemen", 
	and are also ranked in non-increasing order according to their total grades, but they are listed after the "sages". 
	Those with both grades below H, but with virtue not lower than talent are considered as the "fool men". 
	They are ranked in the same way but after the "noblemen". 
	The rest of people whose grades both pass the L line are ranked after the "fool men"
Then N lines follow, each gives the information of a person in the format:
	ID_Number Virtue_Grade Talent_Gradewhere ID_Number is an 8-digit number, 
and both grades are integers in [0, 100]. All the numbers are separated by a space.

Output Specification:
The first line of output must give M (<=N), the total number of people that are actually ranked. Then M lines follow, 
each gives the information of a person in the same format as the input, according to the ranking rules. 
	If there is a tie of the total grade, they must be ranked with respect to their virtue grades in non-increasing order. 
	If there is still a tie, then output in increasing order of their ID's.      '


Sample Input:
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60

Sample Output:
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90


第一类：talent 、virtue 都 >= H
第二类：talent < H       virtue  >= H
第三类：talent 、virtue 都 < H     talent <= virtue
第四类：talent 、virtue 都 < H


#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

int N, L, H, num = 0;

struct node{
	int id;
	int g1;
	int g2;
	int total_g;
	int tag = 4;
}Node[MAXN];

bool cmp(node a, node b) {
	if(a.tag != b.tag) return a.tag < b.tag;						// (类别不等时) 类别小的在前
	else if(a.total_g != b.total_g) return a.total_g > b.total_g;	// 类别相等时， 总分大的在前
	else if(a.g2 != b.g2 ) return a.g2 > b.g2 ;						// 总分相等时， 德分大的在前
	else if(a.id != b.id) return a.id < b.id;						// 德分相等时， id小的在前
}

int main() {
	scanf("%d%d%d",&N,&L,&H);
	for(int i=0; i<N; i++) {
		int T_id, T_g1, T_g2;
		scanf("%d%d%d",&T_id,&T_g2,&T_g1);
		if(T_g1 < L || T_g2 < L) {
			Node[i].tag = 10;
			continue;
		}
		num++;
		if(T_g1 >= H && T_g2 >= H) Node[i].tag = 1;
		if(T_g1 < H && T_g2 >= H) Node[i].tag = 2;
		if(T_g1 < H && T_g2 < H && T_g1 <= T_g2) Node[i].tag = 3;
		// 剩余为默认类(4类)
		Node[i].id = T_id;
		Node[i].g1 = T_g1;
		Node[i].g2 = T_g2;
		Node[i].total_g = T_g1 + T_g2;
	}
	 // for(int i=0; i<N; i++) {
	 // 	printf("%d %d %d %d %d\n",Node[i].id,Node[i].g1,Node[i].g2,Node[i].total_g,Node[i].tag);
	 // }
	printf("%d\n",num);
	sort(Node,Node+N,cmp);
	for(int i=0; i<num; i++) {
		printf("%d %d %d",Node[i].id,Node[i].g2,Node[i].g1);
		if(i != num - 1) printf("\n");  //
	}

	return 0;
}


------------------------------------------------------------------------------------------------------
排序题，肯定有段英文是描述关于“cmp()”函数的主键相等时再按其他键排序的要求等！
------------------------------------------------------------------------------------------------------
【注意！】

	因为是英文题目，读题不便，
	刷题时
		不要死究英文，过长时间的看有些迷糊的英文题意，
		要结合参考书中文的题意，高效刷题，不浪费时间。

	重要的是：总结特定题型的要求！
		例如：排序题，肯定有段英文是描述关于“cmp()”函数的主键相等时再按其他键排序的要求等！


	关键的总结！提高手提效率！
------------------------------------------------------------------------------------------------------