#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
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
    int flag = 0;
    queue<char> proi;
    queue<long long> q;
    for(char i : tmp){
        if(i == '(') flag = 1;
        else if(i == ')'){
            long long a, b;
            char giho;
            a = proi.front(); proi.pop(); a -= '0';
            giho = (char) proi.front(); proi.pop(); 
            b = proi.front(); proi.pop(); b -= '0';
            if(giho == '+') q.push((long long) a + b);
            else if(giho == '*') q.push((long long) a * b);
            else if(giho == '-') q.push((long long) a - b);

        }else if(i >= '0' && i <= '9'){
            if(flag) proi.push(i);
            else{
                if(q.size() == 3){
                    long long a, b;
                    char giho;
                    a = q.front(); q.pop(); a -= '0';
                    giho = (char) q.front(); q.pop();
                    b = q.front(); q.pop(); b -= '0';
                    if(giho == '+') q.push((long long) a + b);
                    else if(giho == '*') q.push((long long) a * b);
                    else if(giho == '-') q.push((long long) a - b);   
                }
                q.push(i);
                if(q.size() == 3){
                    long long a, b;
                    char giho;
                    a = q.front(); q.pop(); a -= '0';
                    giho = (char) q.front(); q.pop();
                    b = q.front(); q.pop(); b -= '0';
                    if(giho == '+') q.push((long long) a + b);
                    else if(giho == '*') q.push((long long) a * b);
                    else if(giho == '-') q.push((long long) a - b);   
                }
            }
        }else{
            if(flag) proi.push(i);
            else{
                q.push(i);
            }

        }

    }

    if(q.size() == 3){
    long long a, b;
    char giho;
    a = q.front(); q.pop(); a -= '0';
    giho = (char) q.front(); q.pop();
    b = q.front(); q.pop(); b -= '0';
    if(giho == '+') q.push((long long) a + b);
    else if(giho == '*') q.push((long long) a * b);
    else if(giho == '-') q.push((long long) a - b); 
    }

    result = max(result, q.front());

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