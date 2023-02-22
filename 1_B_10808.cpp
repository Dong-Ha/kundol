#include <iostream>
#include <string>
using namespace std;

string s;
int a[26];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> s;
    for(auto i : s) {
        a[ i - 'a' ]++;
    }

    for(auto i : a)cout << i << ' ';


    return 0;
}