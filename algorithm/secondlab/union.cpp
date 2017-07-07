#include <stdio.h>
#include <iostream>
using namespace std;

int t=0;
int n=0,m=0;
const int MAX=1000;
int a[MAX];
int b[MAX];

int main(){
	scanf("%d",&t);
	for(int p=0;p<t;p++){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",a+i);
		}
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			scanf("%d",b+i);
		}
		
		for(int i=0;i<m;i++){
			bool flag=0;
			for(int j=0;j<n;j++){
				if(b[i]==a[j]){
					flag=true;
					break;
				}
			}
			if(!flag){
				a[n]=b[i];
				n++;
			}
		}
		for(int i=0;i<n;i++){
			if(i==n-1)
				printf("%d\n",a[i]);
			else
				printf("%d ",a[i]);
		}
	}
	
	system("pause");
	return 0;
}