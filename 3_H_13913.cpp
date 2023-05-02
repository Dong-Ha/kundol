#include <bits/stdc++.h>
using namespace std;

int n, k, now;
int a[200001], visited[200001], last[200001];
queue<int> q;
vector<int> path;

int main(){
    cin >> n >> k;
    if(n == k){
        cout << 0 << '\n';
        cout << n << '\n';
        return 0;
    }
    q.push(n);
    visited[n] = 1;

    while(!q.empty()){

        now = q.front(); q.pop();

        for(int tmp : {now + 1, now - 1, now * 2}){
            if(tmp > 0 && tmp <= 200001){
                if(visited[tmp] == 0){
                    q.push(tmp);
                    visited[tmp] = visited[now] + 1;
                    last[tmp] = now;
                } 
            }
        }
    }

    cout << visited[k] - 1 << '\n';


    now = k;
    path.push_back(now);
    for(int i = 0; i < visited[k] - 1; ++i){
        now = last[now];
        path.push_back(now);
    }

    reverse(path.begin(), path.end());

    for(int i : path) cout << i << ' ';    

    return 0;
}