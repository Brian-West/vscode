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

const int MAXV=210;  //最多MAXV个点
const int MAXE=200000;  //最多MAXE个边，无向图要x2
const int INF=10e8;
int gap[MAXV], pre[MAXV], level[MAXV];

struct Edge{    //边
    int to, next;
    int cap, flow;
};

Edge E[MAXE];
int head[MAXV],numE;

void init(){    //初始化
    numE = 0;
    memset(head,-1,sizeof(head));
}

void addEdge(int u, int v, int c, int rc=0) {   //// 单向边三个参数,双向边四个。
    E[numE].to=v; E[numE].cap=c; E[numE].flow=0; E[numE].next=head[u]; head[u]=numE++;
    E[numE].to=u; E[numE].cap=rc; E[numE].flow=0; E[numE].next=head[v]; head[v]=numE++;
}

int sap(int s, int t) {
    memset(gap, 0, sizeof(gap));
    memset(pre, -1, sizeof(pre));
    memset(level, 0, sizeof(level));
    gap[0]=t;
    int v, i, u=s, maxflow=0;
    while(level[s]<t) {
        for(i=head[u];i!=-1;i=E[i].next) {
            v=E[i].to;
            if(E[i].cap-E[i].flow && level[u]==level[v]+1)
                break;
        }
        if(v<=t) {
            pre[v]=i; u=v;
            if(v==t) {
                int aug=INF;
                for(int i=pre[v];i!=-1;i=pre[E[i^1].to])
                    aug=min(aug, E[i].cap-E[i].flow);
                maxflow+=aug;
                for(int i=pre[v];i!=-1;i=pre[E[i^1].to]) {
                    E[i].flow+=aug;
                    E[i^1].flow-=aug;
                }
                u=s;
            }
        } else {
            int minlevel=t;
            for(int i=head[u];i!=-1;i=E[i].next)
                if(E[i].cap-E[i].flow && minlevel>level[E[i].to])
                    minlevel=level[E[i].to];
            if(--gap[level[u]]==0)
                break;
            level[u]=minlevel+1;
            gap[level[u]]++;
            if(u!=s) u=E[pre[u]^1].to;
        }
    }
    return maxflow;
}

int main() {
    init();
    addEdge(0+1,1+1,2);
    addEdge(0+1,3+1,3);
    addEdge(1+1,4+1,3);
    addEdge(1+1,2+1,5);
    addEdge(3+1,2+1,1);
    addEdge(2+1,5+1,2);
    addEdge(4+1,5+1,4);

    cout<<sap(1,6)<<endl;

    return 0;
}