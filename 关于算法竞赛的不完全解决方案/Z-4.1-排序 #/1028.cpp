List Sorting (25)

Excel can sort records according to any column. Now you are supposed to imitate this function.

Input
Each input file contains one test case. For each case, 
the first line contains two integers N (<=100000) and C, 
where N is the number of records and C is the column that you are supposed to sort the records with. 
Then N lines follow, each contains a record of a student. 
A student's record consists of his or her distinct ID (a 6-digit number),      '
name (a string with no more than 8 characters without space), 
and grade (an integer between 0 and 100, inclusive).

Output
For each test case, output the sorting result in N lines. 
That is, if C = 1 then the records must be sorted in  increasing      order according to  ID's;     '
if          C = 2 then the records must be sorted in  non-decreasing  order according to  names; 
and if      C = 3 then the records must be sorted in  non-decreasing  order according to  grades. 
	If there are several students who have the same name or grade, 
	they must be sorted according to their ID's in increasing(增加) order.     '


Sample Input 1
3 1
000007 James 85
000010 Amy 90
000001 Zoe 60
Sample Output 1
000001 Zoe 60
000007 James 85
000010 Amy 90


Sample Input 2
4 2
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 98
Sample Output 2
000010 Amy 90
000002 James 98
000007 James 85
000001 Zoe 60


Sample Input 3
4 3
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 90
Sample Output 3
000001 Zoe 60
000007 James 85
000002 James 90
000010 Amy 90


#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 100010;

int N, C;

struct node{
	int id;
	char name[30];
	int grade;
} Node[MAXN];

bool cmp1(node a, node b) {
	return a.id < b.id;
}

bool cmp2(node a, node b) {
	int s = strcmp(a.name, b.name);  ////// 相等则返回0
	if(s != 0) return s < 0;  ////// 按字典序从小到大     return s < 0; 为字典序从大到小
	else return a.id < b.id;
}

bool cmp3(node a, node b) {
	if(a.grade != b.grade) return a.grade < b.grade;
	else return a.id < b.id;
}

int main() {
	scanf("%d%d",&N,&C);
	for(int i=0; i<N; i++) {
		scanf("%d %s %d",&Node[i].id,&Node[i].name,&Node[i].grade);
	}

	if(C == 1) sort(Node,Node+N,cmp1);
	if(C == 2) sort(Node,Node+N,cmp2);
	if(C == 3) sort(Node,Node+N,cmp3);

	for(int i=0; i<N; i++) {
		printf("%06d %s %d",Node[i].id,Node[i].name,Node[i].grade);
		if(i != N-1) printf("\n");
	}

	return 0;
}
