#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<string, int> mp;
string s, tmp;
vector<string> v;
int n;

bool cmp(string a, string b){
    return a.length() < b.length();
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(char k : s){
            if( k >= 'a' && k <= 'z') {
                if(tmp.length()) v.push_back(tmp), tmp.clear();
            } else{
                tmp += k;
            }
        }
        if(tmp.length()) v.push_back(tmp), tmp.clear();
    }

    for(string now : v){
        if(now.length() > 1){
            while(now[0] == '0' && now.length() > 1) now = now.substr(1);
        }
        mp[now]++;
    }

    for(int i = 1; i < 100; i++){    
    for(auto k : mp) {
        if(k.first.length() == i){
            for(int j = 0; j < k.second; j++) cout << k.first << '\n';
        }
    }
    }
    
    return 0;
}