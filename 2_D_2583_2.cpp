#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int m, n, k;
int start_x, start_y, end_x, end_y;
int mp[101][101];
int visited[101][101];
int cnt;
int ny, nx;

priority_queue<int, vector<int>, greater<int> > q;
queue< pair<int, int> > qq;
void bfs(int y, int x);

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> m >> n >> k; // m 높이, n 너비
    for(int i = 0; i < k; ++i){

        cin >> start_x >> start_y >> end_x >> end_y;
        for(int ii = start_y; ii < end_y; ++ii){
            for(int jj = start_x; jj < end_x; ++jj){
                ++mp[ii][jj];
            }
        }

    }

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(mp[i][j] == 0 && visited[i][j] == 0) bfs(i, j);
        }
    }


    cout << q.size() << '\n';
    
    while(q.size()) cout << q.top() << ' ', q.pop(); 
    cout << '\n';


    return 0;
}

void bfs(int y, int x){
    cnt = 1;
    qq.push({y, x});
    visited[y][x] = 1;

    while(qq.size()){
        tie(y, x) = qq.front(); qq.pop();
        for(int i = 0; i < 4; i++){
            ny = y + dy[i];
            nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= m || nx >= n )continue;
            if(visited[ny][nx] || mp[ny][nx]) continue;
            qq.push({ny, nx});
            ++visited[ny][nx];
            ++cnt;
        }
    }
    q.push(cnt);
}