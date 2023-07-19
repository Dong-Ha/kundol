#include <bits/stdc++.h>
using namespace std;

#define garo 1
#define sero 1

int N, L, ret = 0;
int cnt = 0, flag = 0; // 0 다리 안놓아도 됨, 1 다리 놓아야함
bool increase = 1;
int b[101][101]; //다리 놓았는지
int m[101][101]; //지도

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> L;
    for(int i = 0; i < N; ++i)for(int j = 0; j < N; ++j) cin >> m[i][j];

    #ifdef garo
    // 가로 방향 진행
    for(int i = 0; i < N; ++i){
        int now = m[i][0]; cnt = 1; flag = 0; increase = 1;
        for(int j = 1; j < N; ++j){
            if( abs(now - m[i][j]) > 1 ){
                increase = 0;
                break; 
            }else if(m[i][j] == now){
                if(flag){
                    cout << "error exist!" << '\n';
                }
                ++cnt;
            }else if(m[i][j] > now){
                if(cnt < L){
                    increase = 0;
                    break;
                }else{
                    for(int k = j; k > j - L; --k){
                        if(b[i][k]){
                            increase = 0;
                            break;
                        }
                    }
                    if(!increase) break;
                    for(int k = j; k > j - L; --k){
                        b[i][k] = 1;
                    }
                    cnt = 1; flag = 0;
                }
            }else if(m[i][j] < now){
                if(L == 1){
                    b[i][j + 1] = 1;
                    cnt = 1; flag = 0;
                    now = m[i][j];
                    continue;
                }
                if(j + L > N) {
                    increase = 0; 
                    break;
                } else{
                    int tmp = m[i][j];
                    for(int k = j + 1; k < j + L; ++k){
                        if(tmp != m[i][k]){
                            increase = 0;
                            break;
                        }else{
                            tmp = m[i][k];
                        }

                    }
                    if(!increase) break;
                    for(int k = j + 1; k < j + L; ++k){
                        b[i][k] = 1;
                    }
                    j = j + L;
                    cnt = 1; flag = 0;
                }
            }

            now = m[i][j];
        }
        if(increase)++ret;
    }
    #endif
    // 초기화
    fill(&b[0][0], &b[0][0] + 101 * 101, 0);

    #ifdef sero
    // 세로 방향 진행
    for(int i = 0; i < N; ++i){
        int now = m[0][i]; cnt = 1; flag = 0; increase = 1;
        for(int j = 1; j < N; ++j){
            if( abs(now - m[j][i]) > 1 ){
                increase = 0;
                break; 
            }else if(m[j][i] == now){
                if(flag){
                    cout << "error exist!" << '\n';
                }
                ++cnt;
            }else if(m[j][i] > now){
                if(cnt < L){
                    increase = 0;
                    break;
                }else{
                    for(int k = j; k > j - L; --k){
                        if(b[k][i]){
                            increase = 0;
                            break;
                        }
                    }
                    if(!increase) break;
                    for(int k = j; k > j - L; --k){
                        b[k][i] = 1;
                    }
                    cnt = 1; flag = 0;
                }
            }else if(m[j][i] < now){
                if(L == 1){
                    b[j + 1][i] = 1;
                    cnt = 1; flag = 0;
                    now = m[j][i];
                    continue;
                }
                if(j + L > N) {
                    increase = 0; 
                    break;
                } else{
                    int tmp = m[j][i];
                    for(int k = j + 1; k < j + L; ++k){
                        if(tmp != m[k][i]){
                            increase = 0;
                            break;
                        }else{
                            tmp = m[k][i];
                        }

                    }
                    if(!increase) break;
                    for(int k = j + 1; k < j + L; ++k){
                        b[k][i] = 1;
                    }
                    j = j + L - 1;
                    cnt = 1; flag = 0;
                }
            }

            now = m[j][i];
        }
        if(increase) ++ret;

            
    }
    #endif


    cout << ret << '\n';
    return 0;
}