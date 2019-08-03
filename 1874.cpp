#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, a, i=0;
    stack<int> stack_array;
    string result = "";
    cin >> n;
    while(n--){
        cin >> a;
        if(!stack_array.empty() && a==stack_array.top()){
            stack_array.pop();
            result.append("-");
        } else if(a>=i){
            while (true){
                stack_array.push(++i);
                result.append("+");
                if(a == stack_array.top()) break;
            }
            stack_array.pop();
            result.append("-");
        } else {
            result = "NO";
            break;
        }
    }
    if(result.compare("NO")==0 || !stack_array.empty()){
        cout << "NO";
    } else {
        for(int i=0;i<result.size();i++){
            cout << result.at(i) << "\n";
        }
    }
    return 0;
}