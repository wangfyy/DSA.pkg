// 链表
// 创建链表
#include <cstdio>
#include <cstdio>
struct node{
	int data;
	node* next;
};
node* create(int Array[]) {
	node *head, *p, *pre;
	head = new node;
	head->next = NULL;
	pre = head;  //头是空的
	for(int i=0; i<5; i++) {
		p = new node;
		p->data = Array[i];
		p->next = NULL;
		pre->next = p;
		pre = p;
	}
	return head;
}
int main() {
	int Array[5] = {4, 5, 6, 2, 3};
	node* L = create(Array);
	// 输出
	L = L->next;
	while(L != NULL) {
		printf("%d ",L->data);
		L = L->next;
	}
}
// 插入元素
void insert(node* head, int pos, int x) {
	//插到pos位置 例 原 5 3 6 1 2 pos=3 x=4 后 5 3 '4' 6 1 2
	node*p = head;
	for(int i=0; i<pos-1; i++) {
		p = p->next;  //p为插入位置的前个节点
	}
	node* p = new node;
	q->data = x;
	q->next = p->next;
	p->next = q;
}
// 删除元素
void del(node* head, int x) {
	node* pre = head;

	node* p = head->next;
	while(p != NULL) {
		if(p->data = x) {
			pre->next = p->next;
			delete(p);  //手动释放空间
			p = p->next;
		} else {
			pre = p;
			p = p->next;
		}
	}
}

