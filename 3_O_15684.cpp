#include <bits/stdc++.h>
#define NO 0
#define UP 1
#define DOWN 2
using namespace std;

int n, m, h, a, b, ret = 10000;
int _mp[11][31] ={0, };

void Solve(int aa, int bb, int now_line);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> h;
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        --a; --b;
        _mp[b][a] = DOWN;
        _mp[b+1][a] = UP;
    }


    Solve(0, 0, 0);

    if(ret > 3)cout << -1 << '\n';
    else cout << ret << '\n';
    return 0;
}

bool Check(int aa, int bb){
    if(NO == _mp[bb][aa] && NO == _mp[bb + 1][aa]) return true;
    else return false;
}

void Test(int now_line){
    int flag = 0;
    for(int i = 0; i < n; ++i){
        int next_i = i;
        for(int j = 0; j < h; ++j){
            if(_mp[next_i][j] == NO) continue;
            else if (_mp[next_i][j] == DOWN) ++next_i;
            else if (_mp[next_i][j] == UP) --next_i;
        }
        if(i == next_i){
            ++flag;
        } else break;
    }
    if(flag == n - 1) ret = min(ret, now_line);
}

void Solve(int aa, int bb, int now_line){
    if(4 < now_line) return ;
    if(n - 1 < bb) return ;

    if(Check(aa, bb)){
        _mp[bb][aa] = DOWN;
        _mp[bb+1][aa] = UP;
        if(h < aa) Solve(0, ++bb, now_line + 1);
        else Solve(aa + 1, bb, now_line + 1);
        Test(now_line);
        _mp[bb][aa] = NO;
        _mp[bb+1][aa] = NO;
        if(h < aa) Solve(0, ++bb, now_line);
        else Solve(aa + 1, bb, now_line);
        Test(now_line);
    }else{
        if(h < aa) Solve(0, ++bb, now_line);
        else Solve(aa + 1, bb, now_line);
        Test(now_line);
    }
}