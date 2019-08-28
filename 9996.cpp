#include <stdio.h>
#include <string.h>

int main(){
    int N, loc=0, patternlen, frontlen, backlen;
    char pattern[101], input[101], front[101], back[101];
    scanf("%d", &N);
    getchar();
    gets(pattern);
    while(1){
        if(pattern[loc]=='*') break;
        loc++;
    }
    pattern[loc] = '\0';
    strcpy(front, pattern);
    frontlen = strlen(front);
    strcpy(back, pattern+loc+1);
    backlen = strlen(back);
    patternlen = frontlen + backlen;
    while(N--){
        gets(input);
        int inputlen = strlen(input);
        if(patternlen>inputlen || strcmp(back, input+(inputlen-backlen))!=0){
            printf("NE\n");
            continue;
        }
        input[frontlen]='\0';
        if(strcmp(front, input)!=0){
            printf("NE\n");
            continue;
        }
        printf("DA\n");
    }
}