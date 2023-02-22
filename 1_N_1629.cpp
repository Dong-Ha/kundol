#include <iostream>
typedef long long ll;
using namespace std;

ll A, B, C;
ll ret;

ll mod(ll n){
    if(n == 1){
        return A % C;
    }
    ll ret = mod(n / 2);

    if(n % 2){ // 홀수
        return ((ret * ret ) % C  * A % C) % C;
    }else { // 짝수
        return ( ret * ret ) % C;
    }
}

int main(){
    cin >> A >> B >> C;

    ret = mod(B) % C;


    cout << ret;
    return 0;
}