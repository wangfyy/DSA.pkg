Tree Traversals Again (25)

An inorder binary tree traversal can be implemented in a non-recursive way with a stack. For example, 
suppose that when a 6-node binary tree (with the keys numbered from 1 to 6) is traversed, 
the stack operations are: 
push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop(); pop(). 
Then a unique binary tree (shown in Figure 1) can be generated from this sequence of operations. 
Your task is to give the postorder traversal sequence of this tree.

Input Specification:
Each input file contains one test case. For each case, 
the first line contains a positive integer N (<=30) which is the total number of nodes in a tree 
(and hence the nodes are numbered from 1 to N). Then 2N lines follow, 
each describes a stack operation in the format: 
"Push X" where X is the index of the node being pushed onto the stack; 
or "Pop" meaning to pop one node from the stack.

Output Specification:
For each test case, print the postorder traversal sequence of the corresponding tree in one line. 
A solution is guaranteed to exist. All the numbers must be separated by exactly one space, 
and there must be no extra space at the end of the line.

123456的push顺序为先序，pop顺序为中序，求后序

Sample Input:
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
Sample Output:
3 4 2 6 5 1

//给定先序中序，求后序
//code:
#include <cstdio>
#include <cstring>
#include <stack>
#include <iostream>
using namespace std;
const int MAXN = 35;
struct node{
    int data;
    node* lChild;
    node* rChild;
};
int N;
int preOrder[MAXN], inOrder[MAXN];
node* create(int preL, int preR, int inL, int inR) {
    if(preL > preR) return NULL;
    node* root = new node;
    root->data = preOrder[preL];
    int k;
    for(k=0; k<N; k++)
        if(preOrder[preL] == inOrder[k])
            break;
    int numLeft = k - inL;
    root->lChild = create(preL+1, preL+numLeft, inL, inL+numLeft-1);
    //或create(preL+1, preL+numLeft, inL, k-1);
    root->rChild = create(preL+numLeft+1, preR, inL+numLeft+1, inR);
    //或create(preL+numLeft+1, preR, k+1, inR);
    return root;
}
int j = 1;
void dfs(node* root) {
    if(root == NULL) return;
    dfs(root->lChild);
    dfs(root->rChild);
    if(j != N){
        printf("%d ",root->data);
        j++;
    } else printf("%d",root->data);
}
int main() {
    scanf("%d",&N);
    stack<int> s;
    char how[5];
    int x;
    int j_1 = 0, j_2 = 0;
    for(int i=0; i<N*2; i++) {
        scanf("%s",how);
        if(strcmp(how, "Push") == 0) {
            scanf("%d",&x);
            preOrder[j_1++] = x;
            s.push(x);
        } else {
            inOrder[j_2++] = s.top();
            s.pop();
        }
    }
    node* root = create(0, N-1, 0, N-1);
    dfs(root);
    return 0;
}