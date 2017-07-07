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
    long long a, b;
    while(cin>>a>>b) {
        if(a == b) {
            cout<<"Lan\n";
        }
        else {
            if(a < b) {
                int temp=a;
                a=b;
                b=temp;
            }
            if((a/b)!=1) {
                cout<<"Lan\n";
            } else {
                cout<<"Lv\n";
            }
        }
    }

    return 0;
}