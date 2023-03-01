#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<string> v;
int n, result;
string s;

void dfs(string tmp, int k, stack<char> stk){ // 괄호가 들어갔으면 flag 1 아니면 flag 0
    if(k == n){
        v.push_back(tmp);
        return ;
    }
    string ttt = tmp;
    for(int i = 0; i < 2; i++){
        if(stk.size()){ // 괄호에 값 있음
            if(k % 2){ // 기호
                stk.push(s[k]);
                dfs(tmp, k + 1, stk);
                stk.pop();
                continue;
            } else{ // 숫자
                string recover_s = tmp;
                stack<char> recover_stk = stk;
                stk.push(s[k]);
                string rr;
                while(stk.size()) rr += stk.top(), stk.pop();
                reverse(rr.begin(), rr.end());
                tmp += '(';
                tmp += rr;
                tmp += ')';
                dfs(tmp, k + 1, stk);
                tmp = recover_s;
                stk = recover_stk;
                continue;
            }

        }else{ // 괄호에 있는 값 없음
            if(i){ // 괄호에 값 넣어
                if(k % 2){ // 기호
                    tmp += s[k];
                    dfs(tmp, k + 1, stk);
                    tmp.pop_back();
                }else{ // 숫자
                    stk.push(s[k]);
                    dfs(tmp, k + 1, stk);
                    stk.pop();
                }

            } else{ // 괄호에 값 안 넣어
                tmp += s[k];
                dfs(tmp, k + 1, stk);
                tmp.pop_back();
            }
        }

    }

}

int main(){
    cin >> n;
    cin >> s;
    dfs("", 0, stack<char>());
    for(string i : v) cout << i << '\n';
    cout << v.size() << '\n';
    return 0;
}