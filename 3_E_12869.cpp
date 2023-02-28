#include <vector> // 항상 최적의 해를 구해주지 못한다! 반례 10 10 6
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

vector<int> scv;
int n = 0, result = 0, tmp = 0;


int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        scv.push_back(tmp);
    }

    sort(scv.begin(), scv.end(), greater<int>() );

    //cout << '\n';

    while(scv[0] > 0){
       //for(int i : scv) cout << i << " "; cout << '\n';

        switch (n){
            case 3:
            scv[2] -= 1;
            case 2:
            scv[1] -= 3;
            case 1:
            scv[0] -= 9;
            break;
            default:
            break;
        }

        result++;
        sort(scv.begin(), scv.end(), greater<int>() );

        
    }
    cout << result << '\n';

    return 0;
}