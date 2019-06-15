//From wangfy
#include <cstdio>
#include <map>
#include <cstring>
#include <string>
using namespace std;

int main() {
    map<string,bool>mapp;
    char s[20];
    int n1;
    scanf("%d ",&n1);
    for(int i=0; i<n1; i++) {
        gets(s);    
        if(mapp.find(s) == mapp.end()) mapp[s] = true;
    }
    printf("------");
    int n2;
    scanf("%d ",&n2);
    for(int i=0; i<n2; i++) {
        gets(s);    
        if(mapp.find(s) == mapp.end()) printf(">> %s\n",s);
    }

    return 0;
}