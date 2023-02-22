#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< vector<int> > v;
vector<int> ret;
int visited[10004];
int n, m, mx, now_mx = -100;
int A, B;

int solve(int n){
    visited[n] = 1;
    int tmp = 1;
    if(v[n].size() == 0) return 0;
    tmp += v[n].size();
    for(int i = 0; i < v[n].size(); i++){
        if(v[n][i]) continue;
        tmp += solve(v[n][i]);
    }
    return tmp;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        v.push_back(vector<int>());
    }
    for(int i = 0; i < m; i++){
        cin >> A >> B;
        v[B].push_back(A);
    }

    for(int i = 1; i <= n; i++){
        fill(visited, visited + 10004, 0);
        mx = 0;
        mx = solve(i);

        if(mx > now_mx) now_mx = mx, ret.clear(), ret.push_back(i);
        else if (mx == now_mx) ret.push_back(i);
    }

    for(int i : ret ) cout << i << ' ';
    cout << '\n';

    return 0;
}