#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int d[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 9, 3},
    {1, 3, 9}
};

int n, scv[3] = {0,}, visited[61][61][61] = {0, };
queue<tuple<int, int, int> > q;
void bfs();

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> scv[i];

    bfs();
    cout << visited[0][0][0] - 1 << '\n';
    return 0;
}

void bfs(){
    visited[scv[0]][scv[1]][scv[2]] = 1;
    q.push({scv[0], scv[1], scv[2]});

    while(q.size()){
        int tx, ty, tz;
        tie(tx, ty, tz) = q.front(); q.pop();

        for(int i = 0; i < 6; i++){
            int x = max(0, tx - d[i][0]);
            int y = max(0, ty - d[i][1]);
            int z = max(0, tz - d[i][2]);
            if(visited[x][y][z]) continue;
            q.push({x, y, z});
            visited[x][y][z] = visited[tx][ty][tz] + 1;
            if(x == 0 && y == 0 && z == 0) return ;
        }


    }
}