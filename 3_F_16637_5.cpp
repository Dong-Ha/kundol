#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;
ll st, ret = -987654321987654321;
string s;

void solve(int ii, ll now);

int main(){
    cin >> n >> s;
    st = s[0] - '0';

    solve(0, st);
    cout << ret << '\n';

    return 0;
}

ll calcul(ll a, int kk){
    if(s[kk - 1] == '+') return a + (s[kk] - '0');
    else if(s[kk - 1] == '-') return a - (s[kk] - '0');
    else if(s[kk - 1] == '*') return a * (s[kk] - '0');
    else return 0;
}

ll calcul2(ll a, ll b, int kk){
    if(s[kk - 1] == '+') return a + b;
    else if(s[kk - 1] == '-') return a - b;
    else if(s[kk - 1] == '*') return a * b;
    else return 0;
}

void solve(int ii, ll now){
    if(ii >= n - 1){
      if(ret < now) ret = now;
      return;  
    }

    solve(ii + 2, calcul(now, ii + 2) ); // 다음꺼랑 계산하는 경우
    if(ii + 4 < n) solve(ii + 4, calcul2(now, calcul( s[ii + 2] - '0', ii + 4) , ii + 2)  ); // 다음꺼랑 계산안하는 경우

}