#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s, t;

int main(){
    cin >> s;
    t = s;
    reverse(t.begin(), t.end());

    if(t == s) cout << "1" << '\n';
    else cout << "0" << '\n';

    return 0;
}