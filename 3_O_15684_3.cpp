#include <bits/stdc++.h>
#define INF 987654321
#define NO 0
#define LEFT 1
#define RIGHT 2
using namespace std;

int n, m, h, a, b, ret = INF;
int _mp[32][12] = {0, };

bool Test(){
    for(int i = 0; i < n; ++i){
        int next_i = i;
        for(int j = 0; j < h; ++j){
            if(RIGHT == _mp[j][next_i]) ++next_i;
            else if(LEFT == _mp[j][next_i]) --next_i;
        }
        if(next_i != i) return false;
    }
    return true;
}

void Go(int yy, int cnt){
    if(3 < cnt)  return;
    if(Test()) {
        ret = min(ret, cnt);}

    for(int i = yy; i < h; ++i){
        for(int j = 0; j < n - 1; ++j){
            if(_mp[i][j] != NO || _mp[i][j + 1] != NO) continue;
            //cout << "(" << i << "," << j <<")" << '\n';
            _mp[i][j] = RIGHT;
            _mp[i][j + 1] = LEFT;
            Go(i, cnt + 1);
            _mp[i][j] = NO;
            _mp[i][j + 1] = NO;
        }
    }
    
    
}

int main(){
    cin >> n >> m >> h;
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        --a; --b;
        _mp[a][b] = RIGHT;
        _mp[a][b + 1] = LEFT;
    }

    Go(0, 0);

    cout << ((ret == INF)? -1 : ret) << '\n';
    //if(INF == ret) cout << "-1" << '\n';
    //else cout << ret << '\n';
    return 0;
}