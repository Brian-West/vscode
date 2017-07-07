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

//单源最短路径算法
const int INF=999999;
const int MAXV=100000;  //最多MAXV个点
const int MAXE=200000*2;  //最多MAXE个边，无向图要x2
int d[5],p[5];      //最短路径数组和前驱数组
struct Node{
    int v,val;
    Node(int _v = 0, int _val = 0) :v(_v), val(_val) {}
    bool operator < (const Node &a) const {
        return val>a.val;
    }
};
struct Edge{
    int v,cost;
    Edge(int _v = 0, int _cost = 0) :v(_v), cost(_cost) {}
};
int visited[MAXV];
vector<Edge> E[MAXE];       //图的邻接表形式

void dijsktra(int root) {
    //初始化最短路径数组和前驱数组
    memset(d, INF, sizeof(d));
    memset(p, -1, sizeof(p));
    memset(visited, 0, sizeof(visited));
    d[root] = 0;
    priority_queue<Node> que;
    que.push(Node(root, 0));
    while(!que.empty()) {
        Node node = que.top(); que.pop();
        int u = node.v;
        if(visited[u]) continue;    //???
        visited[u] = 1;
        int len = E[u].size();
        for (int i = 0; i < len; i++) {
            int v=E[u][i].v,cost=E[u][i].cost;
            if (!visited[v] && d[v] > d[u] + cost) {
                d[v] = d[u] + cost;
                p[v] = u;
                que.push(Node(v, d[v]));
            }
        }
    }
}

void addEdge(int u,int v,int cost) {
    E[u].push_back(Edge(v,cost));
    E[v].push_back(Edge(u,cost));      //无向图
}

int main() {
    addEdge(0,1,1);
    addEdge(0,4,2);
    addEdge(1,2,3);
    addEdge(1,3,4);
    addEdge(3,4,5);

    dijsktra(1);
    for(int i=0;i<5;i++) {
        cout<<d[i]<<' ';
    }
    cout<<endl;

    return 0;
}