#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <tuple>
using namespace std;

int n, m;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int visited[100][100];
int a[100][100];
queue< pair<int, int> > q;

void bfs(){
    
    q.push({0, 0});
    visited[0][0] = 1;
    while(q.size()){
        int y, x;
        tie(y,x) = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 0 || visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            a[i][j] = s[j] - '0';
        }
    }

    bfs();

    cout << visited[n-1][m-1] << '\n';

    return 0;
}