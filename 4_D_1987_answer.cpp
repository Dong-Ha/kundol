#include <bits/stdc++.h>
using namespace std;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int R, C, ret, ny, nx;
string s;
int a[21][21];

void go(int y, int x, int num, int cnt){
    ret = max(ret, cnt);
    for(int i = 0; i < 4; ++i){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
        int _next = (1 << a[ny][nx]);
        if((num & _next) == 0) go(ny, nx, num | _next, cnt + 1);
    }
}



int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> R >> C;
    for(int i = 0; i < R; ++i){
        cin >> s;
        for(int j = 0; j < C; ++j){
            a[i][j] = s[j] - 'A';
        }
    }

    go(0, 0, 1 << a[0][0], 1);
    cout << ret << '\n';

    return 0;
}
