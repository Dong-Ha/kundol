#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, tmp = 1, ret = 1;

int main(){
    while(cin >> n){
        tmp = 1, ret = 1;
        while(1){
        if(tmp % n == 0) {cout << ret << '\n'; break; }
            tmp %= n;
            tmp = tmp * 10 + 1;
            ++ret;
        }
    }
    return 0;
}