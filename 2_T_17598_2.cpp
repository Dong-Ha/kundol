#include <bits/stdc++.h>
using namespace std;

stack<int> stk;
int a[1000004], ret[1000004];
int n;

int main(){
    cin >> n;
    fill(&ret[0], &ret[0] + 1000004, -1);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    return 0;
}