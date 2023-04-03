#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int chess[6] = {1, 1, 2, 2, 2, 8};

int main(){
    for(int i = 0; i < 6; i++){
        int tmp;
        cin >> tmp;
        cout << chess[i] - tmp << ' ';

    }

    return 0;
}