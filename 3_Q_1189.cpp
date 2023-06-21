#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int dy[] ={-1, 0, 1, 0};
int dx[] ={0, 1, 0, -1};

int r, c, k;
int _mp[6][6], visited[6][6];

int dfs(int y, int x, int dis){
    if(0 == y && x == c - 1){
        if(dis == k) return 1;
        return 0;
    }
    if(dis > k) return 0;

    int ret = 0;
    for(int i = 0; i < 4; ++i){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx] || _mp[ny][nx] == 'T') continue;
        visited[ny][nx] = 1;
        ret += dfs(ny, nx, dis + 1);
        visited[ny][nx] = 0;
    }
    return ret;
}

int main(){
    cin >> r >> c >> k;
    for(int i = 0; i < r; ++i){
        string s;
        cin >> s;
        for(int j = 0; j < c; ++j){
            _mp[i][j] = s[j];
        }
    }
    visited[r - 1][0] = 1;
    
    cout << dfs(r - 1, 0, 1) << '\n';

    return 0;
}