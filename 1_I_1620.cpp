#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int N, M;
string s;
map<string, int> mps;
map<int, string> mpi;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> s;
        mps[s] = i;
        mpi[i] = s;
    }

    for(int i = 0; i < M; i++){
        string tmp;
        cin >> tmp;
        if( atoi(tmp.c_str())) cout << mpi[atoi(tmp.c_str())] << '\n';
        else cout << mps[tmp] << '\n';
    }

    return 0;
}