#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <utility>
#include <tuple>
#include <algorithm>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int n, m, result = -987654321;
int mp[50][50], visited[50][50];
queue<pair<int, int> > q;

void bfs(int ty, int tx){
    visited[ty][tx] = 1;
    q.push({ty, tx});
    while(q.size()){
        int y, x;
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || mp[ny][nx] == 'W')continue;
            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1;
            result = max(result, visited[ny][nx]);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n ; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            mp[i][j] = s[j];
        }
    }

    for(int i = 0; i < n; i++)for(int j = 0; j < m; j++){
        if(mp[i][j] == 'L'){
        memset(visited, 0, sizeof(visited));
        bfs(i, j);
        }
    }

    cout << result - 1 << '\n';

    return 0;
}