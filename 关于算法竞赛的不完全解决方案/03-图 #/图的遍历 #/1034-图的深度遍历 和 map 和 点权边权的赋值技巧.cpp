Head of a Gang.

One way that the police finds the head of a gang is to check people's phone calls. '
If there is a phone call between A and B, we say that A and B is related(相关). 
The weight of a relation is defined to be the total time length of all the phone calls made between the two persons. 
A "Gang" is a cluster(集群) of more than 2 persons who are related to each other with 
total relation weight being greater than a given threshold K. (总关系权重大于给定阈值K)
In each gang, the one with maximum total weight is the head. Now given a list of phone calls, 
you are supposed to find the gangs and the heads.

Input Specification:
Each input file contains one test case. For each case, 
the first line contains two positive numbers N and K (both less than or equal to 1000), 
the number of phone calls and the weight threshold(阈值), respectively. Then N lines follow, 
each in the following format:
Name1 Name2 Time
where Name1 and Name2 are the names of people at the two ends of the call, 
and Time is the length of the call. A name is a string of three capital letters chosen from A-Z. 
A time length is a positive integer which is no more than 1000 minutes(分钟).

Output Specification:
For each test case, first print in a line the total number of gangs. 
Then for each gang, print in a line the name of the head and the total number of the members(成员). 

It is guaranteed that the head is unique for each gang.(可以保证每个帮派的头都是独一无二的)
The output must be sorted according to the alphabetical(字母顺序排列) order of the names of the heads.

Sample Input 1:
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 1:
2
AAA 3
GGG 3

Sample Input 2:
8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 2:
0


涉及：map的使用、点权边权的赋值技巧、图的遍历


#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 2010;
const int INF = 1000000000;
int N, K, numPerson = 0;
map<int, string> intToString;  //编号->姓名
map<string, int> stringToInt;  //姓名->编号
map<string, int> Gang;  //head->人数
int G[MAXN][MAXN], weight[MAXN];  // 边权, 点权
bool vis[MAXN] = {false};  //////
int head, numMember, totalValue;  // totalValue---总边权

void dfs(int i) {
	if(vis[i] == false) {
		vis[i] = true;
		numMember ++;
		if(weight[i] > weight[head]) head = i;
		// 枚举递归与i相连的所有节点
		for(int j=0; j<numPerson; j++) {  //// 首先(不得不)枚举所有人
			if(G[i][j] > 0) {  //// 如果i和j相连
				totalValue += G[i][j];
				G[i][j] = G[j][i] = 0;
					//////// 防止回头(因为本题为用完一条边，此边就废),(鉴于“枚举与i相连的所有节点”的方式)
				dfs(j);
			}
		}
	}
}

void dfsTrave() {
	for(int i=0; i<numPerson; i++) {
		if(vis[i] == false) {
			head = i;
			numMember = 0;
			totalValue = 0;  
				// 已经把：'头部','成员数','总边权'定义为全局变量，简化'dfs(xxxxxxx)'传的参数
			dfs(i);
			if(numMember > 2 && totalValue > K) {  /// 如果：此连接块的‘成员数 > 2’且‘总边权 > 阀值’
				Gang[intToString[head]] = numMember;  // 块头名字  <--对应-->  块内成员数
			}
		}
	}
}

int change(string str) {
	if(stringToInt.find(str) != stringToInt.end()) {  // 若str已经出现过
		return stringToInt[str];
	} else {
		stringToInt[str] = numPerson;
		intToString[numPerson] = str;
		return numPerson ++;  // 先返回，再加加
	}
}

int main() {
	scanf("%d%d",&N,&K);
	string str1, str2;
	int id1, id2, w;
	for(int i=0; i<N; i++) {
		cin >> str1 >> str2 >> w;  // string型,输入输出字符串式只能用cin/cout,不能 scanf+%s 输入
		id1 = change(str1);  //// 将字符串转为int型，以便作为数组下标
		id2 = change(str2);
		weight[id1] += w;  ////// 与w有联系的都是增加w
		weight[id2] += w;  ////// 与w有联系的都是增加w
		G[id1][id2] += w;  ////// id1->id2的边权增加w
		G[id2][id1] += w;  ////// id2->id1的边权增加w
	}
	memset(vis,false,sizeof(vis));
	dfsTrave();  // 遍历整个图的所有连接块，获取Gang的信息
	printf("%d\n",Gang.size());  ///  Gang的数目
	//// 迭代器遍历 map<string, int> Gang
	map<string, int>::iterator it;
	for(it = Gang.begin(); it != Gang.end(); it++) {
		cout << it->first << " " << it->second << endl;
			// 错误：printf("%s %d\n",it->first,it->second);
	}

	return 0;
}


==========================================================================================
//带点权边权的图的遍历
//code:
#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 2010;
const int INF = 1000000000;
int N, K, numPerson = 0;
map<string, int> stringToInt;  //姓名->编号
map<int, string> intToString;  //编号->姓名
map<string, int> Gang;
int G[MAXN][MAXN], weight[MAXN];
bool vis[MAXN] = {false};
int head, numMember, totalValue;  //全局
int change(string str) {
	if(stringToInt.find(str) != stringToInt.end()) return stringToInt[str];
	else {
		stringToInt[str] = numPerson;
		intToString[numPerson] = str;
		return numPerson ++;
	}
}
void dfs(int i) {
	if(vis[i] == false) {
		vis[i] = true;
		numMember ++;
		if(weight[i] > weight[head]) head = i;
		for(int j=0; j<numPerson; j++) {
			if(G[i][j] > 0) {
				totalValue += G[i][j];
				G[i][j] = G[j][i] = 0;  ////标记边的方式，即用完就去掉
				dfs(j);
			}
		}
	}
}
void dfsTrave() {
	for(int i=0; i<numPerson; i++) {
		if(vis[i] == false) {
			head = i;  //i
			numMember = 0;
			totalValue = 0;  
			dfs(i);
			if(numMember > 2 && totalValue > K) Gang[intToString[head]] = numMember;
		}
	}
}
int main() {
	scanf("%d%d",&N,&K);
	string str1, str2;
	int id1, id2, w;
	for(int i=0; i<N; i++) {
		cin >> str1 >> str2 >> w;
		id1 = change(str1);
		id2 = change(str2);
		weight[id1] += w;  //与w有联系的都是增加w
		weight[id2] += w;  //与w有联系的都是增加w
		G[id1][id2] += w;  //d1->id2的边权增加w
		G[id2][id1] += w;  //id2->id1的边权增加w
	}
	memset(vis,false,sizeof(vis));
	dfsTrave();
	printf("%d\n",Gang.size());
	for(map<string, int>::iterator it = Gang.begin(); it != Gang.end(); it++)
		cout << it->first << " " << it->second << endl;  //错误：printf("%s %d\n",it->first,it->second);
	return 0;
}
