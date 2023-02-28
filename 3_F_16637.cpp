#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int n;
string s, stmp;
long long result = -9987654321, tmp = 0;
vector<string> v;

queue<char> q, gwalho;

long long calculate(long long a, long long b, char gg){
    a -= '0'; 
    b -= '0'; 
    switch (gg){
        case '+':
        return a + b;

        case '-':
        return a - b;

        case '*':
        return a * b;

        default:
        break;
    }
    return 0;
}

void dfs(int k, long long now){
    if(k == n){
        if(gwalho.size()){
            // 로직 추가해야 함
            result = max(result, now);
        }else result = max(result, now);
        
    }

    for(int i = 0; i < 2; i++){ // 0이면 괄호 안 넣고, 1이면 괄호 넣어
        if(k % 2){ // 현재위치가 기호인경우

        } else{ // 현재위치가 숫자인경우
            if(i){ // 괄호 넣는 경우
                if(gwalho.size()){
                    char m, n;
                    m = (long long)gwalho.front(); gwalho.pop();
                    n = gwalho.front(); gwalho.pop();
                    q.push(calculate(m, (long long)s[k], n));

                }
            } else { // 괄호 안 넣는 경우

            }
        }
    }

}

int main(){
    cin >> n >> s;

    tmp = s[0] - '0';
    dfs(0, 0);

    return 0;
}