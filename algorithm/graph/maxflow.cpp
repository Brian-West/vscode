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

const int MAXV=210;
const int INF=10e8;
int gap[MAXV], pre[MAXV], level[MAXV];
int cap[MAXV][MAXV];

void addEdge(int u, int v, int c) {
    cap[u][v]+=c;
}

int sap(int s, int t) {
    memset(gap, 0, sizeof(gap));
    memset(pre, -1, sizeof(pre));
    memset(level, 0, sizeof(level));
    gap[0]=t;
    int v, u=pre[s]=s, maxflow=0;
    while(level[s]<t) {
        for(v=1;v<=t;v++) {
            if(cap[u][v]&&level[u]==level[v]+1) {   //找到v了，(u,v)为可行弧
                break;
            }
        }
        if(v<=t) {      //找到了可行弧
            pre[v]=u; u=v;
            if(v==t) {      //如果已经找到完整的一条增益路径
                int aug=INF;
                for(int i=v;i!=s;i=pre[i])  //回退整条路径
                    if(aug>cap[pre[i]][i]) aug=cap[pre[i]][i];
                maxflow+=aug;
                for(int i=v;i!=s;i=pre[i]) {
                    cap[pre[i]][i]-=aug;
                    cap[i][pre[i]]+=aug;
                }
                u=s;    //从源点再次找增益路径，因为已经找到过一条完整的路径了
            }
        } else {    //找不到可行弧。第一次循环就是这种情况因为level数组没有确定
            int minlevel=t;
            for(v=1;v<=t;v++)
                if(cap[u][v]&&minlevel>level[v])
                    minlevel=level[v];
            if(--gap[level[u]]==0)
                break;
            level[u]=minlevel+1;
            gap[level[u]]++;
            u=pre[u];   //回退一个点找另外的可行弧，如果回退的太多会导致gap值为0
        }
    }
    return maxflow;
}

int main() {
    for(int i=0;i<MAXV;i++) {
        for(int j=0;j<MAXV;j++) {
            cap[i][j]=0;
        }
    }
    int n,m;
    int source[MAXV],dest[MAXV];
    memset(source,0,sizeof(source));
    memset(dest,0,sizeof(dest));
    while(cin>>n>>m) {
        int s,e,c;
        while(n-- >0) {
            cin>>s>>e>>c;
            dest[s]=1;
            source[e]=1;
            addEdge(s,e,c);
        }
        int sou,des;
        for(int i=1;i<=m;i++) {
            if(source[i]==0)
                sou=i;
            if(dest[i]==0)
                des=i;
        }
        cout<<sap(sou,des)<<endl;
    }
    // addEdge(0+1,1+1,2);
    // addEdge(0+1,3+1,3);
    // addEdge(1+1,4+1,3);
    // addEdge(1+1,2+1,5);
    // addEdge(3+1,2+1,1);
    // addEdge(2+1,5+1,2);
    // addEdge(4+1,5+1,4);

    

    return 0;
}