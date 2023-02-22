#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> mp;
int t, n;
string s;
int main(){
    cin >> t;

    for(int _T = 0; _T < t; _T++){
        mp.clear();

        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> s >> s;
            mp[s]++;
        }

        int ret = 1;

        for(auto i : mp){
            ret *= i.second + 1;
        }

        cout << ret - 1 << '\n';


    }


    return 0;
}