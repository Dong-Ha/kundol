#include <iostream>
#include <string>
using namespace std;

int N;
int a[64][64];

void solve(int start_y, int start_x, int end_y, int end_x, int n){ // (시작점), (끝점)
    if( n == 1 ){ 
        cout << a[start_y][start_x];
        return ;
        }
    int m = a[start_y][start_x];

    for(int i = start_y; i < end_y; i++){
        for(int j = start_x; j < end_x; j++){
            if(a[i][j] != m){
                cout << '(';
                solve(start_y, start_x, end_y / 2, end_x / 2, n / 2);
                solve(start_y, end_x / 2, end_y / 2, end_x, n / 2);
                solve(end_y / 2, start_x, end_y, end_x / 2, n / 2);
                //solve(start_y + (n / 2), start_x + (n / 2), end_y, end_x, n / 2);
                cout << ')';
                return ;
            }
        }
    }
    cout << m;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < N; j++){
            a[i][j] = s[j] - '0';
        }
    }  


    solve(0, 0, N, N, N);

    return 0;
}