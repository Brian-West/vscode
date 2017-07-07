#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

const int MAX_INST=320;
int instructions[MAX_INST];

void FIFO(int physical_size, int head, int tail) { //physical_size指定内存页数，head和tail代表指令序列的头和尾
    int* myqueue=new int[physical_size];
    double hit=0;
    int count=0;
    for(int i=head; i<tail; i++) {
        bool exist=false;
        for(int j=0; j<count; j++) {
            if(myqueue[j]==instructions[i]/10) {
                exist=true;
                break;
            }
        }
        if(exist==true) {
            hit++;
            //printf("Without page fault.\n");
        } else {
            if(count<10) {
                myqueue[count]=instructions[i]/10;
                count++;
                //printf("Without page replacement.\n");
            } else {
                for(int j=1; j<count; j++) {
                    myqueue[j-1]=myqueue[j];
                }
                myqueue[count-1]=instructions[i]/10;
                //printf("With page replacement\n");
            }
        }
        for(int i=0; i<count; i++) {
            //printf("%d  ",myqueue[i]);
        }
        //printf("\n");
    }
    printf("\nThe hit rate is %f\n",hit/(tail-head));
}

void LRU(int physical_size, int head, int tail) { //physical_size指定内存页数，head和tail代表指令序列的头和尾
    int* lruqueue=new int[physical_size];
    double hit=0;
    int count=0;
    for(int i=head; i<tail; i++) {
        bool exist=false;
        for(int j=0; j<count; j++) {
            if(lruqueue[j]==instructions[i]/10) {
                exist=true;
                int temp=lruqueue[j];
                for(int k=j+1; k<count; k++) {
                    lruqueue[k-1]=lruqueue[k];
                }
                lruqueue[count-1]=temp;
                break;
            }
        }
        if(exist==true) {
            hit++;
            //printf("Without page fault.\n");
        } else {
            if(count<10) {
                lruqueue[count]=instructions[i]/10;
                count++;
                //printf("Without page replacement.\n");
            } else {
                for(int j=1; j<count; j++) {
                    lruqueue[j-1]=lruqueue[j];
                }
                lruqueue[count-1]=instructions[i]/10;
                //printf("With page replacement.\n");
            }
        }
        for(int i=0; i<count; i++) {
            //printf("%d  ",lruqueue[i]);
        }
        //printf("\n");
    }
    printf("\nThe hit rate is %f\n",hit/(tail-head));
}

int main() {
    for(int i=0; i<MAX_INST; i+=6) {
        srand(clock());
        int m=rand()%MAX_INST;
        instructions[i]=m;
        instructions[i+1]=m+1;
        instructions[i+2]=m+2;
        int _m=rand()%(m+1);
        instructions[i+3]=_m;
        instructions[i+4]=_m+1;
        instructions[i+5]=319-_m-3+rand()%(_m+4);
    }
    cout<<"begin debuging\n";

//    for(int i=0;i<10;i++){
//	cout<<"aaa"<<endl;
//    }

    /*printf("These are the input instructions:\n");
    for(int i=0;i<30;i++){
        printf("%d  ",instructions[i]);
    }
    printf("\n");*/

    //FIFO(10,0,30);
//    for(int i=4;i<32;i++){
//       LRU(i,i,i+40);
//    }
//    printf("---------------------");
//    for(int i=4;i<32;i++){
//       FIFO(i,i,i+40);
//    }
    //LRU(10,0,30);

    LRU(20,0,320);
    FIFO(20,0,320);
   
    return 0;
}
