Sharing (25)

To store English words, one method is to use linked lists and store a word letter by letter. 
To save some space, we may let the words share the same sublist if they share the same suffix. 
For example, "loading" and "being" are stored as showed in Figure 1.

You are supposed to find the starting position of the common suffix (e.g. the position of "i" in Figure 1).

Input Specification:
Each input file contains one test case. For each case, 
the first line contains two addresses of nodes and a positive N (<= 105), 
where the two addresses are the addresses of the first nodes of the two words, 
and N is the total number of nodes. 
The address of a node is a 5-digit positive integer, and NULL is represented by -1.
Then N lines follow, each describes a node in the format:
Address Data Next
where Address is the position of the node, 
Data is the letter contained by this node which is an English letter chosen from {a-z, A-Z}, 
and Next is the position of the next node.

Output Specification:
For each case, simply output the 5-digit starting position of the common suffix(后缀). 
If the two words have no common suffix, output "-1" instead.


-------------------------------------
Sample Input 1:
11111 22222 9
67890 i 00002
00010 a 12345
00003 g -1
12345 D 67890
00002 n 00003
22222 B 23456
11111 L 00001
23456 e 67890
00001 o 00010
Sample Output 1:
67890
-------------------------------------
11111 22222 9

11111 L 00001
00001 o 00010
00010 a 12345
12345 D 67890
67890 i 00002
00002 n 00003
00003 g -1

22222 B 23456
23456 e 67890

67890
-------------------------------------
Sample Input 2:
00001 00002 4
00001 a 10001
10001 s -1
00002 a 10002
10002 t -1
Sample Output 2:
-1
-------------------------------------
11111 22222 2
11111 L 00001
22222 o 00010

-1
-------------------------------------
11111 22222 2
11111 L -1
22222 o 00010

-1
-------------------------------------
11111 22222 0

-1
-------------------------------------
11111 22222 9
11111 L 00001
00001 o 00010
00010 a 12345
12345 D 67890
67890 i 00002
00002 n 00003
00003 g 22222
22222 B 23456
23456 e 11111

-1
-------------------------------------


将第一个单词的字母串起来，用vis[]标记；
再将第二个单词的字母(加入的条件是vis[i] == false)串起来，返回最后一个单词的next地址(-1 或 五位地址)



#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 100010;

int st1, st2, N;
int vis[MAXN];
int vis_value;
int num = 0, num2 = 0;
int endNext;
int flag = 0;

struct node {
	int adress, next;
	char data;
} Node[MAXN];

void solve(int st) {  // 递推写法
	while(1) {
		for(int i=0; i<N; i++) {
			if(Node[i].adress == st && vis[i] == 0) {
				vis[i] = vis_value;
				num ++;
				endNext = Node[i].next;
				if(Node[i].next != -1) {
					st = Node[i].next;
				} else {
					return;
				}
			} else {
                num2++;
			}
		}
		if(num2 > 100) return;
	}
}

int numValueIs1InVis() {
	int num_ValueIs1InVis = 0;
	for(int i=0; i<N; i++) {
		if(vis[i] ==  1) {
			num_ValueIs1InVis ++;
		}
	}
	return num_ValueIs1InVis;
}

bool isOk(int tempAddress) {
	for(int i=0; i<N; i++) {
		if(Node[i].adress == tempAddress && vis[i] == 1) {
			flag = 1;
		}
	}
	if(numValueIs1InVis() == N) flag = 0;  // 如果vis[]中值为1的元素的数目为N个
	if(flag == 1) return true;
	else return false;
}

int main() {
	scanf("%d%d%d",&st1,&st2,&N);
	for(int i=0; i<N; i++) {
		scanf("%d %c %d",&Node[i].adress,&Node[i].data,&Node[i].next);  // 注意：“ %c ”
	}

	memset(vis,0,sizeof(vis));

	vis_value = 1;
	solve(st1);

	vis_value = 2;
	solve(st2);

	if(!isOk(endNext)) {  // 如果 endNext 在第一个串中没有，则把endNext赋值为-1
		endNext = -1;
	}

	if(endNext == -1) {
		printf("-1");
	} else {
		printf("%05d",endNext);
	}

	return 0;
}






看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  
看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  
看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  
看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  
看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  
看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  
看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！  看参考 ！！ 