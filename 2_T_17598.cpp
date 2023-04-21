#include <bits/stdc++.h>
using namespace std;

stack<int> stk;
int a[1000004];
vector<int> ret;
int n;
int now;

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    for(int i = 0; i < n - 1; ++i){
        if(a[i] < a[i + 1]){
            stk.push(a[i + 1]);
            continue;
        }else if(a[i] == a[i + 1]){
            if(stk.empty()){
                stk.push(a[i]);
                continue;
            }else{
                if(stk.top() == a[i]){
                    stk.push(a[i]);
                    continue;
                } else {
                    while(!stk.empty()){
                        ret.push_back(a[i]);
                        stk.pop();
                    }
                    stk.push(a[i]);
                    continue;
                }
            }
        } else if(a[i] > a[i + 1]){

            if(stk.empty()){
                if(ret.empty()) ret.push_back(-1);
                else ret.push_back(a[i]);
                
                continue;
            }else{

                while(!stk.empty()){
                    ret.push_back(a[i]);
                    stk.pop();
                }
                stk.push(a[i]);
                continue;
            }
        }
    }
    
    if(!stk.empty()){
        int tmp = stk.top();
        while(!stk.empty()){
            ret.push_back(tmp);
            stk.pop();
        }
    }

    ret.push_back(-1);

    for(int i : ret) cout << i << ' '; cout << '\n';


    return 0;
}