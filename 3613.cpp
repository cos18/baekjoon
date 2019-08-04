#include <stdio.h>
#include <string.h>

int main(){
    char name[100], newname[201];
    int is_cpp = 0, isJava = 0, namelen, locate = 0;
    scanf("%s", name);
    namelen = strlen(name);
    if(name[0]<'a'){
        is_cpp=1;
        isJava=1;
    }
    for(int i=0;i<namelen;i++){
        if(name[i]=='_'){
            is_cpp = 1;
            if(name[++i]=='_') isJava = 1;
        }
        if(name[i]<='Z') isJava = 1;
    }
    switch(is_cpp*2+isJava){
        case 0: // 단어 하나로 있는 경우 - is_cpp : 0 && isJava : 0
            printf("%s", name);
            break;
        case 1: // Java 변수인 경우 - is_cpp : 0 && isJava : 1
            for(int i=0;i<namelen;i++){
                if(name[i]<='Z'){
                    newname[locate++] = '_';
                    newname[locate++] = name[i] + 32;
                } else newname[locate++] = name[i];
            }
            newname[locate] = '\0';
            printf("%s", newname);
            break;
        case 2: // C++ 변수인 경우 - is_cpp : 1 && isJava : 0
            for(int i=0;i<namelen;i++){
                if(name[i]=='_'){
                    newname[locate++] = name[++i] - 32;
                } else newname[locate++] = name[i];
            }
            newname[locate] = '\0';
            printf("%s", newname);
            break;
        case 3: // 둘 다 섞인 혼종인 경우 - is_cpp : 1 && isJava : 1
            printf("Error!");
            break;
    }
}