#include <bits/stdc++.h>
#define NO 0
#define UP 1
#define DOWN 2
using namespace std;

int n, m, h, a, b, ret = 10000;
int _mp[31][11] ={0, };
int hubo[10] = {0, };

void Solve(int aa, int bb, int now_line);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> h;
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        --a; --b;
        _mp[a][b] = DOWN;
        _mp[a][b+1] = UP;
    }


    Solve(0, 0, 0);

    if(ret > 3)cout << -1 << '\n';
    else cout << ret << '\n';
    return 0;
}

bool Check(int aa, int bb){
    if(NO == _mp[aa][bb] && NO == _mp[aa][bb + 1]) return true;
    else return false;
}

void Test(int now_line){
    int flag = 0;
    for(int i = 0; i < n; ++i){
        int next_i = i;
        for(int j = 0; j < h; ++j){
            if(_mp[j][next_i] == NO) continue;
            else if (_mp[j][next_i] == DOWN) ++next_i;
            else if (_mp[j][next_i] == UP) --next_i;
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

    if(h <= aa) aa = 0, ++bb;
    
    
    if(Check(aa, bb)){
        _mp[aa][bb] = DOWN;
        _mp[aa][bb+1] = UP; 
        Test(now_line);
        Solve(aa + 1, bb, now_line + 1);
        _mp[aa][bb] = NO;
        _mp[aa][bb+1] = NO;
        Test(now_line);
        Solve(aa + 1, bb, now_line);
    }else{
        Test(now_line);
        Solve(aa + 1, bb, now_line);
    }
}