#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){

    v.push_back(1);
    v.push_back(3);
    v.push_back(2);

    sort(v.begin(), v.end());

    int k = *v.begin();
    int j = *(v.end() - 1);

    cout << k << '\n' << j << '\n';

    return 0;
}