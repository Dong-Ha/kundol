#include <iostream>
using namespace std;

int N, L;
int cnt, ret;
int a[101][101], b[101][101];

void go(int now, int i){
    cnt = 1;
    for(int j = 1; j < N; ++j){
        if(now == a[i][j]) ++cnt;
        else if((now + 1) == a[i][j] && (cnt >= L)) cnt = 1; // 높아지는 경우 
        else if((now - 1) == a[i][j] && (cnt >= 0)) cnt = -L + 1;
        else return;
        now = a[i][j];
    }
    if(cnt >= 0) ++ret;
}

void go2(int now, int i){
    cnt = 1;
    for(int j = 1; j < N; ++j){
        if(now == b[i][j]) ++cnt;
        else if((now + 1) == b[i][j] && (cnt >= L)) cnt = 1; // 높아지는 경우 
        else if((now - 1) == b[i][j] && (cnt >= 0)) cnt = -L + 1;
        else return;
        now = b[i][j];
    }
    if(cnt >= 0) ++ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> L;

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            cin >> a[i][j];
            b[j][i] = a[i][j];
        }
    }

    for(int i = 0; i < N; ++i){
        go(a[i][0], i);
        go2(b[i][0], i);
    }
    cout << ret << '\n';

    return 0;
}