#include <bits/stdc++.h>
using namespace std;

int n, m, tmp, ret = 987654321;

vector<pair<int, int> > chicken, home;
void combi(int nn, int rr, vector<int> b);

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> tmp;
            if(1 == tmp) home.push_back({i, j});
            else if(2 == tmp) chicken.push_back({i, j});
        }
    }
    combi(m, -1, vector<int>());

    cout << ret << '\n';

    return 0;
}

void combi(int nn, int rr, vector<int> b){
    if(b.size() == nn){
        int tmp = 987654321, now_ret = 0;
    for(int j = 0; j < home.size(); ++j){
        tmp = 987654321;
        for(int i : b){ // 선택받은 치킨집 번호
            tmp = min(abs(home[j].first - chicken[i].first) + abs(home[j].second - chicken[i].second), tmp);
            }
            now_ret += tmp;
        }
        if(now_ret < ret) ret = now_ret;
        return;
    }

    for(int i = rr + 1; i < chicken.size(); ++i){
        b.push_back(i);
        combi(nn, i, b);
        b.pop_back();
    }
}