#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int r, c, ret = -10;
int A[30], _mp[22][22], visited[22][22];
string s;

void dfs(int ty, int tx, int cnt);

int main(){
    cin >> r >> c;
    for(int i = 0 ; i < r; ++i){
        cin >> s;
        for(int j = 0; j < c; ++j){
            _mp[i][j] = s[j] - 'A';
        }
    }
    
    ++visited[0][0];
    dfs(0, 0, 0);

    cout << ret << '\n';
    return 0;
}

void dfs(int ty, int tx, int cnt){
    if(A[_mp[ty][tx]] || cnt == r * c - 1){
        if(cnt == r * c - 1) ret = r * c;
        else ret = max(ret, cnt);
        return ;
    }

    ++A[_mp[ty][tx]];

    for(int i = 0; i < 4; ++i){
        int ny = ty + dy[i];
        int nx = tx + dx[i];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx]) continue;
        ++visited[ny][nx];
        ++cnt;
        dfs(ny, nx, cnt);
        --cnt;
        --visited[ny][nx];
    }

    --A[_mp[ty][tx]];

}