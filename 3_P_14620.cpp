#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

int n, ret = INF;
int _mp[11][11] = {0,};
int visited[11][11] = {0, };

int Visit(int y, int x, int num){
    int cash = 0;
    visited[y][x] = num;
    cash += _mp[y][x];
    for(int i = 0; i < 4; ++i){
        visited[y + dy[i]][x + dx[i]] = num;
        cash += _mp[y + dy[i]][x + dx[i]];
    }
    return cash;
}

void Go(int y, int x, int flower, int cash){
    //cout << "(" << y << "," << x << ")"<< flower << '\n'; 
    
    if(3 <= flower) {
        //cout << "(" << y << "," << x << ")"<< "check" << '\n'; 
        ret = min(ret, cash);
        return ;
    }
    
    for(int i = 1; i < n - 1; ++i){
        for(int j = 1; j < n - 1; ++j){
            if(visited[i][j] || visited[i - 1][j] || \
            visited[i][j - 1] || visited[i + 1][j] || visited[i][j + 1] ) continue;
            cash += Visit(i, j, 1);
            Go(i, j, flower + 1, cash);
            cash -= Visit(i, j, 0);

        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i)for(int j = 0; j < n; ++j) cin >> _mp[i][j];

    Go(1, 1, 0, 0);

    cout << ret << '\n';



    return 0;
}