// 静态链表
struct node{
	int data;
	int next;
} Node[MAXN];
// 大整数类 ------------------------------------------
struct bign{
	int d[1000];
	int len;
	// bign() {
	// 	memset(d, 0, sizeof(d));
	// 	len = 0;
	// }
}
// 将字符串表示的大整数转化成bign
bign change(char str[]) {
	bign a;
	a.len = strlen(str);
	for(int i=0; i<a.len; i++) {
		a.d[i] = str[a.len - i - 1] - '0';  // d[0]为个位数字
	}
	return a;
}
// 比较两个bign的大小
int compare(bign a, bign b) {
	if(a.len > b.len) {
		return 1;
	} else if(a.len < b.len) {
		return -1;
	} else {
		for(int i=0; i<a.len; i++) {
			if(a.d[i] > b.d[i]) {
				return 1;
			} else {
				return 1;
			}
		}
		return 0;
	}
}
// 高精度 + 高精度
bign add(bign a, bign b) {
	bign c;
	int carry = 0;
	for(int i=0; i<a.len || i<b.len; i++) {  //以较长的为准
		int temp = a.d[i] + b.d[i] + carry;
		carry = temp / 10;
		c.d[c.len++] = temp % 10;
	}
	if(carry != 0) c.d[c.len++] = carry;
	return c;
}
// 高精度 - 高精度
bign sub(bign a, bign b) {
	bign c;
	for(int i=0; i<a.len || i<b.len; i++) {  //以较长的为准
		if(a.d[i] < b.d[i]) {  //如果不够减
			a.d[i++]--;  //向高位借位
			a.d[i] += 10;  //当前位加10
		}
		c.d[c.len++] = a.d[i] - b.d[i];
	}
	while(c.len >= 2 && c.d[c.len - 1] == 0) {
	//长度至少是2(因为若只有一位的话，那么允许为零)，且最高位为零
		c.len --;  //即：去处高位的0，同时至少保留一位最低位(0)
	}
	return c;
}
// 高精度 * 低精度
bign multi(bign a, int b) {
	bign c;
	int carry = 0;
	for(int i=0; i<a.len; i++) {  //以较长的为准
		int temp = a.d[i] * b + carry;
		carry = temp / 10;
		c.d[c.len++] = temp % 10;
	}
	while(carry != 0) {
		c.d[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}
// 高精度 / 低精度
bign divide(bign a, int b, int& r) {
	bign c;
	c.len = a.len;  //被除数的每一位和商的每一位都是一一对应的
	for(int i=a.len-1; i>=0; i--) {  //从高位开始
		r = r * 10 + a.d[i];
		if(r < b) c.d[i] = 0;  //不够除
		else {
			c.d[i] = r / b;
			r = r % b;
		}
	}
	while(c.len >= 2 && c.d[c.len - 1] == 0) {
		//长度至少是2(因为若只有一位的话，那么允许为零)，且最高位为零
		c.len--;  // 去处高位的0，同时至少保留一位最低位(0)
	}
	return c;
}
// 进制转换 ------------------------------------------

---代码1---
// 将10进制的数字N的每位转换为D(任意)进制存到数组number[]，即：'除基(D)求余(D)'得到每位然后存到数组。《3.5》
// 为什么输入的必须是10进制(或问只被计算机认为是10进制呢)，因为'除基求余法'基于'多项式求和'，所有的任意进制分解都是以它为和进行的。(纯属XB~)
	int len = 0;
	do{  // 0
		number[len++] = N % D;  //数组0号下标存个位数字
		N /= D;
	} while(N != 0);  //注：结束时N为0
// 例如：	input:N=(10进制数字)123,D=8
// 			output:(8进制数字)371(即：173)

---代码2---
// 当上面代码的D=10时，又多了一个新功能：取原数的每位存到数组number[]
	int len = 0;
	do{  // 0
		number[len++] = N % 10;  //数组0号下标存个位数字
		N /= 10;
	} while(N != 0);  //注：结束时N为0

---代码3---
// 以下代码可以理解为上面代码的增加* product后的新增功能，但不无完全是，因为：强行指定了:p进制:product*=p,而不是上述的10进制了
// p(强行指定:product*=p,而不是上述的10进制了)进制x(直接)转为十进制y(不满足任意进制,Only:10进制)，即：'除基(10)求余(10)'得到每位然后乘以对应的权值(p的n次方)（实质即：以p为基数的多项式求和）。《3.5》
// 与秦九韶公式的区别:不需要数组; 从低位开始，而秦九韶从高位开始。
	int y = 0, product = 1;
	while(x != 0) { //for循环不如while，for循环需要先知道位数，while循环的条件只是'x!=0'，且可以顺便求位数
		y += (x % 10) * product;  //初始时从个位开始
		x /= 10;  //x指向高一位
		product *= p;  //product加权
	}

---代码4---
// 得到number[]的情况下用秦九韶公式计算多项式和(因为秦九韶需要数组)，进制(基数)为D
	int N = 0;  //括号内的是N，然后N*D
	for(int i=len-1; i>0; i--) {
	//因为得到的number[]是倒序存的(即:下标由小到大对应数字的由个位到高位)，而秦九韶要求从高位开始，所以起始i=len-1
	//若number[]本来即为正序的，则起始i=0
		N = N * D + number[i];
	}

其中：‘代码3’等价于‘代码2+代码4’，但后者实现代码较长、时间复杂度较优(原因在于秦九韶公式求和比一般的多项式累加求和的计算次数要少)。

8进制  >>>(代码3 或 代码2+代码4)>>>  10进制
10进制  >>>(代码1)>>>  16进制
8进制  >>>(代码3 或 代码2+代码4)>>>  10进制  >>>(代码1)>>>  16进制

但是，用“ 8进制  >>>(代码3 或 代码2+代码4)>>>  10进制  >>>(代码1)>>>  16进制 ”的方式时，对于长数(1000位)溢出。
所以位数长时，用8进制  >>>>>>  2进制  >>>>>>  16进制，例题代码如下：

原题：十六进制转八进制
#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
using namespace std; 
int N;
int main() {
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        string str1, str2 = "";  //str1存16进制, str2存2进制
        cin>>str1;
        for(int j=0; j<str1.length(); j++) {
            switch(str1[j]) {
                case '0' : str2 +="0000"; break;  //16进制转2进制
                case '1' : str2 +="0001"; break;
                case '2' : str2 +="0010"; break;
                case '3' : str2 +="0011"; break;
                case '4' : str2 +="0100"; break;
                case '5' : str2 +="0101"; break;
                case '6' : str2 +="0110"; break;
                case '7' : str2 +="0111"; break;
                case '8' : str2 +="1000"; break;
                case '9' : str2 +="1001"; break;
                case 'A' : str2 +="1010"; break;
                case 'B' : str2 +="1011"; break;
                case 'C' : str2 +="1100"; break;
                case 'D' : str2 +="1101"; break;
                case 'E' : str2 +="1110"; break;
                case 'F' : str2 +="1111"; break;
                default:break;  
            }
        }
        int len2 = str2.length();
        if(len2 % 3 == 1) {
    		str2 = "00" + str2;
        } else if(len2 % 3 == 2) {
    		str2 = "0" + str2;
        }
        len2 = str2.length();
        for(int j=0; j<=len2 - 3; j+=3) {  //2进制转8进制
            int num = 4 * (str2[j] - '0') + 2 * (str2[j+1] - '0') + (str2[j+2] - '0');
            if(num == 0 && j == 0) {  //去掉高位无效的零
                continue;
            }
            printf("%d",num);
        }
        printf("\n");
    }
    return 0;
}
// 字符串处理 ------------------------------------------
Sample Input:
12345
Sample Output:
one five.
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    char a[20], s[20];
    gets(a);
    int sum = 0;
    for(int i=0; i<strlen(a); i++) sum += (a[i] - '0');
    sprintf(s,"%d",sum);
    char arr[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for(int i=0; i<strlen(s); i++) printf("%s ",arr[s[i] - '0']);
    return 0;
}
// 哈希散列 Map 二维数组 ------------------------------------------
哈希散列
	把目标值当做数组arr[]的下标，
	arr[下标]的值为bool类型(表示是否出现过)或int类型(表示出现的次数)，
	这样可以达到快速检索定位某值的作用，避免了遍历查找的时间消耗。
Map
	可以使用标准模板库中的Map映射来直接实现类似哈希散列的需求，
	Map的内部是用RBTree(红黑树-高效的插入查找)实现的，而非哈希散列数组。
	【注意】
		map<typename1,typename2>中，typename1为键(相当于数组的下标)，typename2为值(相当于数组下标所存(对应)的值)，
		当typename1为数字时(即map<int,int>数字到数字的映射)，整个等价于一个数组。
		当typename1为字符时，可使用map<char,int>，也可使用map<int,int>用ACII码。
		当typename1为字符串时，需要用string类型map<string,int>，不能用字符数组map<char[],int>(看着就别扭)。
		当typename1需要为结构体时，也有定义，但一般不推荐，而一般用map和数组结合的方式。（见:PATA180318C）
二维数组
	其实，二维数组就扯远了，他虽能达到和使用Map相同的效果，但效率上并没什么意义。
【例1】----------------------------------
Sample Input 1:
7 5 31 5 88 67 88 17
Sample Output 1:
31  //第一个投注唯一数字的人获胜
Sample Input 2:
5 888 666 666 888 888
Sample Output 2:
None
//代码1-哈希散列实现
#include <cstdio>
int main() {
	int HashTable[150], num[150], N;
	scanf("%d",&N);
	int x;
	for(int i=0; i<N; i++) {
		scanf("%d",&x);
		num[i] = x;  //记录顺序
		HashTable[x] ++;
	}
	for(int i=0; i<N; i++) {
		if(HashTable[num[i]] == 1) {
			printf("%d",num[i]);
			return 0;
		}
	}
	printf("None");
	return 0;
}
//代码2-Map实现
#include <cstdio>
#include <map>
using namespace std;
int main() {
	int N, tag[1010];
	map<int, int> mapp;
	scanf("%d",&N);
	for(int i=0; i<N; i++) {
		int temp;
		scanf("%d",&temp);
		tag[i] = temp;
		if(mapp.find(temp) == mapp.end()) mapp[temp] = 1;
		else mapp[temp]++;
	}
	for(int i=0; i<N; i++) {
		if(mapp[tag[i]] == 1) {
			printf("%d",tag[i]);
			return 0;
		}
	}
	printf("None");
	return 0;
}
【例2】----------------------------------
Sample Input:
They are students.
aeiou
Sample Output:
Thy r stdnts.
//代码1-哈希散列实现
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
	bool HashTable[10010];
	char a[1010], b[1010];
	gets(a);
	gets(b);
	for(int i=0; i<strlen(b); i++) //先读第二个
		HashTable[b[i]] = true;  //下标为ASCII码
	for(int i=0; i<strlen(a); i++)
		if(HashTable[a[i]] == false)
			printf("%c",a[i]);
	return 0;
}
//代码2-Map实现
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;
int main() {
	map<int, int>mapp;
	char strA[1010], strB[1010];
	gets(strA);
	gets(strB);
	for(int i=0; i<strlen(strB); i++)
		if(mapp.find(strB[i]) == mapp.end())
			mapp[strB[i]] = 1;
	for(int i=0; i<strlen(strA); i++)
		if(mapp[strA[i]] == 0)
			printf("%c",strA[i]);
	return 0;
}
【例3】----------------------------------
输出最多的数
Sample Input:
5 3
0 0 255 16777215 24
24 24 0 0 24
24 0 24 24 24
Sample Output:
24
//Map实现，因为16777215太大无法哈希散列
#include <cstdio>
#include <map>
using namespace std;
int main() {
	int M, N;
	map<int,int> count;
	scanf("%d%d",&M,&N);
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			int temp;
			scanf("%d",&temp);
			if(count.find(temp) != count.end()) count[temp]++;
			else count[temp] = 1;
		}
	}
	int k, max = 0;
	for(map<int,int>::iterator it = count.begin(); it != count.end(); it++) {
		if(it->second > max) {
			max = it->second;
			k = it->first;
		}
	}
	printf("%d",k);
	return 0;
}
【例4】----------------------------------
模拟散列的冲突解决（二次探测，仅正增量）
Sample Input:
4 4
10 6 4 15
Sample Output:
0 1 4 -
//哈希散列实现，因为要模拟散列的冲突解决
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 100010;
bool isPrime(int x) {
	if(x<=1) return false;
	for(int i=2; i<=sqrt(x); i++) {  //<= <= <= !!!
		if(x % i == 0) return false;
	}
	return true;
}
int main() {
	int Tsize, N, HashTable[MAX];
	scanf("%d%d",&Tsize,&N);
	memset(HashTable,-1,MAX);
	while(isPrime(Tsize) == false) {
		Tsize++;
	}
	int key;
	for(int i=0; i<N; i++) {
		scanf("%d",&key);
		if(HashTable[key % Tsize] == -1) {
			HashTable[key % Tsize] = key;
			printf("%d",key % Tsize);
		} else {
			int step;
			for(step=1; step<Tsize; step++) {  //探测step步长
				if(HashTable[(key + (int)pow(step,2)) % Tsize] == -1) {  //(int)(int)(int)
					HashTable[(key + (int)pow(step,2)) % Tsize] = key;
					printf("%d",(key + (int)pow(step,2)) % Tsize);
					break;
				}
			}
			if(step >= Tsize) printf("-");
		}
		if(i != N-1) printf(" ");
	}
	return 0;
}
第二遍代码-----------------
#include <cstdio>
#include <cmath>
using namespace std;
bool isPrime(int x) {
	if(x <= 1) return false;
	for(int i=2; i<=sqrt(x); i++)  //<=  <=  <=  4!!
		if(x % i == 0)
			return false;
	return true;
}
int main() {
	int MSize, N, HashTable[1010];
	 scanf("%d%d",&MSize, &N);
	 while(!isPrime(MSize)) MSize++;
	 for(int i=0; i<N; i++) {
	 	int temp;
	 	scanf("%d",&temp);
	 	int pos = temp % MSize, t = 0, flag = 0;
	 	while(HashTable[pos % MSize] == 1) {
	 		t++;
	 		pos+=t*t;
	 		if(pos >= MSize) {
	 			flag = 1;
	 			break;	
	 		}
	 	}
	 	if(flag == 0) {
			printf("%d",pos % MSize);
			HashTable[pos % MSize] = 1;
		} else printf("-");
		if(i < N) printf(" ");
	 }
}
（待验证）----------
【例5】----------------------------------
------------------------------------------------------------------------
// PATA 20180318 B
Input Specification:
	Each input file contains one test case. 
	For each case, the first line gives a positive integer N (≤10^5), 
	which is the number of testees. 
	Then N lines follow, each gives the information of a testee in the following format:
	ID Score School
	where ID is a string of 6 characters with the first one representing the test level: 
	B stands for the basic level, A the advanced level and T the top level; 
	Score is an integer in [0, 100]; 
	and School is the institution code which is a string of no more than 6 English letters (case insensitive). 
	Note: it is guaranteed that ID is unique for each testee.
