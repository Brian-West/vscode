#include <iostream>
#include <cmath>
using namespace std;

const int MAX=10000001;
int prime[MAX];

int main() {
    prime[1]=0;
    for(int i=2;i<MAX;i++) {
        prime[i]=1;
    }
    for(int i=2;i<=sqrt(MAX);i++) {
        if(prime[i]==1) {
            for(int j=i*i;j<MAX;j+=i) {
                prime[j]=0;
            }
        }
    }
    for(int i=2;i<MAX;i++) {
        if(prime[i]) {
            prime[i]=prime[i-1]+1;
        } else {
            prime[i]=prime[i-1];
        }
    }
    int a,b;
    while(cin>>a>>b) {
        if(a==1) cout<<prime[b]<<endl;
        else cout<<prime[b]-prime[a-1]<<endl;
    }

    return 0;
}