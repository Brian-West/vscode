#include<cstdio>  
#include<cstdlib>
#include<iostream>
#include<cstring>  
#include<string>
#include<cmath>
#include<algorithm>  
#include<vector>  
#include<stack>  
#include<bitset>  
#include<set>  
#include<list>  
#include<deque>  
#include<map>  
#include<queue>  
using namespace std;

int main() {
    char my[16];
    cin.getline(my,16);
    char mask[16];
    cin.getline(mask,16);
    int myint[4];
    int maskint[4];
    memset(myint,0,sizeof(myint));
    memset(maskint,0,sizeof(maskint));
    int dot=0;
    int temp=0;
    for(int i=0;i<16;i++) {
        if(my[i]=='.') {
            myint[dot]=temp;
            temp=0;
            dot++;
            continue;
        }
        if(my[i]=='\0') {
            myint[dot]=temp;
            break;
        }
        int cmp=my[i]-'0';
        temp=temp*10+cmp;
    }
    dot=0;
    temp=0;
    for(int i=0;i<16;i++) {
        if(mask[i]=='.') {
            maskint[dot]=temp;
            temp=0;
            dot++;
            continue;
        }
        if(mask[i]=='\0') {
            maskint[dot]=temp;
            break;
        }
        temp=temp*10+(mask[i]-'0');
    }
    int n;
    cin>>n;
    char test[16];
    cin.getline(test,16);
    while(n-- >0) {
        cin.getline(test,16);
        dot=0;
        temp=0;
        int testint[4];
        for(int i=0;i<16;i++) {
            if(test[i]=='.') {
                testint[dot]=temp;
                temp=0;
                dot++;
                continue;
            }
            if(test[i]=='\0') {
                testint[dot]=temp;
                break;
            }
            temp=temp*10+(test[i]-'0');
        }
        int  i=0;
        bool flag=1;
        for(;i<4;i++) {
            int a=myint[i]&maskint[i], b=testint[i]&maskint[i];
            if(a!=b) {
                flag=0;
                break;
            }
        }
        if(flag) {
            cout<<"INNER\n";
        } else {
            cout<<"OUTER\n";
        }
    }
    return 0;
}