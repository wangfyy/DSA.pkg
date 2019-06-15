Sign In and Sign Out

At the beginning of every day, the first person who signs in the computer room will unlock(开锁) the door, 
and the last one who signs out will lock the door. Given the records of signing in's and out's, 
you are supposed to find the ones who have unlocked and locked the door on that day.

Input Specification:
Each input file contains one test case. Each case contains the records for one day. 
The case starts with a positive integer(正整数) M, which is the total number of records, followed by M lines, 
each in the format:
ID_number Sign_in_time Sign_out_time
where times are given in the format HH:MM:SS, and ID number is a string with no more than 15 characters.

Output Specification:
For each test case, 
output in one line the ID numbers of the persons who have unlocked and locked the door on that day. 
The two ID numbers must be separated by one space.

Note: It is guaranteed that the records are consistent. 
That is, the sign in time must be earlier than the sign out time for each person, 
and there are no two persons sign in or out at the same moment.
注意：保证记录是一致的。也就是说，签到时间必须早于每个人的签出时间，
在同一时刻，没有两个人签到或外出。

Sample Input:
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40
Sample Output:
SC3021234 CS301133

#include <cstdio>
const int MAXN = 110;
struct student {
	char ID[20];
	int inTime;
	int outTime;
} Stu[MAXN];
int main() {
	int N, min = 999999, max = 0, inStu, outStu;
	scanf("%d",&N);
	for(int i=0; i<N; i++) {
		char ID[20];
		int inTime, outTime;
		scanf("%s",&Stu[i].ID);
		int h, m, s;
		scanf("%d:%d:%d",&h,&m,&s);
		Stu[i].inTime = h * 10000 + m * 100 + s;
		scanf("%d:%d:%d",&h,&m,&s);
		Stu[i].outTime = h * 10000 + m * 100 + s;
		if(Stu[i].inTime < min) {
			inStu = i;
			min = Stu[i].inTime;  // 更新！！  更新！！  更新！！ 
		}
		if(Stu[i].outTime > max) {
			outStu = i;
			max = Stu[i].outTime;
		}
	}
	printf("%s %s\n",Stu[inStu].ID,Stu[outStu].ID);
	return 0;
}

// 代码 --------------------------------------------
#include <cstdio>
struct person{
	char id[20];
	int time_in;
	int time_out;
} persons[50];
int main() {
	int n;
	scanf("%d",&n);
	int t1,t2,t3,t4,t5,t6;
	for(int i=0; i<n; i++) {
		scanf("%s %d:%d:%d %d:%d:%d",persons[i].id,&t1,&t2,&t3,&t4,&t5,&t6);  //注意：gets(persons[i].id); 是一行(遇\n)
		persons[i].time_in = t1*10000 + t2*100 + t3;
		persons[i].time_out = t4*10000 + t5*100 + t6;
	}
	int min_in = 300000, max_out = -1, min_in_number, max_out_number;
	for(int i=0; i<n; i++) {
		if(persons[i].time_in < min_in) {
			min_in = persons[i].time_in;
			min_in_number = i;
		}
		if(persons[i].time_out > max_out) {
			max_out = persons[i].time_out;
			max_out_number = i;
		}
	}
	printf("%s %s",persons[min_in_number].id,persons[max_out_number].id);
	return 0;
}