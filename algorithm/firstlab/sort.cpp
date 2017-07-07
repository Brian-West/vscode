#include<stdio.h>

int main(){
	int a[10];
	for(int i=0;i<10;i++){
		scanf("%d",a+i);
	}
	for(int i=0;i<10;i++){
		int k=i;
		for(int j=i+1;j<10;j++){
			if(a[k]>a[j])
				k=j;
		}
		int temp=a[i];
		a[i]=a[k];
		a[k]=temp;
	}
	for(int i=0;i<10;i++){
		if(i<9)
			printf("%d\n",a[i]);
		else
			printf("%d",a[i]);
	}
	return 0;
}