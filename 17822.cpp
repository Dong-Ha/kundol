#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main(){
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    rotate(v.begin(), v.begin() + 1, v.end());

    for(int i : v) cout << i << ' ';


    return 0;
}