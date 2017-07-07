#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
    char line[1001];
    int n=0;
    cin>>n;
    int cnt=0;
    cin.getline(line,1001);
    while(cin.getline(line,1001)){
        cnt++;
        if(cnt<=n) {
            cout<<line<<endl<<endl;
        }
        else {
            for(int i=0;i<1001;i++) {
                if(line[i]=='\0') {
                    cout<<endl<<endl;;
                    break;
                }
                if(line[i]!=' '&&line[i]!='\r') {
                    cout<<line[i];
                }
                else {
                    cout<<endl<<endl;
                }
            }
        }
    }
    return 0;
}