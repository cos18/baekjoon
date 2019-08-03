#include <stdio.h>
#include <string.h>

int main(){
    int n, anj=0;
    char name[100];
    scanf("%d", &n);
    while(n--){
        scanf(" %s", &name);
        if(!strcmp("anj", name)) anj=1;
    }
    printf("%s", anj?"뭐야;":"뭐야?");
}