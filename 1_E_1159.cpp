#include <iostream>
#include <string>
using namespace std;

int a[26], N;
string s, ret;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s;
        a[ s[0] - 'a' ]++;
    }

    for(int i = 0; i < 26; i++){
        if(a[i] >= 5) ret += i + 'a';
    }

    if(ret != "") cout << ret << '\n';
    else cout << "PREDAJA" << '\n';


    return 0;
}