#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        int cnt = 0;
        int ret = 0;
        while(1){
            ret++;
            if(cnt % n == 0){
                cout << ret << '\n';
                break;
            }
            cnt = cnt * 10 + 1;
        }

    }

    return 0;
}