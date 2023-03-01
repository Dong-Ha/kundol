#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<string> v;
int n;
long long result= -1987654321;
string s;

void dfs(string tmp, int k, stack<char> stk){ // 괄호가 들어갔으면 flag 1 아니면 flag 0
    if(k == n){
        v.push_back(tmp);
        return ;
    }
    
    for(int i = 0; i < 2; i++){
        if(i){ // 괄호에 값 넣어
            if(k % 2 == 0) { // 숫자
                if(k < n - 2){
                    string recover_s = tmp;
                    stack<char> recover_stk = stk;
                    stk.push(s[k]);
                    stk.push(s[k + 1]);
                    stk.push(s[k + 2]);
                    string rr;
                    while(stk.size()) rr += stk.top(), stk.pop();
                    reverse(rr.begin(), rr.end());
                    tmp += '(';
                    tmp += rr;
                    tmp += ')';
                    dfs(tmp, k + 3, stk);
                    tmp = recover_s;
                    stk = recover_stk;
                }
            }

        } else{ // 괄호에 값 안 넣어
            tmp += s[k];
            dfs(tmp, k + 1, stk);
            tmp.pop_back();
        }
        

    }

}

void calculate(string tmp){
    int t = 0, flag = 0, cnt = 0;
    stack<char> sss;
    stack<long long> ttt;
    for(char i : tmp){
        if(i == '('){
            flag = 1;
        } else if(i == ')'){
            int a, b; char giho;
            b =(int) sss.top() - '0'; sss.pop();
            giho = sss.top(); sss.pop();
            a = (int) sss.top() - '0'; sss.pop();

            switch(giho){
                case '+':
                ttt.push(a + b);
                break;
                case '-':
                ttt.push(a - b);
                break;
                case '*':
                ttt.push(a * b);
                break;
            }

            flag = 0;
        } else if(i >= '0' && i <= '9'){
            if(flag){ // 괄호 내부인 경우
                sss.push(i);
            } else{ // 괄호 아닌 경우
                ttt.push(i);
                if(ttt.size() == 3){
                    int a, b; char giho;
                    b =(int) ttt.top() - '0'; ttt.pop();
                    giho = ttt.top(); ttt.pop();
                    a = (int) ttt.top() - '0'; ttt.pop();

                    switch(giho){
                        case '+':
                        ttt.push(a + b);
                        break;
                        case '-':
                        ttt.push(a - b);
                        break;
                        case '*':
                        ttt.push(a * b);
                        break;
                    }
                }
            }
        } else{ // 기호인 경우
            if(flag){ // 괄호 내부인 경우
                sss.push(i);
            } else{ // 괄호 아닌 경우
                ttt.push(i);
            }

        }
    }

    if(ttt.size() == 3){
                    int a, b; char giho;
                    b =(int) ttt.top() - '0'; ttt.pop();
                    giho = ttt.top(); ttt.pop();
                    a = (int) ttt.top() - '0'; ttt.pop();

                    switch(giho){
                        case '+':
                        ttt.push(a + b);
                        break;
                        case '-':
                        ttt.push(a - b);
                        break;
                        case '*':
                        ttt.push(a * b);
                        break;
                    }
                }

    result = max(result, ttt.top());

}

int main(){
    cin >> n;
    cin >> s;
    dfs("", 0, stack<char>());
    //sort(v.begin(), v.end());
    //for(string i : v) cout << i << '\n';
    //cout << v.size() << '\n';
    for(string i : v) calculate(i);

    cout << result << '\n';
    return 0;
}