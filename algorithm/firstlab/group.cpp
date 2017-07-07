#include <stdio.h>

int partition(int* a,int head,int tail){
	int p=a[head];
	int s=head;
	for(int i=head+1;i<=tail;i++){
		if(a[i]<p){
			s++;
			int temp=a[s];
			a[s]=a[i];
			a[i]=temp;
		}
	}
	int temp=a[head];
	a[head]=a[s];
	a[s]=temp;
	return s;
/*	int p=a[head];
	int i=head,j=tail+1;
	while(i<j){
		do
			i++;
		while(a[i]<=p);
		do 
			j--;
		while(a[j]>=p);
		int temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		temp=a[head];
		a[head]=a[j];
		a[j]=temp;
	}
	return j;
	*/
}

void sort(int* a,int head,int tail){
	if(head<tail){
		int s=partition(a,head,tail);
		sort(a,head,s-1);
		sort(a,s+1,tail);
	}
}

int main(){
	int up=0;
	scanf("%d",&up);
	int sum=0;
	scanf("%d",&sum);
	int value[30000];
	for(int i=0;i<sum;i++)
		scanf("%d",value+i);
	int out=0;
	//先排序，然后两头夹击
	sort(value,0,sum-1);
	int head=0;
	int tail=sum-1;
	while(head<=tail){
		if(head==tail){
			out++;
			break;
		}
		else{
			if(value[head]+value[tail]<=up){
				head++;
				tail--;
				out++;
			}
			else{
				tail--;
				out++;
			}
		}
	}
	printf("%d",out);

	return 0;
}