#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s, A, B, tmp, TA, TB;
int N;

void split(){
    int pos = s.find("*");
    A = s.substr(0, pos);
    B = s.substr(pos + 1, s.length());
}

int main(){
    cin >> N >> s;

    split();

    for(int i = 0; i < N; i++){
        cin >> tmp;
        if(tmp.length() >= A.length())TA = tmp.substr(0, A.length());
        if(tmp.length() >= B.length() &&  tmp.length() - B.length() > 0)TB = tmp.substr(tmp.length() - B.length(), tmp.length());

        if(TA.length() + TB.length() > tmp.length()){
            cout << "NE" << '\n';
            continue;
        }

        if((TA == A) && (TB == B)) cout << "DA" << '\n';
        else cout << "NE" << '\n';
    }

    return 0;
}