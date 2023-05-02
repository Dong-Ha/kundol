#include <bits/stdc++.h>
using namespace std;

int visited[200001];
int mp[200001];

queue<int> q;
int n, k;
int ret = 0;

void bfs(){
    q.push(n);
    visited[n] = 1;
    while(q.size()){
        int tmp = q.front(); q.pop();
        for(int next : {tmp - 1, tmp + 1, tmp * 2}){
            if(next < 0 || next > 200000 || visited[next]) continue;
            if(!visited[next]){
                q.push(next);
                visited[next] = visited[tmp] + 1;
            } else if(visited[next] == visited[tmp] + 1){
                
            }
            if(next == k) ++ret;
            cout << 1 << ' ';
        }
    }
}

int main(){
    cin >> n >> k;
    bfs();

    cout << visited[k] - 1 << '\n' << ret << '\n';

    return 0;
}