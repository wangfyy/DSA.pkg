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
4 4
10 6 4 15
Sample Output:
0 1 4 -


#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 100010;

int Tsize, N, HashTable[MAX];

bool isPrime(int x) {
	if(x<=1) return false;
	for(int i=2; i<=sqrt(x); i++) {  // <=    <=     <=    <=       4 !!!!!!!!
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