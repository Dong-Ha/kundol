#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int n, ret = INF;
int a[21];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        for(int j = 0; j < n; ++j){
            if('H' == s[j]) a[i] |= (1 << j);
            else if('T' == s[j]) a[i] &= ~(1 << j);
        }
    }

    while(1){
        int m = -1, idx, flag = 0, cnt = 0; // flag : 0 row / 1 column
        ret = 0;

        for(int i = 0; i < n; ++i){
            int tmp = 0;
            for(int j = 0; j < n; ++j){
                if(a[i] & (1 << j)) ;
                else ++tmp, ++ret;
            }
            if(tmp > m){
                m = tmp;
                idx = i;
            }
            if(tmp) ++cnt;
        }


        for(int i = 0; i < n; ++i){
            int tmp = 0;
            for(int j = 0; j < n; ++j){
                if(a[j] & (1 << i)) ;
                else ++tmp;
            }
            if(tmp >= m){
                m = tmp;
                idx = i;
                flag = 1;
            }
        }

        if(m <= n / 2)
        { 
            if(cnt != n)break;
            break;
            //else idx = (++idx) % n ,flag ^= 1;
        }

        if(flag){ // column
            for(int i = 0; i < n; ++i){
                    a[i] ^= (1 << idx);
            }
        }else{ // row
                a[idx] ^= -1;
        }
    }

    cout << ret << '\n';

    return 0;
}