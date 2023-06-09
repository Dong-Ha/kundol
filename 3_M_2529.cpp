#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int k, zero_add;
char a[12];
vector<int> v;
ll _max = -1, _min = 9987654321;

void combi(int r, int depth);

int main(){
    cin >> k;
    for(int i = 0; i < k; ++i) cin >> a[i];

    combi(0, 0);

    string s = to_string(_min);
    if(s.size() != k + 1) s = "0" + s;

    cout << _max << '\n';
    cout << s << '\n';

    return 0;
}

void check(){
    do
    {
        bool flag = 1;
        for(int i = 0; i < k; ++i){
            if('<' == a[i]){
                if(v[i] < v[i + 1]) continue;
                else {flag = 0; break;}
            }
            else if ('>' == a[i]){
                if(v[i] > v[i + 1]) continue;
                else {flag = 0; break;}
            }
        }

        if(flag){
            ll tmp = 0;
            for(int i : v) tmp = tmp * 10 + i;
            _min = min(_min, tmp);
            _max = max(_max, tmp);
            
        }


    } while (next_permutation(v.begin(), v.end()));
    
}

void combi(int r, int depth){
    if(depth == k + 1){
        check();

        return ;
    }

    for(int i = r; i < 10; ++i){
        v.push_back(i);
        combi(i + 1, depth + 1);
        v.pop_back();
    }
}