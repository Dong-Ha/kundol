#include <bits/stdc++.h>
using namespace std;
#define MAX 1510

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int r, c, ret = 0;
int _mp[MAX][MAX], swan_visited[MAX][MAX], ice_visited[MAX][MAX];
pair<int, int> swan;
queue<pair<int, int> > swan_now, swan_next, ice_now, ice_next;

bool SwanBfs();
void IceBfs();
void Melt();

int main(){
    cin >> r >> c;
    for(int i = 0; i < r; ++i){
        string s;
        cin >> s;
        for(int j = 0; j < c; ++j){
            _mp[i][j] = s[j];
            if(_mp[i][j] == '.') ice_now.push({i, j});
            else if(_mp[i][j] == 'L') ice_now.push({i, j}), swan = {i, j};
        }
    }
    swan_now.push(swan);
    swan_visited[swan.first][swan.second] = 1;

    while(1){
        if(SwanBfs()){
            IceBfs();
            ice_now = ice_next;
            ice_next = queue<pair<int, int> > ();
            swap(swan_now, swan_next);
        } else break;
    }

    cout << ret - 1 << '\n';

    return 0;
}

bool SwanBfs(){
    while(!swan_now.empty()){
        int y, x;
        tie(y, x) = swan_now.front(); swan_now.pop();
        for(int i = 0; i < 4; ++i){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= r || nx >= c || swan_visited[ny][nx]) continue;
            if(_mp[ny][nx] == '.'){
                swan_visited[ny][nx] = swan_visited[y][x];
                swan_now.push({ny, nx});
            }else if(_mp[ny][nx] == 'X'){
                swan_visited[ny][nx] = swan_visited[y][x] + 1;
                swan_next.push({ny, nx});
            }else if(_mp[ny][nx] == 'L'){
                ret = swan_visited[y][x];
                return false;
            }
        }
    }
    return true;
}

void IceBfs(){
    while(!ice_now.empty()){
        int y, x;
        tie(y, x) = ice_now.front(); ice_now.pop();
        ice_visited[y][x] = 1;
        for(int i = 0; i < 4; ++i){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= r || nx >= c || ice_visited[ny][nx]) continue;
            ice_visited[ny][nx] = 1;
            if(_mp[ny][nx] == 'X') ice_next.push({ny, nx}), _mp[ny][nx] = '.';
        }
    }
}

void Melt(){

    while(!ice_next.empty()){
        _mp[ice_next.front().first][ice_next.front().second] = '.';
        ice_next.pop();
    }
}