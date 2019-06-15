To Fill or Not to Fill (25)

With highways available, driving a car from Hangzhou to any other city is easy. 
But since the tank capacity of a car is limited, 
we have to find gas stations on the way from time to time. 
Different gas station may give different price. You are asked to carefully design the cheapest route to go.

Input Specification:
Each input file contains one test case. For each case, 

  the first line contains 4 positive numbers: 
	Cmax (<= 100), 	---the maximum capacity of the tank; 
	D (<=30000), 	---the distance between Hangzhou and the destination city; 
	Davg (<=20), 	---the average distance per unit gas that the car can run; 
	N (<= 500), 	---the total number of gas stations. 
  Then N lines follow, each contains a pair of non-negative numbers: 
	Pi, 		---the unit gas price, 
	Di (<=D), 	---the distance between this station and Hangzhou, 

for i=1,...N. All the numbers in a line are separated by a space.

Output Specification:
For each test case, 
	print the cheapest price in a line, accurate up to 2 decimal places. (精确到小数点后两位)
	It is assumed that the tank is empty at the beginning.   起始时车是没油的
	If it is impossible to reach the destination, 
	print "The maximum travel distance = X" where X is the maximum possible distance the car can run, 
accurate up to 2 decimal places.


Sample Input 1:
50 1300 12 8		// 容量  距离  每单位油可以走多远距离  油站的数量
6.00 1250			// 每个油站的油品单价  这个油站到起点的距离
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300
 
Sample Output 1:
749.17				// 最多少的油费


Sample Input 2:
50 1300 12 2
7.10 0
7.00 600

Sample Output 2:
The maximum travel distance = 1200.00



