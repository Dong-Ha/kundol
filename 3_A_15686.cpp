#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int n, m, ret=987654321;
vector<pair <int, int> > chicken, home;


int solve(vector<int> v){
    int cnt = 0, tmp = 987654321;
    for(pair<int, int> i : home){
        for(int j : v){
            tmp = min(tmp, abs(i.first - chicken[j].first) + abs(i.second - chicken[j].second));
        }
        cnt += tmp;
        tmp = 987654321;
    }
    return cnt;
}

void combi(int k, vector<int> v){
    if(v.size() == m){
        ret = min(solve(v), ret);
        //for(auto i : v) cout << i << ' ';
        //cout << '\n';
        return ;
    }
    for(int i = k + 1; i < chicken.size(); i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)for(int j = 0; j < n; j++){
        int tmp;
        cin >> tmp;
        switch (tmp){
            case 0:
                break;
            case 1:
                home.push_back({i, j});
                break;
            case 2:
                chicken.push_back({i, j});
                break;
            default:
                break;
        }
    }
    vector<int> v;
    combi(-1, v);

    cout << ret << '\n';

    return 0;
}