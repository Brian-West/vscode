#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAX_ANS=20000;
const int INF=999999999;
int N,M;
int a[105],b[105],f[105][105];
void _init()
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
	    scanf("%d%d",&a[i],&b[i]);
}
bool _can_match(int d)        
{
	for(int i=0;i<=N;i++)    
	    for(int j=0;j<=M;j++)
	        f[i][j]=-INF;
	for(int i=0;i*a[1]<=d;i++)
	    f[1][i]=(d-a[1]*i)/b[1];
	for(int i=2;i<=N;i++)
	    for(int j=0;j<=M;j++)
	        for(int x=0;x*a[i]<=d&&x<=j;x++)
	            f[i][j]=max(f[i][j],f[i-1][j-x]+(d-x*a[i])/b[i]);
	return (f[N][M]>=M);
}
void _solve()
{
	int Left=0,Right=MAX_ANS,Mid,ans;
	while(Left<=Right)        
	{
		Mid=(Left+Right)>>1;
		if(_can_match(Mid))
		{
			ans=Mid;
			Right=Mid-1;
		}
		else
		    Left=Mid+1;
	}
	printf("%d\n",ans);
}
int main()
{
	_init();
	_solve();
	return 0;
}