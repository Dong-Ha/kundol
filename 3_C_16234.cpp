#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#include <algorithm>
using namespace std;

struct INGU{
    vector<pair<int, int> > pos;
    int sum = 0;
} tmp_list;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int N, L, R, cnt;
int mp[50][50], visited[50][50];
vector<INGU> list;
queue<pair<int, int> > q;

void bfs(int ty, int tx){
    tmp_list.pos.clear(); tmp_list.sum = 0;
    tmp_list.pos.push_back({ty, tx}); tmp_list.sum += mp[ty][tx];
    visited[ty][tx] = 1;
    q.push({ty, tx});
    
    while(q.size()){
        int y, x;
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx]) continue;
            if(abs(mp[y][x] - mp[ny][nx]) < L || abs(mp[y][x] - mp[ny][nx]) > R) continue;
            visited[ny][nx] = 1;
            q.push({ny, nx});
            tmp_list.pos.push_back({ny, nx}); tmp_list.sum += mp[ny][nx];
        }
    }
    if(tmp_list.pos.size() >= 2)list.push_back(tmp_list);
}

void distribute(){ // bfs로 구역 나누기
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j]) {
                bfs(i, j);
            }
        }
    }
}

void calculate(){
    for(INGU i : list){
        for(auto pp : i.pos){
            mp[pp.first][pp.second] = i.sum / i.pos.size();
        }
    }
}

int main(){
    cin >> N >> L >> R;
    for(int i = 0; i < N; i++)for(int j = 0; j < N; j++) cin >> mp[i][j];

    while(1){
        distribute();
        if(list.size() == 0) break;
        calculate();
        list.clear();
        fill(&visited[0][0], &visited[0][0] + 50*50, 0);
        cnt++;
    }

    cout << cnt << '\n';

    return 0;
}