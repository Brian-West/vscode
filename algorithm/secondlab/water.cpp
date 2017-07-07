#include <stdio.h>

int main(){
	int n=0;
	scanf("%d",&n);
	while(n!=0){
		if(n<2)
			printf("%d",0);
		else if(n==2)
			printf("%d",1);
		else{
			int sum=0;
			while(n>2){
				int q=n/3;
				int r=n%3;
				sum+=q;
				n=q+r;
			}
			if(n==2)
				sum++;
			printf("%d",sum);
			
		}
		scanf("%d",&n);
		if(n!=0)
			printf("\n");
	}

	return 0;
}