#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int a[9];
int ret;

void combi(){
    for(int i = 0; i < 9; i++){
        for(int j = i + 1; j < 9; j++){
            if(ret - a[i] - a[j] == 100){
                a[i] = 0;
                a[j] = 0;
                return ;
            }
        }
    }
}


int main(){
    for(int i = 0; i < 9; i++){
        cin >> a[i];
    }

    sort(&a[0], &a[0] + 9);
    
    ret = accumulate(&a[0], &a[0] + 9, 0);

    combi();

    for(int i = 0; i < 9; i++){
        if(a[i])cout << a[i] << '\n';
        
    }
    //cout << ret << '\n';
    
    return 0;
}