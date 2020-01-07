#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char str[130];
    cin.getline(str,130,'\n');

    char var[130][130];
    int locate=0, start=0, varsize=0;
    while(true){
        if(str[locate]==';'){
            strncpy(var[varsize], str+start, locate-start);
            varsize++;
            break;
        }
        if(str[locate]==' '){
            strncpy(var[varsize], str+start, locate-start);
            if(varsize) var[varsize][locate-start-1] = '\0';
            start = locate+1;
            varsize++;
        }
        locate++;
    }

    for(int i=1;i<varsize;i++){
        cout << var[0];
        int strsize = strlen(var[i]);
        int newlocate = strsize-1;
        while (true){
            if(var[i][newlocate] !='[' && var[i][newlocate] !=']' && var[i][newlocate] !='&' && var[i][newlocate] !='*') break;
            if(var[i][newlocate] == ']'){
                cout << "[]";
                newlocate--;
            } else cout << var[i][newlocate];
            newlocate--;
        }
        cout << ' ';
        for(int j=0;j<=newlocate;j++) cout << var[i][j];
        cout << ";\n";
    }

    return 0;
}
