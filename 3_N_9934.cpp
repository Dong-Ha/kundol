#include <bits/stdc++.h>
using namespace std;

vector<int> idx;
vector<int> ret[10];
int a[1025]={0, };
int k;


int main(){
    cin >> k;
    for(int i = 0; i < pow(2, k) - 1; ++i){
        cin >> a[i];
    }

    for(int i = 0; i < k; ++i){
        int tmp = 0;
        for(int j = 0; (tmp = pow(2, i) - 1 + pow(2, i + 1) * j) < pow(2, k) - 1; ++j){
            ret[k - i - 1].push_back(a[tmp]);
            //cout << tmp << ' ';
        }
    }

    for(int i = 0; i < k; ++i){
        for(int j : ret[i]) cout << j << ' ';
        cout << '\n';
    }

    return 0;
}