#include <bits/stdc++.h>
using namespace std;

int a[100], b[100][100];

void go(int t[100]){
    cout << &t[10] << '\n';
    cout << &a[10] << '\n';
}

void go2(int t[100][100]){
    cout << &t[10][10] << '\n';
    cout << &b[10][10] << '\n';
}

int main(){
    for(int i = 0; i < 100; ++i){
        a[i] = i * 100;
        for(int j = 0; j < 100; ++j){
            b[i][j] = i * 1000 + j;
        }
    }
    go(a);
    go2(b);

    return 0;
}