#include <iostream>
#include <string>
using namespace std;

string s;
int mo, ja, flag, cnt;

bool check(char i){
    if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') return true;
    else return false;
}

int main(){
    while(cin >> s){
        if(s == "end") break;
        mo = 0; ja = 0; flag = 0; cnt = 0;
        
        if( check(s[0]) ) mo++, cnt++;
        else ja++;

        for(int i = 1; i < s.length(); i++){
            if( check(s[i]) )  mo++, ja = 0, cnt++;
            else  ja++, mo = 0;
            if(ja == 3 || mo == 3) flag = 1;
            if(ja == 2 && s[i] == s[i-1]) flag = 1;
            if(mo == 2 && s[i] == s[i-1] && s[i] != 'e' && s[i] != 'o') flag = 1;
        }
        if(cnt == 0) flag = 1;
        if(flag)cout << "<" << s << "> is not acceptable.\n";
        else cout << "<" << s << "> is acceptable.\n";;
    }

    return 0;
}