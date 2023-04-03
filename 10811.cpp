#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> s;
int n, m;
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        s.push_back(i);
    }

    for(int i = 0; i < m; i++){
        int t1, t2;
        cin >> t1 >> t2;
        reverse(s.begin() + t1 - 1 , s.begin() + t2);
    }

    for(int i : s) cout << i << ' ';

    return 0;
}