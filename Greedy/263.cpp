#include <iostream>
using namespace std;


#include<stdio.h>
int main() {
    long long int x,i,a,b,t,h,arm;
    scanf("%lld",&x);
    for(i=0;i<x;i++){
        scanf("%lld %lld",&a,&b);
        if(a==0||b==0)
         printf("0\n");
        else{
            t=1;
            h=a+3;
            arm=b+2;
            while(1){
                if(h>5&&arm>10){
                    h=h-2;
                    arm=arm-8;
                    t=t+2;
                }else if(h>20&&arm<=10){
                    h=h-17;
                    arm=arm+7;
                    t=t+2;
                }else {
                    printf("%lld\n",t);
                    break;
                }
            }
     }
    }
    return 0;
} 