#include <bits/stdc++.h>
using namespace std;
#define MAX 500001

int n, k, now;
int visited[MAX], dong[MAX];
queue<int> q;

int main(){
    cin >> n >> k;
    if(n == k){
        cout << "0" << '\n';
        return 0;
    }

    q.push(n);
    visited[n] = 1;
    while(!q.empty()){
        now = q.front(); q.pop();
        for(int i : {now - 1, now + 1, now * 2}){
            if(i < 0 || i > MAX || visited[i])continue;
            q.push(i);
            visited[i] = visited[now] + 1;
        }
    }

    now = k;
    for(int i = 1; now < MAX; ++i){
        now += i;
        if(visited[now] - 1 == i){
            cout << i << '\n';
            return 0;
        }
    }

    cout << "-1" << '\n';

    return 0;
}