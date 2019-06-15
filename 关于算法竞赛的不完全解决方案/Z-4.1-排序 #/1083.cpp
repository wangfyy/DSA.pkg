List Grades (25)


Given a list of N student records with name, ID and grade. 
You are supposed to sort the records with respect to the grade in non-increasing order, 
and output those student records of which the grades are in a given interval.

Input Specification:
Each input file contains one test case. Each case is given in the following format:
N
name[1] ID[1] grade[1]
name[2] ID[2] grade[2]
... ...
name[N] ID[N] grade[N]
grade1 grade2
where name[i] and ID[i] are strings of no more than 10 characters with no space, grade[i] is an integer in [0, 100], 
grade1 and grade2 are the boundaries of the grade's interval(间隔/间距). It is guaranteed that all the grades are distinct.    '

Output Specification:
For each test case you should output the student records of which the grades are in the given interval [grade1, grade2] 
and are in non-increasing order. 
Each student record occupies a line with the student's name and ID,     '
separated by one space. If there is no student's grade in that interval, output "NONE" instead.    '


Sample Input 1:
4
Tom CS000001 59
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
60 100

Sample Output 1:
Mike CS991301
Mary EE990830
Joe Math990112


Sample Input 2:
2
Jean AA980920 60
Ann CS01 80
90 95

Sample Output 2:
NONE



#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

int N, grade1, grade2;

struct node{
	char name[30];
	char id[30];
	int grade;
} Node[MAXN];

bool cmp(node a, node b) {
	return a.grade > b.grade;
}

int  main() {
	scanf("%d",&N);
	for(int i=0; i<N; i++) {
		scanf("%s %s %d",&Node[i].name,&Node[i].id,&Node[i].grade);  ////
	}
	scanf("%d%d",&grade1,&grade2);  // 因为是在后面输入的，所以无法赋值时筛选
	// printf("%d\n",N);
	// for(int i=0; i<N; i++) {
	// 	printf("%s %s %d\n",Node[i].name,Node[i].id,Node[i].grade);
	// }
	// printf("%d %d",grade1,grade2);
	sort(Node,Node+N,cmp);
	bool flag;
	for(int i=0; i<N; i++) {
		if(Node[i].grade >= grade1 && Node[i].grade <= grade2) {
			printf("%s %s\n",Node[i].name,Node[i].id);
			flag = true;
		}
	}
	if(flag == false) printf("NONE\n");

	return 0;
}