#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
int n, ret = INF, flag = 1;
int visited[13], a[13];  // idx start 1
vector<int> m[13];
vector<int> A, B;

void visit(int AB, int test){ // A : 1, B : 0
    if(visited[test]) return;
    visited[test] = 1;
    if(AB){
        auto it = find(A.begin(), A.end(), test);
        if(it == A.end()) flag = 0;
    }else{

    }

}

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    
    for(int i = 1; i <= n; ++i){
        int tmp;
        cin >> tmp;
        for(int j = 0; j < tmp; ++j){
            int tmp2;
            cin >> tmp2;
            m[i].push_back(tmp2);
        }
    }
    
    for(int i = 1; i < (1 << n) - 1; ++i){
        for(int j = 0; j < n; ++j){ // A, B그룹 분리
            if((i >> j) & 1) A.push_back(j + 1);
            else B.push_back(j + 1);
        }
    
        for(int k : A){
            visited[k] = 1;

        }


        A.clear();
        B.clear();
    }




    return 0;
}