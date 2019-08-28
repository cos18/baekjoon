#include <stdio.h>
#include <math.h>

int main(){
    long long num;
    scanf("%lld", &num);
    int trying = num, count[1000]={}, i = 0;
    while(1){
        int sum = trying;
        count[i++] = trying;
        trying = 0;
        while(sum){
            trying += pow((sum%10), 2);
            sum /= 10;
        }
        if(trying == 1){
            printf("HAPPY");
            return 0;
        }
        for(int j=0;j<i;j++){
            if(trying == count[j]){
                printf("UNHAPPY");
                return 0;
            }
        }
    }
}