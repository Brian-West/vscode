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

//链式前向星实现图

const int MAXV=100000;  //最多MAXV个点
const int MAXE=200000;  //最多MAXE个边，无向图要x2

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

//前向星加优先队列实现单源最短路径算法
int d[5],p[5];      //最短路径数组和前驱数组
struct Node{
    int v,val;
    Node(int _v = 0, int _val = 0) :v(_v), val(_val) {}
    bool operator < (const Node &a) const {
        return val>a.val;
    }
};
const int INF=999999;
int visited[MAXV];
void dijkstra(int root) {
    memset(visited, 0, sizeof(visited));
    priority_queue<Node> que;
    memset(d, INF, sizeof(d));
    memset(p, -1, sizeof(p));
    d[root] = 0;
    que.push(Node(root, 0));
    while(!que.empty()) {
        Node node = que.top(); que.pop();
        int u = node.v;
        if(visited[u]) continue;    //???
        visited[u] = 1;
        for (int i = head[u]; i != -1; i = E[i].next) {
            int v=E[i].to,cost=E[i].cost;
            if (!visited[v] && d[v] > d[u] + cost) {
                d[v] = d[u] + cost;
                p[v] = u;
                que.push(Node(v, d[v]));
            }
        }
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

    // for(int i=0;i<6;i++){
    //     cout<<i<<endl;
    //     findu(i);
    // }

    addEdge_double(0,1,1);
    addEdge_double(0,4,2);
    addEdge_double(1,2,3);
    addEdge_double(1,3,4);
    addEdge_double(3,4,5);

    dijkstra(1);
    for(int i=0;i<5;i++) {
        cout<<d[i]<<' ';
    }
    cout<<endl;

    return 0;
}