#include <iostream>
using namespace std;

const int N=101;
int matrix[N][N];

int main() {
    int n=0;
    while(cin>>n) {
        int max=n*(1+n)/2;
        int begin=1;
        for(int i=0;i<n;i++) {
            int j=0;
            matrix[i][j]=begin;
            begin++;
            int k=i;
            while(k!=0) {
                k-=1; j+=1;
                matrix[k][j]=begin;
                begin++;
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n-i;j++) {
                cout<<matrix[i][j];
                if(j!=n-i-1)
                    cout<<' ';
                else
                    cout<<endl;
            }
        }
    }
    return 0;
}