#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int n, m, ret;
int jx, jy, bx, by;
int visited[310][310];
int mp[310][310];
bool flag = 0;
queue<pair<int, int> > zero;
queue<pair<int, int> > wall;

void bfs(int y, int x);

int main(){
    cin >> n >> m;
    cin >> jy >> jx >> by >> bx;
    --jy; --jx; --by; --bx;

    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        for(int j = 0; j < m; ++j){
            mp[i][j] = s[j];
        }
    }

    while(!flag) bfs(jy, jx);

    cout << ret << '\n';

    return 0;
}

void bfs(int y, int x){
    fill(&visited[0][0], &visited[0][0] + 310 * 310, 0);
    visited[y][x] = 1;
    ++ret;
    zero.push({y, x});
    while(zero.size()){
        tie(y,x) = zero.front(); zero.pop();

        for(int i = 0; i < 4; ++i){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || mp[ny][nx] == '*') continue;

            if(mp[ny][nx] == '1') wall.push({ny, nx});
            else if(mp[ny][nx] == '0'){
                visited[ny][nx] = 1;
                zero.push({ny, nx});
            } else if(mp[ny][nx] == '#'){
                flag = 1;
                return ;
            }

        }
    }
    
    while(!wall.empty()){
        tie(y, x) = wall.front(); wall.pop();
        mp[y][x] = '0';
    }

}