Elevator(电梯)

The highest building in our city has only one elevator. A request list is made up with N positive numbers. 
The numbers denote at which floors the elevator will stop, in specified order. 
数字表示电梯在哪个楼层按指定的顺序停车。
It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. 
电梯上一层要6秒，下一层楼要4秒。
The elevator will stay for 5 seconds at each stop(每站).

For a given request list, you are to compute the total time spent to fulfill the requests on the list. 
The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.

Input Specification:
Each input file contains one test case. Each case contains a positive integer N, followed by N positive numbers. 
All the numbers in the input are less than 100.

Output Specification:
For each test case, print the total time on a single line.

Sample Input:
3 2 3 1
Sample Output:
41

#include <cstdio>
int main() {
	int N, s = 0, c = 0; //0..
	scanf("%d",&N);
	for(int i=0; i<N; i++) {
		int t;
		scanf("%d",&t);
		if(c > t) s += 4 * (c - t);
		if(c < t) s += 6 * (t - c);
		c = t;
		s += 5;
	}
	printf("%d",s);
	return 0;
}