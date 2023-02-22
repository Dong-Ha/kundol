#include <iostream>
#include <stack>
#include <string>
using namespace std;

int n, ret;
string s;

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> s;
        stack<char> stk;
        for(int j = 0; j < s.length(); j++){
            if(stk.size() && stk.top() == s[j]) stk.pop();
            else stk.push(s[j]);
        }

        if(stk.empty()) ret++;
    }

    cout << ret << '\n';


    return 0;
}