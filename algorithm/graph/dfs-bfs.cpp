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

const int MAXV=100000;  //最多MAXV个点
const int MAXE=200000*2;  //最多MAXE个边，无向图要x2

struct Edge{    //边
    int to, next;
    int cost;
};

Edge E[MAXE];
int head[MAXV],numE;

void init(){    //初始化
    numE = 0;
    memset(head,-1,sizeof(head));
}

void addEdge(int u, int v, int c) {     //加一条从u到v的权重为c的边
    E[numE].to = v;
    E[numE].cost = c;
    E[numE].next = head[u];
    head[u] = numE++;
}

void addEdge_double(int u, int v, int c) {
    addEdge(u,v,c);
    addEdge(v,u,c);
}

void findu(int u) {     //找到点u能到的所有点
    for(int i=head[u];i!=-1;i=E[i].next) {
        cout<<E[i].to<<' '<<E[i].cost<<endl;
    }
}

//无向图的深度优先搜索和广度优先搜索

bool visited[MAXV];
void dfs(int u) {
    cout<<u<<' ';
    visited[u]=1;
    for(int i=head[u];i!=-1;i=E[i].next) {
        if(visited[E[i].to]==0)
            dfs(E[i].to);
    }
}

void bfs(int u) {
    memset(visited,0,sizeof(visited));
    visited[u]=1;
    queue<int> q;
    q.push(u);
    int p;
    while(!q.empty()) {
        p=q.front();
        cout<<p<<' ';
        q.pop();
        for(int i=head[p];i!=-1;i=E[i].next) {
            if(visited[E[i].to]==0) {
                q.push(E[i].to);
                visited[E[i].to]=1;
            }
        }
    }
}

//求有向图传递闭包。稀疏图适用。前向星+dfs或bfs
bool closure[6][6];

void _bfs(int root) {
    memset(visited,0,sizeof(visited));
    visited[root]=1;
    queue<int> q;
    q.push(root);
    int p;
    while(!q.empty()) {
        p=q.front();q.pop();
        for(int i=head[p];i!=-1;i=E[i].next) {
            if(visited[E[i].to]==0) {
                q.push(E[i].to);
                visited[E[i].to]=1;
                closure[root][E[i].to]=1;
            }
        }
    }
}

void transitive_closure() {
    memset(closure,0,sizeof(closure));
    for(int i=0;i<6;i++) {
        _bfs(i);
    }
    for(int i=0;i<6;i++) {
        for(int j=0;j<6;j++) {
            cout<<closure[i][j]<<' ';
        }
        cout<<endl;
    }
}

int main(){
    init();
    // addEdge_double(0,1,1);
    // addEdge_double(0,2,1);
    // addEdge_double(0,3,1);
    // addEdge_double(1,2,1);
    // addEdge_double(1,3,1);
    // addEdge_double(2,5,1);
    // addEdge_double(2,4,1);
    // addEdge_double(3,4,1);
    // addEdge_double(4,5,1);

    // dfs(0);
    // cout<<endl;
    // bfs(0);
    // cout<<endl;

    addEdge(0,1,1);
    addEdge(0,2,1);
    addEdge(0,3,1);
    addEdge(1,2,1);
    addEdge(1,3,1);
    addEdge(2,5,1);
    addEdge(2,4,1);
    addEdge(3,4,1);
    addEdge(4,5,1);

    transitive_closure();

    return 0;
}
