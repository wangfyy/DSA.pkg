// PAT-A-1056-Mice and Rice-队列

/*
  Mice and Rice is the name of a programming contest in which each programmer
   must write a piece of code to control the movements of a mouse in a given map.
    The goal of each mouse is to eat as much rice as possible in order to become
     a FatMouse.

【老鼠和大米是一个程序设计竞赛，每一个程序员必须写一段代码去控制一个耗子在给定的
图中的行动。每个耗子的目标是去吃尽可能多的大米为了成为个胖耗子。】

  First the playing order is randomly decided for NP programmers. Then every NG
   programmers are grouped in a match. The fattest mouse in a group wins and
    enters the next turn. All the losers in this turn are ranked the same. Every
     NG winners are then grouped in the next match until a final winner is determined.

【首先the playing order是由NP程序员随机决定。然后在比赛中每一个NG程序员被分组。
一个组内最胖的耗子获胜并且进入下一轮。本轮所有的失败者are ranked the same。
每一个NG获胜者在下一场比赛中被分组直到最终获胜者被选出。】

  For the sake of simplicity, assume that the weight of each mouse is fixed once
   the programmer submits his/her code. Given the weights of all the mice and the
    initial playing order, you are supposed to output the ranks for the programmers.

【为了简单， 假设每个耗子的重量被一次性的在他的代码中确定。给定的所有大米的重量和
初始的顺序。你应该输出这些程序员的排名。】

Input Specification:
Each input file contains one test case. For each case, the first line contains 2
 positive integers: NP and NG (<= 1000), the number of programmers and the maximum
  number of mice in a group, respectively. If there are less than NG mice at the
   end of the player's list, then all the mice left will be put into the last group.
    The second line contains NP distinct non-negative numbers Wi (i=0,...NP-1) where
     each Wi is the weight of the i-th mouse respectively. The third line gives the
      initial playing order which is a permutation of 0,...NP-1 (assume that the
       programmers are numbered from 0 to NP-1). All the numbers in a line are
        separated by a space.

【NP：the number of programmers
NG：the maximum number of mice in a group】

Output Specification:
For each test case, print the final ranks in a line. The i-th number is the rank
 of the i-th programmer, and all the numbers must be separated by a space, with
  no extra space at the end of the line.

Sample Input:

11 3
25 18 0 46 37 3 19 22 57 56 10
6 0 8 7 10 5 9 1 4 2 3

Sample Output:

5 5 5 2 5 5 5 3 1 3 5
*/

#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 1010;
struct mouse {
  int weight;  //质量
  int R;  //排名
}mouse [maxn];
int main() {
  int np, ng, order;
  scanf("%d%d",&np,&ng);
  for(int i=0;i<np;i++) {
    scanf("%d",&mouse[i].weight);
  }
  queue<int> q;
  for(int i=0;i<np;i++) {
    scanf("%d",&order);
    q.push(order);  //注意：按顺序把老鼠们的标号入队
  }
  int temp = np, group;  //temp为每层中的组数
  while(q.size() != 1) {
    if(temp % ng == 0) group = temp / ng;
    else group = temp / ng + 1;
    //枚举每一组
    for(int i=0;i<group;i++) {
      int bh_maxw = q.front();  //bh_maxw是该组质量最大的老鼠的编号（并且设置其初值为队列（该组）的队首元素）
      //枚举一组内的每个元素
      for(int j=0;j<ng;j++) {
        //与其说：在最后一组老鼠数不足ng时，退出循环  不如说是：结束一层的条件(因为后面就是新的一层了)
        if(i * ng + j >= temp) break;
        int front = q.front();  //队首老鼠编号
        if(mouse[front].weight > mouse[bh_maxw].weight) bh_maxw = front;
        //该轮所有的老鼠的排名为(group+1)
        mouse[front].R = group + 1;
        q.pop();  //出队
      }
      q.push(bh_maxw);  //晋级  注意是push到q中
    }
    temp = group;
  }
  mouse[q.front()].R = 1;  //注意：抽象建模的关键————当队列只剩1只耗子时，令其排名为1
  for(int i=0;i<np;i++) {
    printf("%d",mouse[i].R);
    if(i<np - 1) printf(" ");
  }
  return 0;
}