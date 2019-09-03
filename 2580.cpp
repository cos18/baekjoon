#include <iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int sudoku[10][10]={}, zero=0;
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
            cin >> sudoku[i][j];
            if(!sudoku[i][j]) zero++;
        }
    }
    while(1){
        int check = 0;
        for(int i=1;i<10;i++){
            int linecheck = 0;
            for(int j=1;j<10;j++){
                if(!sudoku[i][j]){
                    linecheck = (linecheck)?10:j;
                }
            }
            if(linecheck!=0 && linecheck!=10){
                int sum=45;
                for(int j=1;j<10;j++) sum -= sudoku[i][j];
                sudoku[i][linecheck] = sum;
                check++;
            }
        }
        for(int j=1;j<10;j++){
            int linecheck = 0;
            for(int i=1;i<10;i++){
                if(!sudoku[i][j]){
                    linecheck = (linecheck)?10:i;
                }
            }
            if(linecheck!=0 && linecheck!=10){
                int sum=45;
                for(int i=1;i<10;i++) sum -= sudoku[i][j];
                sudoku[linecheck][j] = sum;
                check++;
            }
        }
        for(int k=0;k<3;k++){
            for(int l=0;l<3;l++){
                int linecheck = 0;
                for(int i=k*3+1;i<=k*3+3;i++){
                    for(int j=l*3+1;j<=l*3+3;j++){
                        if(!sudoku[i][j]) linecheck = (linecheck)?100:10*i+j;
                    }
                }
                if(linecheck!=0 && linecheck!=100){
                    int sum=45;
                    for(int i=k*3+1;i<=k*3+3;i++){
                        for(int j=l*3+1;j<=l*3+3;j++){
                            sum -= sudoku[i][j];
                        }
                    }
                    sudoku[linecheck/10][linecheck%10] = sum;
                    check++;
                }
            }
        }
        if(!check) break;
    }
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
            cout << sudoku[i][j] << " ";
        }
        cout << "\n";
    }
}