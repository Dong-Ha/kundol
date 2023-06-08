#include <bits/stdc++.h>
using namespace std;

int main(){
    string s = "0123456789";
    int tc = 0;
    do{
        
        cout << s << '\n';
        ++tc;
    }while(next_permutation(s.begin(), s.end()));

    cout << tc << '\n';
    return 0;
}