// 链表
// 创建链表
#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	node* next;
};
node* create(int Array[]) {
	node *head,*p,*pre;
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
	int Array[5] = {4,5,6,2,3};
	node* L = create(Array);
	L = L->next;
	while(L != NULL) {
		printf("%d\n",L->data);
		L = L->next;
	}
	return 0;
}
// 插入元素
void insert(node* head, int pos, int x) {
	//插到pos位置 例 原 5 3 6 1 2 pos=3 x=4 后 5 3 '4' 6 1 2
	node* p = head;
	for(int i=0; i<pos-1; i++) {
		p = p->next;  //p为插入位置的前个节点
	}
	node* q = new node;
	q->data = x;
	q->next = p->next;
	p->next = q;
}
// 删除元素
void del(node* head, int x) {
	node* pre = head;
	node* p = head->next;
	while(p != NULL) {
		if(p->data == x) {
			pre->next = p->next;
			delete(p);
			p = p->next;
		}else {
			pre = p;
			p = p->next;
		}
	}
}
// 静态链表
struct Node{
	typename data;
	int next;
}node[size];

// 例 PAT-A-1032 p261
(待)
// 例 PAT-A-1052 p265
(待)