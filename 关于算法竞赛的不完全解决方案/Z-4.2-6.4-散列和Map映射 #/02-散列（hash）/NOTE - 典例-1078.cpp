Hashing (25)

The task of this problem is simple: insert a sequence of distinct positive integers into a hash table, 
and output the positions of the input numbers. 
The hash function is defined to be 
	"H(key) = key % TSize" where TSize is the maximum size of the hash table. 
	Quadratic probing (with positive increments only) is used to solve the collisions.
	二次探测(只有正增量)用于解决碰撞。

	Note that the table size is better to be prime. If the maximum size given by the user is not prime, 
	you must re-define the table size to be the smallest prime number which is larger than the size given by the user.
	注意，表的大小最好是质数。如果用户给出的最大大小不是质数，
	您必须重新定义表的大小，以成为大于用户给出的大小的最小素数。
	。。。英文全都不认识咋办。。。

Input Specification:

Each input file contains one test case. For each case, 
the first line contains two positive numbers: 
	MSize (<=104) 
	and N (<=MSize) 
	which are the user-defined table size (表长)
	and the number of input numbers (要插入的数字的个数), respectively. 
	Then N distinct positive integers are given in the next line. 
All the numbers in a line are separated by a space.

Output Specification:

For each test case, print 
	the corresponding(相应的) positions (index starts from 0) of the input numbers in one line. 
All the numbers in a line are separated by a space, and there must be no extra space at the end of the line. 
	In case it is impossible to insert the number, print "-" instead.


Sample Input:
4 4  MSize(表长)  N
10 6 4 15
Sample Output:
0 1 4 -


【一般来说可以使用标准模板库中的【Map映射】来直接使用【散列hash】的功能，
除非必须模拟这些方法或是对算法的效率要求较高】

此题需要模拟散列，尤其冲突解决


#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 100010;

int Tsize, N, HashTable[MAX];

bool isPrime(int x) {
	if(x<=1) return false;
	for(int i=2; i<=sqrt(x); i++) {  // <=    <=    <=    <=    <=    <=    <=    <=       4 !!!!!!!!
		if(x % i == 0) return false;
	}
	return true;
}

int main() {
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
				if(HashTable[(key + (int)pow(step,2)) % Tsize] == -1) {  //(int)(int)(int)(int)(int)(int)
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

第二遍-----------------------------------
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