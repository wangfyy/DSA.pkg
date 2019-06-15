//相较于通过10进制，通过二进制可以处理长数据
#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
using namespace std; 

int N;

int main() {
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        string str1, str2 = "";
        cin>>str1;
        for(int j=0; j<str1.length(); j++) {
            switch(str1[j]) {
                case '0' : str2 +="0000"; break;
                case '1' : str2 +="0001"; break;
                case '2' : str2 +="0010"; break;
                case '3' : str2 +="0011"; break;
                case '4' : str2 +="0100"; break;
                case '5' : str2 +="0101"; break;
                case '6' : str2 +="0110"; break;
                case '7' : str2 +="0111"; break;
                case '8' : str2 +="1000"; break;
                case '9' : str2 +="1001"; break;
                case 'A' : str2 +="1010"; break;
                case 'B' : str2 +="1011"; break;
                case 'C' : str2 +="1100"; break;
                case 'D' : str2 +="1101"; break;
                case 'E' : str2 +="1110"; break;
                case 'F' : str2 +="1111"; break;
                default:break;  
            }
        }
        int len2 = str2.length();
        if(len2 % 3 == 1) {
    		str2 = "00" + str2;
        } else if(len2 % 3 == 2) {
    		str2 = "0" + str2;
        }
        len2 = str2.length();
        for(int j=0; j<=len2 - 3; j+=3) {
            int num = 4 * (str2[j] - '0') + 2 * (str2[j+1] - '0') + (str2[j+2] - '0');
            if(num == 0 && j == 0) {
                continue;
            }
            printf("%d",num);
        }
        printf("\n");
    }

    return 0;
}