Output Specification:
	For each case, first print in a line the total number of institutions. 
	Then output the ranklist of institutions in nondecreasing order of their ranks in the following format:
	Rank School TWS Ns
	where Rank is the rank (start from 1) of the institution; 
	School is the institution code (all in lower case);
	TWS is the total weighted score which is defined to be the integer part of ScoreB/1.5 + ScoreA + ScoreT*1.5, 
	where ScoreX is the total score of the testees belong to this institution on level X; 
	and Ns is the total number of testees who belong to this institution.
	The institutions are ranked according to their TWS. 
	If there is a tie, the institutions are supposed to have the same rank, 
	and they shall be printed in ascending order of Ns. 
	If there is still a tie, they shall be printed in alphabetical order of their codes.

code ------------------------------------
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100000;
struct school {
    int Rank;
    char SchoolN[20];
    double TWS;
    int TWSInt;  //注意是按总分的int型来排名！
    int Ns;
} School[MAXN];
map<string,int> mapp;
int index1 = 0;
int findIndex(char SchoolName[20]) {
    if(mapp.find(SchoolName) != mapp.end()) {
        return mapp[SchoolName];
    } else {
        mapp[SchoolName] = index1;  ////
        return index1++;
    }
}
bool cmp(school a, school b) {
    if(a.TWSInt != b.TWSInt) return a.TWSInt > b.TWSInt;
    if(a.Ns != b.Ns) return a.Ns < b.Ns;
    return strcmp(a.SchoolN,b.SchoolN) < 0;  ////
}
int main() {
    int N;
    scanf("%d",&N);
    char ID[20];
    double Score;
    char SchoolName[20];
    for(int i=0; i<N; i++) {
        scanf("%s %lf %s",&ID,&Score,&SchoolName);
        for(int j=0; j<strlen(SchoolName); j++)
            if(SchoolName[j] >= 'A' && SchoolName[j] <= 'Z') SchoolName[j] += 32;
        int currentIndex = findIndex(SchoolName);
        strcpy(School[currentIndex].SchoolN,SchoolName);
        if(ID[0] == 'B') School[currentIndex].TWS += Score/1.5;
        if(ID[0] == 'T') School[currentIndex].TWS += Score*1.5;
        if(ID[0] == 'A') School[currentIndex].TWS += Score;
        School[currentIndex].Ns ++;
    }
    for(int i=0; i<index1; i++)
        School[i].TWSInt = (int)School[i].TWS;
    sort(School, School + index1, cmp);
    School[0].Rank = 1;
    for(int i=1; i<index1; i++) {
        if(School[i].TWSInt == School[i-1].TWSInt) School[i].Rank = School[i-1].Rank;
        else School[i].Rank = i+1;
    }
    printf("%d\n",index1);
    for(int i=0; i<index1; i++)
        printf("%d %s %d %d\n",School[i].Rank,School[i].SchoolN,School[i].TWSInt,School[i].Ns);
    return 0;
}

