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
vector<int> graph[MAXV];
bool visited[MAXV]={0};

void addEdge(int u, int v) {
    graph[u].push_back(v);
}

stack<int> sta;
void topsort(int root) {
    visited[root]=1;
    int len=graph[root].size();
    for(int i=0;i<len;i++) {
        int v=graph[root][i];
        if(!visited[v])
            topsort(v);
    }
    sta.push(root);
}

int cnt[MAXV];
void topsort_queue() {
    queue<int> que;
    int n=6;
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++) {
        int len=graph[i].size();
        for(int j=0;j<len;j++) {
            cnt[graph[i][j]]++;
        }
    }
    for(int i=0;i<n;i++) {
        if(cnt[i]==0)
            que.push(i);
    }
    while(!que.empty()) {
        int v=que.front(); que.pop();
        cout<<v<<' ';
        int len=graph[v].size();
        for(int i=0;i<len;i++) {
            if(--cnt[graph[v][i]]==0)
                que.push(graph[v][i]);
        }
    }
}

int main() {
    addEdge(0,1);
    addEdge(0,2);
    addEdge(0,3);
    addEdge(1,2);
    //addEdge(1,3);
    addEdge(2,5);
    addEdge(2,4);
    addEdge(3,4);
    addEdge(4,5);

    topsort(0);
    int len=sta.size();
    for(int i=0;i<len;i++) {
        cout<<sta.top()<<' ';
        sta.pop();
    }
    cout<<endl;

    topsort_queue();
    cout<<endl;

    return 0;
}