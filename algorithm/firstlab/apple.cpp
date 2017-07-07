#include<stdio.h>

int main(){
	int a[10];
	for (int i = 0; i < 10; i++){
		scanf("%d",a+i);
	}
	int b = 0;
	scanf("%d", &b);
	int count=0;
	for (int i = 0; i < 10; i++){
		if (b + 30 >= a[i])
			count++;
	}
	printf("%d", count);
	return 0;
}