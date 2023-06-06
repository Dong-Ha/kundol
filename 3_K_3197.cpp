#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int r, c, ret = 0;
int _mp[1510][1510], visited[1510][1510];
string s;
pair<int, int> bak1, bak2;
queue<pair<int, int> > q, ice;
void bfs(int y, int x);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c;

    for(int i = 0; i < r; ++i){
        cin >> s;
        for(int j = 0; j < c; ++j){
            _mp[i][j] = s[j];
            if(s[j] == 'L'){ 
                if( !ret )bak1 = {i, j}, ++ret;
                else bak2 = {i, j};
            }
        }
    }

    ret = 0;

    while(1){
        fill(&visited[0][0], &visited[0][0] + 1510 * 1510, 0);
        bfs(bak1.first, bak1.second); // 한 곳에서 탐색 시작

        if(!visited[bak2.first][bak2.second]){ // 다른 곳 방문 안했을 경우
            ice = queue<pair<int, int> > ();
            fill(&visited[0][0], &visited[0][0] + 1510 * 1510, 0);

            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){
                    if(!visited[i][j] && _mp[i][j] == '.') bfs(i, j);
                }
            }
            while(!ice.empty()){
                _mp[ice.front().first][ice.front().second] = '.';
                ice.pop();
            }
            ++ret;
        }else{
            break;
        }
    }

    cout << ret << '\n';

    return 0;
}

void bfs(int ty, int tx){
    
    q.push({ty, tx});
    visited[ty][tx] = 1;

    while(!q.empty()){
        int y, x;
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; ++i){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx]) continue;
            if(_mp[ny][nx] == 'X'){ ice.push({ny, nx}), visited[ny][nx] = visited[y][x] + 1; continue;}
            
            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1;
        }
    }


}