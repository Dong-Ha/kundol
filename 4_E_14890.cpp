#include <bits/stdc++.h>
using namespace std;

int N, L, ret = 0;
int cnt = 0, flag = 0;
int b[101][101]; //다리 놓았는지
int m[101][101]; //지도

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> L;
    for(int i = 0; i < N; ++i)for(int j = 0; j < N; ++j) cin >> m[i][j];


    for(int i = 0; i < N; ++i){
        int now = m[i][0];
        for(int j = 1; j < N; ++j){
            if( abs(now - m[i][j]) > 1 ){
                break; 
            }else if(m[i][j] == now){

            }else if(m[i][j] > now){

            }else if(m[i][j] < now){

            }

            now = m[i][j];
        }

    }
    
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            
        }
    }

    return 0;
}