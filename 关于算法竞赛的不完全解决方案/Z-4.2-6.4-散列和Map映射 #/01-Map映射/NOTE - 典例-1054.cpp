The Dominant Color (20)

Behind the scenes in the computer's memory,   '
color is always talked about as a series of 24 bits of information for each pixel. 
In an image, the color with the largest proportional area is called the dominant color. 
A strictly dominant color takes more than half of the total area. 
Now given an image of resolution M by N (for example, 800x600), 
you are supposed to point out the strictly dominant color.

Input Specification:

Each input file contains one test case. 
For each case, the first line contains 2 positive numbers: 
M (<=800) and N (<=600) which are the resolutions of the image. 
Then N lines follow, each contains M digital colors in the range [0, 224). 
It is guaranteed that the strictly dominant color exists for each input image. 
All the numbers in a line are separated by a space.

Output Specification:

For each test case, simply print the dominant color in a line.


Sample Input:
5 3
0 0 255 16777215 24
24 24 0 0 24
24 0 24 24 24
Sample Output:
24

----------------------------------------------------------------------
散列GG，，16777215太大了

二维数组仅能处理整型的，此题可以二维数组(第一行存值，第二行存次数)

【一般来说可以使用标准模板库中的【Map映射】来直接使用【散列hash】的功能，
除非必须模拟这些方法或是对算法的效率要求较高】

----------------------------------------------------------------------


---------- 代码1 map ----------
#include <cstdio>
#include <map>
using namespace std;

int main() {
	int M, N;
	map<int,int> count;  //////// 第一格是键，第二个是值
	scanf("%d%d",&M,&N);
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			int temp;
			scanf("%d",&temp);
			if(count.find(temp) != count.end()) count[temp]++;  ////
			else count[temp] = 1;
		}
	}
	int k, max = 0;
	for(map<int,int>::iterator it = count.begin(); it != count.end(); it++) {  //// iterator  iterator  iterator
		if(it->second > max) {  ////
			max = it->second;
			k = it->first;  ////
		}
	}
	printf("%d",k);

	return 0;
}

---------- 代码2 二维数组 ----------
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 10010;

int M, N, num = 0, count2[MAX][MAX];

int findArray(int x) {
	for(int i=0; i<num; i++) {
		if(count2[1][i] == x) {
			return i;
		}
	}
	return -1;
}

int main() {
	scanf("%d%d",&M,&N);
	memset(count2,-1,M*N);
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			int temp;
			scanf("%d",&temp);
			if(findArray(temp) != -1) count2[2][findArray(temp)]++;
			else {
				count2[1][num++] = temp;
				count2[2][num-1] = 1;
			}
		}
	}
	int k, max = 0;
	for(int i=0; i<num; i++) {
		if(count2[2][i] > max) {
			max = count2[2][i];
			k = count2[1][i];
		}
	}
	printf("%d",k);

	return 0;
}

（可能有值为-1,,解决方法fill,,375673,,防止重复）