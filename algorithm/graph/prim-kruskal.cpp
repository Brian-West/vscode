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

//邻接表加优先队列实现prim算法
const int MAXV=101;
int visited[MAXV];
struct Node {
    int v,val;
    Node(int _v = 0, int _val = 0) :v(_v), val(_val) {}
    bool operator < (const Node &a) const {
        return val>a.val;
    }
};
struct Edge {
    int v,cost;
    Edge(int _v = 0, int _cost = 0) :v(_v), cost(_cost) {}
};
vector<Edge> E[MAXV];

void addEdge(int u, int v, int cost) {
    E[u].push_back(Edge(v, cost));
    E[v].push_back(Edge(u, cost));
}

int prim(int root) {
    int ans=0;
    memset(visited, 0, sizeof(visited));
    visited[root]=1;
    priority_queue<Node> que;
    int len=E[root].size();
    for(int i=0; i<len; i++) {
        int v=E[root][i].v, cost=E[root][i].cost;
        que.push(Node(v, cost));
    }
    while(!que.empty()) {
        Node node=que.top(); que.pop();
        int v=node.v;
        if(visited[v]) continue;
        visited[v]=1; ans+=node.val;
        len=E[v].size();
        for(int i=0; i<len; i++) {
            int u=E[v][i].v, cost=E[v][i].cost;
            que.push(Node(u, cost));
        }
    }
    return ans;
}

//并查算法加优先队列实现kruskal算法
int fa[MAXV];
int find(int i) {
    if(fa[i]==i) return i;
    return fa[i]=find(fa[i]);
}
// void union(int u, int v) {
//     if(find(u)!=find(v)) {
//         fa[u]=v;
//     }
// }

struct Edge_kru {
    int u,v,cost;
    Edge_kru(int _u, int _v, int _cost):u(_u), v(_v), cost(_cost) {}
    bool operator < (const Edge_kru &a) const {
        return cost>a.cost;
    }
};
priority_queue<Edge_kru> que_kru;
void addEdge_kru(int u, int v, int cost) {
    que_kru.push(Edge_kru(u, v, cost));
}
int kruskal() {
    int ans=0;
    for(int i=0;i<6;i++) {
        fa[i]=i;
    }
    while(!que_kru.empty()) {
        Edge_kru edge = que_kru.top(); que_kru.pop();
        int u=edge.u, v=edge.v, cost=edge.cost;
        if(find(u)!=find(v)) {
            ans+=cost;
            fa[u]=v;
        }
    }
    return ans;
}

int main() {
    addEdge(0,1,3);
    addEdge(0,5,5);
    addEdge(0,4,6);
    addEdge(1,2,1);
    addEdge(1,5,4);
    addEdge(2,3,6);
    addEdge(2,5,4);
    addEdge(3,4,8);
    addEdge(3,5,5);
    addEdge(4,5,2);
    
    cout<<prim(0)<<endl;

    addEdge_kru(0,1,3);
    addEdge_kru(0,5,5);
    addEdge_kru(0,4,6);
    addEdge_kru(1,2,1);
    addEdge_kru(1,5,4);
    addEdge_kru(2,3,6);
    addEdge_kru(2,5,4);
    addEdge_kru(3,4,8);
    addEdge_kru(3,5,5);
    addEdge_kru(4,5,2);

    cout<<kruskal()<<endl;

    return 0;
}