// 并查集 ------------------------------------------
Sample Input:
3 2 3  //城市数目 路的数目 检查的数目
1 2
1 3
1 2 3
Sample Output:
1  //如果城市1沦陷了，需修1条公路才能将其他的城市连起来
0
0
// Thinking：
// 先把路径保存到图里，
// 再根据读取到的删除的结点来把图里的路径相连的结点包含到并查集里的一个集合，
// 然后遍历集合个数。
// 注：（1）为啥不一开始读路径时就直接建并查集呢？ 因为之后在并查集里删结点不好操作
// 注：（2）为啥第一步不是把数据读到一个二维数组里，而是读到图里呢？ 
// 		因为既然选择了要先存路径相连节点再根据其建立并查集，
// 		所以相比一个随意的存储结构，图更具便利性。
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 1010;
int N, M, K, vis[MAXN];
vector<int> G[MAXN];
int father[MAXN];
void init() {
	for(int i=1; i<=N; i++) {
		father[i] = i;
		vis[i] = false;
	}
}
int findFather(int a) {
	int b = a;
	while(father[a] != a)
		a = father[a];
	while(b != father[b]) {
		int c = b;
		b = father[b];
		father[c] = a;
	}
	return a;
}
void un(int u, int v) {
	int uF = findFather(u);
	int vF = findFather(v);
	if(uF != vF) father[uF] = vF;
}
int main() {
	scanf("%d%d%d",&N,&M,&K);
	int a, b;
	for(int i=0; i<M; i++) {  //存储节点
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i=0; i<K; i++) {  //建立集合
		init();
		int currentPoint;
		scanf("%d",&currentPoint);
		for(int i=1; i<=N; i++) {
			for(int j=0; j<G[i].size(); j++) {
				int u = i, v = G[i][j];
				if(u != currentPoint && v != currentPoint)
					un(u, v);
			}
		}
		int cnt = 0;
		for(int i=1; i<=N; i++)
			if(vis[findFather(i)] == false && i != currentPoint) {
				cnt++;
				vis[findFather(i)] = true;
			}
		printf("%d\n",cnt-1);
	}
	return 0;
}
======================================================
.size()
	int vector<int> G[MAXN]; G[i].size();
.length() 
	String srt; str.length();
strlen()
	char a[20]; strlen(a);
======================================================