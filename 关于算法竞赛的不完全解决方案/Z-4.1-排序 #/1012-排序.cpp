The Best Rank.

To evaluate the performance of our first year CS majored students, 
we consider their grades of three courses only: C - C Programming Language, 
M - Mathematics (Calculus or Linear Algebra), and E - English. At the mean time, 
we encourage students by emphasizing on their best ranks -- that is, 
among the four ranks with respect to the three courses and the average grade, 
we print the best rank for each student.

For example, The grades of C, M, E and A - Average of 4 students are given as the following:
StudentID  C  M  E  A
310101     98 85 88 90
310102     70 95 88 84
310103     82 87 94 88
310104     91 91 91 91
Then the best ranks for all the students are No.1 since the 1st one has done the best in C Programming Language, 
while the 2nd one in Mathematics, the 3rd one in English, and the last one in average.

Input
Each input file contains one test case. Each case starts with a line containing 2 numbers N and M (<=2000), 
which are the total number of students, and the number of students who would check their ranks, respectively. 
Then N lines follow, each contains a student ID which is a string of 6 digits, 
followed by the three integer grades (in the range of [0, 100]) of that student in the order of C, 
M and E. Then there are M lines, each containing a student ID.

Output
For each of the M students, print in one line the best rank for him/her, 
and the symbol of the corresponding rank, separated by a space.

The priorities of the ranking methods are ordered as A > C > M > E. 
Hence if there are two or more ways for a student to obtain the same best rank, output the one with the highest priority.
If a student is not on the grading list, simply output "N/A".


Sample Input
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310105
Sample Output
3 A


#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 10010;

int N, MM;

struct node {
	int id, C, M, E, A, rank;
} Node[MAXN];

bool cmp(node a, node b) {
	return a.A > b.A;
}

void solve() {
	Node[0].rank = 1;
	for(int i=1; i<N; i++) {
		if(Node[i-1].A == Node[i].A) {
			Node[i].rank = Node[i-1].rank;
		} else {
			Node[i].rank = i + 1;
		}
	}	
}

void bestRankFromAllCourse(int idCheck) {
	// 判断存在, 定位下标
	int flag = 0;
	int j;
	for(j=0; j<N; j++) { 
		if(idCheck == Node[j].id) {
			flag = 1;
			break;
		}
	}
	if(flag == 0) {
		printf("N/A");
		return;
	}

	int max;
	// 如果此id的A为所有id的A的最大值,则输出“1 A”
	max = -1;
	for(int i=0; i<N; i++) {  // 找最大值
		if(Node[i].A > max) max = Node[i].A;
	}
	if(Node[j].A == max) {
		printf("1 A");
		return;
	}
	// 如果此id的C为所有id的C的最大值,则输出“1 C”
	max = -1;
	for(int i=0; i<N; i++) {  // 找最大值
		if(Node[i].C > max) max = Node[i].C;
	}
	if(Node[j].C == max) {
		printf("1 C");
		return;
	}
	// 如果此id的M为所有id的M的最大值,则输出“1 M”
	max = -1;
	for(int i=0; i<N; i++) {  // 找最大值
		if(Node[i].M > max) max = Node[i].M;
	}
	if(Node[j].M == max) {
		printf("1 M");
		return;
	}
	// 如果此id的E为所有id的E的最大值,则输出“1 E”
	max = -1;
	for(int i=0; i<N; i++) {  // 找最大值
		if(Node[i].E > max) max = Node[i].E;
	}
	if(Node[j].E == max) {
		printf("1 E");
		return;
	}
	// 最后，以A排序,输出rank
	sort(Node, Node + N, cmp);
	solve();  ////// 并列名次的处理
	// for(int i=0; i<N; i++) {
	// 	if(Node[i].id == idCheck) printf("%d A",i);
	// }
	int k;
	for(k=0; k<N; k++) { 
		if(idCheck == Node[k].id) {
			break;
		}
	}
	printf("%d A",Node[k].rank);
}

int main() {
	scanf("%d%d",&N,&MM);
	for(int i=0; i<N; i++) {
		double dC, dM, dE, dA;
		scanf("%d%lf%lf%lf",&Node[i].id,&dC,&dM,&dE);
			////// 整型是直接无法运算小数，，而不仅是最后赋值的问题
			// 例如：double x = (4 + 3 + 3) / 4;  // x=2.00，，小数点后为00。。
		dA = (dC + dM + dE) / 3 + 0.5;  //// 其实可以直接存储总分，简洁且正确率高
		Node[i].C = (int)dC;
		Node[i].M = (int)dM;
		Node[i].E = (int)dE;
		Node[i].A = (int)dA;
	}
	for(int i=0; i<MM; i++) {
		int idCheck;
		scanf("%d",&idCheck);
		bestRankFromAllCourse(idCheck);
		if(i != MM - 1) printf("\n");
	}
//	for(int i=0; i<N; i++) {
//		printf("\n%d %d %d %d %d %d\n",Node[i].id,Node[i].C,Node[i].M,Node[i].E,Node[i].A,Node[i].rank);
//	}

	return 0;
}



21'   两个测试点没过。。