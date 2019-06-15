//给定层序中序，求先序后序
//code:
#include <cstdio>
const int maxn = 10010;
int n, num, layer[maxn], in[maxn];
struct tree {
    tree *l, *r;
    int data;
};
void PreOrder(tree* root) {
    if(root != NULL) {
        printf("%d",root->data);
        num++;
        if(num != n) printf(" ");
        PreOrder(root->l);
        PreOrder(root->r);
    }
}
void PostOrder(tree * root) {
    if(root != NULL) {
        PostOrder(root->l);
        PostOrder(root->r);
        printf("%d",root->data);
        num++;
        if(num != n) printf(" ");
    }
}
tree* CreateTree(int* layer, int* in, int t) {  //t为当前数组(layer,in)的元素个数
    if(t == 0) return NULL;
    int Llayer[maxn], Rlayer[maxn];
    int Lin[maxn], Rin[maxn];
    tree* node = new tree;
    node->data = layer[0];
    // 在in数组中找出当前根结点的位置
    int i;
    for(i = 0; i < t; i++)
        if(in[i] == layer[0])
            break;
    // 找出in数组中的左子树和右子树
    int cnt = 0;  //count
    for(int j = 0; j < i ; j++)
        Lin[cnt++] = in[j];
    cnt = 0;
    for(int j = i+1; j < t; j++)
        Rin[cnt++] = in[j];
    cnt--;
    // 找出layer数组中的左子树和右子树
    int Llayercnt = 0;
    int Rlayercnt = 0;
    for(int j = 1; j < t ; j++)
        for(int k = 0 ; k < i ; k++)
            if(layer[j] == in[k])
                Llayer[Llayercnt++] = layer[j];
    for(int j = 1; j < t; j++)
        for(int k = i ; k < t; k++)
            if(layer[j] == in[k])
                Rlayer[Rlayercnt++] = layer[j];
    node->l = CreateTree(Llayer,Lin,Llayercnt);
    node->r = CreateTree(Rlayer,Rin,Rlayercnt);
    return node;
}
int main() {
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",&layer[i]);
    for(int i=0; i<n; i++) scanf("%d",&in[i]);
    tree* root = CreateTree(layer,in,n);
    num = 0;
    PreOrder(root);
    printf("\n");
    num = 0;
    PostOrder(root);
    return 0;
}