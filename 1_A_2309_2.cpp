#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int a[9];
vector<int> b;
int ret;
pair <int, int> p;

void combi(){
    for(int i = 0; i < 9 ; i++){
        for(int j = i + 1; j < 9; j++){
            if(ret - a[i] - a[j] == 100){
                p = {i, j};
                return ;
            }
        }
    }
}

int main(){
    for(int i = 0; i < 9; i++){
        cin >> a[i];
        ret += a[i];
    }


    combi();

    for(int i = 0; i < 9; i++){
        if(i == p.first || i == p.second) continue;
        b.emplace_back(a[i]);
    }
    sort(b.begin(), b.end());

    for(auto i : b) cout << i << '\n';

    return 0;
}