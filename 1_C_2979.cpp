#include <iostream>
using namespace std;

int A, B, C;
int a[101];
int ret;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> A >> B >> C;
    int _start, _finish;
    for(int j = 0; j < 3; j++){
        cin >> _start >> _finish;
        for(int i = _start; i < _finish; i++){
            a[i]++;
        }
    }

    for(int i = 1; i <= 100; i++){
        switch(a[i])
        {
        case 1:
        ret += A;
        break;
        case 2:
        ret += 2 * B;
        break;
        case 3:
        ret += 3 * C;
        break;
        default:
        break;
        }
    }

    cout << ret << '\n';

    return 0;
}