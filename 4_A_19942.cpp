#include <bits/stdc++.h>
using namespace std;

struct neut{
    int p;
    int f;
    int s;
    int v;
    int c;
};

int n, ret = 987654321;
string sret = "999999";
neut tar;
neut a[16];

void go(int num){
    neut tmp  = {0, 0, 0, 0, 0};
    string s = "";
    for(int i = 0; i < n; ++i){
        if(num & (1 << i)){
            tmp.p += a[i].p;
            tmp.f += a[i].f;
            tmp.s += a[i].s;
            tmp.v += a[i].v;
            tmp.c += a[i].c;
            s += to_string(i + 1);
            s += " ";
            if(tmp.c > ret) return;
        }
    }
    if(tmp.p >= tar.p && tmp.f >= tar.f && tmp.s >= tar.s && tmp.v >= tar.v){
        if(ret > tmp.c){
            ret = tmp.c;
            sret = s;
        } else if(ret == tmp.c){
            if(sret > s){
                ret = tmp.c;
                sret = s;
            }
        }
    }
}

int main(){
    cin >> n;
    cin >> tar.p >> tar.f >> tar.s >> tar.v;
    for(int i = 0; i < n; ++i){
        cin >> a[i].p >> a[i].f >> a[i].s >> a[i].v >> a[i].c;
    }

    for(int i = 0; i < (1 << n); ++i){
        go(i);
    }

    if(987654321 == ret){
        cout << "-1" << '\n';
    } else{
        cout << ret << '\n' << sret << '\n';
    }

    return 0;
}