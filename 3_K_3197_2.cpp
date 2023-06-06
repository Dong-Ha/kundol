#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int r, c, ret = 0;
int _mp[1510][1510], visited[1510][1510], dis[1510][1510];
string s;
pair<int, int> bak1, bak2;
queue<pair<int, int> > swan, next_swan, ice;
void bfs(int y, int x);
void bakbfs(int y, int x);

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

    swan.push({bak1.first, bak1.second});
    


    cout << ret << '\n';

    return 0;
}

