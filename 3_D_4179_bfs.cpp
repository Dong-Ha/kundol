#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
char a[1004][1004];
int visited[1004][1004];
int r, c, result;
pair<int, int> ji;
vector<pair<int, int> > fire, prev_fire;
queue<pair<int, int> > q, prev_q;

void print(){
    cout << '\n';
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << a[i][j];
        }
        cout << '\n';
    }
}

bool meetF(int y, int x){
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(a[ny][nx] == 'F') return true;
    }
    return false;
}


void bfs(){
    prev_q = q;
    q = queue<pair<int, int> > ();
    while(prev_q.size()){
        int y, x;
        tie(y, x) = prev_q.front(), prev_q.pop();

        if(y == 0 || x == 0 || y == r - 1 || x == c - 1){
            q = queue<pair<int, int> > ();
            result = visited[y][x];
            
            return ;
        }

        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx]) continue;
            if(a[ny][nx] != '.' || meetF(ny, nx)) continue;
            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1;
            a[ny][nx] = 'J';
        }
        a[y][x] = '.';
    }

    prev_fire = fire;
    fire.clear();
    for(pair<int, int> i : prev_fire){
        for(int j = 0; j < 4; j++){
            int ny = i.first + dy[j];
            int nx = i.second + dx[j];
            if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
            if(a[ny][nx] != '#' && a[ny][nx] != 'F'){
                fire.push_back({ny, nx});
                a[ny][nx] = 'F';
            }
        }
    }

   //print();
}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> r >> c;
    fill(&visited[0][0], &visited[0][0] + 1004 * 1004 , 0); 
    fill(&a[0][0], &a[0][0] + 1004 * 1004 , 0); 
    fire.clear(), prev_fire.clear();
    q = queue<pair<int, int> >();
    prev_q = queue<pair<int, int> >();

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> a[i][j];
            switch(a[i][j]){
                case 'J':
                ji = {i, j};
                break;
                case 'F':
                fire.push_back({i, j});
                break;
                default:
                break;
            }
        }
    }

    visited[ji.first][ji.second] = 1;
    q.push({ji.first, ji.second});
    while(q.size()) bfs();

    if(result) cout << result << '\n';
    else cout << "IMPOSSIBLE" << '\n';

    return 0;
}