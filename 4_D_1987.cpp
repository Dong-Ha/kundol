#include <bits/stdc++.h>
using namespace std;
int dy[]={-1, 0, 1, 0};
int dx[]={0, 1, 0, -1};
int R, C;
int m[21][21], visited[21][21];
int flag = 0, ret = 0;

void go(int y, int x, int depth){
    if(depth == R * C) {
        ret = depth;
        return ;
    }
    if((y || x)) {
        if(flag & (1 << m[y][x]) ){
            ret = max(ret, depth);
            return ;
        }
    }
    flag |= (1 << m[y][x]);
    for(int i = 0; i < 4; ++i){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(nx < 0 || ny < 0 || ny >= R || nx >= C || visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        go(ny, nx, depth + 1);
        visited[ny][nx] = 0;
    }
    flag &= ~(1 << m[y][x]);
    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    for(int i = 0; i < R; ++i){
        string s;
        cin >> s;
        for(int j = 0; j < C; ++j){
            m[i][j] = s[j] - 'A';
        }
    }
    visited[0][0] = 1;
    flag |= (1 << m[0][0]);
    go(0, 0, 1);
    if(ret == R * C)cout << ret << '\n';
    else cout << ret - 1 << '\n';

    return 0;
}