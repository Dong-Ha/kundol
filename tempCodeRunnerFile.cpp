#include <bits/stdc++.h>
using namespace std;

int m = 3;
void combi(int k, vector<int> v){
    if(v.size() == 3){
        for(int i : v){
            cout << i << ' ';
        }
        cout << '\n';
        return ;
    }
    for(int i = k + 1; i < 5; i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }

}

int main(){

    vector<int> v1, v2;
    v1.push_back(1);
    v2 = v1;
    cout << &v1 << ' ' << &v2 << '\n';
    return 0;
}