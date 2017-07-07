#include <iostream>
using namespace std;

int main() {
    int n=0;
    int array[10][10];
    int t=0;
    while(cin>>n) {
        if(t!=0) {
            cout<<endl;
        }
        array[0][0]=1;
        array[1][0]=1;
        array[1][1]=1;
        if(n>2) {
            for(int i=2;i<n;i++) {
                for(int j=0;j<=i;j++) {
                    if(j==0||j==i) {
                        array[i][j]=1;
                    }
                    else{
                        array[i][j]=array[i-1][j-1]+array[i-1][j];
                    }
                }
            }
        }
        int level=0;
        for(int i=n-1;i>=0;i--) {
            for(int k=0;k<level;k++) {
                cout<<' ';
            }
            for(int j=0;j<=i;j++) {
                cout<<array[i][j];
                if(j!=i) {
                    cout<<' ';
                }
            }
            if(i!=0) cout<<endl;
            level++;
        }
        t++;
    }

    return 0;
}