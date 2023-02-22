#include <iostream>
#include <algorithm>
using namespace std;

int N, K, tmp;
int a[100001], ret[100001];

int main(){
    cin >> N >> K;

    fill(ret, ret + N, -987654321);

    cin >> a[0];
    for(int i = 1; i < N; i++){
        cin >> tmp;
        a[i] = a[i - 1] + tmp;
    }

    ret[K - 1] = a[K - 1];
    for(int i = K; i < N; i++){
        ret[i] = a[i] - a[i - K];
    }

    cout << *max_element(ret, ret + N) << '\n';

    return 0;
}