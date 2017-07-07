#include <iostream>
#include <stack>
using namespace std;

int main() {
    char ch[101];
    stack<char> sta;
    cin.getline(ch,101);
    for(int i=0;i<101;i++) {
        if(ch[i]!='\0') {
            sta.push(ch[i]);
        }
        else{
            break;
        }
    }
    int len=sta.size();
    for(int i=0;i<len;i++) {
        cout<<sta.top();
        sta.pop();
    }

    return 0;
}