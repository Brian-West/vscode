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

const int MAXV=100;  //最多MAXV个点
const int INF=100;

//求传递闭包的warshall算法
bool closure[MAXV][MAXV];
int n=0;

void addEdge(int u,int v) {
    closure[u][v]=1;
}

void warshall() {
    for(int k=0;k<n;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                closure[i][j]=closure[i][j]|closure[i][k]&closure[k][j];
            }
        }
    }
}

//求任意两点间最短路径值的Floyd算法
int cost[MAXV][MAXV];

void addCost(int u,int v,int c) {
    cost[u][v]=c;
}

void floyd() {
    for(int k=0;k<n;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
            }
        }
    }
}

int main() {
    n=4;

    //warshall
    for(int i=0;i<n;i++) {
        memset(closure[i],0,sizeof(closure[i]));
    }
    addEdge(0,1);
    addEdge(1,3);
    addEdge(3,0);
    addEdge(3,2);

    warshall();

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout<<closure[i][j]<<' ';
        }
        cout<<endl;
    }

    //floyd
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i==j)
                cost[i][j]=0;
            else
                cost[i][j]=INF;
        }
    }
    addCost(0,2,3);
    addCost(1,0,2);
    addCost(2,1,7);
    addCost(2,3,1);
    addCost(3,0,6);

    floyd();

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout<<cost[i][j]<<' ';
        }
        cout<<endl;
    }

    return 0;
}