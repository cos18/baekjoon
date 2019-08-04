#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);
    while(n--) {
        int locate = 0;
        char name[100], godname[101], tmp;
        while(1){
            scanf("%s", name);
            if(!locate) strcpy(name, "god");
            strcpy(godname+locate, name);
            locate += strlen(name);
            scanf("%c", &tmp);
            if(tmp=='\n') break;
        }
        godname[locate] = '\0';
        printf("%s\n", godname);
    }
}