#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int R, C, cnt = 1, flag, result = 987654321;
char a[1004][1004], visited[1004][1004];
pair<int, int> ji, prev_ji;
vector<pair<int, int> > fire, prev_fire;

bool meet(int y, int x){ // 이동한 지훈이 옆에 불이 있는지 체크
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(a[ny][nx] == 'F') return true;
    }
    return false;
}

void dfs(int y, int x){
    if(y == 0 || x == 0 || y == R - 1 || x == C - 1) {
        result = min(result, cnt);
        flag = 1;
        return ;
    }

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= R || nx >= C || visited[ny][nx] || a[ny][nx] != '.') continue;
        if(meet(ny, nx)) continue;
        visited[ny][nx] = 1;
        a[y][x] = '.';
        a[ny][nx] = 'J';
        prev_ji = ji;
        ji = {ny, nx};
        cnt++;
        int tmp = 0;
        if(fire.size()){
            prev_fire = fire;
            fire.clear();
            for(pair<int, int> bull : prev_fire){
                for(int j = 0; j < 4; j++){
                    int ty = bull.first + dy[i];
                    int tx = bull.second + dx[i];
                    if(a[ty][tx] == '.') a[ty][tx] = 'F', fire.push_back({ty, tx});
                }
            }
        }
        dfs(ny, nx);
        ji = prev_ji;
        if(fire.size()){
            for(pair<int, int> bull : fire){
                a[bull.first][bull.second] = '.';
            }
        }
        fire = prev_fire;
        cnt--;
    }
}

int main(){
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> a[i][j];
            if(a[i][j] == 'J') ji = {i, j}, visited[i][j] = 1;
            else if(a[i][j] == 'F') fire.push_back({i, j});
        }
    }

    dfs(ji.first, ji.second);

    if(flag)cout << result << '\n';
    else cout << "IMPOSSIBLE" << '\n';

    return 0;
}