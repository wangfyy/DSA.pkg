1058. A+B in Hogwarts (20)

If you are a fan of Harry Potter, 
you would know the world of magic has its own currency(货币) system -- as Hagrid explained it to Harry, 
"Seventeen silver Sickles to a Galleon and twenty-nine Knuts to a Sickle, it's easy enough." 
Your job is to write a program to compute A+B where A and B are given in the standard form of 
	"Galleon.Sickle.Knut" 
	(Galleon is an integer in [0, 107], 
	Sickle is an integer in [0, 17), 
	and Knut is an integer in [0, 29)).

Input Specification:
Each input file contains one test case which occupies a line with A and B in the standard form, 
separated by one space.

Output Specification:
For each test case you should output the sum of A and B in one line, 
with the same format as the input.

Sample Input:
3.2.1 10.16.27
Sample Output:
14.1.28


#include <cstdio>

int main() {
	int a1,a2,a3,b1,b2,b3,jinwei;  // jinwei 进位
	scanf("%d.%d.%d",&a1,&a2,&a3);
	scanf("%d.%d.%d",&b1,&b2,&b3);

	int h3 = a3 + b3;
	jinwei = h3 / 29;  // 这两条语句的执行无需if判断 h3 > 29
	h3 = h3 % 29;

	int h2 = a2 + b2 + jinwei;
	jinwei = h2 / 17;
	h2 = h2 % 17;

	int h1 = a1 + b1 + jinwei;  // 注意：最前因为没有进位，可以无限大

	printf("%d.%d.%d",h1,h2,h3);

	return 0;
}	



。。。。什么鬼题。。。。