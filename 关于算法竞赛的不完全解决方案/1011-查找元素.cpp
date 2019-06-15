World Cup Betting(投注).

With the 2010 FIFA World Cup running, 
football fans the world over were becoming increasingly excited as the best players      ,
from the best teams doing battles for the World Cup trophy in South Africa. 
Similarly, football betting fans were putting their money where their mouths were, 
by laying all manner of World Cup bets.
Chinese Football Lottery provided a "Triple Winning" game. 
The rule of winning was simple: first select any three of the games. 
Then for each selected game, bet on one of the three possible results -- namely W for win, 
T for tie, and L for lose. There was an odd assigned to each result. 
The winner's odd would be the product of the three odds times 65%.

For example, 3 games' odds(3场比赛的赔率) are given as the following:
 W    T    L
1.1  2.5  1.7
1.2  3.0  1.6
4.1  1.2  1.1
To obtain the maximum profit, one must buy W for the 3rd game, T for the 2nd game, and T for the 1st game. 
If each bet takes 2 yuans, 
then the maximum profit would be (4.1*3.0*2.5*65%-1)*2 = 37.98 yuans (accurate up to 2 decimal places).

Input
Each input file contains one test case. Each case contains the betting information of 3 games. 
Each game occupies a line with three distinct odds corresponding to W, T and L.

Output
For each test case, print in one line the best bet of each game, 
and the maximum profit accurate up to 2 decimal places. The characters and the number must be separated by one space.

Sample Input
1.1 2.5 1.7
1.2 3.0 1.6
4.1 1.2 1.1
Sample Output
T T W 37.98


其实题意是让你输出每行的最大值的j标尺。而不是倒着输出，怎么会这么不合理呢？？动动脑子！！

代码1----------
#include <cstdio>
const int MAXN = 3;
int main() {
	double s = 1.0;
	int max_j;
	char c[MAXN + 1] = {"WTL"};  //////
	for(int i=0; i<MAXN; i++) {
		double max = -1.0;////若此句在for()外面，逻辑就错了，但题目的样例可以通过，因为其三个最大值依次递增，所以...mmp...
		for(int j=0; j<MAXN; j++) {
			double temp;  //此题根本不需要数组，5min的题......
			scanf("%lf",&temp);
			if(max <= temp) {
				max = temp;
				max_j = j;
			}
		}
		printf("%c ",c[max_j]);  //系统竟然接受这样的输出顺序，get了...
		s *= max;
	}
	//printf("%0.2f",(s * 0.65 - 1.0) * 2.0 + 0.005);  //说好的37.98...
	printf("%0.2f",(s * 0.65 - 1.0) * 2.0);
	return 0;
}


代码2----------刚睡醒代码：
#include <cstdio>
const int MAXN = 3;
double n[MAXN][MAXN]; 
double max;
int max_i,max_j;
void pri() {
	n[max_i][max_j] = -1.0;
	if(max_j == 0)
		printf("W ");
	if(max_j == 1)
		printf("T ");
	if(max_j == 2)
		printf("L ");
}
void findmax() {
	max = -1.0;
	for(int i=0; i<MAXN; i++) {
		for(int j=0; j<MAXN; j++) {
			if(max < n[i][j]) {
				max = n[i][j];
				max_i = i;
				max_j = j;
			}
		}
	}
}
int main() {
	double s = 1.0;
	for(int i=0; i<MAXN; i++) {
		for(int j=0; j<MAXN; j++) {
			scanf("%lf",&n[i][j]);
		}
	}
	for(int i=0; i<MAXN; i++){
		findmax();
		pri();
		s *= max;
	}
	printf("%0.2f",(s * 65.0 / 100.0 - 1.0) * 2.0 + 0.005);
	return 0;
}