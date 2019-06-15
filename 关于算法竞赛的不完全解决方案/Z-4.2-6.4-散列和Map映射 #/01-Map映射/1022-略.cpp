Digital Library (30)


A Digital Library contains millions of books, stored according to their titles, authors, key words of their abstracts, publishers, and published years. Each book is assigned an unique 7-digit number as its ID. Given any query from a reader, you are supposed to output the resulting books, sorted in increasing order of their ID's.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=10000) which is the total number of books. Then N blocks follow, each contains the information of a book in 6 lines:

Line #1: the 7-digit ID number;
Line #2: the book title -- a string of no more than 80 characters;
Line #3: the author -- a string of no more than 80 characters;
Line #4: the key words -- each word is a string of no more than 10 characters without any white space, and the keywords are separated by exactly one space;
Line #5: the publisher -- a string of no more than 80 characters;
Line #6: the published year -- a 4-digit number which is in the range [1000, 3000].
It is assumed that each book belongs to one author only, and contains no more than 5 key words; there are no more than 1000 distinct key words in total; and there are no more than 1000 distinct publishers.

After the book information, there is a line containing a positive integer M (<=1000) which is the number of user's search queries. Then M lines follow, each in one of the formats shown below:

1: a book title
2: name of an author
3: a key word
4: name of a publisher
5: a 4-digit number representing the year
Output Specification:

For each query, first print the original query in a line, then output the resulting book ID's in increasing order,   '
each occupying a line. If no book is found, print "Not Found" instead.



Sample Input:

3

1111111
The Testing Book
Yue Chen
test code debug sort keywords
ZUCS Print
2011

3333333
Another Testing Book
Yue Chen
test code sort keywords
ZUCS Print2
2012

2222222
The Testing Book
CYLL
keywords debug book
ZUCS Print2
2011


6
1: The Testing Book
2: Yue Chen
3: keywords
4: ZUCS Print
5: 2011
3: blablabla



Sample Output:


1: The Testing Book
1111111
2222222

2: Yue Chen
1111111
3333333

3: keywords
1111111
2222222
3333333

4: ZUCS Print
1111111

5: 2011
1111111
2222222

3: blablabla
Not Found





Thinking:
	1. 使用 map<string,set<int>>  (p254)
	2. 使用 二维数组，每一行表示一种信息
		book[6][MAX]:
			book[0][i]
			book[1][i]
			book[2][i]
			book[3][i]
			book[4][i]
			book[5][i]



测试读取输入-------------------------------------------
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int N;
	scanf("%d",&N);
	for(int i=0; i<N; i++) {
		int x;
		char b[10];
		scanf("%d: ",&x);
		gets(b);
		printf(">>%s<<\n",b);
	}
	return 0;
}

输出：
6
1: The Testing Book
>>The Testing Book<<
2: Yue Chen
>>Yue Chen<<
3: keywords
>>keywords<<
4: ZUCS Print
>>ZUCS Print<<
5: 2011
>>2011<<
3: blablabla
>>blablabla<<


测试比较-------------------------------------------
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	char a[10] = {"abc"}, b[10] = {"abc"};
	if(strcmp(a,b) == 0) printf("YES\n");
	else printf("NO\n");
	return 0;
}

输出：YES
-------------------------------------------